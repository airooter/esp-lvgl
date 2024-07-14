
/*******************************************************************************
 ******************************************************************************/
#include <Arduino_GFX_Library.h>
#define TFT_BL 2
#define GFX_BL DF_GFX_BL

// put your board's driver here:
 Arduino_ESP32RGBPanel *rgbpanel = new Arduino_ESP32RGBPanel();
 Arduino_RGB_Display *gfx = new Arduino_RGB_Display();

Arduino_Canvas_Indexed *canvasGfx = new Arduino_Canvas_Indexed();

/*******************************************************************************
 ******************************************************************************/
#include <esp_now.h>
#include <WiFi.h>
//=============================================================================
// indicator LED pin assignment, the LED lights up when sender button is pressed
#define LED 2


//=============================================================================
// receive data structure
// Must match the sender structure
typedef struct data_structure {
  int newPosition;
  bool isButtonPressed;
} data_structure;

// Create a struct_message called receivedData
data_structure receivedData;



//=============================================================================
// callback function that will be executed when ESP-NOW data is received
void OnDataRecv(const uint8_t * mac, const uint8_t *incomingData, int len) {
  memcpy(&receivedData, incomingData, sizeof(receivedData));
  Serial.print("Bytes received: ");
  Serial.println(len);
  Serial.print("newPosition: ");
  Serial.println(receivedData.newPosition);
  Serial.print("isButtonPressed: ");
  Serial.println(receivedData.isButtonPressed);  
 

}

void setup() {
  // Initialize Serial Monitor
  Serial.begin(115200);

  
  // Set device as a Wi-Fi Station
  WiFi.mode(WIFI_STA);

  // Init ESP-NOW
  if (esp_now_init() != ESP_OK) {
    Serial.println("Error initializing ESP-NOW");
    return;

  
  }

 Serial.println("5inch board is starting with ESP-NOW");


  // Once ESPNow is successfully Init, we will register for recv CB to
  // get recv packer info
 
  esp_now_register_recv_cb(OnDataRecv);

 


#ifdef TFT_BL
  pinMode(TFT_BL, OUTPUT);
  digitalWrite(TFT_BL, HIGH);
#endif

  canvasGfx->begin();
  canvasGfx->fillScreen(BLACK);
  canvasGfx ->flush();
 
  canvasGfx->setDirectUseColorIndex(false);


  

}

void loop() {

    canvasGfx->fillScreen(CYAN);

    canvasGfx->setCursor(150, 210);
    canvasGfx->setTextSize(8);
    canvasGfx->setTextColor(BLUE);

    canvasGfx->print(receivedData.newPosition);
    canvasGfx->drawCircle(240, 240, int16_t((receivedData.newPosition)/10), PALERED);

    if(receivedData.isButtonPressed)
    {
    canvasGfx->fillScreen(RED);

    canvasGfx->setCursor(150, 210);
    canvasGfx->setTextSize(8);
    canvasGfx->setTextColor(YELLOW);

    canvasGfx->print(receivedData.newPosition);
       
    }
    canvasGfx->flush();

   

}
//=============================================================================
// END