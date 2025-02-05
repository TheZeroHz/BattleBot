#include "Motor.h"

void Motor::init(){
pinMode(motoPWM,OUTPUT);
pinMode(motoA1,OUTPUT);
pinMode(motoA2,OUTPUT);
pinMode(motoB1,OUTPUT);
pinMode(motoB2,OUTPUT);
}


void Motor::moveForward(int SPEED){
analogWrite(motoPWM,SPEED);
digitalWrite(motoA1,HIGH);
digitalWrite(motoA2,LOW);
digitalWrite(motoB1,HIGH);
digitalWrite(motoB2,LOW);
}


void Motor::moveReverse(int SPEED){
analogWrite(motoPWM,SPEED);
digitalWrite(motoA1,LOW);
digitalWrite(motoA2,HIGH);
digitalWrite(motoB1,LOW);
digitalWrite(motoB2,HIGH);
}

void Motor::moveLeft(int SPEED){
analogWrite(motoPWM,SPEED);
digitalWrite(motoA1,HIGH);
digitalWrite(motoA2,LOW);
digitalWrite(motoB1,LOW);
digitalWrite(motoB2,HIGH);
}


void Motor::moveRight(int SPEED){
analogWrite(motoPWM,SPEED);
digitalWrite(motoA1,LOW);
digitalWrite(motoA2,HIGH);
digitalWrite(motoB1,HIGH);
digitalWrite(motoB2,LOW);
}


void Motor::stop(){
analogWrite(motoPWM,0);
digitalWrite(motoA1,LOW);
digitalWrite(motoA2,LOW);
digitalWrite(motoB1,LOW);
digitalWrite(motoB2,LOW);
}