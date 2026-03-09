# ESP32 for Domotic with Google Cloud Service firebase and Flutter app 

[![](https://markdown-videos.deta.dev/youtube/xkLEQ8njIVo)](https://youtu.be/xkLEQ8njIVo)


>## Description
***
This project named **ESP32 for Domotic with Google Cloud Service firebase and Flutter app** is used to:
1. Control home automation devices (Lamp, Blinds, Fan...) with a mobile application developed with the Flutter SDK on VS Code. 
2. Receive feedback and display it on the mobile application according to the current value.
3. Measure the current then calculate the Energy consumption and display it on the application.


>## Hardware used:

 1. ESP8266 NodeMCU (12-E)
 2. Analog-SPI Converter (MCP3002) we use the channel (CH0)
 3. ACSP712 Current sensor (30A)
 4. Lighting lamp & 3.3V Relay

>## Software used: 

1. Arduino IDE 
2. VS Code
3. Flutter 
4. Android Studio 


>## Server Part:


This project is connected to the database under the name keeper-connect of the Firebase server.

> ## Wi-Fi Part 

The board is connected to the Wi-Fi
- SSID: Maker Lab 
- WIFI_PASSWORD: ######

> ## Project Operation:


First, the board starts reading the current value and calculates the energy consumption expressed in kW, then depending on this value:
- If the current = 0: returns low-state feedback to the application showing that the lamp is not activated.
- If the current > 0: returns high-state feedback to the application showing that the lamp is working properly.

Then the system allows reading the logical value of a button on the application to control the actuator through the Firebase server. 

> ## Project Architecture:  
<div align="center"><img src="https://user-images.githubusercontent.com/93054393/187061146-6d996a2d-d211-415e-b0b4-c50d7d490f95.jpg" width="75%"></div>
<div align="center"><i>Project Architecture</i></div>


> ## Mobile Part 

       Screen 1: Home
<div align="center"><img src="https://user-images.githubusercontent.com/93054393/187058069-5d30a5cd-f875-4747-b83a-27ab4a0c03c2.jpg" width="20%"></div>
<div align="center"><i>Screen 1</i></div>

       Screen 2: Social media contact

<div align="center"><img src="https://user-images.githubusercontent.com/93054393/187058071-fb233c67-cd75-4cd9-9c8f-5d517a4d5ff8.jpg" width="20%"></div>
<div align="center"><i>Screen 2</i></div>

       Screen 3: Create an account if you don't have one

<div align="center"><img src="https://user-images.githubusercontent.com/93054393/187058072-a32e4af1-4b48-4c64-bee4-510a82667c50.jpg" width="20%"></div>
<div align="center"><i>Screen 3</i></div>

       Screen 4: Verify identity with an ID and Password already created and stored on Firebase.

<div align="center"><img src="https://user-images.githubusercontent.com/93054393/187058075-ee6a14d9-87bc-49c2-942e-5ca3f0d909d4.jpg" width="20%"></div>
<div align="center"><i>Screen 4</i></div>


        Screen 5: Clickable image to enter one of the rooms in the house and control the devices.


<div align="center"><img src="https://user-images.githubusercontent.com/93054393/187058079-25b35a41-f17b-43e0-b09b-5c2e9b489cdf.jpg" width="20%"></div>
<div align="center"><i>Screen 5</i></div>

       Screen 6: Button to send a command to Firebase and an image that displays the feedback status depending on whether each device is working or not.

<div align="center"><img src="https://user-images.githubusercontent.com/93054393/187058082-8b33dcaf-f0e1-4f81-97bb-815ce1bdd3d4.jpg" width="20%"></div>
<div align="center"><i>Screen 6</i></div>

> ## Hardware Configuration:
--------------------------------

Wiring of the assembly (ESP8266 + MCP3002):


|Pin Name |	MCP3002	   |ESP8266|
|-|-|-|
|CSS	|1	|D8|
|MISO	|Dout (Pin6)	|D7|
|MOSI	|Din  (Pin5)	|D7|
|CLK	|7|	D5|

###  Wiring of the assembly (ACS712 + MCP3002):


|Pin Name	|MCP3002	|ACS712|
|-----|----|----|
|DATA	|CH0 | (Pin2)|	


The Relay wiring is with (pin D4).
Libraries Installation:
FirebaseArduino is a library to simplify the connection to the Firebase database from Arduino clients.
It is a complete abstraction of the Firebase REST API exposed via C++ calls in a user-friendly way. All JSON parsing is handled by the library and you can process pure C/Arduino types.
The library cannot work standalone. You must therefore also add the ArduinoJSON library.
So first go to the library manager and search for "JSON" and install the library as shown in the figure below.

----------------------------------------------------------------------------

>## Note:


The latest JSON library might not work with the code. You may need to downgrade the library to version v5.13.5.
Google Firebase Extended Library:
Now, you also need to install the Google Firebase library. So, download the Firebase ESP8266 library version 4.0.3.
Google Firebase Console Database Configuration:

Now, the main thing we need to do is configure the Google Firebase console database. Once the setup is complete, we can then send real-time sensor data to Google Firebase with the NodeMCU ESP8266.
But I won't explain here how to configure the Google Firebase console database, as I have already explained the whole process in the previous tutorial. You can check the following tutorial to know how to perform the setup.

> ### WARNING !! :

For the system to work, you must pay attention to the compatibility of the library versions of Firebase & ArduinoJson & ESP8266WiFi.

* ArduinoJson (version 5.13.1)

* Firebase ESP8266 client 4.0.3 

* (board manager)

* ESP8266 (version 2.3.0)
  
  <div align="center"><img src="https://user-images.githubusercontent.com/93054393/187058084-44c3ac2f-ddf6-4fd8-9008-14afa67f6c33.jpg" width="60%"></div>
<div align="center"><i>Screen 6</i></div>







> ## Code Part: 

1. First of all, we include the library for Firebase & MCP3XXX.h & SPI.h

```Arduino
       #include <ESP8266WiFi.h>
       #include <FirebaseArduino.h>   
       #include <ESP8266HTTPClient.h> 
       #include <MCP3XXX.h>
       #include<SPI.h>
```

2. Next, we define the two parameters FIREBASE_HOST & FIREBASE_AUTH. We obtain these parameters from the Google Firebase Setup. These two parameters are very important for communicating with Firebase. This allows data exchange between the ESP8266 and Firebase.

```Arduino
       #define FIREBASE_HOST "keeper-connect-default-rtdb.firebaseio.com"
       #define FIREBASE_AUTH "6pTTp2lBqUIYk1XHoxkUaaOhhU71dEbQnmeO0NO6" 
       
```


3. Then, we define the WiFi SSID and password. Replace the SSID and password with your network's SSID and password. The NodeMCU will connect to the network and communicate with the Google Firewall.

```Arduino
       #define WIFI_SSID "Maker Lab"
       #define WIFI_PASSWORD "makerlabtn"

```

4. Declaration of variables and constants.

```Arduino
       MCP3002 adc;
       int x= 0;
       #define acs712 A0
       long lastsample = 0;
       long samplesum = 0;
       int sampleCount = 0;
       float vpc = 4.8828125;
```
5. In the void Setup, we start by declaring the NodeMCU SPI pins, then the baud rate (115200Kb/s), moving on to declaring Pin D4 as an output.

```Arduino
       void setup() 
       adc.begin(D8, D7, D6, D5);
       Serial.begin(115200);
       pinMode(D4, OUTPUT);    
```
6. These lines allow connecting the NodeMCU ESP8266 board to the Wifi network. Once connected, the serial monitor displays the connection status and prints the IP address.
  ```Arduino
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
          delay(1000);   
```
7. In the void Loop we start by converting each frame received through the SPI into an analog value during each period.

```Arduino
         void loop() {
         if (millis() > lastsample + 1) 
         {
         int x = adc.analogRead(0)-2;
         //  Serial.println(x);
         samplesum += sq(x - 512);
         sampleCount++;
         lastsample = millis ();
         }
```
8. During each one we aim to convert the RMS current to nominal current, then we calculate the current by dividing the measured value by the sensor's rating.

```Arduino
         if (sampleCount == 1000)
          {
         float mean = samplesum / sampleCount;
         float value = sqrt(mean);
         float mv = value * vpc;
         float amperage = mv / 66;  //66 for 30A  185 for 20A  185 for 5A
         samplesum = 0;
         sampleCount = 0;  
```

9. For sensor calibration, we used a low pass filter with a condition to block small current values.
```Arduino
          if (amperage <0.2)
          {
          amperage =0;
```

10. We now send the data to Google Firebase using the path provided by the code.

```Arduino
         Firebase.setString("House/Salon/feedback_Lampe","LOW");
         Serial.println("The final RMS Amperage is: " + String(amperage) + " Appox WATTAGE is: " + String(amperage * 220) + ".");
         Firebase.setFloat("House/Salon/Consommation_Lampe",amperage*220);
         int result = Firebase.getInt("House/Salon/switch");   
```
11. The LED will turn on/off depending on the received string like "ON" or "OFF" respectively. If another character is sent, 
This was about LED control using Google Firebase. Now, there is another side to the tutorial: what happens if you want to send the sensor data to Google Firebase.

```Arduino
         int result = Firebase.getInt("House/Salon/switch");
         if (result == 1) {
         Serial.println("Led Turned ON");
         digitalWrite(D4, LOW);
         }
         else if (result == 0){
         Serial.println("Led Turned OFF");
         digitalWrite(D4, HIGH);   
```


To control the LED using Google Firebase and NodeMCU ESP8266, you must first configure Google Firebase. The step is a bit long but don't panic, as I have explained all the steps to you below.

       Step 1: If you have a Gmail ID, you are already registered with Firebase. But if you don't have a Gmail ID, first sign up for Gmail: https://gmail.com/

<div align="center"><img src="https://user-images.githubusercontent.com/93054393/187058090-b596c9f9-04a0-4b20-8534-e3089d514fe6.jpg" width="60%"></div>
<div align="center"><i>Step 1</i></div>


       Step 2: Now visit https://firebase.google.com/ and click on Go to console at the top right.

<div align="center"><img src="https://user-images.githubusercontent.com/93054393/187058093-bee594de-351b-4ef6-b905-32b6f5a6a8c4.jpg" width="60%"></div>
<div align="center"><i>Step 2</i></div>

       Step 3: Click on "Create a project".

<div align="center"><img src="https://user-images.githubusercontent.com/93054393/187058095-9b7a2c98-68c9-4e02-95e2-637cb5e4246f.jpg" width="60%"></div>
<div align="center"><i>Step 3</i></div>

       Step 4: Provide your "Project Name", then check the box "I accept the Firebase terms" and finally click on "Continue".


<div align="center"><img src="https://user-images.githubusercontent.com/93054393/187058101-86cf37e0-7774-4ab2-a0fd-40f08c249031.jpg" width="60%"></div>
<div align="center"><i>Step 4</i></div>

       Step 5: Now, another window will appear. So click on "Continue".

<div align="center"><img src="https://user-images.githubusercontent.com/93054393/187058104-bdbd0dcf-b14a-4598-a18b-5d4829c62dc8.jpg" width="60%"></div>
<div align="center"><i>Step 5</i></div>

       Step 6: Select the "Google Analytics account" created using the Gmail ID.


 And then click on "Create a project".

<div align="center"><img src="https://user-images.githubusercontent.com/93054393/187058106-4dd2a5c1-1cb2-4100-880a-767a3ce1d2f8.jpg" width="60%"></div>
<div align="center"><i>Step 6</i></div>

       Step 7: Your project is now ready. So you will get the following window. Click on "Continue".

<div align="center"><img src="https://user-images.githubusercontent.com/93054393/187058114-c59688f0-3664-4a24-af5f-4d66f02a2df0.jpg" width="60%"></div>
<div align="center"><i>Step 7</i></div>


       Step 8: Now click on "Project settings".

<div align="center"><img src="https://user-images.githubusercontent.com/93054393/187058118-35393205-ef48-4456-9a59-a70ee07f0ffb.jpg" width="60%"></div>
<div align="center"><i>Step 8</i></div>

       Step 9: Under Project settings, click on "Service accounts". Copy the secret key below. The code is required in the Arduino code.
<div align="center"><img src="https://user-images.githubusercontent.com/93054393/187058120-8dda0747-74a4-49d6-8723-15b97d850e90.jpg" width="60%"></div>
<div align="center"><i>Step 9</i></div>

       Step 10: Click on "Create a database".
<div align="center"><img src="https://user-images.githubusercontent.com/93054393/187058121-91717e1a-0e9b-4647-a5a6-80fbd5d65d57.jpg" width="60%"></div>
<div align="center"><i>Step 10</i></div>

       Step 11: Choose "Start in test mode" then click on "Next".

<div align="center"><img src="https://user-images.githubusercontent.com/93054393/187058123-b9638ca5-385d-4e0b-b97c-0dcfce91339b.jpg" width="60%"></div>
<div align="center"><i>Step 11</i></div>

       Step 12: Now click on "Done" and on the left side, click on "Database".


<div align="center"><img src="https://user-images.githubusercontent.com/93054393/187058125-676c7e7e-5f4c-41f7-a902-15e9d52a1172.jpg" width="60%"></div>
<div align="center"><i>Step 12</i></div>



       Step 13: Select the "Realtime Database" option from the list of databases.

## Note:

We worked with the MakerLab account with a database named "KEEPER-CONNECT".
