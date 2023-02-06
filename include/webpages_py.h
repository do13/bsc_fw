// Copyright (c) 2022 tobias
// 
// This software is released under the MIT License.
// https://opensource.org/licenses/MIT


/* ***********************************************************************************
 * Wichtiger Hinweis!
 * webpages.h nicht manuell bearbeiten! Änderungen immer in der webpages_py.h vornehmen!
 * Die webpages.h wird beim Build automatisch erstellt!
 * ***********************************************************************************/

/*//PY_VAR_ANF
PYVAR_HTML_WEBPAGES_STYLE
"<style>" 
  "html {font-family:Helvetica;display:inline-block;margin:0px auto;text-align:center;}"
  "body {margin:0;}"
  ".content {padding:20px;}"
  ".topnav {overflow: hidden;position:sticky;top:0;background-color:#6E6E6E;color:white;padding:5px;cursor:default;}"
  ".topnav span {float:left; padding: 14px 16px; text-decoration:none; font-size:1.7rem;}"
  ".btnBack:hover {background-color:#555555;color:white;}"
  ".hl {flex:1;font-size:2rem;}"
  ".cards {padding:20px;max-width:700px;margin:0 auto;display:grid;grid-gap:2rem;grid-template-columns:repeat(auto-fit,minmax(200px,1fr));}"
  ".card {background-color:white;box-shadow:2px 2px 12px 1px rgba(140,140,140,.5);text-decoration:none;font-size:26px; cursor:default;}"
  ".cardDash {background-color:#F2F2F2;box-shadow:2px 2px 12px 1px rgba(140,140,140,.5);text-decoration:none;font-size:26px; cursor:default;}"
  ".card:hover {background-color:#555555;color:white;}"
  ".button {background-color:#BDBDBD;border:none;border-radius:10px;color:white;padding:16px 40px;text-decoration:none;font-size:26px;margin:2px;cursor:default;}"
  ".button:hover {background-color:#555555;color:white;}"
  ".button:active {color:#BDBDBD;}"
"</style>";
//PY_VAR_END*/

const char htmlPageRoot[] PROGMEM = "<!DOCTYPE HTML>"
"<html>"
"<head>"
  "<title>BSC</title>"
  "<meta name='viewport' content='width=device-width, initial-scale=1'>"
  "<link rel='icon' href='data:,'>"
  "__PYVAR_HTML_WEBPAGES_STYLE__"
"</head>"
"<body>"
  "<div class='topnav'>"
    "<span class='hl'>Battery Safety Controller&nbsp;&nbsp;&nbsp;__BSC_SW_VERSION__</span>"
  "</div>"
  "<div class='content'>"
    "<div class='cards'>"
      "<div class='cardDash'><p>System<br><span id='card_system'></span></p></div>" 
      "<div class='cardDash'><p>MQTT<br><span id='card_mqtt'></span></p></div>"   
      "<div class='cardDash' id='card_freeheap'></div>"  
      "<div class='cardDash'><p>BT-Devices<center><table style='margin-top: -1em'>"
        "<tr><td>1..5</td><td><span id='card_bt1'></span></td></tr>"
        "<tr><td>6..7&nbsp;&nbsp;</td><td><span id='card_bt2'></span></td></tr></table></center></p></div>"   
      "<div class='cardDash'><p>Alarme<center><table style='margin-top: -1em'>"
        "<tr><td>1..5</td><td><span id='card_alarm1'></span></td></tr>"
        "<tr><td>6..10&nbsp;&nbsp;</td><td><span id='card_alarm2'></span></td></tr></table></center></p></div>"
      "<div class='card' onclick=\"location.href='./owTempLive'\"><p>Livedaten</p></div>"
      "<div class='card' onclick=\"location.href='./settings/'\"><p>Einstellungen</p></div>"
      "<div class='card' onclick=\"location.href='./log'\"><p>Log</p></div>"
      "<div class='card' onclick=\"location.href='https://github.com/shining-man/bsc_fw'\"><p>BSC on GitHub</p></div>"
    "</div>"
  "</div>"
"</body>"
"<script>"
"function getData() {"
  "var xhttp = new XMLHttpRequest();"
  "xhttp.onreadystatechange = function() {"
    "if (this.readyState == 4 && this.status == 200) {"
      "var values = this.responseText.split('|');"
      "document.getElementById('card_freeheap').innerHTML = '<p>Free Heap<br>' + values[0] + '</p>';"
      "document.getElementById('card_alarm1').innerHTML = values[1];"
      "document.getElementById('card_alarm2').innerHTML = values[2];"
      "if(values[3]=='1') {"
        "document.getElementById('card_mqtt').innerHTML = 'connect';"
        "document.getElementById('card_mqtt').style.color = '#00FF00';"
      "}else{"
        "document.getElementById('card_mqtt').innerHTML = 'disconnect';"
        "document.getElementById('card_mqtt').style.color = '#FF0000';"
      "}"
      "if(values[4]=='0') {"
        "document.getElementById('card_system').innerHTML = 'running';"
        "document.getElementById('card_system').style.color = '#00FF00';"
      "}else{"
        "document.getElementById('card_system').innerHTML = 'failure (' + values[4] + ')';"
        "document.getElementById('card_system').style.color = '#FF0000';"
      "}"
      "document.getElementById('card_bt1').innerHTML = values[5];"
      "document.getElementById('card_bt2').innerHTML = values[6];"
    "}"
  "};"
  "xhttp.open('GET', 'getDashboardData', true);"
  "xhttp.timeout=1000;"
  "xhttp.send();"
  "var timer = window.setTimeout('getData()', 2000);"
"}"
"getData();"
"</script>"
"</html>";


const char htmlPageSettings[] PROGMEM = "<!DOCTYPE HTML>"
"<html>"
"<head>"
  "<title>BSC</title>"
  "<meta name='viewport' content='width=device-width, initial-scale=1'>"
  "<link rel='icon' href='data:,'>"
  "__PYVAR_HTML_WEBPAGES_STYLE__"
  "<script>"
    "function reboot() {"
      "var check = confirm('Reboot?');"
      "if (check == true){location.href='../restart/';}"
    "}"
  "</script>"
"</head>"
"<body>"
  "<div class='topnav'>"
    "<span class='btnBack' onclick=\"location.href='../'\">&#10094;</span>"
    "<span class='hl'>Einstellungen</span>"
  "</div>"
  "<div class='content'>"
    "<div class='cards'>"
    "<div class='card' onclick=\"location.href='./system/'\"><p>System</p></div>"
    "<div class='card' onclick=\"location.href='./schnittstellen/'\"><p>Schnittstellen</p></div>"
    "<div class='card' onclick=\"location.href='./alarm/'\"><p>Alarmregeln</p></div>"
    "<div class='card' onclick=\"location.href='./bms_can/'\"><p>Wechselrichter&nbsp;&<br>Laderegelung</p></div>"
    "<div class='card' onclick=\"location.href='./webota/'\"><p>Update</p></div>"
    "<div class='card' onclick='reboot()'><p>Reboot</p></div>"
    "</div>"
  "</div>"
"</body>"
"</html>";


const char htmlPageSchnittstellen[] PROGMEM = "<!DOCTYPE HTML>"
"<html>"
"<head>"
  "<title>BSC</title>"
  "<meta name='viewport' content='width=device-width, initial-scale=1'>"
  "<link rel='icon' href='data:,'>"
  "__PYVAR_HTML_WEBPAGES_STYLE__"
"</head>"
"<body>"
  "<div class='topnav'>"
    "<span class='btnBack' onclick=\"location.href='../'\">&#10094;</span>"
    "<span class='hl'>Einstellungen - Schnittstellen</span>"
  "</div>"
  "<div class='content'>"
    "<div class='cards'>"
    "<div class='card' onclick=\"location.href='./dout/'\"><p>Digitalausg&auml;nge</p></div>"
    "<div class='card' onclick=\"location.href='./din/'\"><p>Digitaleing&auml;nge</p></div>"
    "<div class='card' onclick=\"location.href='./serial/'\"><p>Serial</p></div>"
    "<div class='card' onclick=\"location.href='./ow/'\"><p>Onewire</p></div>"
    "<div class='card' onclick=\"location.href='./ow2/'\"><p>Onewire II</p></div>"
    "<div class='card' onclick=\"location.href='./bt/'\"><p>Bluetooth</p></div>"
    "</div>"
  "</div>"
"</body>"
"</html>";


const char htmlPageAlarm[] PROGMEM = "<!DOCTYPE HTML>"
"<html>"
"<head>"
  "<title>BSC</title>"
  "<meta name='viewport' content='width=device-width, initial-scale=1'>"
  "<link rel='icon' href='data:,'>"
  "__PYVAR_HTML_WEBPAGES_STYLE__"
"</head>"
"<body>"
  "<div class='topnav'>"
    "<span class='btnBack' onclick=\"location.href='../'\">&#10094;</span>"
    "<span class='hl'>Einstellungen - Alarmregeln</span>"
  "</div>"
  "<div class='content'>"
    "<div class='cards'>"
    "<div class='card' onclick=\"location.href='./alarmBt/'\"><p>BMS</p></div>"
    "<div class='card' onclick=\"location.href='./alarmTemp/'\"><p>Temperatur</p></div>"
    "</div>"
  "</div>"
"</body>"
"</html>";


const char htmlPageBmsSpg[] PROGMEM = "<!doctype html>"
"<html>"
"<head>"
  "<meta charset='utf-8'>"
  "<meta name='viewport' content='width=device-width, initial-scale=1.0'>"
  "<title>BSC</title>"
  "__PYVAR_HTML_WEBPAGES_STYLE__"

  "<style>"
  ".chart-wrap {margin-left: 50px; font-family: sans-serif; height: 650px; width: 300px;}"
  "//.chart-wrap .title {font-weight: bold; font-size: 1.62em; padding: 0.5em 0 1.8em 0; text-align: center; white-space: nowrap;}"
  ".chart-wrap.vertical .grid {transform: translateY(-175px) translateX(175px) rotate(-90deg);}"
  ".chart-wrap.vertical .grid .bar::after {transform: translateY(-50%); display: block;}"
  ".chart-wrap.vertical .grid::before,"
  ".chart-wrap.vertical .grid::after {transform: translateX(-0.2em) rotate(90deg);}"
  ".chart-wrap .grid {position: relative; padding: 5px 0 5px 0; height: 100%; width: 100%; border-left: 2px solid #aaa; "
    "background: repeating-linear-gradient(90deg, transparent, transparent 19.5%, rgba(170, 170, 170, 0.7) 20%);}"
  ".chart-wrap .grid::before {font-size: 0.8em; font-weight: bold; content: '2,5 V'; position: absolute; left: -0.5em; top: -1.5em;}"
  ".chart-wrap .grid::after {font-size: 0.8em; font-weight: bold; content: '4,0 V'; position: absolute; right: -1.5em; top: -1.5em;}"
  ".chart-wrap .bar {width: 0%; height: 20px; margin: 10px 0; background-color: #F16335; border-radius: 0 3px 3px 0;}"
  ".chart-wrap .bar:hover {opacity: 0.7;}"
  "</style>"
"</head>"
 "<body>"
  "<div class='topnav'>"
    "<span class='btnBack' onclick=\"location.href='../'\">&#10094;</span>"
    "<span class='hl'>Zellspannungen</span>"
  "</div>"
  "<br><br>"
  "<div class='chart-wrap vertical'>"
  "<div class='grid'>"
  "<div id='b0' class='bar'></div>"
  "<div id='b1' class='bar'></div>"
  "<div id='b2' class='bar'></div>"
  "<div id='b3' class='bar'></div>"
  "<div id='b4' class='bar'></div>"
  "<div id='b5' class='bar'></div>"
  "<div id='b6' class='bar'></div>"
  "<div id='b7' class='bar'></div>"
  "<div id='b8' class='bar'></div>"
  "<div id='b9' class='bar'></div>"
  "<div id='b10' class='bar'></div>"
  "<div id='b11' class='bar'></div>"
  "<div id='b12' class='bar'></div>"
  "<div id='b13' class='bar'></div>"
  "<div id='b14' class='bar'></div>"
  "<div id='b15' class='bar'></div>"
  "</div>"
  "</div>"

  "<script>"
  "function getData() {"
    "var xhttp = new XMLHttpRequest();"
    "xhttp.onreadystatechange = function() {"
      "if (this.readyState == 4 && this.status == 200) {"
        "let values = this.responseText.split(';');"
        "let n = 0;"
        "for (let i=0; i<(values.length/2); i++) {"
          "let divId = 'b' + i;"
          "document.getElementById(divId).style.width = values[n] + '%';"
          "document.getElementById(divId).innerHTML = values[n+1] + '&nbsp;';"
          "n=n+2;"
        "}"
      "}"
    "};"
    "xhttp.open('GET', 'getBmsSpgData', true);"
    "xhttp.timeout=1000;"
    "xhttp.send();"
    "var timer = window.setTimeout('getData()', 1000);"
  "}"
  "getData();"
  "</script>"
"</body>"
"</html>";


const char htmlPageStatus[] PROGMEM = "<!DOCTYPE HTML>"
"<html>"
"<head>"
  "<title>BSC</title>"
  "<meta name='viewport' content='width=device-width, initial-scale=1'>"
  "<link rel='icon' href='data:,'>"
  "__PYVAR_HTML_WEBPAGES_STYLE__"
"</head>"
"<body>"
  "<div class='topnav'>"
    "<span class='hl'>Battery Safety Controller - Status</span>" 
  "</div>"
  "<div class='content'>"
    "<pre id='status'></pre>"
  "</div>"
"</body>"
"<script>"
"function getData() {"
  "var xhttp = new XMLHttpRequest();"
  "xhttp.onreadystatechange = function() {"
    "if (this.readyState == 4 && this.status == 200) {"
      "const myObj = JSON.parse(this.responseText);"
      "document.getElementById('status').innerHTML = JSON.stringify(myObj, undefined, 3);"
    "}"
  "};"
  "xhttp.open('GET', 'getDashboardData', true);"
  "xhttp.timeout=1000;"
  "xhttp.send();"
  "var timer = window.setTimeout('getStatusData()', 2000);"
"}"
"getData();"
"</script>"
"</html>";


const char htmlPageOwTempLive[] PROGMEM = "<!doctype html>"
"<html>"
"<head>"
"<meta charset='utf-8'/>"
"<title></title>"
"__PYVAR_HTML_WEBPAGES_STYLE__"

"<style>"
  ".bar {"
  "border: solid #808080 2px;"
  "border-radius: 5px;"
  "-moz-box-shadow: 3px 3px 3px #C0C0C0;"
  "-webkit-box-shadow: 3px 3px 3px #C0C0C0;"
  "box-shadow: 3px 3px 3px #C0C0C0;"
  "padding: 3px;"
  "width: 400px;"
  "height: 10px;"
  "}"
"</style>"

"<script>"
  "function addSensor(sensorNr){"
  "elem = document.createElement('span');"
  "elem.innerHTML ='<br>Sensor #' + sensorNr + ' - ';"
  "document.body.appendChild(elem);"

  "elem = document.createElement('span');"
  "elem.id = 'temps'+sensorNr;"
  "elem.innerHTML ='-- °C';"
  "document.body.appendChild(elem);"

  "elem = document.createElement('br');"
  "document.body.appendChild(elem);"

  "elem = document.createElement('progress');"
  "elem.id = 'temp'+sensorNr;"
  "elem.className = 'bar';"
  "elem.value = 0;"
  "elem.max = 50;"
  "document.body.appendChild(elem);"
  "} "

  "function setSensorVal(sensorNr, sensorValue){"
  "let elem = document.getElementById('temp'+sensorNr);"
  "elem.value = sensorValue;"

  "elem = document.getElementById('temps'+sensorNr);"
  "elem.innerHTML = '<b>'+sensorValue+' °C<b/';"
  "}"

  "function getData() {"
  "var xhttp = new XMLHttpRequest();"
  "xhttp.onreadystatechange = function(){"
  "  if (this.readyState == 4 && this.status == 200){"
  "    var values = this.responseText.split(';');"
  "    for(i=0;i<64;i++){"
  "	   if(values[i]<150){setSensorVal(i, values[i]);}"
  "    }"
  "  }"
  "};"
  "xhttp.open('GET', 'getOwTempData', true);"
  "xhttp.timeout=1000;"
  "xhttp.send();"
  "var timer = window.setTimeout('getData()', 10000);"
  "}"
"</script>"
"</head>"

"<body>"
"<div class='topnav'>"
  "<span class='btnBack' onclick=\"location.href='../'\">&#10094;</span>"
  "<span class='hl'>Temperaturen (OW)</span>"
"</div>"

"<script>"
"for(i=0;i<64;i++){addSensor(i);} "
"getData();"
"</script>"
"</body>"
"</html>";