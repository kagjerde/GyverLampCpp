Please note that this project is work-in-progress, and just a fork from the original project by CODeRUS, please use his repository for any changes: https://github.com/CODeRUS/GyverLampCpp



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

Then just upload fs to module

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
