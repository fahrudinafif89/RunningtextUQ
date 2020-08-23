//----------------------------------------------------------------------
// FORMAT TEKS CENTER

void textCenter(int y,String Msg)   
{
  int center = int((Disp.width()-Disp.textWidth(Msg)) / 2);
  Disp.drawText(center,y,Msg);
}

//----------------------------------------------------------------------
//TAMPILAN UNIVERSITAS QOMARUDDIN
void UQ()
{
  static uint32_t pM;
  uint32_t cM = millis();
  static uint8_t flag;

  if(cM - pM > 10000)
  {
    pM = cM;
    flag++;

    Disp.setFont(ElektronMart6x12);
    static char *Pgm[] = {"UNIVERSITAS QOMARUDDIN"};
    textCenter(2, Pgm[0]);

    if (flag >= 2)
    {
      flag = 0;
      Disp.clear();
      show = 1;
    }
  }
}

//----------------------------------------------------------------------
//TAMPILAN LABORATORIUM FAKULTAS TEKNIK
void Lab()
{
  static uint32_t pM;
  uint32_t cM = millis();
  static uint8_t flag;

  if(cM - pM > 10000)
  {
    pM = cM;
    flag++;

    Disp.setFont(ElektronMart6x12);
    static char *Pgm[] = {"LAB. FAKULTAS TEKNIK"};
    textCenter(2, Pgm[0]);

    if (flag >= 2)
    {
      flag = 0;
      Disp.clear();
      show = 2;
    }
  }
}

//----------------------------------------------------------------------
//TAMPILAN RUNNING TEKS PENGUMUMAN
void Info() {

  static uint32_t pM;
  uint32_t cM = millis();
  static uint8_t Kecepatan = 50;
  static uint32_t x;

  int width = Disp.width();
  int fullScroll = Disp.textWidth(configisi.rtx1) + width;

  Disp.setFont(ElektronMart5x6);
  textCenter(0,"PENGUMUMAN");

  if(cM - pM > Kecepatan) 
  {
    pM = cM;

    if (x < fullScroll) {
      ++x;      
    } else {
      x = 0;
      Disp.clear();
      show = 3;      
    }
    Disp.drawText(width - x, 8, configisi.rtx1);  // koordinat    
  } 
}

//----------------------------------------------------------------------
//TAMPILAN RUNNING TEKS DENAH RUANGAN LANTAI L101-104
void Denah11() {

  static uint32_t pM;
  uint32_t cM = millis();
  static uint8_t Kecepatan = 50;
  static uint32_t x;

  int width = Disp.width();
  int fullScroll = Disp.textWidth(configisi.r1) + width;

  Disp.setFont(ElektronMart5x6);
  textCenter(0,"<< DENAH RUANG KELAS   ");
  if(cM - pM > Kecepatan) 
  {
    pM = cM;

    if (x < fullScroll) {
      ++x;      
    } else {
      x = 0;
      Disp.clear();
      show = 5;      
    }
    Disp.drawText(width - x, 8, configisi.r1);  // koordinat    
  } 
}

//----------------------------------------------------------------------
//TAMPILAN RUNNING TEKS DENAH RUANGAN LANTAI 105-108
void Denah12() {

  static uint32_t pM;
  uint32_t cM = millis();
  static uint8_t Kecepatan = 50;
  static uint32_t x;

  int width = Disp.width();
  int fullScroll = Disp.textWidth(configisi.r2) + width;

  Disp.setFont(ElektronMart5x6);
  textCenter(0,"   DENAH RUANG KELAS >>");
  if(cM - pM > Kecepatan) 
  {
    pM = cM;

    if (x < fullScroll) {
      ++x;      
    } else {
      x = 0;
      Disp.clear();
      show = 6;      
    }
    Disp.drawText(width - x, 8, configisi.r2);  // koordinat    
  } 
}

//----------------------------------------------------------------------
//TAMPILAN RUNNING TEKS DENAH RUANGAN LANTAI 201-204
void Denah21() {

  static uint32_t pM;
  uint32_t cM = millis();
  static uint8_t Kecepatan = 50;
  static uint32_t x;

  int width = Disp.width();
  int fullScroll = Disp.textWidth(configisi.r3) + width;

  Disp.setFont(ElektronMart5x6);
  textCenter(0,"<< DENAH RUANG KELAS   ");
  if(cM - pM > Kecepatan) 
  {
    pM = cM;

    if (x < fullScroll) {
      ++x;      
    } else {
      x = 0;
      Disp.clear();
      show = 7;      
    }
    Disp.drawText(width - x, 8, configisi.r3);  // koordinat    
  } 
}

//----------------------------------------------------------------------
//TAMPILAN RUNNING TEKS DENAH RUANGAN LANTAI 205-208
void Denah22() {

  static uint32_t pM;
  uint32_t cM = millis();
  static uint8_t Kecepatan = 50;
  static uint32_t x;

  int width = Disp.width();
  int fullScroll = Disp.textWidth(configisi.r4) + width;

  Disp.setFont(ElektronMart5x6);
  textCenter(0,"   DENAH RUANG KELAS >>");
  if(cM - pM > Kecepatan) 
  {
    pM = cM;

    if (x < fullScroll) {
      ++x;      
    } else {
      x = 0;
      Disp.clear();
      show = 0;      
    }
    Disp.drawText(width - x, 8, configisi.r4);  // koordinat    
  } 
}
