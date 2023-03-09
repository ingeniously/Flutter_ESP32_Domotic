#include <ESP8266WiFi.h>
#include <FirebaseArduino.h>   
#include <ESP8266HTTPClient.h> 
#define FIREBASE_HOST "keeper-connect-default-rtdb.firebaseio.com"
#define FIREBASE_AUTH "6pTTp2lBqUIYk1XHoxkUaaOhhU71dEbQnmeO0NO6"
#define WIFI_SSID "Maker Lab"
#define WIFI_PASSWORD "makerlabtn"                                    
int val1=0, val2=1000;
int fireStatus = 0;
#include <MCP3XXX.h>
#include<SPI.h>
MCP3002 adc;
int x= 0;
#define acs712 A0
long lastsample = 0;
long samplesum = 0;
int sampleCount = 0;
float vpc = 4.8828125;
void setup(){
   adc.begin(D8, D7, D6, D5);
Serial.begin(115200);
pinMode(D4, OUTPUT); 
        
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);          
  Serial.print("Connecting to ");
  Serial.print(WIFI_SSID);
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(500);}
 Serial.println();
  Serial.print("Connected to ");
  Serial.println(WIFI_SSID);
  Serial.print("IP Address is : ");
  Serial.println(WiFi.localIP());                
  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);  
  delay(1000);}
void loop() {
if (millis() > lastsample + 1) {
    int x = adc.analogRead(0)-2;
   //  Serial.println(x);
    samplesum += sq(x - 512);
    sampleCount++;
    lastsample = millis ();}
  if (sampleCount == 1000) {
    float mean = samplesum / sampleCount;
    float value = sqrt(mean);
    float mv = value * vpc;
    float amperage = mv / 66;  //66 for 30A  185 for 20A  185 for 5A
        samplesum = 0;
    sampleCount = 0;
    if (amperage <0.2){
     amperage =0;
     Firebase.setString("House/Salon/feedback_Prise","LOW");
         Serial.println("The final RMS Amperage is: " + String(amperage) + " Appox WATTAGE is: " + String(amperage * 220) + ".");
    Firebase.setFloat("House/Salon/Consommation_Prise",amperage*220);      
    }
     else{
       Firebase.setString("House/Salon/feedback_Prise","HIGH");
          Serial.println("The final RMS Amperage is: " + String(amperage) + " Appox WATTAGE is: " + String(amperage * 220) + ".");
    Firebase.setFloat("House/Salon/Consommation_Prise",amperage*220);


    
      } 
  }
    
  }
