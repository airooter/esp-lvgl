#include <TwoWayESP.h>

// Make this the OTHER ESPs mac address
// The mac address can be found by uploading this program
// It will be output on the serial terminal
const uint8_t otherESPAddr[6] = {0x00, 0x00, 0x00, 0x00, 0x00, 0x09 };

void setup() {
	Serial.begin(115200);

	// Begin TwoWayESP with the other ESPs mac
	TwoWayESP::Begin(otherESPAddr);
}

void loop() {


	// Check if there is an available read
	if(TwoWayESP::Available()) {
    String str1 = TwoWayESP::GetString();
   	Serial.print("[Incoming] String data: ");
 		Serial.println(str1);
	}

	// Output send string to serial terminal
	String send = "I am esp32cam sending data to another ESP!";
	Serial.print("[Outgoing] String data: ");
	Serial.println(send);
	
	// Send some string to the other ESP
	TwoWayESP::SendString(send);

	// Delay to not overrun the memory limit
	delay(500);
}
