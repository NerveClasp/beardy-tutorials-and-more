const int button = 5;
// const int buttonDown = 5;
int brightness = 0;
int steps = 8;
bool goingUp = true;
bool changed = false;

// #define buttonUp D10
// #define buttonDown D11
// #define bluePin D10
// #define echoPin D15
// #define trigPin D14

void setup()
{
  pinMode(button, INPUT);
  // pinMode(buttonDown, INPUT);
  brightness = 7;
  Serial.begin(115200);
}

void loop()
{
  Serial.println("Button:");
  Serial.println(analogRead(button));
  Serial.println("Going Up?:");
  Serial.println(goingUp);
  if (analogRead(button) > 450)
  {
    changed = true;
    if (goingUp)
    {
      if (brightness < 255)
      {
        Serial.println("Increasing brightness");
        brightness++;
      }
      else
      {
        Serial.println("Brightness has reached maximum value.");
      }
    }
    else
    {
      if (brightness > 0)
      {
        Serial.println("Decreasing brightness");
        brightness--;
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
      Serial.println("Going Up Now?");
      Serial.println(goingUp);
    }
    Serial.println("Both buttons are off");
  }
  Serial.println(brightness);
  Serial.println("=============== FIN ===============");

  delay(3000);
}