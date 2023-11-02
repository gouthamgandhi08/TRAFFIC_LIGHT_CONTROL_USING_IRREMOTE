#include <TM1637Display.h>
#include <IRremote.h>
const byte IR_RECEIVE_PIN=19;
#define CLK1 A0
#define DIO1 A1
#define CLK2 A2
#define DIO2 A3
#define CLK3 A4
#define DIO3 A5
#define CLK4 14
#define DIO4 15
#define RED1 11
#define ORANGE1 12
#define GREEN1 17
#define RED2 8
#define ORANGE2 9
#define GREEN2 10
#define RED3 5
#define ORANGE3 6
#define GREEN3 7
#define RED4 2
#define ORANGE4 3
#define GREEN4 4
TM1637Display display1 = TM1637Display(CLK1, DIO1);
TM1637Display display2 = TM1637Display(CLK2, DIO2);
TM1637Display display3 = TM1637Display(CLK3, DIO3);
TM1637Display display4 = TM1637Display(CLK4, DIO4);
volatile boolean ledON=false;

void setup() {
 
  pinMode(RED4 , OUTPUT);
  pinMode(ORANGE4, OUTPUT);
  pinMode(GREEN4, OUTPUT);
  pinMode(RED3, OUTPUT);
  pinMode(ORANGE3, OUTPUT);
  pinMode(GREEN3, OUTPUT);
  pinMode(RED2, OUTPUT);
  pinMode(ORANGE2, OUTPUT);
  pinMode(GREEN2 , OUTPUT);
  pinMode(RED1, OUTPUT);
  pinMode(ORANGE1, OUTPUT);
  pinMode(GREEN1, OUTPUT);
  IrReceiver.begin(IR_RECEIVE_PIN,ENABLE_LED_FEEDBACK);
  display2.clear();
  display1.clear();
  display3.clear();
  display4.clear();

}
void loop() 

{
  // Set the brightness:
  display1.setBrightness(7);
  display2.setBrightness(7);
  display3.setBrightness(7);
  display4.setBrightness(7);
  int i;
 
  for (i = 10; i>0; i--) {
    display1.showNumberDec(i);
    display2.showNumberDec(i+5);
    display3.showNumberDec(i+20);
    display4.showNumberDec(i+35);
    digitalWrite(GREEN1, HIGH);
    digitalWrite(GREEN2,0);
    digitalWrite(GREEN3,0);
    digitalWrite(GREEN4,0);
    digitalWrite(RED4 ,HIGH);
    digitalWrite(RED3,HIGH);
    digitalWrite(RED2,HIGH);
    digitalWrite(RED1,0);
    digitalWrite(ORANGE4,LOW);
    buttonpress();
    delay(1000);
    }
  for (i = 5; i>0; i--) {
    display1.showNumberDec(i);
    display2.showNumberDec(i);
    display3.showNumberDec(i+15);
    display4.showNumberDec(i+30);
    digitalWrite(ORANGE1,HIGH);
    digitalWrite(RED1,0);
    digitalWrite(GREEN1,LOW);
    digitalWrite(GREEN2,0);
    digitalWrite(GREEN3,0);
    digitalWrite(GREEN4,0);
     buttonpress();
    delay(1000);
  }
  for (i = 10; i>0; i--) {
    display1.showNumberDec(i+35);
    display2.showNumberDec(i);
    display3.showNumberDec(i+5);
    display4.showNumberDec(i+20);
    digitalWrite(ORANGE1,LOW);
    digitalWrite(RED1,HIGH);
    digitalWrite(GREEN2 ,HIGH);
    digitalWrite(GREEN1,0);
    digitalWrite(GREEN3,0);
    digitalWrite(GREEN4,0);
    digitalWrite(RED2,LOW);
     buttonpress();
    delay(1000);
  }
  for (i = 5; i>0; i--) {
    display1.showNumberDec(i+30);
    display2.showNumberDec(i);
    display3.showNumberDec(i);
    display4.showNumberDec(i+15);
    digitalWrite(GREEN2 ,LOW);
    digitalWrite(RED2,0);
    digitalWrite(GREEN1,0);
    digitalWrite(GREEN3,0);
    digitalWrite(GREEN4,0);
    digitalWrite(ORANGE2,HIGH);
     buttonpress();
    delay(1000);
  }
  for (i = 10; i>0; i--) {
    display1.showNumberDec(i+20);
    display2.showNumberDec(i+35);
    display3.showNumberDec(i);
    display4.showNumberDec(i+5);
    digitalWrite(ORANGE2,LOW);
    digitalWrite(RED2,HIGH);
    digitalWrite(GREEN3,HIGH);
    digitalWrite(GREEN2,0);
    digitalWrite(GREEN1,0);
    digitalWrite(GREEN4,0);
    digitalWrite(RED3,LOW);
     buttonpress();
    delay(1000);
    }
  for (i = 5; i>0; i--) {
    display1.showNumberDec(i+15);
    display2.showNumberDec(i+30);
    display3.showNumberDec(i);
    display4.showNumberDec(i);
    digitalWrite(GREEN3,LOW);
    digitalWrite(GREEN2,0);
    digitalWrite(GREEN1,0);
    digitalWrite(GREEN4,0);
    digitalWrite(ORANGE3,HIGH);
    digitalWrite(RED3,LOW);
    buttonpress();
    delay(1000);
  }
   for (i = 10; i>0; i--) {
    display1.showNumberDec(i+5);
    display2.showNumberDec(i+20);
    display3.showNumberDec(i+35);
    display4.showNumberDec(i);
    digitalWrite(ORANGE3,LOW);
    digitalWrite(RED3,HIGH);
    digitalWrite(GREEN4,HIGH);
    digitalWrite(GREEN2,0);
    digitalWrite(GREEN3,0);
    digitalWrite(GREEN1,0);
    digitalWrite(RED4 ,LOW);
     buttonpress();
    delay(1000);
    }
  for (i = 5; i>0; i--) {
    display1.showNumberDec(i);
    display2.showNumberDec(i+15);
    display3.showNumberDec(i+30);
    display4.showNumberDec(i);
    digitalWrite(GREEN4,LOW);
    digitalWrite(GREEN2,0);
    digitalWrite(GREEN3,0);
    digitalWrite(GREEN1,0);
    digitalWrite(ORANGE4,HIGH);
    digitalWrite(RED4 ,LOW);
     buttonpress();
    delay(1000);
  }

}
void buttonpress()
{
  int buttonstatus=digitalRead(IR_RECEIVE_PIN);
    if (IrReceiver.decode())
 {
  String ir_code=String(IrReceiver.decodedIRData.command,HEX);
 
  if (buttonstatus==1)
  {

  if(ir_code=="10")
  {
   for(int j=0;j<20;j++)
   { 
    digitalWrite(GREEN1,1);
    digitalWrite(RED2,1);
    digitalWrite(RED3,1);
    digitalWrite(RED4,1);
    digitalWrite(GREEN2,0);
    digitalWrite(ORANGE1,0);
    digitalWrite(ORANGE2,0);
    digitalWrite(GREEN4,0);
    digitalWrite(GREEN3,0);
    digitalWrite(ORANGE3,0);
    digitalWrite(RED1,0);
    digitalWrite(ORANGE4,0);
    delay(1000);
    
   }  
  }
  else if(ir_code=="18")
  {
  for(int j=0;j<20;j++) 
  {
    digitalWrite(GREEN1,0);
    digitalWrite(RED2,0);
    digitalWrite(RED3,1);
    digitalWrite(RED4,1);
    digitalWrite(GREEN2,1);
    digitalWrite(ORANGE1,0);
    digitalWrite(ORANGE2,0);
    digitalWrite(GREEN4,0);
    digitalWrite(GREEN3,0);
    digitalWrite(ORANGE3,0);
    digitalWrite(RED1,1);
    digitalWrite(ORANGE4,0);
 
    delay (1000);
  }
  }
  else if (ir_code=="5a")
  {
  for(int j=0;j<20;j++) 
  {
    digitalWrite(GREEN1,0);
    digitalWrite(RED2,1);
    digitalWrite(RED3,0);
    digitalWrite(RED4,1);
    digitalWrite(GREEN2,0);
    digitalWrite(ORANGE1,0);
    digitalWrite(ORANGE2,0);
    digitalWrite(GREEN4,0);
    digitalWrite(GREEN3,1);
    digitalWrite(ORANGE3,0);
    digitalWrite(RED1,1);
    digitalWrite(ORANGE4,0);
    delay(1000);
  }
  }
  else if (ir_code=="4a")
  {
  for(int j=0;j<20;j++) 
  {
    digitalWrite(GREEN1,0);
    digitalWrite(RED2,1);
    digitalWrite(RED3,1);
    digitalWrite(RED4,0);
    digitalWrite(GREEN2,0);
    digitalWrite(ORANGE1,0);
    digitalWrite(ORANGE2,0);
    digitalWrite(GREEN4,1);
    digitalWrite(GREEN3,0);
    digitalWrite(ORANGE3,0);
    digitalWrite(RED1,1);
    digitalWrite(ORANGE4,0);
    delay(1000);
  }
  }
  IrReceiver.resume();
 }
 }
}
