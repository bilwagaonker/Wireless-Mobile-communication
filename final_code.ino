#include <Keypad.h>
#include <LiquidCrystal.h>
#include <Servo.h>
#include <SoftwareSerial.h>

SoftwareSerial SIM800(1,0);

Servo myservo;
int pos=0;
LiquidCrystal lcd(A0,A1,A2,A3,A4,A5);
const byte rows=4;
const byte cols=4;

char key[rows][cols]={
{'1', '2', '3', 'A'},
{'4', '5', '6', 'B'},
{'7', '8', '9', 'C'},
{'*', '0', '#', 'D'}
};
byte rowPins[rows]={9,8,7,6};
byte colPins[cols]={5,4,3,2};
Keypad keypad= Keypad(makeKeymap(key),rowPins,colPins,rows,cols);
char* password="A1B2C3"; //password of your choice
int currentposition=0;
int buzz=11;
int invalidcount=0;
int alarm=0;
void setup()
{
displayscreen();
Serial.begin(9600);
SIM800.begin(2400);
delay(100);
SIM800.println("AT+CMGF=1");    
delay(1000);  
SIM800.println("AT+CMGS=\"+918975185333\"\r"); 
delay(1000);
pinMode(buzz, OUTPUT);
myservo.attach(10);
lcd.begin(16,2);
}
void loop()
{ 
if(currentposition==0 && alarm==0)
{
lcd.clear();  
displayscreen();
}
else if(alarm==1)
{
  lcd.clear();
  accessdenied();
}

int l ;
char code=keypad.getKey();
if(code!=NO_KEY)
{
lcd.clear();
lcd.setCursor(0,0);
lcd.print("PASSWORD:");
lcd.setCursor(7,1);
lcd.print(" ");
lcd.setCursor(7,1);
for(l=0;l<=currentposition;++l)
{
lcd.print("*");
keypress();
}

if (code==password[currentposition])
{
++currentposition;
if(currentposition==6)
{
lcd.clear();
unlockdoor();
currentposition=0;
}
}

else
{
lcd.clear();
++invalidcount;
incorrect();
currentposition=0;
}
if(invalidcount==2)
{
++invalidcount;
torture1();
accessdenied();


}
}
}
void unlockdoor()
{
delay(900);

lcd.setCursor(0,0);
lcd.println(" ");
lcd.setCursor(1,0);
lcd.print("Access Granted");
lcd.setCursor(4,1);
lcd.println("WELCOME!!");
lcd.setCursor(15,1);
lcd.println(" ");
lcd.setCursor(16,1);
lcd.println(" ");
lcd.setCursor(14,1);
lcd.println(" ");
lcd.setCursor(13,1);
lcd.println(" ");
unlockbuzz();

for(pos = 90; pos>=0; pos-=5) 
{
myservo.write(pos); 
delay(5); 
}
delay(2000);

delay(1000);
counterbeep();

delay(1000);

for(pos = 0; pos <= 90; pos +=5) 
{
myservo.write(pos); 
delay(15);
currentposition=0;
lcd.clear();
displayscreen();
}
}

void incorrect()
{
delay(500);
lcd.clear();
lcd.setCursor(1,0);
lcd.print("Code");
lcd.setCursor(6,0);
lcd.print("Wrong");
lcd.setCursor(15,1);
lcd.println(" ");

lcd.setCursor(13,1);
lcd.println(" ");
digitalWrite(buzz, HIGH);
delay(1000);
lcd.clear();
digitalWrite(buzz,LOW);
displayscreen();
}
void accessdenied()
{
  lcd.clear();
  lcd.setCursor(0,1);
  lcd.print("Max attempts");
  lcd.setCursor(1,0);
  lcd.print("ACCESS DENIED");
  myservo.detach();
  SendMessage();
  invalidcount=0;
  alarm=1;
  currentposition=-1;
}
void clearscreen()
{
lcd.setCursor(0,0);
lcd.println(" ");
lcd.setCursor(0,1);
lcd.println(" ");
lcd.setCursor(0,2);
lcd.println(" ");
lcd.setCursor(0,3);
lcd.println(" ");
}

void keypress()
{
digitalWrite(buzz, HIGH);
delay(50);
digitalWrite(buzz, LOW);
}

void displayscreen()
{
  
lcd.setCursor(0,0);
lcd.print("Enter");
lcd.setCursor(0,1); 
lcd.println("the Password");
}

void armservo()
{

for (pos=180;pos<=180;pos+=50)
{
myservo.write(pos);
delay(5);
}
delay(5000);

for(pos=180;pos>=0;pos-=50)
{
myservo.write(pos);
}

}
void unlockbuzz()
{

digitalWrite(buzz, HIGH);
delay(80);
digitalWrite(buzz, LOW);
delay(80);
digitalWrite(buzz, HIGH);
delay(80);
digitalWrite(buzz, LOW);
delay(200);
digitalWrite(buzz, HIGH);
delay(80);
digitalWrite(buzz, LOW);
delay(80);
digitalWrite(buzz, HIGH);
delay(80);
digitalWrite(buzz, LOW);
delay(80);
}

void counterbeep()
{
delay(1200);
lcd.clear();
digitalWrite(buzz, HIGH);

lcd.setCursor(2,15);
lcd.println(" ");
lcd.setCursor(2,14);
lcd.println(" ");
lcd.setCursor(2,0);
delay(200);
lcd.println("GET IN WITHIN:::");

lcd.setCursor(4,1);
lcd.print("5");
delay(200);
lcd.clear();
lcd.setCursor(2,0);
lcd.println("GET IN WITHIN:");
digitalWrite(buzz,LOW);
delay(1000);
//2
digitalWrite(buzz, HIGH);
lcd.setCursor(2,0);
lcd.println("GET IN WITHIN:");
lcd.setCursor(4,1); //2
lcd.print("4");
delay(100);
lcd.clear();
lcd.setCursor(2,0);
lcd.println("GET IN WITHIN:");
digitalWrite(buzz,LOW);
delay(1000);
//3
digitalWrite(buzz, HIGH);
lcd.setCursor(2,0);
lcd.println("GET IN WITHIN:");
lcd.setCursor(4,1); //3
lcd.print("3");
delay(100);
lcd.clear();
lcd.setCursor(2,0);
lcd.println("GET IN WITHIN:");
digitalWrite(buzz,LOW);
delay(1000);
//4
digitalWrite(buzz, HIGH);
lcd.setCursor(2,0);
lcd.println("GET IN WITHIN:");
lcd.setCursor(4,1); //4
lcd.print("2");
delay(100);
lcd.clear();
lcd.setCursor(2,0);
lcd.println("GET IN WITHIN:");
digitalWrite(buzz,LOW);
delay(1000);
//
digitalWrite(buzz, HIGH);
lcd.setCursor(4,1);
lcd.print("1");
delay(100);
lcd.clear();
lcd.setCursor(2,0);
lcd.println("GET IN WITHIN::");
digitalWrite(buzz,LOW);
delay(1000);
//5
digitalWrite(buzz, HIGH);
delay(40);
digitalWrite(buzz,LOW);
delay(40);
digitalWrite(buzz, HIGH);
delay(40);
digitalWrite(buzz,LOW);
delay(40);
digitalWrite(buzz, HIGH);
delay(40);
digitalWrite(buzz,LOW);
delay(40);
digitalWrite(buzz, HIGH);
delay(40);
digitalWrite(buzz,LOW);
lcd.clear();
lcd.setCursor(2,0);
lcd.print("RE-LOCKING");
delay(500);
lcd.setCursor(12,0);
lcd.print(".");
delay(500);
lcd.setCursor(13,0);
lcd.print(".");
delay(500);
lcd.setCursor(14,0);
lcd.print(".");
delay(400);
lcd.clear();
lcd.setCursor(4,0);
lcd.print("LOCKED!");
delay(440);
}
void torture1()
{
delay(1000);
lcd.clear();
lcd.setCursor(2,0);
lcd.print("INTRUDER");
lcd.setCursor(5,1);
lcd.print("ALERT");
digitalWrite(buzz, HIGH);
delay(5000);
digitalWrite(buzz, LOW);
lcd.clear();
}
void SendMessage()
{
  SIM800.println("AT+CMGF=1");    
  delay(1000);  
  SIM800.println("AT+CMGS=\"**********\"\r"); //add the phone number of the SIM inserted in the GSM Module
  delay(1000);
  SIM800.println("Intruder at the door; call security");
  delay(100);
  SIM800.println((char)26);
  delay(1000);
}

