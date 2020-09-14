#include <DS3231.h>
#include <MD_Parola.h>
#include <MD_MAX72xx.h>
#include <SPI.h>

const uint16_t WAIT_TIME = 1000;

#define HARDWARE_TYPE MD_MAX72XX::FC16_HW
#define MAX_DEVICES 4

#define CLK_PIN   13
#define DATA_PIN  11
#define CS_PIN    10

DS3231  rtc(SDA, SCL);
MD_Parola P = MD_Parola(HARDWARE_TYPE, CS_PIN, MAX_DEVICES);

Time t;
const String dots = " : ";
const String na = "";

void setup(void)
{
  rtc.begin();
//  rtc.setDOW(MONDAY);
//  rtc.setTime(12, 06, 0);
//  rtc.setDate(10, 8, 2020);
  P.begin();
}

void loop(void)
{
  t = rtc.getTime();
  
  P.print(t.hour + dots + t.min);
  delay(45000);

  P.print(t.date + na + t.mon + ((String) t.year).substring(2));
  delay(15000);
}
