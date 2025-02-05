#include "Motor.h"
#include "Reciever.h"
#define DEBUG_SERIAL
#define JOYSTICK_THRESHOLD 30
Reciever fsi6;
Motor vehicle;
// Integers to represent values from sticks and pots
int ch1Value, ch1PWM;
int ch2Value, ch2PWM;


void setup() {
  Serial.begin(115200);
  vehicle.init();
  fsi6.init();
}

void loop() {
  // Get values for each channel
  ch1Value = fsi6.readChannel(CH1, -100, 100, 0);
  ch2Value = fsi6.readChannel(CH2, -100, 100, 0);
  ch1PWM = map(abs(ch1Value), 0, 100, 0, 255);
  ch2PWM = map(abs(ch2Value), 0, 100, 0, 255);

#ifdef DEBUG_SERIAL  // Print to Serial Monitor0
  Serial.print("Ch1: ");
  Serial.print(ch1Value);
  Serial.print(" | Ch2: ");
  Serial.print(ch2Value);
#endif

  if (abs(ch1Value) < JOYSTICK_THRESHOLD && abs(ch2Value) >= JOYSTICK_THRESHOLD) {
    int ch2dir = ch2Value / abs(ch2Value);
    if (ch2dir == 1) {
#ifdef DEBUG_SERIAL
      vehicle.moveForward(ch2PWM);
      Serial.print(" Moving Forward: " + (String)ch2PWM);
#endif
    } else if (ch2dir == -1) {
#ifdef DEBUG_SERIAL
      vehicle.moveReverse(ch2PWM);
      Serial.print(" Moving Backward: " + (String)ch2PWM);
#endif
    }
  }
  if (abs(ch1Value) >= JOYSTICK_THRESHOLD) {
    int ch1dir = ch1Value / abs(ch1Value);
    if (ch1dir == 1) {
#ifdef DEBUG_SERIAL
      vehicle.moveRight(ch1PWM);
      Serial.print(" Moving Right: " + (String)ch1PWM);
#endif

    } else if (ch1dir == -1) {
#ifdef DEBUG_SERIAL
      vehicle.moveLeft(ch1PWM);
      Serial.print(" Moving Left: " + (String)ch1PWM);
#endif
    }
  }
  if (abs(ch1Value) < JOYSTICK_THRESHOLD && abs(ch2Value) < JOYSTICK_THRESHOLD) {
    vehicle.stop();
  }
#ifdef DEBUG_SERIAL
  Serial.println();
#endif
}
