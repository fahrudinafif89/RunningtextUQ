// ----------------------
// FS CONFIG

uint8_t show;

struct ConfigIsi {

  char rtx1[10240];
  char r1[4096];
  char r2[4096];
  char r3[4096];
  char r4[4096];
};

const char *fileconfigisi = "/configisi.json";
ConfigIsi configisi;

String message, XML;

// -------------------------------------------
// Membuat file config ISI JSON di File Sistem

void membuatDataAwal() {

  String dataawal = "{\"rtx1\":\"ini adalh pengumuman \", \"r1\":\"room 1\", \"r2\":\"room 2\", \"r3\":\"room 3\",  \"r4\":\"room 4\"}"; 

  DynamicJsonDocument doc(1024);
  DeserializationError error = deserializeJson(doc, dataawal);

  File configFileIsi = LittleFS.open(fileconfigisi, "w");
  
  if (!configFileIsi) {
    Serial.println("Gagal membuat file configisi.json untuk ditulis mungkin partisi belum dibuat");
    return;
  }
  
  serializeJson(doc, configFileIsi);

  if (error) {
    
    Serial.print(F("deserializeJson() gagal kode sebagai berikut: "));
    Serial.println(error.c_str());
    return;
    
  } else {
    
    configFileIsi.close();
    Serial.println("Berhasil membuat file configisi.json");
  
  }  

}



// -------------------------------------------
// Membaca file config ISI JSON di File Sistem

void loadIsiConfig(const char *fileconfigisi, ConfigIsi &configisi) {  

  File configFileIsi = LittleFS.open(fileconfigisi, "r");

  if (!configFileIsi) {
    
    Serial.println("Gagal membuka file configisi.json untuk dibaca");
    membuatDataAwal();
    Serial.println("Sistem restart...");
    ESP.restart();
    
  }

  size_t size = configFileIsi.size();
  std::unique_ptr<char[]> buf(new char[size]);
  configFileIsi.readBytes(buf.get(), size);

  DynamicJsonDocument doc(1024);
  DeserializationError error = deserializeJson(doc, buf.get());  

  if (error) {
    Serial.println("Gagal parse fileconfigisi");
    return;
  }

  strlcpy(configisi.rtx1, doc["rtx1"] | "", sizeof(configisi.rtx1));
  strlcpy(configisi.r1, doc["r1"] | "", sizeof(configisi.r1));
  strlcpy(configisi.r2, doc["r2"] | "", sizeof(configisi.r2));
  strlcpy(configisi.r3, doc["r3"] | "", sizeof(configisi.r3));
  strlcpy(configisi.r4, doc["r4"] | "", sizeof(configisi.r4));

  configFileIsi.close(); 

}


// -------------------------------------------
// MEMBACA PARAMETER YANG TERSIMPAN

void bacaParameter() {

  Serial.println(" ");
  Serial.println("PARAMETER TERSIMPAN");
  Serial.print("Pengumuman                : "); Serial.println(configisi.rtx1);
  Serial.print("Denah lantai 1 L101-L104  : "); Serial.println(configisi.r1);
  Serial.print("Denah lantai 1 L105-L10   : "); Serial.println(configisi.r2);
  Serial.print("Denah lantai 2 L201-L204  : "); Serial.println(configisi.r3);
  Serial.print("Denah lantai 2 L205-L208  : "); Serial.println(configisi.r4);
  Serial.println(" ");
  
}

//-----------------------------------
// UPDATE WAKTU

void UpdateWaktu() {

  static long pM;
  static uint16_t d;
  

  if (millis() - pM > 1000) {
    d++;
    if (d < 2) {
      BacaRTC();
    } else if (d < 60) { // Update setiap 60 detik
      rDet++;
      if (rDet > 59) {
        rMen++;
        rDet=0;
        if (rMen > 59) {
          rJam++;
          rMen = 0;
        }
      }
    } else {
      d = 0; 
    }
    pM = millis();    
  }
  
}



//----------------------------------------------------------------------
// XML UNTUK JEMBATAN DATA MESIN DENGAN WEB

void XMLWaktu(){

  XML="<?xml version='1.0'?>";
  XML+="<t>";
  
    XML+="<Tahun>";
    XML+=rTah;
    XML+="</Tahun>";
    XML+="<Bulan>";
    XML+=rBul;
    XML+="</Bulan>";
    XML+="<Tanggal>";
    XML+=rTgl;
    XML+="</Tanggal>";
    XML+="<Jam>";
      if(rJam<10){
        XML+="0";
        XML+=rJam;
      }else{XML+=rJam;}
    XML+="</Jam>";
    XML+="<Menit>";
      if(rMen<10){
        XML+="0";
        XML+=rMen;
      }else{XML+=rMen;}
    XML+="</Menit>";
    XML+="<Detik>";
      if(rDet<10){
        XML+="0";
        XML+=rDet;
      }else{XML+=rDet;}
    XML+="</Detik>";
    XML+="<Suhu>";
    XML+= celsius - 5;
    XML+="</Suhu>";
    
  XML+="</t>"; 
}


void XMLDataISI(){

  XML="<?xml version='1.0'?>";
  XML+="<t>";
    XML+="<RTX1>";
    XML+= configisi.rtx1;
    XML+="</RTX1>";
    XML+="<R1>";
    XML+= configisi.r1;
    XML+="</R1>";
    XML+="<R2>";
    XML+= configisi.r2;
    XML+="</R2>";
    XML+="<R3>";
    XML+= configisi.r3;
    XML+="</R3>";
    XML+="<R4>";
    XML+= configisi.r4;
    XML+="</R4>";
    
  XML+="</t>"; 
}
