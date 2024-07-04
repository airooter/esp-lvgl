
void setup() {
  Serial.begin(115200);
  delay(10);
  Serial.println("Starting Touch work!");
  
}
 
void loop() {
  Serial.println(touchRead(7));  //  GPIO 7.
  delay(300);

}