// Copyright (c) 2022 tobias
// 
// This software is released under the MIT License.
// https://opensource.org/licenses/MIT

#include "Arduino.h"
#include "defines.h"
#include "WebSettings.h"

/* ***********************************************************************************
 * Wichtiger Hinweis!
 * params.h nicht manuell bearbeiten! Änderungen immer in der params_py.h vornehmen!
 * Die params.h wird beim Build automatisch erstellt!
 * ***********************************************************************************/


const char paramSystem[] = "["
  "{"
    "'label':'WLAN',"
    "'type':13,"
  "},"
  "{"
  "'name':40,"
  "'label':'WLAN SSID',"
  "'type':0,"
  "'default':''"
  "},"
  "{"
  "'name':41,"
  "'label':'WLAN Passwort',"
  "'type':2,"
  "'default':''"
  "},"
  "{"
  "'name':96,"
  "'label':'WLAN connect Timeout',"
  "'type':3,"
  "'unit':'s',"
  "'default':30,"
  "'min':0,"
  "'max':3600,"
  "'help':'Der Timeout gibt an, nach welcher Zeit ein Verbindungsversuch abgebrochen wird und ein Accesspoint erstellt wird.\n"
    "0 deaktiviert den Timeout.'"
  "},"
  "{"
  "'label':'MQTT',"
  "'type':13"
  "},"
  "{"
  "'name':44,"
  "'label':'MQTT enable',"
  "'type':10,"
  "'default':0"
  "},"
  "{"
  "'name':42,"
  "'label':'MQTT Server IP',"
  "'type':0,"
  "'default':''"
  "},"
  "{"
  "'name':43,"
  "'label':'MQTT Server Port',"
  "'type':3,"
  "'default':1883,"
  "'min':1,"
  "'max':10000"
  "},"
  "{"
  "'name':86,"
  "'label':'Username',"
  "'type':0,"
  "'default':''"
  "},"
  "{"
  "'name':87,"
  "'label':'Passwort',"
  "'type':2,"
  "'default':''"
  "},"
  "{"
  "'name':45,"
  "'label':'MQTT Device Name',"
  "'type':0,"
  "'default':'bsc'"
  "}"
  /*"{"
    "'label':'Display',"
    "'type':13,"
  "},"
  "{"
  "'name':"+String(ID_PARAM_DISPLAY_ENABLE)+","
  "'label':'Display',"
  "'type':10,"
  "'default':'1'"
  "}"*/
  "]";


const char paramBluetooth[] PROGMEM = "["
  "{"
    "'name':3,"
    "'label':'Bluetooth',"
    "'label_entry':'BT Device',"
    "'groupsize':7,"
    "'type':12,"
    "'group':["
    "{"
      "'name':4,"
      "'label':'Bluetooth',"
      "'type':9,"
      "'options':["
        "{'v':'0','l':'nicht belegt'},"
        "{'v':'1','l':'NEEY Balancer 4A'}],"
      "'default':'0'"
    "},"
    "{"
      "'name':5,"
      "'label':'MAC-Adresse',"
      "'type':0,"
      "'default':''"
    "}]"
  "}"
  "]";
  

const char paramSerial[] PROGMEM = "["
  "{"
    "'label':'Serielle Schnitstellen',"
    "'label_entry':'Serial',"
    "'groupsize':3,"
    "'type':12,"
    "'group':["
      "{"
        "'name':1,"
        "'label':'Serial',"
        "'type':9,"
        "'options':["
          "{'v':'0','l':'nicht belegt'},"
          "{'v':'1','l':'JBD BMS (IN)'},"
          "{'v':'2','l':'JK-BMS (IN)'},"
          "{'v':'3','l':'Seplos-BMS (IN)'}],"
        "'default':'0'"
      "}"
    "]"
  "}"
"]";


const char paramAlarmBms[] PROGMEM = "["
  "{"
    "'name':10,"
    "'label':'Bluetooth Alarmregeln',"
    "'label_entry':'Alarmregel',"
    "'groupsize':10,"
    "'type':12,"
    "'group':["
      "{"
      "'name':9,"
      "'label':'Zu &Uuml;berwachendes BMS',"
      "'type':9,"
      "'options':["
        "{'v':'0','l':'Aus'},"
        "{'v':'1','l':'Bluetooth 0'},"
        "{'v':'2','l':'Bluetooth 1'},"
        "{'v':'3','l':'Bluetooth 2'},"
        "{'v':'4','l':'Bluetooth 3'},"
        "{'v':'5','l':'Bluetooth 4'},"
        "{'v':'6','l':'Bluetooth 5'},"
        "{'v':'7','l':'Bluetooth 6'},"
        "{'v':'8','l':'Serial 0'},"
        "{'v':'9','l':'Serial 1'},"
        "{'v':'10','l':'Serial 2'}"
        "],"
      "'default':0"
      "},"
      "{"
        "'label':'Keine Daten vom BMS',"
        "'type':13,"
      "},"
      "{"
        "'name':11,"
        "'label':'Alarm keine Daten',"
        "'type':10,"
        "'default':'0'"
      "},"
      "{"
      "'name':17,"
      "'label':'Aktion bei Alarm',"
      "'type':9,"
      "'options':["
        "{'v':'1','l':'Alarm 1'},{'v':'2','l':'Alarm 2'},{'v':'3','l':'Alarm 3'},{'v':'4','l':'Alarm 4'},{'v':'5','l':'Alarm 5'},{'v':'6','l':'Alarm 6'},{'v':'7','l':'Alarm 7'},{'v':'8','l':'Alarm 8'},{'v':'9','l':'Alarm 9'},{'v':'10','l':'Alarm 10'}"
        "],"
      "'default':'0'"
      "},"
      "{"
        "'name':12,"
        "'label':'Alarm keine Daten',"
        "'unit':'s',"
        "'type':3,"
        "'default':15,"
        "'min':1,"
        "'max':255"
      "},"
      "{"
        "'label':'Spannungs&uuml;berwachung Zelle Min/Max',"
        "'type':13,"
      "},"
      "{"
        "'name':13,"
        "'label':'Spg.-&#220;berwachung',"
        "'type':10,"
        "'default':'0'"
      "},"
      "{"
      "'name':18,"
      "'label':'Aktion bei Alarm',"
      "'type':9,"
      "'options':["
        "{'v':'1','l':'Alarm 1'},{'v':'2','l':'Alarm 2'},{'v':'3','l':'Alarm 3'},{'v':'4','l':'Alarm 4'},{'v':'5','l':'Alarm 5'},{'v':'6','l':'Alarm 6'},{'v':'7','l':'Alarm 7'},{'v':'8','l':'Alarm 8'},{'v':'9','l':'Alarm 9'},{'v':'10','l':'Alarm 10'}"
        "],"
      "'default':'0'"
      "},"
      "{"
        "'name':14,"
        "'label':'Anzahl Zellen Monitoring',"
        "'type':3,"
        "'default':16,"
        "'min':1,"
        "'max':24"
      "},"
      "{"
        "'name':15,"
        "'label':'Zellspannung Min',"
        "'unit':'mV',"
        "'type':3,"
        "'default':2500,"
        "'min':2000,"
        "'max':5000"
      "},"
      "{"
        "'name':16,"
        "'label':'Zellspannung Max',"
        "'unit':'mV',"
        "'type':3,"
        "'default':3650,"
        "'min':2000,"
        "'max':5000"
      "},"
      /*"{"
        "'name':"+String(ID_PARAM_ALARM_BT_CELL_SPG_MAX_HYSTERESE)+","
        "'label':'Hysterese',"
        "'unit':'mV',"
        "'type':3,"
        "'default':20,"
        "'min':0,"
        "'max':255"
      "},"*/
      "{"
        "'label':'Spannungs&uuml;berwachung Gesamt Min/Max',"
        "'type':13,"
      "},"
      "{"
      "'name':19          //0=AUS; 1-5=Alarm 1-5,"
      "'label':'Aktion bei Alarm',"
      "'type':9,"
      "'options':["
        "{'v':'0','l':'Aus'},"
        "{'v':'1','l':'Alarm 1'},{'v':'2','l':'Alarm 2'},{'v':'3','l':'Alarm 3'},{'v':'4','l':'Alarm 4'},{'v':'5','l':'Alarm 5'},{'v':'6','l':'Alarm 6'},{'v':'7','l':'Alarm 7'},{'v':'8','l':'Alarm 8'},{'v':'9','l':'Alarm 9'},{'v':'10','l':'Alarm 10'}"
        "],"
      "'default':'0'"
      "},"
      "{"
        "'name':72,"
        "'label':'Spannung Min',"
        "'unit':'V',"
        "'type':4,"
        "'default':48.0,"
        "'min':0,"
        "'max':60"
      "},"
      "{"
        "'name':73,"
        "'label':'Spannung Max',"
        "'unit':'V',"
        "'type':4,"
        "'default':54.0,"
        "'min':0,"
        "'max':60"
      "}"
    "]"
  "}"
"]";


const char paramAlarmTemp[] PROGMEM = "["
  "{"
    "'name':20,"
    "'label':'Temperatur &#220;berwachung,"
    "'label_entry':'&#220;berwachung',"
    "'groupsize':10,"
    "'type':12,"
    "'group':["
      "{"
        "'name':21,"
        "'label':'Sensornummer von',"
        "'type':3,"
        "'default':'',"
        "'min':0,"
        "'max':255"
      "},"
      "{"
        "'name':22,"
        "'label':'Sensornummer bis',"
        "'type':3,"
        "'default':'',"
        "'min':0,"
        "'max':255"
      "},"
      "{"
        "'name':27,"
        "'label':'&Uuml;berwachung',"
        "'type':9,"
        "'options':["
          "{'v':'0','l':'nicht belegt'},"
          "{'v':'1','l':'Maximalwert-&Uuml;berschreitung'},"
          "{'v':'2','l':'Maximalwert-&Uuml;berschreitung (Referenz)'},"
          "{'v':'3','l':'Differenzwert-&Uuml;berwachung'}],"
        "'default':'0',"
        "'help':'Maximalwert-&Uuml;berschreitung: Wert1=Maximale Temperatur\n"
          "Maximalwert-&Uuml;berschreitung (Referenz): Wert1=Temperatur Offset'\n"
          "Differenzwert-&Uuml;berwachung: Wert1=Maximal erlaubte Differenz'"
      "},"
      "{"
        "'name':23,"
        "'label':'Referenzsensor',"
        "'type':3,"
        "'default':'',"
        "'min':0,"
        "'max':255"
      "},"
      "{"
        "'name':24,"
        "'label':'Wert 1',"
        "'type':4,"
        "'default':'',"
        "'min':0,"
        "'max':70"
      "},"
      "{"
        "'name':25,"
        "'label':'Wert 2',"
        "'type':4,"
        "'default':'',"
        "'min':0,"
        "'max':70"
      "},"
      "{"
      "'name':26,"
      "'label':'Ausl&ouml;sung',"
      "'type':9,"
      "'options':["
        "{'v':'0','l':'Aus'},"
        "{'v':'1','l':'Alarm 1'},{'v':'2','l':'Alarm 2'},{'v':'3','l':'Alarm 3'},{'v':'4','l':'Alarm 4'},{'v':'5','l':'Alarm 5'},{'v':'6','l':'Alarm 6'},{'v':'7','l':'Alarm 7'},{'v':'8','l':'Alarm 8'},{'v':'9','l':'Alarm 9'},{'v':'10','l':'Alarm 10'}"
        "],"
      "'default':'0'"
      "}"
    "]"
  "}"
"]";


//Digitalausgang 1..6
const char paramDigitalOut[] PROGMEM = "["
  "{"
    "'label':'Digitalausg&#228;nge',"
    "'label_entry':'Digitalausgang',"
    "'groupsize':6,"
    "'type':12,"
    "'group':["
      "{"
      "'name':30,"
      "'label':'Ausl&#246;severhalten',"
      "'type':9,"
      "'options':["
        "{'v':'0','l':'Permanent'},"
        "{'v':'1','l':'Impuls'}],"
      "'default':'0'"
      "},"
      "{"
        "'name':31,"
        "'label':'Impulsdauer',"
        "'unit':'ms',"
        "'type':3,"
        "'default':500,"
        "'min':100,"
        "'max':10000"
      "},"
      "{"
        "'name':33,"
        "'label':'Verz&ouml;gerung',"
        "'unit':'s',"
        "'type':3,"
        "'default':0,"
        "'min':0,"
        "'max':254"
      "},"
      "{"
      "'name':32,"
      "'label':'Ausl&#246;sung bei',"
      "'type':9,"
      "'options':["
        "{'v':'0','l':'Aus'},"
        "{'v':'1','l':'Alarm 1'},{'v':'2','l':'Alarm 2'},{'v':'3','l':'Alarm 3'},{'v':'4','l':'Alarm 4'},{'v':'5','l':'Alarm 5'},{'v':'6','l':'Alarm 6'},{'v':'7','l':'Alarm 7'},{'v':'8','l':'Alarm 8'},{'v':'9','l':'Alarm 9'},{'v':'10','l':'Alarm 10'}"
        "],"
      "'default':'0'"
      "}"
    "]"
  "}"
"]";


//Digitaleingänge 1..4
const char paramDigitalIn[] PROGMEM = "["
  "{"
    "'label':'Digitaleing&#228;nge',"
    "'label_entry':'Digitaleingang',"
    "'groupsize':4,"
    "'type':12,"
    "'group':["
      "{"
      "'name':34,"
      "'label':'Eingang invertieren',"
      "'type':10,"
      "'default':'0'"
      "},"
      "{"
      "'name':35,"
      "'label':'Weiterleiten an',"
      "'type':9,"
      "'options':["
        "{'v':'0','l':'Aus'},"
        "{'v':'1','l':'Alarm 1'},{'v':'2','l':'Alarm 2'},{'v':'3','l':'Alarm 3'},{'v':'4','l':'Alarm 4'},{'v':'5','l':'Alarm 5'},{'v':'6','l':'Alarm 6'},{'v':'7','l':'Alarm 7'},{'v':'8','l':'Alarm 8'},{'v':'9','l':'Alarm 9'},{'v':'10','l':'Alarm 10'}"
        "],"
      "'default':'0'"
      "}"
    "]"
  "}"
"]";


const char paramOnewireAdr[] PROGMEM = "["
  "{"
  "'name':50,"
  "'label':'Onewire enable',"
  "'type':10,"
  "'default':'0'"
  "},"
  "{"
  "'name':51,"
  "'label':'OW Adr.',"
  "'type':0,"
  "'size':64,"
  "'default':''"
  "}"
  "]";


const char paramOnewire2[] PROGMEM = "["
  "{"
    "'label':'Onewire Sensoren',"
    "'label_entry':'Sensor',"
    "'groupsize':64,"
    "'type':12,"
    "'group':["
      "{"
        "'name':52,"
        "'label':'Offset',"
        "'unit':'&deg;C',"
        "'type':4,"
        "'default':0,"
        "'min':-10,"
        "'max':10"
      "}"
    "]"
  "}"
"]";


//BMS to Inverter
const char paramBmsToInverter[] PROGMEM = "["
  "{"
    "'name':60,"
    "'label':'BMS Canbus enable',"
    "'type':10,"
    "'default':'0'"
  "},"
  "{"
    "'name':2,"
    "'label':'Canbus',"
    "'type':9,"
    "'options':["
      "{'v':'0','l':'nicht belegt'},"
      "{'v':'1','l':'Solis RHI'},"
      "{'v':'2','l':'DEYE'},"
      "{'v':'3','l':'VICTRON'}],"
    "'default':'nb'"
  "},"
  "{"
  "'name':61,"
  "'label':'Datenquelle (Master)',"
  "'type':9,"
  "'options':["
    "{'v':'0','l':'Bluetooth Device 1'},"
    "{'v':'1','l':'Bluetooth Device 2'},"
    "{'v':'2','l':'Bluetooth Device 3'},"
    "{'v':'3','l':'Bluetooth Device 4'},"
    "{'v':'4','l':'Bluetooth Device 5'},"
    "{'v':'5','l':'Bluetooth Device 6'},"
    "{'v':'6','l':'Bluetooth Device 7'},"
    "{'v':'7','l':'Serial Device 1'},"
    "{'v':'8','l':'Serial Device 2'},"
    "{'v':'9','l':'Serial Device 3'}],"
  "'default':'0'"
  "},"
  "{"
    "'name':83,"
    "'label':'& Datenquelle Serial 0',"
    "'type':10,"
    "'default':'0'"
  "},"
  "{"
    "'name':84,"
    "'label':'& Datenquelle Serial 1',"
    "'type':10,"
    "'default':'0'"
  "},"
  "{"
    "'name':85,"
    "'label':'& Datenquelle Serial 2',"
    "'type':10,"
    "'default':'0'"
  "},"
  "{"
    "'name':62,"
    "'label':'Max. Ladespannung',"
    "'unit':'V',"
    "'type':4,"
    "'default':'54.4',"
    "'min':40.0,"
    "'max':58.4"
  "},"
  "{"
    "'name':64,"
    "'label':'Max. Ladestrom',"
    "'unit':'A',"
    "'type':3,"
    "'default':'100',"
    "'min':0,"
    "'max':200"
  "},"
  "{"
    "'name':65,"
    "'label':'Max. Entladestrom',"
    "'unit':'A',"
    "'type':3,"
    "'default':'100',"
    "'min':0,"
    "'max':200"
  "},"
  "{"
    "'name':66,"
    "'label':'Ladeleistung auf 0 bei:',"
    "'type':9,"
    "'options':["
      "{'v':'0','l':'AUS'},"
      "{'v':'1','l':'Alarm 1'},{'v':'2','l':'Alarm 2'},{'v':'3','l':'Alarm 3'},{'v':'4','l':'Alarm 4'},{'v':'5','l':'Alarm 5'},{'v':'6','l':'Alarm 6'},{'v':'7','l':'Alarm 7'},{'v':'8','l':'Alarm 8'},{'v':'9','l':'Alarm 9'},{'v':'10','l':'Alarm 10'}"
      "],"
    "'default':'0'"
  "},"
  "{"
    "'name':67,"
    "'label':'Entladeleistung auf 0 bei:',"
    "'type':9,"
    "'options':["
      "{'v':'0','l':'AUS'},"
      "{'v':'1','l':'Alarm 1'},{'v':'2','l':'Alarm 2'},{'v':'3','l':'Alarm 3'},{'v':'4','l':'Alarm 4'},{'v':'5','l':'Alarm 5'},{'v':'6','l':'Alarm 6'},{'v':'7','l':'Alarm 7'},{'v':'8','l':'Alarm 8'},{'v':'9','l':'Alarm 9'},{'v':'10','l':'Alarm 10'}"
      "],"
    "'default':'0'"
  "},"
  "{"
    "'name':77,"
    "'label':'SOC auf 100 bei:',"
    "'type':9,"
    "'options':["
      "{'v':'0','l':'AUS'},"
      "{'v':'1','l':'Alarm 1'},{'v':'2','l':'Alarm 2'},{'v':'3','l':'Alarm 3'},{'v':'4','l':'Alarm 4'},{'v':'5','l':'Alarm 5'},{'v':'6','l':'Alarm 6'},{'v':'7','l':'Alarm 7'},{'v':'8','l':'Alarm 8'},{'v':'9','l':'Alarm 9'},{'v':'10','l':'Alarm 10'}"
      "],"
    "'default':'0'"
  "},"

  "{"
    "'label':'Batterietemperatur',"
    "'type':13,"
  "},"
  "{"
    "'name':97,"
    "'label':'Quelle',"
    "'type':9,"
    "'options':["
      "{'v':'1','l':'BMS'},"
      "{'v':'2','l':'Onewire'}"
      "],"
    "'default':'1'"
  "},"
  "{"
    "'name':98,"
    "'label':'Sensornummer',"
    "'type':3,"
    "'default':'0',"
    "'min':0,"
    "'max':64,"
    "'help':'Mögliche Wert:\nBMS:0-2\nOnewire:0-63'"
  "},"

  "{"
    "'label':'Zell-Spannungsabhängige Drosselung',"
    "'type':13,"
  "},"
  "{"
    "'name':74,"
    "'label':'Ein/Aus',"
    "'type':10,"
    "'default':'0'"
  "},"
  "{"
    "'name':75,"
    "'label':'Starten bei Zellspg. gr&ouml;ßer',"
    "'unit':'mV',"
    "'type':3,"
    "'default':'3325',"
    "'min':2500,"
    "'max':5000"
  "},"
  "{"
    "'name':76,"
    "'label':'Maximale Zellspannung',"
    "'unit':'mV',"
    "'type':3,"
    "'default':'3300',"
    "'min':2500,"
    "'max':5000"
  "},"
  "{"
    "'name':78,"
    "'label':'Mindest Ladestrom',"
    "'unit':'A',"
    "'type':3,"
    "'default':'5',"
    "'min':0,"
    "'max':200"
  "},"
  "{"
    "'label':'Ladestrom reduzieren bei Zelldrift',"
    "'type':13,"
  "},"
  "{"
    "'name':68,"
    "'label':'Ein/Aus',"
    "'type':10,"
    "'default':'0'"
  "},"
  "{"
    "'name':71,"
    "'label':'Starten bei Zellspg. gr&ouml;ßer',"
    "'unit':'mV',"
    "'type':3,"
    "'default':'3400',"
    "'min':2500,"
    "'max':5000"
  "},"
  "{"
    "'name':69,"
    "'label':'Starten bei Drift gr&ouml;ßer',"
    "'unit':'mV',"
    "'type':3,"
    "'default':'10',"
    "'min':1,"
    "'max':200"
  "},"
  "{"
    "'name':70,"
    "'label':'Reduzierung pro mV Abweichung',"
    "'unit':'A',"
    "'type':3,"
    "'default':'1',"
    "'min':1,"
    "'max':200"
  "},"

  //Ladestrom reduzieren ab bestimmten SoC
  "{"
    "'label':'Ladesstrom reduzieren - SoC',"
    "'type':13,"
  "},"
  "{"
    "'name':79,"
    "'label':'Ein/Aus',"
    "'type':10,"
    "'default':'0'"
  "},"
  "{"
    "'name':80,"
    "'label':'Reduzierung ab SoC',"
    "'unit':'%',"
    "'type':3,"
    "'default':'98',"
    "'min':1,"
    "'max':99"
  "},"
  "{"
    "'name':81,"
    "'label':'Pro 1% um x A reduzieren',"
    "'unit':'A',"
    "'type':3,"
    "'default':'48',"
    "'min':1,"
    "'max':100"
  "},"  

  //Bei unterschreiten von Zellspannung melde SoC x% 
  "{"
    "'label':'SoC beim Unterschreiten der Zellspannung',"
    "'type':13,"
    "'help':'Wenn die eingestellte Zellspannung für den Ladebeginn unterschritten wird, dann kann durch das senden eines beliebigen SoC an den Wechselrichter ein Nachladen veranlasst werden.\n"
      "Es wird so lange nachgeladen, bis die Zellspannung Ladeende überschritten wird.'"
  "},"
  "{"
    "'name':88,"
    "'label':'Ein/Aus',"
    "'type':10,"
    "'default':'0'"
  "},"
  "{"
    "'name':89,"
    "'label':'Zellspannung Ladebeginn',"
    "'unit':'mV',"
    "'type':3,"
    "'default':'3000',"
    "'min':2500,"
    "'max':4000"
  "},"
  "{"
    "'name':92,"
    "'label':'Zellspannung Ladeende',"
    "'unit':'mV',"
    "'type':3,"
    "'default':'0',"
    "'min':0,"
    "'max':4000,"
    "'help':'Wenn Zellspannung Ladeende 0, dann wird geladen, bis die Zellspannung Ladebeginn wieder überschritten wird.'"
  "},"
  "{"
    "'name':90,"
    "'label':'SoC',"
    "'unit':'%',"
    "'type':3,"
    "'default':'9',"
    "'min':1,"
    "'max':100"
  "},"  
  "{"
    "'name':91,"
    "'label':'Sperrzeit zwischen zwei Nachladungen',"
    "'unit':'s',"
    "'type':3,"
    "'default':'600',"
    "'min':0,"
    "'max':3600"
  "}," 

  /* Wenn eine Zelle z.B. >3.4V ist und das Delta zwischen größter und kleinster größer als z.B. 5mV ist, 
  dann Ladespannung reduzieren. */
  "{"
    "'label':'Dynamische Ladespannungsbegrenzung (Beta!)',"
    "'type':13,"
    "'help':'Sobald die Spannung einer Zelle und das Delta zwischen der niedrigsten und der höchsten Zellenspannung größer als eingestellt werden, "
      "wird die Ladespannung dynamisch angepasst, um die maximale Ladeleistung zu erreichen, ohne dass die Zellen weiter auseinander driften.'"
  "},"
  "{"
    "'name':93,"
    "'label':'Ein/Aus',"
    "'type':10,"
    "'default':'0'"
  "},"
  "{"
    "'name':94,"
    "'label':'Start-Zellspannung',"
    "'unit':'mV',"
    "'type':3,"
    "'default':'3400',"
    "'min':2000,"
    "'max':4000"
  "},"
  "{"
    "'name':95,"
    "'label':'Spg.-Delta Min/Max',"
    "'unit':'mV',"
    "'type':3,"
    "'default':'5',"
    "'min':1,"
    "'max':100"
  "},"

//Sperrzeit einstellbar
  "{"
    "'label':'Sonstiges',"
    "'type':13,"
  "},"
  "{"
    "'name':82,"
    "'label':'Sperrzeit wenn Ladestrom 0',"
    "'unit':'s',"
    "'type':3,"
    "'default':'1800',"
    "'min':0,"
    "'max':65000"
  "}"
  "]";

