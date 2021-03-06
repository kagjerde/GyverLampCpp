#include "SnowEffect.h"
#include <Spectrometer.h>

namespace  {

bool useSpectrometer = false;
CRGB myColor = CRGB(255, 255, 255);

} // namespace

SnowEffect::SnowEffect()
{
}

void SnowEffect::tick()
{
    // сдвигаем всё вниз
    for (uint8_t x = 0; x < mySettings->matrixSettings.width; x++) {
        for (byte y = 0; y < mySettings->matrixSettings.height - 1; y++) {
            myMatrix->drawPixelXY(x, y, myMatrix->getPixColorXY(x, y + 1));
        }
    }

    for (uint8_t x = 0; x < mySettings->matrixSettings.width; x++) {
        // заполняем случайно верхнюю строку
        // а также не даём двум блокам по вертикали вместе быть
        if (!myMatrix->getPixColorXY(x, mySettings->matrixSettings.height - 2) && (random(0, settings.scale) == 0)) {
            CRGB color = (mySettings->generalSettings.soundControl && useSpectrometer)
                    ? CHSV(mySpectrometer->asHue(), mySpectrometer->asHue(), 255)
                    : myColor;
            myMatrix->drawPixelXY(x, mySettings->matrixSettings.height - 1, color);
        } else {
            myMatrix->drawPixelXY(x, mySettings->matrixSettings.height - 1, 0x000000);
        }
    }
}

void SnowEffect::initialize(const JsonObject &json)
{
    Effect::initialize(json);
    if (json.containsKey(F("useSpectrometer"))) {
        useSpectrometer = json[F("useSpectrometer")];
    }
    if (json.containsKey(F("color"))) {
        uint32_t color = json[F("color")];
        myColor = color;
    }
}

void SnowEffect::writeSettings(JsonObject &json)
{
    json[F("useSpectrometer")] = useSpectrometer;
    uint32_t color = myColor;
    json[F("color")] = color;
}
