// -----------------------------
// HALAMAN WEB UNTUK SETTING ISI

char setwaktu[] PROGMEM = R"=====(

<!DOCTYPE HTML>
<html>
<meta name='viewport' content='width=device-width, initial-scale=1'>

<head>
    <title>SETTING</title>
    <style>
        body {
            width: 97%;
            text-align: center;
            background-color: rgb(173, 238, 247);
        }
        
        input {
            background-color: rgb(210, 248, 255);
            border-color: rgb(252, 0, 239);
            border-style: ridge;
            border-width: 2px;
        }
        
        select,
        button {
            background-color: rgb(0, 255, 42);
            max-width: 100%;
            margin: 5px;
            padding: 10px;
            border-radius: 7px;
            border-color: rgb(255, 238, 0);
            border-style: solid;
            border-width: 3px;
        }
        
        textarea {
            background-color: rgb(210, 248, 255);
            max-width: 100%;
            margin: 5px;
            padding: 5px;
            border-radius: 7px;
        }
        
        meter,
        progress,
        output {
            max-width: 100%;
        }
        
        h1 {
            color: rgb(255, 0, 0);
            margin: 1px;
        }
        
        h2 {
            color: rgb(68, 0, 255);
            margin: 3px;
        }
        
        h3 {
            color: rgb(68, 0, 255);
            margin: 3px;
        }
        
        h4 {
            color: rgb(0, 0, 0);
            margin: 2px;
        }
        
        .note {
            color: #555;
            font-size: 1em;
        }
        
        .info {
            background-color: rgb(210, 248, 255);
            border-radius: 30px;
            border-color: rgb(252, 0, 239);
            border-style: dotted;
            padding-top: 17px;
            margin: 5px;
        }
        
        .tombol {
            background-color: rgb(232, 255, 104);
            margin: 20px;
            padding: 10px;
            border-radius: 10px;
            text-decoration: none;
            border-style: solid;
            border-width: 2px;
        }
    </style>
</head>

<body onload='updateData()'>
<br><br>
    <h1>PAPAN INFORMASI</h1>
    <h3>LABORATORIUM FAKULTAS TEKNIK UNIVERSITAS QOMARUDDIN GRESIK</h3>
    <a href="http://uqgresik.ac.id">uqgresik.ac.id</a>
    <br><br>

<div class='info'>
  <span id='day'></span>/<span id='month'></span>/<span id='year'></span><span> </span>
  <span id='hour'></span>:<span id='minute'></span>:<span id='second'></span><span> </span>
  <br><br>
</div>



<table width='100%'>
<hr/>
WARNING: jika anda sekarang berada pada 192.168.4.1 
berarti sekarang anda tidak memiliki koneksi internet
<hr/>
  <tr>
<form>
  <div>
    <h3><label for="rtx1">PENGUMUMAN</label><br></h3>
    <textarea rows="3" id="rtx1" placeholder="pengumuman"/></textarea>
  </div>
  usahakan menggunkan teks sedikit mungkin untuk menghindari flicker
  <br>
  <div>
    <h3><label for="r1">LANTAI 1 101-104</label><br></h3>
    <textarea rows="3" id="r1" placeholder=" 101-104"/></textarea>
  </div> 
  <div>
    <h3><label for="r2"> LANTAI 1 105-108</label><br></h3>
    <textarea rows="3" id="r2" placeholder=" 105-108"/></textarea>
  </div> 
  <div>
    <h3><label for="r3"> LANTAI 2 201-204</label><br></h3>
    <textarea rows="3" id="r3" placeholder=" 201-204"/></textarea>
  </div>  
  <div>
    <h3><label for="r4"> LANTAI 2 205-208</label><br></h3>
    <textarea rows="3" id="r4" placeholder=" 205-208"/></textarea>
  </div> 
  <div>
    <br>
    <button onClick="setIsi()"> Simpan </button>
  </div>
<hr/>
  <h3>Ubah Waktu</h3>
</form>
  </tr>
  <tr>
    <td>
      <form>
        <h4>Tanggal</h4>  
        <input type='date' name='date' min='2019-01-01'><br><br>
        <input type='submit' value='Ubah Tanggal'> 
      </form>  
    </td>
    <td>
      <form>  
        <h4>Jam</h4>
        <input type='TIME' name='time'><br><br>
        <input type='submit' value='Ubah Jam'> 
      </form>
    </td>
  </tr>
</table>
<br>
<hr/>
<br>
<a class ='tombol' href="/info">------------( INFO )------------</a> <br><br>
<br>
TERIMAKSIH    
<br><br>
    





<br>

</body>


<script>

var xmlHttp=createXmlHttpObject();

function createXmlHttpObject(){
 if(window.XMLHttpRequest){
    xmlHttp=new XMLHttpRequest();
 }else{
    xmlHttp=new ActiveXObject('Microsoft.XMLHTTP');// code for IE6, IE5
 }
 return xmlHttp;
}

function updateData() {
  prosesdataisi();
  proseswaktu();
}

function proseswaktu(){
 if(xmlHttp.readyState==0 || xmlHttp.readyState==4){
   xmlHttp.open('PUT','xmlwaktu',true);
   xmlHttp.onreadystatechange=handleServerResponseWaktu;
   xmlHttp.send(null);
 }
 setTimeout('proseswaktu()',1000);
}

function prosesdataisi(){
 if(xmlHttp.readyState==0 || xmlHttp.readyState==4){
   xmlHttp.open('PUT','xmldataisi',true);
   xmlHttp.onreadystatechange=handleServerResponseDataISI;
   xmlHttp.send(null);
 }
}


function handleServerResponseWaktu(){
  
 if(xmlHttp.readyState==4 && xmlHttp.status==200){
   xmlResponse=xmlHttp.responseXML;

   xmldoc = xmlResponse.getElementsByTagName('Tahun');
   message = xmldoc[0].firstChild.nodeValue;
   document.getElementById('year').innerHTML=message;

   xmldoc = xmlResponse.getElementsByTagName('Bulan');
   message = xmldoc[0].firstChild.nodeValue;
   document.getElementById('month').innerHTML=message;

   xmldoc = xmlResponse.getElementsByTagName('Tanggal');
   message = xmldoc[0].firstChild.nodeValue;
   document.getElementById('day').innerHTML=message;

   xmldoc = xmlResponse.getElementsByTagName('Jam');
   message = xmldoc[0].firstChild.nodeValue;
   document.getElementById('hour').innerHTML=message;

   xmldoc = xmlResponse.getElementsByTagName('Menit');
   message = xmldoc[0].firstChild.nodeValue;
   document.getElementById('minute').innerHTML=message;

   xmldoc = xmlResponse.getElementsByTagName('Detik');
   message = xmldoc[0].firstChild.nodeValue;
   document.getElementById('second').innerHTML=message;
 }
 
}


function handleServerResponseDataISI(){
  
 if(xmlHttp.readyState==4 && xmlHttp.status==200){
   xmlResponse=xmlHttp.responseXML;

 
   xmldoc = xmlResponse.getElementsByTagName('RTX1');
   message = xmldoc[0].firstChild.nodeValue;
   document.getElementById('rtx1').value=message;

   xmldoc = xmlResponse.getElementsByTagName('R1');
   message = xmldoc[0].firstChild.nodeValue;
   document.getElementById('r1').value=message;

   xmldoc = xmlResponse.getElementsByTagName('R2');
   message = xmldoc[0].firstChild.nodeValue;
   document.getElementById('r2').value=message;

   xmldoc = xmlResponse.getElementsByTagName('R3');
   message = xmldoc[0].firstChild.nodeValue;
   document.getElementById('r3').value=message;
   
   xmldoc = xmlResponse.getElementsByTagName('R4');
   message = xmldoc[0].firstChild.nodeValue;
   document.getElementById('r4').value=message;
   /*
   xmldoc = xmlResponse.getElementsByTagName('RTX4');
   message = xmldoc[0].firstChild.nodeValue;
   document.getElementById('rtx4').value=message;

   xmldoc = xmlResponse.getElementsByTagName('RTX5');
   message = xmldoc[0].firstChild.nodeValue;
   document.getElementById('rtx5').value=message;
   */
 }
 
}


function setIsi() {
  
  console.log("tombol telah ditekan!");
  var rtx1 = document.getElementById("rtx1").value;
  var r1 = document.getElementById("r1").value;
  var r2 = document.getElementById("r2").value;
  var r3 = document.getElementById("r3").value;
  var r4 = document.getElementById("r4").value;
  //var rtx4 = document.getElementById("rtx4").value;
  //var rtx5 = document.getElementById("rtx5").value;
  
  var dataisi = {rtx1:rtx1, r1:r1, r2:r2, r3:r3, r4:r4};
  //rtx4:rtx4, rtx5:rtx5
  
  var xhr = new XMLHttpRequest();
  var url = "/simpandataisi";
  
  xhr.onreadystatechange = function() {
    if(this.onreadyState == 4  && this.status == 200) {
      console.log(xhr.responseText);
    }
  };
  xhr.open("POST", url, true);
  xhr.send(JSON.stringify(dataisi));
  
};


</script>

</html>


)=====";
