#include <SoftwareSerial.h>
#include <Keypad.h>

const int trigPin1 = 2 ; 
const int echoPin1 = 3 ; 
const int trigPin2 = 4 ; 
const int echoPin2 = 5 ; 
const int trigPin3 = 6 ; 
const int echoPin3 = 7 ; 

long duration1 ; 
int distance1 ; 
long duration2 ; 
int distance2 ; 
long duration3 ; 
int distance3 ; 
char x[1],y[1],z[1];
const byte numRows= 3;

const byte numCols= 3;

char keymap[numRows][numCols]= { {'1', '2', '3'},{'4', '5', '6'},{'7', '8', '9'}};

byte rowPins[numRows] = {13,12,11}; //Rows 0 to 3

byte colPins[numCols]= {10,9,8}; //Columns 0 to 3
Keypad myKeypad= Keypad(makeKeymap(keymap), rowPins, colPins, numRows, numCols);

char out[7];

SoftwareSerial asw(19,18) ;  


void setup(){
 Serial.begin(115200);
 asw.begin(115200);
 pinMode(trigPin1 , OUTPUT) ; 
 pinMode(echoPin1 , INPUT) ;
 Serial.begin(115200) ;
 pinMode(trigPin2 , OUTPUT) ; 
 pinMode(echoPin2 , INPUT) ; 
 Serial.begin(115200) ;
 pinMode(trigPin3 , OUTPUT) ; 
 pinMode(echoPin3 , INPUT) ; 
 Serial.begin(115200) ;
 Serial.print(char(170)); // Copyright Symbol
 Serial.println(" Setup Complete ");
  out[3]='0';
  out[4]='0';
  out[5]='0';
  out[6]='0';
  out[7]='0';
 delay(2000);
}


void loop()
{
  digitalWrite(trigPin1 , LOW) ;
  delayMicroseconds(2) ; 
  digitalWrite(trigPin1, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin1, LOW);
  duration1 = pulseIn(echoPin1, HIGH);
  distance1= duration1*0.034/2;

  digitalWrite(trigPin2 , LOW) ;
  delayMicroseconds(2) ; 
  digitalWrite(trigPin2, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin2, LOW);
  duration2 = pulseIn(echoPin2, HIGH);
  distance2= duration2*0.034/2;


  digitalWrite(trigPin3 , LOW) ;
  delayMicroseconds(2) ; 
  digitalWrite(trigPin3, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin3, LOW);
  duration3 = pulseIn(echoPin3, HIGH);
  distance3= duration3*0.034/2;

  
  
  if(distance1 < 10){
    //Serial.println("Slot 1 Occupied");
    x[0] = '1' ;
    }
  else{
    //Serial.println("Slot 1 empty");
    x[0] = '0' ;
    }

  if(distance2 < 10){
    //Serial.println("Slot 2 Occupied");
    y[0] = '1' ;
    }
  else{
   // Serial.println("Slot 2 empty");
    y[0] = '0' ;
    }

  if(distance3 < 10){
    //Serial.println("Slot 3 Occupied");
    z[0] = '1' ;
    }
  else{
    //Serial.println("Slot 3 empty");
    z[0] = '0' ;
    }

  out[0]=x[0];
  out[1]=y[0];
  out[2]=z[0];
  
  


    //asw.rite(str);
  int i=0;
  char keypressed = myKeypad.getKey();
  if(keypressed != NO_KEY)
  { 
    Serial.println(keypressed);
    out[i+3]=keypressed;
  i++;
  while(i<4){
    char keypressed = myKeypad.getKey();
  if (keypressed != NO_KEY){
  Serial.println(keypressed);
  out[i+3]=keypressed;
  i++;
  }
  }
  }
    asw.write(out , 8);
      
  Serial.println(out[0]);
  Serial.println(out[1]);
  Serial.println(out[2]);
  Serial.println(out[3]);
  Serial.println(out[4]);
  Serial.println(out[5]);
  Serial.println(out[6]);
  Serial.println("done");
  delay(1000);
}
