//----------------------------------------------------------------------
//TAMPILKAN TANGGAL
void Waktu() 
     {
      char hari[8];
      char tanggal[7]; // 21 SEP
      static uint32_t pM;
      uint32_t cM = millis();
      static uint8_t flag;
      
      if(cM - pM > 10000) 
        {
          pM = cM;
          flag++;
          
          sprintf(hari, "%02d:%02d >> %s-%02d-%s" , rJam, rMen, namaHari[rHar], rTgl, namaBulan[rBul]);
          Disp.setFont(ElektronMart6x12);
          textCenter(2, hari);
          
          if (flag >= 2) 
             {
              flag = 0;
              Disp.clear();
              show = 4;
             }
        } 
  
     }
