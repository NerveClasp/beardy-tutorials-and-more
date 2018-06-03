#include <FastLED.h>

#include "FastLED_RGBW.h" // Include the FastLED_RGBW helper file

#define LED_COUNT 60

#define LED_OUT 6

const int button = 5;
const int maxBrightness = 255;
const int minBrightness = 0;
int brightness = 0;
int steps = 8;
bool goingUp = true;
bool changed = false;

CRGBW leds[LED_COUNT]; // FastLED with RGBW
CRGB *ledsRGB = (CRGB *)&leds[0];


void setup()
{
  Serial.begin(115200);
  LEDS.addLeds<WS2812B, LED_OUT, RGB>(ledsRGB, getRGBWsize(LED_COUNT)); //use both the CRGB pointer and the size function "getRGBWsize" in the FastLED_RGBW helper file

  //  brightness = STARTING_BRIGHTNESS;
  //  LEDS.setBrightness(brightnesSteps[brightness]);
  LEDS.setBrightness(brightness);
  LEDS.show();
  pinMode(LED_OUT, OUTPUT);
  pinMode(button, INPUT);
  initialFadeIn();
}

void initialFadeIn()
{
  Serial.println("Initiating initial fade-in.");
  for (int i = 0; i < 255 / steps; i = i + steps)
  {
    changeBrightness(true);
    LEDS.show();
    delay(100);
  }
  Serial.println("Finished initial fade-in.");
}

void changeBrightness(bool direction)
{
  if (direction)
  {
    if (brightness < 255 - steps)
    {
      Serial.println("Increasing brightness");
      brightness += steps;
      LEDS.setBrightness(brightness);
    }
    else
    {
      Serial.println("Brightness has reached maximum value.");
    }
  }
  else
  {
    if (brightness >= steps)
    {
      Serial.println("Decreasing brightness");
      brightness -= steps;
      LEDS.setBrightness(brightness);
    }
    else
    {
      Serial.println("Brightness has reached minimum value.");
    }
  }
}

void loop()
{
  Serial.print("Button: ");
  Serial.println(analogRead(button));
  Serial.print("Going Up?: ");
  Serial.println(goingUp);
  if (analogRead(button) > 450)
  {
    changed = true;
    changeBrightness(goingUp);
  }
  else
  {
    if (changed)
    {
      changed = false;
      goingUp = !goingUp;
      Serial.print("Going Up Now? -- ");
      Serial.println(goingUp);
    }
    Serial.println("Button is off");
  }
  Serial.print("Brightness: ");
  Serial.println(brightness);
  Serial.println("=============== FIN ===============");
//  LEDS.show();
  LEDS.show();
  delay(500);
}
