#ifndef MOTOR_H
#define MOTOR_H
#define motoA1 2
#define motoA2 3 
#define motoB1 4
#define motoB2 5
#define motoPWM 6

#include<Arduino.h>
class Motor{
public:
void init();
void moveForward(int SPEED);
void moveReverse(int SPEED);
void moveRight(int SPEED);
void moveLeft(int SPEED);
void stop();
};

#endif