#include "Keyboard.h"

int buttonState = 0;

#define DEBOUNCE_DELAY 10
#define BUTTON_COUNT 16

// ZM Keyboard Cube Macropad's Button Pinouts
int buttonPins[] = {2, 3, 4, 5, 6, 7, 8, 9, 10, 16, 14, 15, 18, 19, 20, 21};

int buttonReadings[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
bool state[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
unsigned long lastTime[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
bool latched[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
bool lastReading[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

void setup()
{
  // initialize the pushbutton pin as an input:
  for (int x = 0; x < BUTTON_COUNT; x++)
  {
    pinMode(buttonPins[x], INPUT_PULLUP);
  }
  Keyboard.begin();
}

void loop()
{
  updateButtons();
}

void updateButtons()
{
  for (byte i = 0; i < BUTTON_COUNT; i++)
  {
    // update button readings
    buttonReadings[i] = !digitalRead(buttonPins[i]);
    if (buttonReadings[i] != lastReading[i])
    {
      lastTime[i] = millis();
    }

    // press/release buttons
    if ((millis() - lastTime[i]) > DEBOUNCE_DELAY)
    {
      state[i] = buttonReadings[i];
      if (state[i] && !latched[i])
      {
        pressChars(i);
        latched[i] = true;
      }
      else if (!state[i] && latched[i])
      {
        //  releaseChars(buttons[i]);
        latched[i] = false;
      }
    }

    // update last reading
    lastReading[i] = buttonReadings[i];
  }
}

void pressChars(int button)
{
  if (button == 0)
  {
    Keyboard.print("0");
  }
  else if (button == 1)
  {
    Keyboard.print("1");
  }
  else if (button == 2)
  {
    Keyboard.print("2");
  }
  else if (button == 3)
  {
    Keyboard.print("3");
  }
  else if (button == 4)
  {
    Keyboard.press(KEY_LEFT_GUI);
    Keyboard.press('2');
    delay(20);
    Keyboard.releaseAll();
  }
  else if (button == 5)
  {
    Keyboard.print("5");
  }
  else if (button == 6)
  {
    Keyboard.print("6");
  }
  else if (button == 7)
  {
    Keyboard.print("7");
  }
  else if (button == 8)
  {
    Keyboard.print("8");
  }
  else if (button == 9)
  {
    Keyboard.print("9");
  }
  else if (button == 10)
  {
    Keyboard.print("10");
  }
  else if (button == 11)
  {
    Keyboard.print("11");
  }
  else if (button == 12)
  {
    Keyboard.print("12");
  }
  else if (button == 13)
  {
    Keyboard.print("13");
  }
  else if (button == 14)
  {
    Keyboard.print("14");
  }
  else if (button == 15)
  {
    Keyboard.print("15");
  }
}