
#include <ESP8266WiFi.h>
#include <FirebaseArduino.h>
#include<SoftwareSerial.h> 
// Set these to run example.
#define FIREBASE_HOST "parking-f9d18.firebaseio.com"
#define FIREBASE_AUTH "UBnCGDLQepu1LsKwug08899o1dYH0r8Fox2Kenel"
#define WIFI_SSID "wifihots"
#define WIFI_PASSWORD "12345678"
String otp="1234";
char out[7] ;
void setup() {
  // Open serial communications and wait for port to open:
  Serial.begin(115200);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB port only
  }



  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  Serial.print("connecting");
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(500);
  }
  Serial.println();
  Serial.print("connected: ");
  Serial.println(WiFi.localIP());
  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
  Firebase.set("ultrasonic","");

  
}

void loop() { // run over and over
  if (Serial.available()) {
    /*otp[0]='1';
    otp[1]='2';
    otp[2]='3';
    otp[3]='4';*/
      
    ///x =x Serial.read() ;
  Serial.readBytes(out , 8) ;out[7]='0';
  char ultra[6];
  ultra[0]=out[0];
  ultra[1]=out[1];
  ultra[2]=out[2];
  ultra[3]=out[3];
  ultra[4]=out[4];
  ultra[5]=out[5];
  ultra[6]=out[6];
  Serial.println(ultra);
  //Serial.write(otp,4);
  Firebase.set("ultrasonic",ultra);
  //otp=Firebase.getString("otp");
  Serial.println(otp);
  if(otp[0]==out[3] && otp[1]==out[4] && otp[2]==out[5] && otp[3]==out[6])
  {
    Serial.println("OTP VERIFIED");
  }
  }
}
