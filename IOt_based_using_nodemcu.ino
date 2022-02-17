#define BLYNK_TEMPLATE_ID "TMPL4_pTJUiq"
#define BLYNK_DEVICE_NAME "Alcohol detection"
#define BLYNK_AUTH_TOKEN "VjReGJYzfbebcdSaUVG5e8x0kdX-JoJa"
#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
//#include<SoftwareSerial.h>
//SoftwareSerial mySerial(3,1);//rx tx pin
BlynkTimer timer;

char auth[] = "VjReGJYzfbebcdSaUVG5e8x0kdX-JoJa";
char ssid[] = "Galaxy M31_ajuu";
char pass[] = "ajinkya@123";

int n;

void setup()
{

  Serial.begin(9600);
  //mySerial.begin(9600);

  Blynk.begin(auth, ssid, pass);
  
  pinMode(16,OUTPUT);
  pinMode(5,OUTPUT);
  timer.setInterval(1024L, sendUptime);
}


void sendUptime()
{
  Blynk.virtualWrite(V1, n);
  
}

void loop()
{

  Blynk.run();
  timer.run();
  
  n=analogRead(A0);  
  if(n==1024)
  {
    Serial.println("Dont Drive , you are fully Alcoholated");
  }
  Serial.println(n);
  delay(100);
  
if(n==1024)
{
  Blynk.email("hatalageaju@gmail.com","OLA_CAB_OWNER :","Hello Ajinkya, the person owning car MH09BZ3647 has consumed alcohol, The engine has been locked, please do the needful.");
 Blynk.email("rutikmk10@gmail.com","OLA_CAB_OWNER :" ,"Hello Ajinkya, the person owning car MH09BZ3647 has consumed alcohol, The engine has been locked, please do the needful.");
  Blynk.email("vijay.vrushabh@walchandsangli.ac.in" ,"OLA_CAB_OWNER :","Hello Ajinkya, the person owning car MH09BZ3647 has consumed alcohol, The engine has been locked, please do the needful.");
  Blynk.email("rutuja.birnale@walchandsangli.ac.in" ,"OLA_CAB_OWNER :","Hello Ajinkya, the person owning car MH09BZ3647 has consumed alcohol, The engine has been locked, please do the needful.");
  Blynk.email("saloni.ambi@walchandsangli.ac.in",  "OLA_CAB_OWNER :","Hello Ajinkya, the person owning car MH09BZ3647 has consumed alcohol, The engine has been locked, please do the needful.");
} 
  if(n==1024)
  {
    
    digitalWrite(16,LOW);
    digitalWrite(5,HIGH);   
  }
  
  if(n<1000)
  {
      digitalWrite(16,HIGH);
      digitalWrite(5,LOW);
  }
 

}
