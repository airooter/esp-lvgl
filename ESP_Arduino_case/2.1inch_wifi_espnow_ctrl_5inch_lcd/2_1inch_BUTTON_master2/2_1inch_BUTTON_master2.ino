#include <Arduino_GFX_Library.h>


#include <U8g2lib.h>


#include <esp_now.h>
#include <WiFi.h>

// Global copy of slave
esp_now_peer_info_t slave;



#define GFX_BL 7

//put your board's driver here:
Arduino_ESP32RGBPanel *rgbpanel = new Arduino_ESP32RGBPanel();
Arduino_RGB_Display *gfx = new Arduino_RGB_Display();
Arduino_Canvas_Indexed *canvasGfx = new Arduino_Canvas_Indexed();


#include "AiEsp32RotaryEncoder.h"



#if defined(ESP8266)
#define ROTARY_ENCODER_A_PIN D6
#define ROTARY_ENCODER_B_PIN D5
#define ROTARY_ENCODER_BUTTON_PIN D7
#else
#define ROTARY_ENCODER_A_PIN 6
#define ROTARY_ENCODER_B_PIN 5
#define ROTARY_ENCODER_BUTTON_PIN 0
#endif

#define ROTARY_ENCODER_STEPS 1
AiEsp32RotaryEncoder rotaryEncoder = AiEsp32RotaryEncoder(ROTARY_ENCODER_A_PIN, ROTARY_ENCODER_B_PIN, ROTARY_ENCODER_BUTTON_PIN, -1, ROTARY_ENCODER_STEPS);

// ==========================================================================
// your data structure (the data block you send to receiver)
// your reciever should use the same data structure
typedef struct data_structure {
  int newPosition;
  bool isButtonPressed;
} data_structure;

data_structure sending_data;

//=============================================================================
// some global variables
int newPosition = 15;
int oldPosition = 0;
bool isButtonPressed = false;


float getFrequency()
{
    return (float)rotaryEncoder.readEncoder();
}

void rotary_onButtonClick()
{
    static unsigned long lastTimePressed = 0;
    if (millis() - lastTimePressed < 500)
        return;
    lastTimePressed = millis();

    Serial.print("Radio station set to ");
    Serial.print(getFrequency());
    Serial.println(" MHz ");

    sending_data.newPosition = getFrequency();
    if (rotaryEncoder.isEncoderButtonClicked()){
  
      sending_data.isButtonPressed = true;
    }
    else{

            sending_data.isButtonPressed = false;

    }
    

    esp_err_t result = esp_now_send(0, (uint8_t *) &sending_data, sizeof(data_structure));

    if (result == ESP_OK) {
      Serial.println("Sent with success");
    }
    else {
      Serial.println("Error sending the data");
    }
}

void IRAM_ATTR readEncoderISR()
{
    rotaryEncoder.readEncoder_ISR();
}
/**
   ESPNOW - Basic communication - Master
   Date: 26th September 2017
   Author: Arvind Ravulavaru <https://github.com/arvindr21>
   Purpose: ESPNow Communication between a Master ESP32 and a Slave ESP32
   Description: This sketch consists of the code for the Master module.
   Resources: (A bit outdated)
   a. https://espressif.com/sites/default/files/documentation/esp-now_user_guide_en.pdf
   b. http://www.esploradores.com/practica-6-conexion-esp-now/

   << This Device Master >>

   Flow: Master
   Step 1 : ESPNow Init on Master and set it in STA mode
   Step 2 : Start scanning for Slave ESP32 (we have added a prefix of `slave` to the SSID of slave for an easy setup)
   Step 3 : Once found, add Slave as peer
   Step 4 : Register for send callback
   Step 5 : Start Transmitting data from Master to Slave

   Flow: Slave
   Step 1 : ESPNow Init on Slave
   Step 2 : Update the SSID of Slave with a prefix of `slave`
   Step 3 : Set Slave in AP mode
   Step 4 : Register for receive callback and wait for data
   Step 5 : Once data arrives, print it in the serial monitor

   Note: Master and Slave have been defined to easily understand the setup.
         Based on the ESPNOW API, there is no concept of Master and Slave.
         Any devices can act as master or salve.
*/

#define CHANNEL 0
#define PRINTSCANRESULTS 0
#define DELETEBEFOREPAIR 0

 int mac[6] = {0x34, 0x85, 0x18, 0x98, 0xdf, 0xa8};
 //int mac[6] = {0xDE, 0xDA, 0x0C, 0x15, 0x80, 0xF0};
// Init ESP Now with fallback
void InitESPNow() {
  WiFi.disconnect();
  if (esp_now_init() == ESP_OK) {
    Serial.println("ESPNow Init Success");
  }
  else {
    Serial.println("ESPNow Init Failed");
    // Retry InitESPNow, add a counte and then restart?
    // InitESPNow();
    // or Simply Restart
    ESP.restart();
  }
}

// Scan for slaves in AP mode
void ScanForSlave() {
  //int8_t scanResults = WiFi.scanNetworks();
  // reset on each scan
  bool slaveFound = 0;
  memset(&slave, 0, sizeof(slave));

 
  for (int ii = 0; ii < 6; ++ii )
  {
    slave.peer_addr[ii] = (uint8_t) mac[ii];
  }

  slave.channel = CHANNEL; // pick a channel
  slave.encrypt = 0; // no encryption

  slaveFound = 1;


  if (slaveFound)
  {
    Serial.println("Slave Found, processing..");
  } else
  {
    Serial.println("Slave Not Found, trying again.");
  }

}

// Check if the slave is already paired with the master.
// If not, pair the slave with master
bool manageSlave() {
  if (slave.channel == CHANNEL) {
    if (DELETEBEFOREPAIR) {
      deletePeer();
    }

    Serial.print("Slave Status: ");
    // check if the peer exists
    bool exists = esp_now_is_peer_exist(slave.peer_addr);
    if ( exists) {
      // Slave already paired.
      Serial.println("Already Paired");
      return true;
    } else {
      // Slave not paired, attempt pair
      esp_err_t addStatus = esp_now_add_peer(&slave);
      if (addStatus == ESP_OK) {
        // Pair success
        Serial.println("Pair success");
        return true;
      } else if (addStatus == ESP_ERR_ESPNOW_NOT_INIT) {
        // How did we get so far!!
        Serial.println("ESPNOW Not Init");
        return false;
      } else if (addStatus == ESP_ERR_ESPNOW_ARG) {
        Serial.println("Invalid Argument");
        return false;
      } else if (addStatus == ESP_ERR_ESPNOW_FULL) {
        Serial.println("Peer list full");
        return false;
      } else if (addStatus == ESP_ERR_ESPNOW_NO_MEM) {
        Serial.println("Out of memory");
        return false;
      } else if (addStatus == ESP_ERR_ESPNOW_EXIST) {
        Serial.println("Peer Exists");
        return true;
      } else {
        Serial.println("Not sure what happened");
        return false;
      }
    }
  } else {
    // No slave found to process
    Serial.println("No Slave found to process");
    return false;
  }
}

void deletePeer() {
  esp_err_t delStatus = esp_now_del_peer(slave.peer_addr);
  Serial.print("Slave Delete Status: ");
  if (delStatus == ESP_OK) {
    // Delete success
    Serial.println("Success");
  } else if (delStatus == ESP_ERR_ESPNOW_NOT_INIT) {
    // How did we get so far!!
    Serial.println("ESPNOW Not Init");
  } else if (delStatus == ESP_ERR_ESPNOW_ARG) {
    Serial.println("Invalid Argument");
  } else if (delStatus == ESP_ERR_ESPNOW_NOT_FOUND) {
    Serial.println("Peer not found.");
  } else {
    Serial.println("Not sure what happened");
  }
}

uint8_t data = 0;

// send data
void sendData() {

  data = digitalRead(0);

  const uint8_t *peer_addr = slave.peer_addr;
  Serial.print("Sending: "); Serial.println(data);
  // Send message via ESP-NOW
  esp_err_t result = esp_now_send(peer_addr, (uint8_t *) &data, sizeof(data));

  Serial.print("Send Status: ");
  if (result == ESP_OK) {
    Serial.println("Success");
  } else if (result == ESP_ERR_ESPNOW_NOT_INIT) {
    // How did we get so far!!
    Serial.println("ESPNOW not Init.");
  } else if (result == ESP_ERR_ESPNOW_ARG) {
    Serial.println("Invalid Argument");
  } else if (result == ESP_ERR_ESPNOW_INTERNAL) {
    Serial.println("Internal Error");
  } else if (result == ESP_ERR_ESPNOW_NO_MEM) {
    Serial.println("ESP_ERR_ESPNOW_NO_MEM");
  } else if (result == ESP_ERR_ESPNOW_NOT_FOUND) {
    Serial.println("Peer not found.");
  } else {
    Serial.println("Not sure what happened");
  }
}

// callback when data is sent from Master to Slave
void OnDataSent(const uint8_t *mac_addr, esp_now_send_status_t status) {
  char macStr[18];
  snprintf(macStr, sizeof(macStr), "%02x:%02x:%02x:%02x:%02x:%02x",
           mac_addr[0], mac_addr[1], mac_addr[2], mac_addr[3], mac_addr[4], mac_addr[5]);
  Serial.print("Last Packet Sent to: "); Serial.println(macStr);
  Serial.print("Last Packet Send Status: "); Serial.println(status == ESP_NOW_SEND_SUCCESS ? "Delivery Success" : "Delivery Fail");
}

void setup() {
  Serial.begin(115200);
  pinMode(0,INPUT);

  
    #ifdef GFX_BL //打开背光
    pinMode(GFX_BL, OUTPUT);
    digitalWrite(GFX_BL, LOW);
    #endif

    #ifdef GFX_EXTRA_PRE_INIT
    GFX_EXTRA_PRE_INIT();
    #endif
  //初始化gfx
   // gfx->begin(80000000);
    
   // gfx->setUTF8Print(true); // enable UTF8 support for the Arduino print() function
   // gfx->setFont(u8g2_font_unifont_t_chinese);


    rotaryEncoder.begin();
    rotaryEncoder.setup(readEncoderISR);
    rotaryEncoder.setBoundaries(888, 9999, true); //minValue, maxValue, circleValues true|false (when max go to min and vice versa)
    rotaryEncoder.setAcceleration(2);
    rotaryEncoder.setEncoderValue(888); //set default to 92.1 MHz
    Serial.println("FM Radio");
    Serial.print("Radio station initially set to ");
    Serial.print(getFrequency());
    Serial.println(" MHz. Tune to some other station like 103.2... and press button ");


  //Set device in STA mode to begin with
  WiFi.mode(WIFI_STA);
  Serial.println("ESPNow/Basic/Master Example");
  // This is the mac address of the Master in Station Mode
  Serial.print("STA MAC: "); Serial.println(WiFi.macAddress());
  // Init ESPNow with a fallback logic
  InitESPNow();
  // Once ESPNow is successfully Init, we will register for Send CB to
  // get the status of Trasnmitted packet
  esp_now_register_send_cb(OnDataSent);


  canvasGfx->begin();
  canvasGfx->fillScreen(BLACK);
  canvasGfx ->flush();
  canvasGfx->setDirectUseColorIndex(false);
}

void loop() {
  // In the loop we scan for slave
  ScanForSlave();

  canvasGfx->fillScreen(RED);
  canvasGfx->setCursor(150, 210);
  canvasGfx->setTextSize(8);
  canvasGfx->setTextColor(WHITE);
  canvasGfx->print(rotaryEncoder.readEncoder());
   // gfx->setCursor(250, 240);
   // gfx->println("MHz");


  // If Slave is found, it would be populate in `slave` variable
  // We will check if `slave` is defined and then we proceed further
  if (slave.channel == CHANNEL) { // check if slave channel is defined
    // `slave` is defined
    // Add slave as peer if it has not been added already
    bool isPaired = manageSlave();
    if (rotaryEncoder.isEncoderButtonClicked()){
 
        rotary_onButtonClick();
        Serial.println(rotaryEncoder.readEncoder());
        newPosition = rotaryEncoder.readEncoder();

        Serial.println(newPosition);
        sending_data.newPosition = newPosition;
      
        sending_data.isButtonPressed = true;
      
      esp_err_t result = esp_now_send(0, (uint8_t *) &sending_data, sizeof(data_structure));

      if (result == ESP_OK) {
        Serial.println("Sent with success");
      }
      else {
        Serial.println("Error sending the data");
      }
    
    } 
  

    
    if (isPaired && rotaryEncoder.encoderChanged() ) { //
      // pair success or already paired
      // Send data to device
      //sendData();
     

      Serial.println(rotaryEncoder.readEncoder());
      newPosition = rotaryEncoder.readEncoder();

      Serial.println(newPosition);
      sending_data.newPosition = newPosition;
      sending_data.isButtonPressed = false;
      
      esp_err_t result = esp_now_send(0, (uint8_t *) &sending_data, sizeof(data_structure));

      if (result == ESP_OK) {
        Serial.println("Sent with success");
      }
      else {
        Serial.println("Error sending the data");
      }
    
    }

  }
  
    canvasGfx->flush();


}
