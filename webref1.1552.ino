// PAPAN INFORMASI LABORATORIUM UNIVERSITAS QUMARUDDIN
//update in 22 agust 2020
//created by: Muhammad Fahrudin Afif

#include <FS.h>
#include <LittleFS.h>
#include <ArduinoJson.h>

#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
#include <ESP8266HTTPUpdateServer.h>

#include <Wire.h>
#include <RtcDS3231.h>
RtcDS3231<TwoWire> Rtc(Wire);

#include <DMDESP.h>

#include <fonts/ElektronMart5x6.h>
#include <fonts/ElektronMart6x8.h>
#include <fonts/ElektronMart6x12.h>
#include <fonts/ElektronMart6x16.h>

#include "Display.h"
#include "RTC.h"
#include "FSConfig.h"
#include "WebServer.h"
#include "WebPage.h"


#include "ShowRtextLogo.h"
#include "ShowTime.h"
#include "info.h"




void handleinfo() {
  Serial.println("GET /info");
  server.send(200, "text/html", htmlinfo);
}
  
//----------------------------------------------------------------------
// SETUP

void setup() {

  Serial.begin(115200);


  //RTC
  mulaiRTC();

  //FILE SYSTEM
  LittleFS.begin();
  loadIsiConfig(fileconfigisi, configisi);

  //WIFI

  pinMode(pin_led, OUTPUT);

  wifiConnect();
  
    
    
  server.on("/", []() {
    server.on("/info", handleinfo);

    server.send_P(200, "text/html", setwaktu);


    // Kalau ada perubahan tanggal
    if (server.hasArg("date")) {
    
      uint16_t jam;
      uint8_t menit;
      uint8_t detik;      
      String sd=server.arg("date");
      String lastSd;

      //uint_8: bit hampir sama dengan const char> tipe data untuk bilangan cacac
      
      jam = ((sd[0]-'0')*1000)+((sd[1]-'0')*100)+((sd[2]-'0')*10)+(sd[3]-'0');
      menit = ((sd[5]-'0')*10)+(sd[6]-'0');
      detik = ((sd[8]-'0')*10)+(sd[9]-'0');
      
      if (sd != lastSd){
        RtcDateTime now = Rtc.GetDateTime();
        uint8_t hour = now.Hour();
        uint8_t minute = now.Minute();
        Rtc.SetDateTime(RtcDateTime(jam, menit, detik, hour, minute, 0));
        lastSd=sd;
      }

      BacaRTC();
  
      server.send ( 404 ,"text", message );
    
    }

    // Kalau ada perubahaan jam
    if (server.hasArg("time")) {
      
      String st=server.arg("time");
      String lastSt;
      uint8_t jam = ((st[0]-'0')*10)+(st[1]-'0');
      uint8_t menit = ((st[3]-'0')*10)+(st[4]-'0');
      
      if (st != lastSt){
         RtcDateTime now = Rtc.GetDateTime();
         uint16_t year = now.Year();
         uint8_t month = now.Month();
         uint8_t day = now.Day();
         Rtc.SetDateTime(RtcDateTime(year, month, day, jam, menit, 0));
         lastSt=st;
       }
       
       BacaRTC();
      
       server.send ( 404 ,"text", message );
  
    }
  });

  server.on("/simpandataisi", HTTP_POST, handleSettingIsiUpdate);
  server.on("/xmlwaktu", handleXMLWaktu); // http://192.168.4.1/xmlwaktu
  server.on("/xmldataisi", handleXMLDataISI); // http://192.168.4.1/xmldataisi


  httpUpdater.setup(&server);
  server.begin();
  Serial.println("HTTP server started"); 
  
  bacaParameter(); // Tampilkan Parameter yang tersimpan

  //DMD
  Disp.start();  
  Disp.setBrightness(20);

  UpdateWaktu();
  
}

//----------------------------------------------------------------------
// LOOP

void loop()
{
  server.handleClient();
  switch(show)
   {
    case 0:
    UQ();
    break;
    
    case 1:
    Lab();
    break;

    case 2:
    Info();
    break;

    case 3:
    Waktu();
    break;

    case 4:
    Denah11();
    break;

    case 5:
    Denah12();
    break;

    case 6:
    Denah21();
    break;

    case 7:
    Denah22();
    break;
   }
  Disp.loop();
  UpdateWaktu();
}
