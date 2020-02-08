Please note that this project is work-in-progress, and just a fork from the original project by CODeRUS, please use his repository for any changes: https://github.com/CODeRUS/GyverLampCpp

Please note that the project is developed using [PLATFOMIO](https://platformio.org/)
So, forst step is to download visual studio code from [Microsoft](https://code.visualstudio.com/download)
Then download PLATFORMIO from inside Visual Studio Code.

After this just download the project, and navigate to GyverLampCpp-master.

Then all the files will make sense..

[![Build Status](https://travis-ci.org/CODeRUS/GyverLampCpp.svg?branch=master)](https://travis-ci.org/CODeRUS/GyverLampCpp)
<br />
You can download latest build with artifacts from GitHub [Releases](https://github.com/CODeRUS/GyverLampCpp/releases) page
<br />
# GyverLampCpp

fork of https://github.com/AlexGyver/GyverLamp for PlatformIO

# How to build

1. build firmware
2. build filesystem

# Filesystem build

Manual steps:

- build https://github.com/zeburek/led-lamp-webui
- build https://github.com/CODeRUS/wifimanager-react-page
- copy artifacts without folder structure to data_src

Easy steps:
- grab data_src.zip from latest release (https://github.com/CODeRUS/GyverLampCpp/releases)
- extract to project folder

Upload file system to module, by using the following command in a new terminal windows (in PLATFORMIO):
<platformio run --target uploadfs -e nodemcu>
Where nodemcu must be replaced with esp32dev or sonoff - according to your target.

## Changes

- Rewritten for easier maintenance
- ESP32 support
- Asynchronous WiFi Manager
- FastLED_NeoMatrix library instead of Gyver handmade one (sorry)
- Settings moved to SPIFFS json file

## New features:

- Clock effects
- Spectrometer effect (requires microphone module or aux)
- React web with controls (over websockets)
- Firmware update page
- SPIFFS update page

## Known issues

- Alarms not implemented

## TODO

- Alarms support
- Explain connection of microphone and aux
