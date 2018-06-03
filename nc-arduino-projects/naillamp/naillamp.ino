
const int button = 5;
// const int buttonDown = 5;
int brightness = 0;
int steps = 8;
bool goingUp = true;
bool changed = false;

int ledPin = 6;

// #define buttonUp D10
// #define buttonDown D11
// #define bluePin D10
// #define echoPin D15
// #define trigPin D14

void setup()
{
  pinMode(ledPin, OUTPUT);
  pinMode(button, INPUT);
  // pinMode(buttonDown, INPUT);
  brightness = 8;
  Serial.begin(115200);
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
    if (goingUp)
    {
      if (brightness < 255)
      {
        Serial.println("Increasing brightness");
        brightness += steps;
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
      }
      else
      {
        Serial.println("Brightness has reached minimum value.");
      }
    }
  }
  // else if (analogRead(buttonUp) > 450 && analogRead(buttonDown) <= 450)
  // {
  //   if (brightness > 0)
  //   {
  //     Serial.println("Decreasing brightness");
  //     brightness--;
  //   }
  //   else
  //   {
  //     Serial.println("Brightness has reached minimum value.");
  //   }
  // }
  // else if (analogRead(buttonUp) > 450 && analogRead(buttonDown) > 450)
  // {
  //   Serial.println("Both buttons are on!");
  // }
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

  delay(500);
}