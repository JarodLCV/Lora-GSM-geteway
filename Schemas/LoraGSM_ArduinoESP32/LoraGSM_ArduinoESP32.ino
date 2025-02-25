#define TINY_GSM_MODEM_SIM7000

#include <TinyGsmClient.h>
#include <HardwareSerial.h>


HardwareSerial mySerial(2); // UART2 for SIM7000G

// Define TinyGSM modem
TinyGsm modem(mySerial);

void setup() {
  
  // Start USB Serial for debugging
  Serial.begin(115200);
  delay(10);

  // Initialize UART2 for the modem
  mySerial.begin(115200, SERIAL_8N1, 16, 17);


  /*
  Serial.println("Initializing modem...");
    modem.sendAT("+CSQ"); // Check signal quality
  delay(1000);

  // Print response to Serial Monitor
  while (mySerial.available()) {
    Serial.write(mySerial.read());
  }
  
  if (!modem.restart()) {
    Serial.println("Failed to initialize modem!");
    while (true);
  }

  Serial.println("Modem initialized!");

  // Wait for network connection
  if (!modem.waitForNetwork(30000)) {
    Serial.println("Failed to connect to network!");
    while (true);
  }
  Serial.println("Network connected!");

  // Send SMS
  String recipient = "+1234567890"; // Replace with recipient's number
  String message = "Hello from TinyGSM!";
  if (modem.sendSMS(recipient, message)) {
    Serial.println("SMS sent successfully!");
  } else {
    Serial.println("Failed to send SMS!");
  }
  */
}

void loop() {
  // Nothing to do in the loop
}