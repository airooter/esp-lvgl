# ESP32 BLE键盘库

# ESP32 BLE Keyboard library

这个库允许你把ESP32变成蓝牙键盘并控制它的操作。  
你可能也会对以下内容感兴趣：
- [ESP32-BLE-Mouse](https://github.com/T-vK/ESP32-BLE-Mouse)
- [ESP32-BLE-Gamepad](https://github.com/lemmingDev/ESP32-BLE-Gamepad)


## 特性

 - [x] 发送按键操作
 - [x] 发送文本
 - [x] 按下/释放单个按键
 - [x] 支持媒体按键
 - [ ] 读取Numlock/Capslock/Scrolllock状态
 - [x] 设置电池电量（基本上可行，但在Android状态栏中不显示）
 - [x] 兼容Android
 - [x] 兼容Windows
 - [x] 兼容Linux
 - [x] 兼容MacOS X（不稳定，部分用户遇到问题，旧设备不支持）
 - [x] 兼容iOS（不稳定，部分用户遇到问题，旧设备不支持）

## 安装
- （确保你可以在Arduino IDE中使用ESP32。[安装指南请点击此链接。](https://github.com/espressif/arduino-esp32#installation-instructions)）
- [从发布页面下载此库的最新版本。](https://github.com/T-vK/ESP32-BLE-Keyboard/releases)
- 在Arduino IDE中转到“Sketch”->“Include Library”->“Add .ZIP Library...”，然后选择刚刚下载的文件。
- 现在你可以转到“文件”->“示例”->“ESP32 BLE Keyboard”，选择任何一个示例进行开始。

## 示例

``` C++
/**
 * 此示例将ESP32变成蓝牙低功耗键盘，写入单词，按Enter键，按媒体按键，然后按Ctrl+Alt+Delete
 */
#include <BleKeyboard.h>

BleKeyboard bleKeyboard;

void setup() {
  Serial.begin(115200);
  Serial.println("Starting BLE work!");
  bleKeyboard.begin();
}

void loop() {
  if(bleKeyboard.isConnected()) {
    Serial.println("Sending 'Hello world'...");
    bleKeyboard.print("Hello world");

    delay(1000);

    Serial.println("Sending Enter key...");
    bleKeyboard.write(KEY_RETURN);

    delay(1000);

    Serial.println("Sending Play/Pause media key...");
    bleKeyboard.write(KEY_MEDIA_PLAY_PAUSE);

    delay(1000);

    Serial.println("Sending Ctrl+Alt+Delete...");
    bleKeyboard.press(KEY_LEFT_CTRL);
    bleKeyboard.press(KEY_LEFT_ALT);
    bleKeyboard.press(KEY_DELETE);
    delay(100);
    bleKeyboard.releaseAll();

  }
  Serial.println("Waiting 5 seconds...");
  delay(5000);
}
```

## API文档
BleKeyboard接口几乎与键盘接口相同，因此你可以在这里使用文档：
https://www.arduino.cc/reference/en/language/functions/usb/keyboard/

只需记住，你必须使用`bleKeyboard`而不是仅使用`Keyboard`，并且在脚本顶部需要这两行：
```
#include <BleKeyboard.h>
BleKeyboard bleKeyboard;
```

除此之外，你还可以发送媒体按键（这是USB键盘库无法做到的）。支持以下按键：
- KEY_MEDIA_NEXT_TRACK
- KEY_MEDIA_PREVIOUS_TRACK
- KEY_MEDIA_STOP
- KEY_MEDIA_PLAY_PAUSE
- KEY_MEDIA_MUTE
- KEY_MEDIA_VOLUME_UP
- KEY_MEDIA_VOLUME_DOWN
- KEY_MEDIA_WWW_HOME
- KEY_MEDIA_LOCAL_MACHINE_BROWSER // 在Windows上打开“我的电脑”
- KEY_MEDIA_CALCULATOR
- KEY_MEDIA_WWW_BOOKMARKS
- KEY_MEDIA_WWW_SEARCH
- KEY_MEDIA_WWW_STOP
- KEY_MEDIA_WWW_BACK
- KEY_MEDIA_CONSUMER_CONTROL_CONFIGURATION // 媒体选择
- KEY_MEDIA_EMAIL_READER

此外，你还可以设置蓝牙特定的信息（可选）：
在`BleKeyboard bleKeyboard;`之后，你可以使用`BleKeyboard bleKeyboard("蓝牙设备名称", "蓝牙设备制造商", 100);`。（最大长度为15个字符，超出部分将被截断。）
第三个参数是你的设备的初始电池电量。要在以后调整电池电量，只需简单地调用`bleKeyboard.setBatteryLevel(50)`（设置电池电量为50%）。
默认情况下，电池电量将被设置为100%，设备名称将为`ESP32 Bluetooth Keyboard`，制造商将为`Espressif`。
还有一个`setDelay`方法用于设置每个键事件之间的延迟。例如`bleKeyboard.setDelay(10)`（10毫秒）。默认值为`8`。
这个功能旨在弥补一些应用程序和设备无法处理快速输入，会在短时间内发送太多按键而跳过字母。

## NimBLE模式
NimBLE模式可以显著节省RAM和FLASH存储器。

### 比较（编译时的SendKeyStrokes.ino）

**标准**
```
RAM:   [=         ]   9.3%（从327680字节中使用了30548字节）
Flash: [========  ]  75.8%（从1310720字节中使用了994120字节）
```

**NimBLE模式**
```
RAM:   [=         ]   8.3%（从327680字节中使用了27180字节）
Flash: [====      ]  44.2%（从1310720字节中使用了579158字节）
```

### 比较（运行时的SendKeyStrokes.ino）

|   | 标准 | NimBLE模式 | 差异
|---|--:|--:|--:|
| `ESP.getHeapSize()`   | 296.804 | 321.252 | **+ 24.448**  |
| `ESP.getFreeHeap()`   | 143.572 | 260.764 | **+ 117.192** |
| `ESP.getSketchSize()` | 994.224 | 579.264 | **- 414.960** |

### 如何激活NimBLE模式？

ArduinoIDE：在包含库之前，插入以下行 `#define USE_NIMBLE`
```C++
#define USE_NIMBLE
#include <BleKeyboard.h>
```

PlatformIO：更改你的`platformio.ini`到以下设置
```ini
lib_deps = 
  NimBLE-Arduino

build-flags = 
  -D USE_NIMBLE
```

## 鸣谢

感谢[chegewara](https://github.com/chegewara)和[USB键盘库的作者](https://github.com/arduino-libraries/Keyboard/)，因为这个项目在很大程度上基于他们的工作！
还有感谢[duke2421](https://github.com/T-vK/ESP32-BLE-Keyboard/issues/1)，他在测试、调试和修复设备描述符方面提供了很大帮助！
还有感谢[sivar2311](https://github.com/sivar2311)为添加NimBLE支持，大大减少内存占用，修复广告问题和添加`setDelay`方法做出的贡献。