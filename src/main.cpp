#include <Arduino.h>

#define PIN1 3
#define PIN2 7

const int dt = 10;
const unsigned long dT = 50000;
const int Np = 4000;
//int Np2 = dT/dt;
const int nb = 1;

unsigned long Tcurr = 0;
int flashon = 0;
int started = 0;


void setup()
{
    Serial.begin(115200);
    pinMode(PIN1, OUTPUT);
    pinMode(PIN2, INPUT_PULLUP);
}

void loop()
{
  if(digitalRead(PIN2)==0)
  {
    started = 1;
  }
  if(started)
  {
    for(int i = 0;i<nb;i++)
    {
      for(int j = 0; j < Np; j++)
      {
        flashon = !flashon;
        digitalWrite(PIN1, flashon);
        Serial.print(Tcurr);
        Serial.print(",");
        Serial.println(flashon);
        delay(dt);
        Tcurr += dt;
      }
      /*
      for(int k = 0;k<Np2;k++)
      {
        Serial.print(Tcurr);
        Serial.print(",");
        Serial.println(flashon);
        delay(dt);
        Tcurr += dt;
      }*/
      delay(dT);
      Tcurr += dT;
    }
    started = 0;
    
  }
}
