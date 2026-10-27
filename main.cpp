#define ledgreenA1 4
#define ledyellowA2 3
#define ledredA3 2

#define ledgreenB1 7
#define ledyellowB2 6
#define ledredB3 5

#define ledgreenC1 10
#define ledyellowC2 9
#define ledredC3 8

#define ledgreenD1 13
#define ledyellowD2 12
#define ledredD3 11 


int sensorValue = 0; 
int a1,a2,b1 ,b2, c, d; 
int k=0;int l=0;int m=0;int n=0;int da1,da2,db1,db2,dc,dd;


void readSensor()
{
  a1 = analogRead(A0);

  a2 = analogRead(A1);
  
  b1 = analogRead(A2);
  
  b2 = analogRead(A3);
  
  c = analogRead(A4);
  
  d = analogRead(A5);
  

if (a1 < 100) k=18000;
else if (a2 < 60) k=8000;else  k=4000;
if (b1 < 100) l=18000;
else if (b2 < 100) l= 8000; else l = 4000;
if (c < 100) m = 8000; else m = 4000; 
if (d < 100) n = 8000; else n = 4000; 

Serial.print(a1);
Serial.print("\t");
Serial.print(a2);
Serial.print("\t");
Serial.print(b1);
Serial.print("\t");
Serial.print(b2);
Serial.print("\t");
Serial.print(c);
Serial.print("\t");
Serial.print(d);
Serial.print("\t");
Serial.println("\t");

}


void setup() {

  Serial.begin(9600);

  pinMode(ledgreenA1, OUTPUT);
  pinMode(ledyellowA2, OUTPUT);
  pinMode(ledredA3, OUTPUT);

  pinMode(ledgreenB1, OUTPUT);
  pinMode(ledyellowB2, OUTPUT);
  pinMode(ledredB3, OUTPUT);

  pinMode(ledgreenC1, OUTPUT);
  pinMode(ledyellowC2, OUTPUT);
  pinMode(ledredC3, OUTPUT);

  pinMode(ledgreenD1, OUTPUT);
  pinMode(ledyellowD2, OUTPUT);
  pinMode(ledredD3, OUTPUT);


}

void loop()
{

readSensor();

//normal working of traffic 
//a is green
digitalWrite(ledgreenD1,LOW);
digitalWrite(ledredA3,LOW);
digitalWrite(ledyellowD2,LOW);
digitalWrite(ledyellowA2,LOW);
digitalWrite(ledgreenA1,HIGH);
digitalWrite(ledredB3,HIGH);
digitalWrite(ledredC3,HIGH);
digitalWrite(ledredD3,HIGH);
delay(k);//after delay of 8 sec
digitalWrite(ledyellowA2,HIGH);
digitalWrite(ledyellowB2,HIGH);
delay(2000);

//b is green
digitalWrite(ledyellowA2,LOW);
digitalWrite(ledyellowB2,LOW);
digitalWrite(ledgreenA1,LOW);
digitalWrite(ledredB3,LOW);
digitalWrite(ledgreenB1,HIGH);
digitalWrite(ledredA3,HIGH);
delay(l);//after delay of 8 sec
digitalWrite(ledyellowB2,HIGH);
digitalWrite(ledyellowC2,HIGH);
delay(2000);

//c is green
digitalWrite(ledredC3,LOW);
digitalWrite(ledgreenB1,LOW);
digitalWrite(ledyellowB2,LOW);
digitalWrite(ledyellowC2,LOW);
digitalWrite(ledgreenC1,HIGH);
digitalWrite(ledredB3,HIGH);
delay(m);//after delay of 8 sec
digitalWrite(ledyellowC2,HIGH);
digitalWrite(ledyellowD2,HIGH);
delay(2000);

//d is green
digitalWrite(ledyellowC2,LOW);
digitalWrite(ledyellowD2,LOW);
digitalWrite(ledgreenC1,LOW);
digitalWrite(ledredD3,LOW);
digitalWrite(ledgreenD1,HIGH);
digitalWrite(ledredC3,HIGH);
delay(n);//after delay of 8 sec
digitalWrite(ledyellowA2,HIGH);
digitalWrite(ledyellowD2,HIGH);
delay(2000);


}
