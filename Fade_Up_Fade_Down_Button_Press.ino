/*==========================
  Variables
  ==========================*/
const int triggerPin = 2;
const int motorPin = 3;


const int barrelDelay = 50;
int buttonState = 0;
int fadeValue = 5;

void setup() {
  Serial.begin(9600);
  pinMode(triggerPin, INPUT_PULLUP);
  pinMode(motorPin, OUTPUT);
}

void loop()
{
  buttonState = digitalRead(triggerPin);
  Serial.println(buttonState);

  if (buttonState == LOW) {
    Serial.println("gate 1");
    if (fadeValue < 255)
    {
      Serial.println("gate 2");
      if (fadeValue >= 245)
      {
        fadeValue = 255;
      }
      else
      {
        fadeValue++;
        Serial.println(fadeValue);
      }
      analogWrite(motorPin, fadeValue);
      delay(50);
    }
  }

  if (buttonState == HIGH) {
    Serial.println("gate 3");
    if (fadeValue > 1)
    {
      Serial.println("gate 4");
      if (fadeValue <= 5)
      {
        fadeValue = 0;
      }
      else
      {
        fadeValue--;
        Serial.println(fadeValue);
      }
      analogWrite(motorPin, fadeValue);
      delay(50);
    }
  }
}
