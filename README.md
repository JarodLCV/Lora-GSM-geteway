# **Passerelle LoRa-GSM**  

Un projet combinant des connaissances en électronique et en programmation pour créer un pont entre le GSM et le LoRa.

![image](https://github.com/user-attachments/assets/3acdb9e8-fed4-4b29-99b4-2c63c6d7694c)

----

**Table de matières**
- [**Passerelle LoRa-GSM**](#passerelle-lora-gsm)
  - [ℹ️ **Contexte du projet**](#ℹ️-contexte-du-projet)
  - [🗂️ Dossiers](#️-dossiers)
  - [**Réalisation du projet**](#réalisation-du-projet)
    - [**Définitions :**](#définitions-)
  - [Comment continuer le projet](#comment-continuer-le-projet)
  - [Explication du code](#explication-du-code)

----

## ℹ️ **Contexte du projet**

Il s'agit d'un projet du cours de Projet d'Électronique, encadré par Monsieur Christian Peter (<Christian.PETER@univ-cotedazur.fr>), dans le cadre du cursus d'Ingénierie Électronique et Informatique Industrielle de la Polytech de Sophia Antipolis.  
Ce projet consiste à concevoir une ruche connectée, incluant la collecte de données, la transmission de ces données à distance, l’élimination des parasites par laser, etc.  
Cette partie du projet concerne la communication à distance des données et est réalisée par le groupe composé de:
**Guilherme VENTAPANE RODRIGUES** <guilherme@ventapane.eu>
et
**Jarod LECOEUVRE** <jarod.lecoeuvre@etu.univ-cotedazur.fr>

## 🗂️ Dossiers

- 📁 **Compte-rendu** : Les étapes d'avancement du projet et les tâches que chaque membre du groupe avait effectuées.

- 📁 **Partie_Electronique** : Fichiers liés à la partie électronique du projet, tels que le schéma de la carte, la documentation des composants, etc.
  - 📁 **BOM** : Bill of Material de notre projet. La liste des composants nécessaires avec leurs valeurs, pour être placés sur le PCB.
  - 📁 **Documentation_composants** : Fichiers de documentation pour certains composants utilisés dans le projet.
  - 📁 **Eagle_Components** : Composants supplémentaires pour le logiciel EAGLE, qui n'étaient pas présents par défaut et que nous avons dû télécharger pour compléter notre projet.
  - 📁 **Eagle_Schemas** : Schémas que nous avons utilisés pour notre projet, réalisés avec le logiciel EAGLE d'Autodesk.
  - 📁 **Nano to micro simcard adapter 3d** : Un adaptateur de carte SIM vers micro SIM que nous avons imprimé en 3D pour notre projet.
  - 📁 **Anciens_Schemas** : Fichiers de schémas du groupe de l'année dernière.

- 📁 **Partie_Informatique** : Le dossier où se trouve le code qui tourne sur la carte.
  - 📁 **code_groupe_annee_derniere** : Code du projet du groupe de l'année dernière.
  - 📁 **src** : Les fichiers sources de notre projet, où se trouve le fichier main.ino, le fichier principal de notre projet.

## **Réalisation du projet**  

Pour assurer la communication des données sur de longues distances, une passerelle entre LoRa et GSM sera utilisée.  
Cette passerelle sera réalisée à partir d'un circuit imprimé conçu par nous, ainsi que d'un code exécuté sur un **ESP32** connecté à un **SIM7000G**.

Nous nous basons sur le projet de la promotion précédente, réalisé par **Oumar Sadjo Barry & Mor Dieng** / [oumarsadjo / RucherLoRa](https://github.com/oumarsadjo/RucherLoRa)  
<oumar-sadjo.barry@etu.univ-cotedazur.fr> & <mor.dieng@etu.univ-cotedazur.fr>

### **Définitions :**  

**GSM (Global System for Mobile Communications) :**  
C'est un standard de communication mobile utilisé pour la téléphonie cellulaire et la transmission de données. Il permet l’envoi de messages SMS, les appels et la connexion à Internet via **GPRS/EDGE/3G/4G**. Le GSM est largement utilisé pour les dispositifs IoT nécessitant une connectivité dans des environnements sans Wi-Fi.  

**LoRa (Long Range) :**  
C'est une technologie de communication sans fil à longue portée et à faible consommation d'énergie, utilisée pour connecter des dispositifs IoT aux réseaux LPWAN (**Low Power Wide Area Network**). LoRa permet de transmettre de petits paquets de données sur de longues distances (jusqu'à 15 km en zones rurales) avec une consommation d’énergie minimale.  

**ESP32 :**  
C'est un microcontrôleur développé par Espressif, intégrant **Wi-Fi et Bluetooth**, ainsi que plusieurs broches **GPIO** pour les capteurs et modules externes. Il est largement utilisé dans les projets IoT grâce à sa connectivité, sa puissance et son faible coût.  

**SIM7000 :**  
C'est un module de communication **GSM/GPRS/NB-IoT/LTE Cat-M1** développé par Simcom. Il permet aux dispositifs IoT d'envoyer et de recevoir des données via les réseaux mobiles, en prenant en charge les connexions **basse consommation**, idéales pour les capteurs distants et les applications de surveillance.  

<img width="300" alt="image" src="https://github.com/user-attachments/assets/89d18e22-138f-430b-ac1e-dbb92593b67c"/>

## Comment continuer le projet

Il reste encore à :
- [ ] Finaliser le débogage de la carte pour établir une communication stable entre les composants ;
- [ ] Intégrer la partie LoRa ;
- [ ] Optimiser la consommation énergétique de la passerelle, pour un usage autonome sur batterie.

## Explication du code

La bibliothèque utilise la communication série (UART) pour envoyer des commandes AT au module GSM. En interne, elle structure ces commandes de façon organisée, permettant au développeur de simplement appeler des fonctions comme modem.gprsConnect() ou modem.sendSMS(), au lieu d’écrire manuellement des lignes du type `AT+CGDCONT=1`,"IP","internet".

TinyGSM est également optimisée pour fonctionner sur des cartes à faible mémoire (d’où le “Tiny” dans son nom), ce qui la rend efficace même sur des microcontrôleurs limités comme l’Arduino Uno.

Analyse du code et explication des parties principales

Le code de notre projet est organisé en plusieurs étapes : configuration, initialisation du modem, choix des modes réseau, test de la connexion GPRS, et envoi de SMS. Voici un résumé des parties essentielles :

Définition du modem et configuration initiale
Au début du code, on définit le type de modem utilisé :

``` CPP
#define TINY_GSM_MODEM_SIM7000
#define TINY_GSM_RX_BUFFER 1024
#define SerialAT Serial1
```

Ces lignes informent la bibliothèque qu’on utilise un SIM7000. On augmente aussi la taille du buffer de réception à 1024 octets, ce qui est utile pour traiter des réponses longues du modem.

Il y a aussi l’option suivante :

``` CPP
#define DUMP_AT_COMMANDS
```

Cela permet d’afficher toutes les commandes AT envoyées et les réponses reçues. C’est très utile pour déboguer si quelque chose ne fonctionne pas comme prévu.

Paramètres pour le réseau mobile

``` CPP
const char apn[]  = "sl2sfr";
const char gprsUser[] = "";
const char gprsPass[] = "";
```

Ici, on entre les informations nécessaires pour se connecter au réseau mobile. L’APN dépend de l’opérateur utilisé. Dans notre cas, c’est “sl2sfr” car nous utilisons un SIM de SFR.

Initialisation du modem

Dans la fonction setup(), on initialise la communication série avec le modem :

``` CPP
SerialAT.begin(UART_BAUD, SERIAL_8N1, PIN_RX, PIN_TX);
```

Ensuite, on redémarre le modem avec `modem.restart()` et on vérifie si tout s’est bien passé.

On récupère aussi quelques infos utiles :

``` CPP
String name = modem.getModemName();
String modemInfo = modem.getModemInfo();
```

Cela permet d’afficher le nom du modem et quelques infos techniques pour s’assurer que le module est bien reconnu.

Configuration du mode réseau

Dans la `loop()`, on configure le mode de fonctionnement du modem :

``` CPP
modem.sendAT("+CFUN=0"); // désactive le modem temporairement
modem.setNetworkMode(2); // mode automatique
modem.setPreferredMode(1); // priorité au mode CAT-M
modem.sendAT("+CFUN=1"); // réactive le modem
```

Ces commandes AT permettent de choisir comment le modem va chercher le réseau (LTE, GSM, NB-IoT, etc.).

Connexion GPRS

Une fois le modem prêt, on tente de se connecter au réseau mobile :

``` CPP
modem.gprsConnect(apn, gprsUser, gprsPass);
```

Après la connexion, on peut vérifier le signal, l’opérateur, l’IMEI, l’adresse IP locale, etc.

Envoi de SMS

À la fin du code, il y a une partie pour tester l’envoi de SMS :

``` CPP
modem.sendSMS(SMS_TARGET, String("Hello from ") + imei);
```

C’est un test simple qui envoie un message contenant l’IMEI du module à un numéro prédéfini.

Mise hors tension et sommeil profond

Enfin, on met le modem hors tension et on fait entrer l’ESP32 en mode sommeil profond pour économiser l’énergie :

``` CPP
modem.poweroff();
esp_deep_sleep_start();
```
