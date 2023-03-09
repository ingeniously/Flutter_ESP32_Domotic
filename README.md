 # Youtube Demo 

[![](https://markdown-videos.deta.dev/youtube/xkLEQ8njIVo)](https://youtu.be/xkLEQ8njIVo)


>## Description
***
Ce projet nommé energyzium sert à :
1. Commander des appareils domotique(Lampe,Store,Fan...) avec une application mobile développer avec flutter SDK sur VS code. 
2. Recevoir le feedback et l'afficher sur l'application mobile selon la valeur du courant.
3. Mesurer le courant puis calculer la consommation Energétique et l'afficher sur l'application


>## Matériels utilisés :

 1. ESP8266 NodeMcu (12-E)
 2. Convertisseur Analogique-SPI (MCP3002) on utilise la chaine(CH0)
 3. Capteur de courant ACSP712 (30A)
 4. Lampe d'éclairage & Relais 3.3V
>## Logiciel utilisé : 

1. Arduino IDE 
2. Vs Code
3. Flutter 
4. Android Studio 


>## Partie Serveurs :


Ce projet est connecté sur la base de données sous le nom keeper-connect du serveur firebase 

> ## Partie Wi-Fi 

La carte est connectée sur le Wi-Fi
- SSID : Maker Lab 
- WIFI_PASSWORD : ######

> ## Fonctionnement du Projets:


En premier lieu la carte commence à  lire la valeur du courant et calculer la consommation énergétique exprimée en KW puis selon cette valeur:
- Si le courant = 0 : retour d'un feedback a l'état bas vers l'application qui montre que la lampe n'est pas activée
- Si le courant > 0 : retour d'un feedback a état haut vers l'application qui montre que la lampe fonctionne bien

Ensuite le système permet de lire la valeur logique d'un bouton sur l'application afin de commander l'actionneur é travers le serveur firebase. 

> ## Architecture du projet :  
<div align="center"><img src="https://user-images.githubusercontent.com/93054393/187061146-6d996a2d-d211-415e-b0b4-c50d7d490f95.jpg" width="75%"></div>
<div align="center"><i>Architecture du projet</i></div>


> ## Partie Mobile 

       Screen 1 : Accueil
<div align="center"><img src="https://user-images.githubusercontent.com/93054393/187058069-5d30a5cd-f875-4747-b83a-27ab4a0c03c2.jpg" width="20%"></div>
<div align="center"><i>Screen 1</i></div>

       Screen 2 : Contact sur les réseaux

<div align="center"><img src="https://user-images.githubusercontent.com/93054393/187058071-fb233c67-cd75-4cd9-9c8f-5d517a4d5ff8.jpg" width="20%"></div>
<div align="center"><i>Screen 2</i></div>

       Screen 3 : Créer un compte si vous n'en disposer pas

<div align="center"><img src="https://user-images.githubusercontent.com/93054393/187058072-a32e4af1-4b48-4c64-bee4-510a82667c50.jpg" width="20%"></div>
<div align="center"><i>Screen 3</i></div>

      Screen 4 : Vérifier l'identité avec un Id et un Mot de passe déja  créer et stocker sur Firebase.

<div align="center"><img src="https://user-images.githubusercontent.com/93054393/187058075-ee6a14d9-87bc-49c2-942e-5ca3f0d909d4.jpg" width="20%"></div>
<div align="center"><i>Screen 4</i></div>


        Screen 5 : Image cliquable pour entrer dans une des salles de la maison et commander les appareils


<div align="center"><img src="https://user-images.githubusercontent.com/93054393/187058079-25b35a41-f17b-43e0-b09b-5c2e9b489cdf.jpg" width="20%"></div>
<div align="center"><i>Screen 5</i></div>

       Screen 6 : Bouton pour l'envoi de commande sur Firebase et image qui affiche l'état du feedback selon le fonctionnement ou non de chaque appareil

<div align="center"><img src="https://user-images.githubusercontent.com/93054393/187058082-8b33dcaf-f0e1-4f81-97bb-815ce1bdd3d4.jpg" width="20%"></div>
<div align="center"><i>Screen 6</i></div>

> ## Configuration du matériel :
--------------------------------

Cablage du montage (ESP8266 + MCP3002) :


|Nom du Pin |	MCP3002	   |ESP8266|
|-|-|-|
|CSS	|1	|D8|
|MISO	|Dout (Pin6)	|D7|
|MOSI	|Din  (Pin5)	|D7|
|CLK	|7|	D5|

###  Cablage du montage (ACS712 + MCP3002) :


|Nom du Pin	|MCP3002	|ACS712|
|-----|----|----|
|DATA	|CH0 | (Pin2)|	


Le cablage du Relais est avec le (pin D4)
Installation des bibliothèques
FirebaseArduino est une bibliothèque pour simplifier la connexion à la base de données Firebase à  partir des clients Arduino
 Il s'agit d'une abstraction complète de l'API REST de Firebase exposée via des appels C++ d'une manière conviviale. Toute l'analyse JSON est gérée par la bibliothèque et vous pouvez traiter des types C/Arduino purs.
La bibliothèque ne peut pas fonctionner de manière autonome. Vous devez donc également ajouter la bibliothèque ArduinoJSON.
Alors allez d'abord dans le gestionnaire de bibliothèque et recherchez "JSON" et installez la bibliothèque comme indiqué dans la figure ci-dessous

----------------------------------------------------------------------------

>## Remarque :


La dernière bibliothèque JSON peut ne pas fonctionner avec le code. Vous devrez donc peut-ètre rétrograder la bibliothèque vers la version v5.13.5
Bibliothèque Google Firebase Extended
Maintenant, vous devez également installer la bibliothèque Google Firebase. Alors, téléchargez la bibliothèque Firebase ESP8266 version 4.0.3
Configuration de la base de données de la console Google Firebase

Maintenant, la principale chose que nous devons faire est de configurer la base de données de la console Google Firebase. Une fois la configuration terminée, nous pouvons ensuite envoyer des données de capteur en temps réel à  Google Firebase avec Nodemcu ESP8266.
Mais je n'expliquerai pas ici comment configurer la base de données de la console Google Firebase, car j'ai déjà  expliqué l'ensemble du processus dans le didacticiel précédent. Vous pouvez consulter le didacticiel suivant pour savoir comment effectuer la configuration.

> ### ATTENTION !! :

Pour que le système fonctionne il faut faire attention à  la compatibilité des versions des bibliothèque du firebase & ArduinoJson & ESP8266WiFi

* ArduinoJson (version 5.13.1)

* Firebase ESP8266 client 4.0.3 

* (gestionnaire des carte)

* ESP8266 (version 2.3.0)
  
  <div align="center"><img src="https://user-images.githubusercontent.com/93054393/187058084-44c3ac2f-ddf6-4fd8-9008-14afa67f6c33.jpg" width="60%"></div>
<div align="center"><i>Screen 6</i></div>







> ## Partie Code : 

1. Tout d'abord, nous incluons la bibliothèque pour Firebase & MCP3XXX.h & SPI.h

```Arduino
       #include <ESP8266WiFi.h>
       #include <FirebaseArduino.h>   
       #include <ESP8266HTTPClient.h> 
       #include <MCP3XXX.h>
       #include<SPI.h>
```

2. Ensuite, nous définissons les deux paramètres FIREBASE_HOST & FIREBASE_AUTH . Nous obtenons ces paramètres à  partir de Google Firebase Setup. Ces deux paramètres sont très importants pour communiquer avec firebase. Cela permet l'échange de données entre l'ESP8266 et la firebase.

```Arduino
       #define FIREBASE_HOST "keeper-connect-default-rtdb.firebaseio.com"
       #define FIREBASE_AUTH "6pTTp2lBqUIYk1XHoxkUaaOhhU71dEbQnmeO0NO6" 
       
```


3. Ensuite, nous définissons le SSID et le mot de passe WiFi. Remplacez le SSID et le mot de passe par le SSID et le mot de passe de votre réseau. Le Nodemcu se connectera au réseau et communiquera avec Google Firewall.

```Arduino
       #define WIFI_SSID "Maker Lab"
       #define WIFI_PASSWORD "makerlabtn"

```

4. déclaration des variables et des constatant.

```Arduino
       MCP3002 adc;
       int x= 0;
       #define acs712 A0
       long lastsample = 0;
       long samplesum = 0;
       int sampleCount = 0;
       float vpc = 4.8828125;
```
5. Dans le void Setup, nous commençons par la déclaration des pins SPI de la NodeMcu puis la vitesse de transmission (115200Kb/s) passant par la déclaration du Pin D4 comme sortie.

```Arduino
       void setup() 
       adc.begin(D8, D7, D6, D5);
       Serial.begin(115200);
       pinMode(D4, OUTPUT);    
```
6. Ces lignes permettent de connecter la carte NodeMCU ESP8266 au réseau Wifi. Une fois connecté, le moniteur série affiche l'état de la connexion et imprime l'adresse IP.
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
7. dans le void Loop nous commençons par la conversion de chaque trame reçue a travers le SPI en valeur analogique pendant chaque période.

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
8. pendant chaque nous tenons a convertir le courant efficace au courant nominal puis nous tenons a calucler le courant en divisant la valeur mesurer par le calibre du capteur.

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

9. pour l'étalonnage du capteur nous avons utiliser un filtre passe bas avec une condition pour bloquer les petites valeurs du courant.
```Arduino
          if (amperage <0.2)
          {
          amperage =0;
```

10. Nous envoyons maintenant les données à  Google Firebase en utilisant le chemin fourni par le code.

```Arduino
         Firebase.setString("House/Salon/feedback_Lampe","LOW");
         Serial.println("The final RMS Amperage is: " + String(amperage) + " Appox WATTAGE is: " + String(amperage * 220) + ".");
         Firebase.setFloat("House/Salon/Consommation_Lampe",amperage*220);
         int result = Firebase.getInt("House/Salon/switch");   
```
11. La LED s'allumera/s'éteindra en fonction de la chaîne reçue comme "ON" ou "OFF respectivement. Si un autre caractère est envoyé, 
Il s'agissait du contrôle des LED à  l'aide de Google Firebase. Maintenant, il y a un autre côté du tutoriel, que se passe-t-il si vous souhaitez envoyer les données du capteur à  Google Firebase.

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


Pour contrôler la LED à  l'aide de Google Firebase et Nodemcu ESP8266, vous devez d'abord configurer Google Firebase. L'étape est un peu longue mais pas de panique, car je vous ai expliqué toutes les étapes ci-dessous.

       Étape 1 : Si vous avez un identifiant Gmail, vous ètes déjà  inscrit à  Firebase. Mais si vous n'avez pas d'identifiant Gmail, inscrivez-vous d'abord à  Gmail : https://gmail.com/

<div align="center"><img src="https://user-images.githubusercontent.com/93054393/187058090-b596c9f9-04a0-4b20-8534-e3089d514fe6.jpg" width=60%"></div>
<div align="center"><i>Étape 1</i></div>


       Étape 2 :  Visitez maintenant https://firebase.google.com/ et cliquez sur Aller à  la console en haut à  droite.

<div align="center"><img src="https://user-images.githubusercontent.com/93054393/187058093-bee594de-351b-4ef6-b905-32b6f5a6a8c4.jpg" width="60%"></div>
<div align="center"><i>Étape 2</i></div>

       Étape 3 : Cliquez sur "Créer un projet".

<div align="center"><img src="https://user-images.githubusercontent.com/93054393/187058095-9b7a2c98-68c9-4e02-95e2-637cb5e4246f.jpg" width="60%"></div>
<div align="center"><i>Étape 3</i></div>

       Étape 4 : Donnez votre "Nom du projet", puis cochez la case "J'accepte les conditions de Firebase" et enfin cliquez sur "Continuer"


<div align="center"><img src="https://user-images.githubusercontent.com/93054393/187058101-86cf37e0-7774-4ab2-a0fd-40f08c249031.jpg" width="60%"></div>
<div align="center"><i>Étape 4</i></div>

       Étape 5 : Maintenant, une autre fenètre apparaîtra. Cliquez donc sur "Continuer".

<div align="center"><img src="https://user-images.githubusercontent.com/93054393/187058104-bdbd0dcf-b14a-4598-a18b-5d4829c62dc8.jpg" width="60%"></div>
<div align="center"><i>Étape 5</i></div>

       Étape 6 : Sélectionnez le "compte Google Analytics" crée à  l'aide de l'identifiant Gmail.


 Et puis cliquez sur "Créer un projet".

<div align="center"><img src="https://user-images.githubusercontent.com/93054393/187058106-4dd2a5c1-1cb2-4100-880a-767a3ce1d2f8.jpg" width="60%"></div>
<div align="center"><i>Étape 6</i></div>

       Étape 7 : Votre projet est maintenant prèt. Vous obtiendrez donc la fenètre suivante. Cliquez sur "Continuer".

<div align="center"><img src="https://user-images.githubusercontent.com/93054393/187058114-c59688f0-3664-4a24-af5f-4d66f02a2df0.jpg" width="60%"></div>
<div align="center"><i>Étape 7</i></div>


       Étape 8 : Cliquez maintenant sur "Paramètres du projet".

<div align="center"><img src="https://user-images.githubusercontent.com/93054393/187058118-35393205-ef48-4456-9a59-a70ee07f0ffb.jpg" width="60%"></div>
<div align="center"><i>Étape 8</i></div>

       Étape 9 :  Sous Paramètres du projet, cliquez sur "Comptes de service". Copiez la clé secrète ci-dessous. Le code est requis dans le code Arduino.
<div align="center"><img src="https://user-images.githubusercontent.com/93054393/187058120-8dda0747-74a4-49d6-8723-15b97d850e90.jpg" width="60%"></div>
<div align="center"><i>Étape 9</i></div>

       Étape 10 :  Cliquez sur "Créer une base de données".
<div align="center"><img src="https://user-images.githubusercontent.com/93054393/187058121-91717e1a-0e9b-4647-a5a6-80fbd5d65d57.jpg" width="60%"></div>
<div align="center"><i>Étape 10</i></div>

       Étape 11 :  Choisissez "Démarrer en mode test" puis cliquez sur "Suivant".

<div align="center"><img src="https://user-images.githubusercontent.com/93054393/187058123-b9638ca5-385d-4e0b-b97c-0dcfce91339b.jpg" width="60%"></div>
<div align="center"><i>Étape 11</i></div>

       Étape 12 :  Cliquez maintenant sur "Terminé" et sur le côté gauche, cliquez sur "Base de données".


<div align="center"><img src="https://user-images.githubusercontent.com/93054393/187058125-676c7e7e-5f4c-41f7-a902-15e9d52a1172.jpg" width="60%"></div>
<div align="center"><i>Étape 12</i></div>



       Étape 13 :  Sélectionnez l'option "Base de données en temps réel" dans la liste des bases de données.

## Remarque :

Nous avons travaillé avec le compte du MakerLab avec une base de données nommé "KEEPER-CONNECT".






       

