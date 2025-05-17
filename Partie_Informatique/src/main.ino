#define TINY_GSM_MODEM_SIM7000
#define TINY_GSM_RX_BUFFER 1024 // Définir le tampon RX à 1Ko
#define SerialAT Serial1

// Voir toutes les commandes AT, si souhaité
#define DUMP_AT_COMMANDS

// Définir le code PIN de la carte SIM, si nécessaire
#define GSM_PIN ""

// Vos identifiants GPRS, si vous en avez
const char apn[]  = "sl2sfr";     //DÉFINISSEZ VOTRE APN
const char gprsUser[] = "";
const char gprsPass[] = "";

// Définir un numéro de téléphone pour tester les SMS (doit être au format international avec le "+" devant)
#define SMS_TARGET  "+33645218132"

#include <TinyGsmClient.h>
#include <Ticker.h>

#ifdef DUMP_AT_COMMANDS  // si activé, nécessite la lib streamDebugger
  #include <StreamDebugger.h>
  StreamDebugger debugger(SerialAT, Serial);
  TinyGsm modem(debugger);
#else
  TinyGsm modem(SerialAT);
#endif

#define uS_TO_S_FACTOR 1000000ULL  // Facteur de conversion de microsecondes en secondes
#define TIME_TO_SLEEP  60          // Durée pendant laquelle l'ESP32 dormira (en secondes)

#define UART_BAUD   115200
#define PIN_DTR     25
#define PIN_TX      20
#define PIN_RX      19
#define PWR_PIN     4

// #define SD_MISO     2
// #define SD_MOSI     15
// #define SD_SCLK     14
// #define SD_CS       13
#define LED_PIN     12

int counter, lastIndex, numberOfPieces = 24;
String pieces[24], input;

void setup(){
  // Définir le débit en bauds de la console
  Serial.begin(115200);
  delay(10);

  // Éteindre la LED
  pinMode(LED_PIN, OUTPUT);
  digitalWrite(LED_PIN, HIGH);

  pinMode(PWR_PIN, OUTPUT);
  digitalWrite(PWR_PIN, HIGH);
  delay(300);
  digitalWrite(PWR_PIN, LOW);

  //SPI.begin(SD_SCLK, SD_MISO, SD_MOSI, SD_CS);
  // if (!SD.begin(SD_CS)) {
  //   Serial.println("ÉCHEC DU MONTAGE DE LA CARTE SD");
  // } else {
  //   uint32_t cardSize = SD.cardSize() / (1024 * 1024);
  //   String str = "Taille de la carte SD : " + String(cardSize) + "MB";
  //   Serial.println(str);
  // }

  Serial.println("\nPatientez...");

  delay(1000);

  SerialAT.begin(UART_BAUD, SERIAL_8N1, PIN_RX, PIN_TX);

  // Redémarrer prend un certain temps
  // Pour le sauter, appelez init() au lieu de restart()
  Serial.println("Initialisation du modem...");
  if (!modem.restart()) {
    Serial.println("Échec du redémarrage du modem, tentative de continuation sans redémarrage");
  }

  String name = modem.getModemName();
  delay(500);
  Serial.println("Nom du modem : " + name);

  String modemInfo = modem.getModemInfo();
  delay(500);
  Serial.println("Infos modem : " + modemInfo);

  // Déverrouillez votre carte SIM avec un PIN si nécessaire
  if ( GSM_PIN && modem.getSimStatus() != 3 ) {
      modem.simUnlock(GSM_PIN);
  }
}

void loop(){
  // Redémarrer prend un certain temps
  // Pour le sauter, appelez init() au lieu de restart()
  // Serial.println("Initialisation du modem...");
  // if (!modem.init()) {
  //   Serial.println("Échec de l'initialisation du modem, tentative de continuation sans redémarrage");
  // }

  modem.sendAT("+CFUN=0 ");
  if (modem.waitResponse(10000L) != 1) {
    DBG(" +CFUN=0  échoué ");
  }
  delay(200);

  /*
    2 Automatique
    13 GSM seulement
    38 LTE seulement
    51 GSM et LTE uniquement
  */
  String res;
  // CHANGER LE MODE RÉSEAU, SI NÉCESSAIRE
  res = modem.setNetworkMode(2);
  if (res != "1") {
    DBG("setNetworkMode échoué ");
    return ;
  }
  delay(200);

  /*
    1 CAT-M
    2 NB-IoT
    3 CAT-M et NB-IoT
  */
  // CHANGER LE MODE PRÉFÉRÉ, SI NÉCESSAIRE
  res = modem.setPreferredMode(1);
  if (res != "1") {
    DBG("setPreferredMode échoué ");
    return ;
  }
  delay(200);

  /*
    AT+CBANDCFG=<mode>,<band>[,<band>…]
    <mode> "CAT-M"   "NB-IOT"
    <band> Doit correspondre à la liste retournée par AT+CBANDCFG=?
    Exemple : Mon opérateur NB-IoT supporte la bande B8 → AT+CBANDCFG="NB-IOT",8
  */
  /* modem.sendAT("+CBANDCFG=\"NB-IOT\",8 ");*/
  
  /* if (modem.waitResponse(10000L) != 1) {
       DBG(" +CBANDCFG=\"NB-IOT\" ");
   }*/
   delay(200);

  modem.sendAT("+CFUN=1 ");
  if (modem.waitResponse(10000L) != 1) {
    DBG(" +CFUN=1 échoué ");
  }
  delay(200);

  SerialAT.println("AT+CGDCONT?");
  delay(500);
  if (SerialAT.available()) {
    input = SerialAT.readString();
    for (int i = 0; i < input.length(); i++) {
      if (input.substring(i, i + 1) == "\n") {
        pieces[counter] = input.substring(lastIndex, i);
        lastIndex = i + 1;
        counter++;
       }
        if (i == input.length() - 1) {
          pieces[counter] = input.substring(lastIndex, i);
        }
      }
      // Réinitialiser pour réutilisation
      input = "";
      counter = 0;
      lastIndex = 0;

      for ( int y = 0; y < numberOfPieces; y++) {
        for ( int x = 0; x < pieces[y].length(); x++) {
          char c = pieces[y][x];  // récupère un octet du tampon
          if (c == ',') {
            if (input.indexOf(": ") >= 0) {
              String data = input.substring((input.indexOf(": ") + 1));
              if ( data.toInt() > 0 && data.toInt() < 25) {
                modem.sendAT("+CGDCONT=" + String(data.toInt()) + ",\"IP\",\"" + String(apn) + "\",\"0.0.0.0\",0,0,0,0");
              }
              input = "";
              break;
            }
          // Réinitialiser pour réutilisation
          input = "";
         } else {
          input += c;
         }
      }
    }
  } else {
    Serial.println("Échec de récupération du PDP !");
  }

  Serial.println("\n\n\nAttente du réseau...");
  if (!modem.waitForNetwork()) {
    delay(10000);
    return;
  }

  if (modem.isNetworkConnected()) {
    Serial.println("Réseau connecté");
  }

  // --------TEST GPRS--------
  Serial.println("\n---DÉBUT DU TEST GPRS---\n");
  Serial.println("Connexion à : " + String(apn));
  if (!modem.gprsConnect(apn, gprsUser, gprsPass)) {
    delay(10000);
    return;
  }

  Serial.print("Statut GPRS : ");
  if (modem.isGprsConnected()) {
    Serial.println("connecté");
  } else {
    Serial.println("non connecté");
  }

  String ccid = modem.getSimCCID();
  Serial.println("CCID : " + ccid);

  String imei = modem.getIMEI();
  Serial.println("IMEI : " + imei);

  String cop = modem.getOperator();
  Serial.println("Opérateur : " + cop);

  IPAddress local = modem.localIP();
  Serial.println("IP locale : " + String(local));

  int csq = modem.getSignalQuality();
  Serial.println("Qualité du signal : " + String(csq));

  SerialAT.println("AT+CPSI?");     //Obtenir le type de connexion et la bande
  delay(500);
  if (SerialAT.available()) {
    String r = SerialAT.readString();
    Serial.println(r);
  }

  Serial.println("\n---FIN DU TEST GPRS---\n");

  modem.gprsDisconnect();
  if (!modem.isGprsConnected()) {
    Serial.println("GPRS déconnecté");
  } else {
    Serial.println("Déconnexion GPRS : Échec");
  }

  // --------TEST GPS--------
  /*
  Serial.println("\n---DÉBUT DU TEST GPS---\n");
  // Mettre GPIO4 du SIM7000G à HIGH, allume l’alimentation GPS
  // CMD:AT+SGPIO=0,4,1,1
  // Fonction disponible uniquement dans la version 20200415
  modem.sendAT("+SGPIO=0,4,1,1");
  if (modem.waitResponse(10000L) != 1) {
    DBG(" SGPIO=0,4,1,1 échoué ");
  }
  modem.enableGPS();
  float lat,  lon;
  while (1) {
    if (modem.getGPS(&lat, &lon)) {
      Serial.printf("lat:%f lon:%f\n", lat, lon);
      break;
    } else {
      Serial.print("getGPS ");
      Serial.println(millis());
    }
    delay(2000);
  }
  modem.disableGPS();

  // GPIO4 à LOW, couper l’alim GPS
  modem.sendAT("+SGPIO=0,4,1,0");
  if (modem.waitResponse(10000L) != 1) {
    DBG(" SGPIO=0,4,1,0 échoué ");
  }
  Serial.println("\n---FIN DU TEST GPS---\n");
*/

  // --------TEST ENVOI SMS--------
  res = modem.sendSMS(SMS_TARGET, String("Salut de la part de ") + imei);
  DBG("SMS:", res ? "Envoyé" : "Échec");


  // --------TEST ARRÊT DU MODÈME--------

  // Essayer d'éteindre (le modem peut décider de redémarrer automatiquement)
  // Pour éteindre complètement, utiliser les pins Reset/Enable
  modem.sendAT("+CPOWD=1");
  if (modem.waitResponse(10000L) != 1) {
    DBG("+CPOWD=1");
  }
  // La commande suivante fait la même chose que les lignes précédentes
  modem.poweroff();
  Serial.println("Extinction...");

  // DORMIR
  esp_sleep_enable_timer_wakeup(TIME_TO_SLEEP * uS_TO_S_FACTOR);
  delay(200);
  esp_deep_sleep_start();

  // Ne rien faire pour l’éternité
  while (true) {
      modem.maintain();
  }
}