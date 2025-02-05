#ifndef RECIEVER_H
#define RECIEVER_H
#include<Arduino.h>
// Define Input Connections
#define CH1 A0
#define CH2 A1


class Reciever{
public:
void init();
int readChannel(int channelInput, int minLimit, int maxLimit, int defaultValue);
bool readSwitch(byte channelInput, bool defaultValue);
};
#endif