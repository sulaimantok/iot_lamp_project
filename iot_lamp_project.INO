#include <ESP8266WiFi.h>
#include <WiFiClientSecure.h>
#include <TelegramBot.h>
 
// Initialize Wifi connection to the router  
const char* ssid  = "ini_ssid_wifi";
const char* password = "password_aman123";

// Initialize your Telegram BOT API  
const char BotToken[] = "xxxxxxxxxxxxxxxxxxxxxxxxxx";

WiFiClientSecure net_ssl;
TelegramBot bot (BotToken, net_ssl);

const int ledPin = D1;  
 
void setup() 
{  
 Serial.begin(115200);  
 while (!Serial) {}  
 delay(3000);  
 // attempt to connect to Wifi network:  
 Serial.print("Connecting Wifi: ");  
 Serial.println(ssid);  
 WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  } 
 Serial.println("");  
 Serial.println("WiFi connected");  
 bot.begin();  
 pinMode(ledPin, OUTPUT);  
}  

void loop() 
{  
 message m = bot.getUpdates(); 
 if (m.text.equals("On")) 
       {  
   digitalWrite(ledPin, HIGH);  
   Serial.println("message received");  
   bot.sendMessage(m.chat_id, "Lampu Sekarang Menyala"); 
 }  
 else if (m.text.equals("Off"))
       {  
   digitalWrite(ledPin, LOW);  
   Serial.println("message received");  
   bot.sendMessage(m.chat_id, "Lampu Sekarang Mati"); 
 }  
}
