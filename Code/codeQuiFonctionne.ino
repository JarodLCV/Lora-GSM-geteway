#define TINY_GSM_MODEM_SIM7000

#include <TinyGsmClient.h>

// Define the correct RX/TX pins for your board
#define MODEM_TX 20  // ESP32 TX (connects to SIM7000 RX)
#define MODEM_RX 19  // ESP32 RX (connects to SIM7000 TX)
#define PWRKEY    4  // Modify if your SIM7000 uses a different power key pin
#define RESET     5  // Optional reset pin (if available)

TinyGsm modem(Serial1);

void setup() {
  Serial.begin(115200);
  delay(3000);

  Serial.println("Initializing Serial1 for SIM7000G...");
  Serial1.begin(115200, SERIAL_8N1, MODEM_RX, MODEM_TX);
  delay(1000);

  // Power on SIM7000G
  pinMode(PWRKEY, OUTPUT);
  digitalWrite(PWRKEY, LOW);
  delay(1000);
  digitalWrite(PWRKEY, HIGH);
  Serial.println("Powering on SIM7000...");
  delay(5000);

  // Check if modem responds
  if (modem.testAT()) {
    Serial.println("✅ Modem is responding!");
  } else {
    Serial.println("❌ Modem not responding. Check wiring & power.");
    return;
  }

  // Check SIM status
  Serial.println("\nChecking SIM card...");

  
  if (modem.getSimStatus() == 3) {
    Serial.println("✅ SIM card is ready!");
  } else {
    Serial.println("❌ SIM card not detected or locked.");

    // Afficher les infos du SIM
    // Check SIM status
    Serial.print("AT+CPIN?: ");
    modem.sendAT("AT+CPIN?");
    String response = modem.stream.readStringUntil('\n');
    Serial.println(response);
    //modem.simUnlock("1234");

    // Get SIM Card ID (ICCID)
    Serial.print("AT+CCID: ");
    modem.sendAT("AT+CCID");
    response = modem.stream.readStringUntil('\n');
    Serial.println(response);

    modem.sendAT("AT+CFUN=1");  // Full functionality mode
    modem.sendAT("AT+CNMP=38"); // Set to LTE only (for SIM7000G)
    modem.sendAT("AT+COPS=0");  // Auto-select operator

    return;
  }

  // Send an SMS
  String phoneNumber = "+";  // 🔴 Replace with the real phone number
  String message = "Hello from ESP32 & SIM7000G! 🚀";

  Serial.println("\nSending SMS...");
  if (modem.sendSMS(phoneNumber, message)) {
    Serial.println("✅ SMS sent successfully!");
  } else {
    Serial.println("❌ Failed to send SMS.");
  }
}

void loop() {
  // No need to repeat sending SMS
    Serial.println("---------------------------");
    Serial.print("SIM status: ");
    int simStatus = modem.getSimStatus();
    Serial.println(simStatus);

   // Check SIM status
    Serial.print("AT+CPIN?: ");
    modem.sendAT("AT+CPIN?");
    String response = modem.stream.readStringUntil('\n');
    Serial.println(response);
    //modem.simUnlock("1234");

    // Get SIM Card ID (ICCID)
    Serial.print("AT+CCID: ");
    modem.sendAT("AT+CCID");
    response = modem.stream.readStringUntil('\n');
    Serial.println(response);

    Serial.print("AT+COPS?: ");
    modem.sendAT("AT+COPS?");  // Check current network operator
    String cops = modem.stream.readStringUntil('\n');
    Serial.println(cops);

    Serial.print("AT+CSQ: ");
    modem.sendAT("AT+CSQ");  // Get signal strength
    String csq = modem.stream.readStringUntil('\n');
    Serial.println(csq);

    delay(1000);
}