#include "Reciever.h"

void Reciever::init(){
  pinMode(CH1, INPUT);
  pinMode(CH2, INPUT);
}


// Read the number of a specified channel and convert to the range provided.
// If the channel is off, return the default value
int Reciever::readChannel(int channelInput, int minLimit, int maxLimit, int defaultValue){
  int ch = pulseIn(channelInput, HIGH, 30000);
  if (ch < 100) return defaultValue;
  return map(ch, 1000, 1980, minLimit, maxLimit);
}

// Read the switch channel and return a boolean value
bool Reciever::readSwitch(byte channelInput, bool defaultValue){
  int intDefaultValue = (defaultValue)? 100: 0;
  int ch = readChannel(channelInput, 0, 100, intDefaultValue);
  return (ch > 50);
}