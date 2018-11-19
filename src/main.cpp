#include <Arduino.h>
#include <SBUS.h>

SBUS sbus(Serial);

void setup()
{
  sbus.begin(false);
}

void loop()
{
  sbus.process();
  rewriteChannel(13, 2);
  rewriteChannel(14, 3);
  rewriteChannel(15, 4);
}

void rewriteChannel(int from, int to)
{
  int value = sbus.getChannel(from);
  analogWrite(to, value / 8);
}