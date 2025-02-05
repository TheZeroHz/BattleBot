#ifndef RECIEVER_H
#define RECIEVER_H
#include<Arduino.h>
// Define Input Connections
#define CH1 A1
#define CH2 A2
#define CH3 A3
#define CH4 A4
#define CH5 A5
#define CH6 A0

class Reciever{
public:
void init();
int readChannel(int channelInput, int minLimit, int maxLimit, int defaultValue);
bool readSwitch(byte channelInput, bool defaultValue);
};
#endif