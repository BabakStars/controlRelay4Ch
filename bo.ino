#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>
#include <ESP8266HTTPClient.h>
#include "index.h"
ESP8266WebServer server(80);
IPAddress local_IP(192,168,1,103);
IPAddress subnet(255,255,255,0);
bool ch1=false,ch2=false,ch3=false,ch4=false;
void setup() {
  delay(2000);
  Serial.begin(115200);
  pinMode(D0,OUTPUT);
  pinMode(D1,OUTPUT);
  pinMode(D2,OUTPUT);
  pinMode(D3,OUTPUT);
  digitalWrite(D0,1);
  digitalWrite(D1,1);
  digitalWrite(D2,1);
  digitalWrite(D3,1);
  WiFi.mode(WIFI_AP);
  WiFi.softAPConfig(local_IP,local_IP,subnet);
  WiFi.softAP("ESP-12E", "123456789");
  Serial.print("Wifi Ap IP = ");
  Serial.println(WiFi.softAPIP());
  server.on("/", handleRoot);
  server.on("/SET", action);
  server.begin();

}

void loop() {
  server.handleClient();
}
void handleRoot() {
  server.send(200,"text/html",index_page);
}
void action() {
  Serial.println("OK");
  String steps = server.arg("Set");
  if(steps == "stop")
  {
    digitalWrite(D0,1);
    digitalWrite(D1,1);
    digitalWrite(D2,1);
    digitalWrite(D3,1);
    server.send(200,"text/plain","All channels are off");
  }
  if(steps == "I")
  {
    if(ch1 == false)
    {
      ch1 = true;
      digitalWrite(D0,0);
      server.send(200,"text/plain","channel one is ON");
    }
    else
    {
      ch1 = false;
      digitalWrite(D0,1); 
      server.send(200,"text/plain","channel one is OFF");  
    }
    
  }
  if(steps == "II")
  {
    if(ch2 == false)
    {
      ch2 = true;
      digitalWrite(D1,0);
      server.send(200,"text/plain","channel two is ON");
    }
    else
    {
      ch2 = false;
      digitalWrite(D1,1);  
      server.send(200,"text/plain","channel two is OFF");
    }
    
  }
    if(steps == "III")
  {
    if(ch3 == false)
    {
      ch3 = true;
      digitalWrite(D2,0);
      server.send(200,"text/plain","channel three is ON");
    }
    else
    {
      ch3 = false;
      digitalWrite(D2,1); 
      server.send(200,"text/plain","channel three is OFF");  
    }
    
  }
  if(steps == "IIII")
  {
    if(ch4 == false)
    {
      ch4 = true;
      digitalWrite(D3,0);
      server.send(200,"text/plain","channel four is ON");
    }
    else
    {
      ch4 = false;
      digitalWrite(D3,1);
      server.send(200,"text/plain","channel four is OFF");  
    }
    
  }
  Serial.println(steps);
}
