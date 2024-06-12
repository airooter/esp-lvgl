/**
段代码来自https://github.com/T-vK/ESP32-BLE-Keyboard
原代码在esp32 arduino 3.0以上版本会出错：
BleKeyboard.cpp:106:19: error: cannot convert 'std::string' {aka 'std::__cxx11::basic_string<char>'} to 'String'
  106 |   BLEDevice::init(deviceName);
      |                   ^~~~~~~~~~
      |                   |
      |                   std::string {aka std::__cxx11::basic_string<char>}

这里我们进
这个示例将ESP32变成一个蓝牙LE键盘，它会写入一些文字，按下回车键，按下一个媒体键，然后按下Ctrl+Alt+Delete组合键
*/

#include <BleKeyboard.h>
BleKeyboard bleKeyboard;

void setup() {
Serial.begin(115200);
Serial.println("Starting BLE work!");
bleKeyboard.begin();
}

void loop() {
if (bleKeyboard.isConnected()) {

Serial.println("Sending 'Hello world'..."); // 发送“Hello world”
bleKeyboard.print("Hello world"); // 打印“Hello world”

delay(1000);

Serial.println("Sending Enter key...");  // 发送回车键
bleKeyboard.write(KEY_RETURN);  // 写入回车键

delay(1000);

Serial.println("Sending Play/Pause media key...");  // 发送播放/暂停媒体键
bleKeyboard.write(KEY_MEDIA_PLAY_PAUSE);  // 写入播放/暂停媒体键

delay(1000);

//
// 以下是按下多个键盘修饰键的示例，默认情况下已注释掉。
/*
Serial.println("Sending Ctrl+Alt+Delete...");  // 发送Ctrl+Alt+Delete
bleKeyboard.press(KEY_LEFT_CTRL);  // 按下左Ctrl键
bleKeyboard.press(KEY_LEFT_ALT);  // 按下左Alt键
bleKeyboard.press(KEY_DELETE);  // 按下Delete键
delay(100);
bleKeyboard.releaseAll();  // 释放所有键
*/
}

Serial.println("Waiting 5 seconds..."); // 等待5秒钟
delay(5000);
}