#define TINY_GSM_MODEM_SIM7000

#include "RucherLoRa.h"
#include <TinyGsmClient.h>

// Define RX/TX pins for ESP32 <-> SIM7000G communication
#define MODEM_TX 20  // ESP32 TX → SIM7000 RX
#define MODEM_RX 19  // ESP32 RX → SIM7000 TX
#define PWRKEY    4  // SIM7000 Power Key (adjust if needed)
#define RESET     5  // SIM7000 Reset Pin (optional)

TinyGsm modem(Serial1);

// Function prototypes
void powerOnSIM7000();
void initLTE(const char* apn);
void sendMessage(const char* number, const char* message);
void readMessage();

void setup() {
    Serial.begin(115200);
    delay(3000);
    
    Serial.println("Initializing Serial1 for SIM7000G...");
    Serial1.begin(115200, SERIAL_8N1, MODEM_RX, MODEM_TX);

    // Power on SIM7000G
    powerOnSIM7000();
    delay(5000);

    // Set LTE APN (modify as per your provider)
    const char* apn = "orange";
    initLTE(apn);
    delay(3000);

    // Read incoming messages
    readMessage();

    // Send an SMS
    const char* recipient = "+33635150270"; // Replace with the real number
    const char* message = "Hello from your SIM7000 with RucherLoRa!";
    sendMessage(recipient, message);
}

void loop() {
    // Example: Uncomment if you want to send an SMS periodically
    // sendMessage("+33645218132", "Hello, World!");
    // delay(60000); // Send a message every 60 seconds

    // Example: Read signal strength every 10 seconds
    Serial.println("Checking signal strength...");
    modem.sendAT("AT+CSQ");
    delay(10000);
}

// Function to power on the SIM7000G module
void powerOnSIM7000() {
    pinMode(PWRKEY, OUTPUT);
    digitalWrite(PWRKEY, LOW);
    delay(1000);
    digitalWrite(PWRKEY, HIGH);
    Serial.println("Powering on SIM7000...");
}
/*
// Function to initialize LTE connection
void initLTE(const char* apn) {
    Serial.println("Initializing LTE...");

    // Set APN for network connection
    String cmd = "AT+CGDCONT=1,\"IP\",\"";
    cmd += apn;
    cmd += "\"";
    modem.sendAT(cmd.c_str());
    delay(1000);

    // Ensure module is in LTE mode
    modem.sendAT("AT+CNMP=51"); // LTE-only mode
    delay(1000);

    Serial.println("LTE Initialized!");
}

// Function to send an SMS
void sendMessage(const char* number, const char* message) {
    Serial.print("Sending SMS to ");
    Serial.println(number);
    
    modem.sendAT("AT+CMGF=1");  // Set SMS mode to text
    delay(1000);
    
    String smsCmd = "AT+CMGS=\"";
    smsCmd += number;
    smsCmd += "\"";
    
    modem.sendAT(smsCmd.c_str());
    delay(1000);
    
    modem.stream.print(message);
    delay(500);
    
    modem.stream.write(26); // End SMS with CTRL+Z
    delay(5000);

    Serial.println("SMS Sent!");
}

// Function to read received messages
void readMessage() {
    Serial.println("Checking for incoming messages...");
    modem.sendAT("AT+CMGL=\"REC UNREAD\"");  // Read unread messages
    delay(1000);
}*/