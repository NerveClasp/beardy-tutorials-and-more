const int button = 5;
const int maxBrightness = 255;
const int minBrightness = 0;
int brightness = 0;
int steps = 8;
bool goingUp = true;
bool changed = false;

int ledPin = 6;

void setup()
{
  Serial.begin(115200);
  pinMode(ledPin, OUTPUT);
  pinMode(button, INPUT);
  initialFadeIn();
}

void initialFadeIn()
{
  Serial.println("Initiating initial fade-in.");
  for (int i = 0; i < 255 / steps; i = i + steps)
  {
    changeBrightness(true);
    delay(100);
  }
  Serial.println("Finished initial fade-in.");
}

void changeBrightness(bool direction)
{
  if (direction)
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

  delay(500);
}