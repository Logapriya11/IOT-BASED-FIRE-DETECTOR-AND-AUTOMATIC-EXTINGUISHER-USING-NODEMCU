#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
BlynkTimer timer;
char auth[] = "QsFj_hR8B2UyBX9ASxxTgrr1YpJ0eo8c"; //Auth code sent via Email 
char ssid[] = "NIVEDHA"; //Wifi name
char pass[] = "9884407236"; //Wifi Password
int flag = 0;
int notify = 0;

void notifyOnFire()
{
    int isButtonPressed = digitalRead (D0) ; 
    int buzz= D2;
    int RELAY = D3;
    int NO_FLAME = D4;
    if (isButtonPressed==LOW&& flag==0)
        {
         Serial.println ("Fire in the House");
         if(notify==0)
         {
            Blynk.notify ("Alert :Fire in the House");
            digitalWrite (buzz, HIGH);
            digitalWrite(RELAY, HIGH);
            digitalWrite(NO_FLAME, LOW);
            
            //notify=1;
         }
         
         //digitalWrite(LED, HIGH);
          
         }
     else if (isButtonPressed==HIGH)
         {
          flag = 0;
          notify = 0;
         Serial.println("No Flame");
         digitalWrite(RELAY, LOW);
         digitalWrite(buzz, LOW);
         digitalWrite(NO_FLAME, HIGH);
         }
}

void setup()
{
Serial.begin(9600);
Blynk.begin(auth, ssid, pass);
pinMode(D0, INPUT_PULLUP);
pinMode(D3, OUTPUT);
pinMode(D2, OUTPUT);
pinMode(D4, OUTPUT);
timer.setInterval(1000L, notifyOnFire);
}

void loop()
{
Blynk.run();
timer.run();
}
