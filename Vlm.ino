/*for nano*/




#include <Keypad.h>
int  flr,floorchose,fr,start;
void uprear(void);
void upfront(void);
void up(void);
void downrear(void);
void downfront(void);
void down(void);
void front(void);
void rear(void);
void flapup(void);
void flapdown(void);
void toget(void);
void store(void);
int seven_seg[] = {3,2,7,8,9,4,5,6};/*edit here*/
int num_array[10][7] = {{ 1, 1, 1, 1, 1, 1, 0 },  // 0
                        { 0, 1, 1, 0, 0, 0, 0 },  // 1
                        { 1, 1, 0, 1, 1, 0, 1 },  // 2
                        { 1, 1, 1, 1, 0, 0, 1 },  // 3
                        { 0, 1, 1, 0, 0, 1, 1 },  // 4
                        { 1, 0, 1, 1, 0, 1, 1 },  // 5
                        { 1, 0, 1, 1, 1, 1, 1 },  // 6
                        { 1, 1, 1, 0, 0, 0, 0 },  // 7
                        { 1, 1, 1, 1, 1, 1, 1 },  // 8
                        { 1, 1, 1, 1, 0, 1, 1 }}; // 9

const byte ROWS = 4; //four rows
const byte COLS = 4; //four columns
char keys[ROWS][COLS] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};
byte rowPins[ROWS] = { 9,8,7,6}; //connect to the row pinouts of the keypad
byte colPins[COLS] = {5,4,3,2}; //connect to the column pinouts of the keypad
//Create an object of keypad
Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );
void setup(){
  Serial.begin(9600);
  flr=5;
  //DDRD = B11111111; // set PORTD (digital 7~0) to outputs
  /*pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);*/
}
 
void loop(){
  /*digitalWrite(2, 0);
  digitalWrite(3, 0);
  digitalWrite(4, 0);
  digitalWrite(5, 0);*/
  
    char key;
  digitalWrite(A0, 1);
  delay(5000);
    digitalWrite(A0, 0);
  digitalWrite(A1, 0);
  delay(5000);
key=0;
  for (int i = 0; i <= 8; i++) {    pinMode(seven_seg[i], OUTPUT);  }
  digitalWrite(A6, 1);
while(1-(key>=48 && key<=57))
{
  key= int(keypad.getKey());
}
  floorchose=int(key)-48;
  
  Serial.print("florr : ");
  Serial.println(floorchose);
  
  key=0;
while(1-(key==65 || key==66))
{
  key= int(keypad.getKey());
}
  if(key==65){fr=1;}
  if(key==66){fr=0;}
  
  Serial.print("side : ");
  Serial.println(fr);
  key=0;
  while(1-(key==35))
{
  key= int(keypad.getKey());
}
  Serial.print("done ");
  key=0;
  digitalWrite(A6, 0);
  printNumber(floorchose);
  if(fr==0){digitalWrite(A4, 0);}
  delay(3000);
 toget();
 digitalWrite(A6, 1);
 for (int i = 0; i <= 8; i++) {pinMode(seven_seg[i], INPUT);}
while(1-(key==35))
{
  key= int(keypad.getKey());
}
digitalWrite(A6, 0);
Serial.print("done ");
 store();
PORTD=0;
flr=floorchose;
  
}
void printNumber(int number) {
  for (int i = 0; i <= 8; i++) {
    pinMode(seven_seg[i], OUTPUT);
  }
  int pin;
  for (int j = 0; j < 8; j++) {
    pin = seven_seg[j];
    digitalWrite(pin,num_array[number][j]);
  }
 
}
void toget(void)
{
  unsigned char togofloor,u;
 signed char difference;
 togofloor=floorchose;
 difference=flr-togofloor;
 difference=togofloor-flr;
 if(difference>0)/*add to choose cloumn*/
  {
    u=1;
   up();
  }
 else if(difference<0)
  {u=0;
   difference=~difference;
    difference=difference+1;
   down();
  }
  for(;;)
  {
    if(u==1){printNumber(togofloor-difference);}
   else{printNumber(togofloor+difference);}
    
    Serial.println(difference);
    /*PORTA=difference;*/
   if(difference==0) break;
   difference=difference-1;
delay(5000);/*delay floor*/
  }
  flr=togofloor;
  /*P3=flr;*/
 if(fr==0)rear();
  else  front();
  delay(5000);/*delay for rear front*/
  if(fr==0)front();
  else  rear();
  delay(5000);
  togofloor=5;/*reach surface*/
  difference=togofloor-flr;
  if(difference>0)
  {u=1;
   up();
  }
  else if(difference<0)
  {u=0;
   down();
   difference=~difference;
    difference=difference+1;
  }
  for(;;)
  {if(u==1){printNumber(togofloor-difference);}
   else{printNumber(togofloor+difference);}
   if(difference==0) break;
   difference=difference-1;
   delay(5000);/*delay updown*/
  }
 
  front();
  flr=5;
  delay(5000);/*delay for front*/
  PORTD=0;

 }
void store(void)
{
  unsigned char togofloor,u;
 signed char difference;
 rear();
delay(5000); /*delay rear*/
 togofloor=floorchose;
 difference=togofloor-flr;
  if(difference>0)
  {u=1;
   up();
  }
  else if(difference<0)
  {u=0;
   down();
   difference=~difference;
    difference=difference+1;
  }
  for(;;)
  {if(u==1){printNumber(togofloor-difference);}
   else{printNumber(togofloor+difference);}
    if(difference==0) break;
   delay(5000);/*delay updown*/
   difference=difference-1;
  }
  if(fr==0)rear();
  else  front();
delay(5000);
  if(fr==1)rear();
  else  front();
delay(5000);
 }
void up(void)
{
  PORTD = B00000000;
 digitalWrite(A0, 1);
}

void down(void)
{
 PORTD = B00000000;
 digitalWrite(A1, 1);
}

void flapup(void)
{
 PORTD=16;
}

void flapdown(void)
{
 PORTD=32;
}

void front(void)
{
 PORTD = B00000000;
 digitalWrite(A2, 1);
}
void rear(void)
{
 PORTD = B00000000;
 digitalWrite(A3, 1);
}

void uprear(void)
{
 PORTD=9;
}

void upfront(void)
{
 PORTD=5;
}

void downrear(void)
{
 PORTD=10;
}

void downfront(void)
{
 PORTD=6;
}
