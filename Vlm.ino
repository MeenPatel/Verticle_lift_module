#include<reg51.h>
sbit keyrow1 = P3 ^ 0;
sbit keyrow2 = P3 ^ 1;
sbit keyrow3 = P3 ^ 2;
sbit keyrow4 = P3 ^ 3;
//keypad column
sbit keycolumn1 = P3 ^ 4;
sbit keycolumn2 = P3 ^ 5;
sbit keycolumn3 = P3 ^ 6;
sbit keycolumn4 = P3 ^ 7;
//functions
unsigned char keypad(void);
void delay(unsigned int);
unsigned char Epin[5];
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
unsigned char floor,floorchose,fr,start;
void main(void)
{
 floor=5;
 P0=0;
 P1=0;
 P2=0;
 /*add keypad here togofloor
 get floorchose*/
 while(1)
	{
		fr=0;
		floorchose=keypad();
		fr=keypad();
		for(;;)
		{
			start=0;
			start=keypad();
			if(start==10){break;}
		}
		toget();
		start=0;
		for(;;)/p1.0to start/
		{
		start=keypad();
		if(start==10){break;}
		}
		store();
		P2=0;
		floor=floorchose;
	}
}

void toget(void)
{
 unsigned char togofloor;
 signed char difference;
 togofloor=floorchose;
 difference=floor-togofloor;
 difference=togofloor-floor;
 if(difference>0)/add to choose cloumn/
  {
   up();
  }
 else if(difference<0)
  {
   difference=~difference;
		difference=difference+1;
   down();
  }
  for(;;)
  {
		P3=difference;
   if(difference==0) break;
   difference=difference-1;
delay(50);/delay floor/
  }
  floor=togofloor;
  P3=floor;
 if(front==1)rear();
  else	front();
  delay(50);/delay for rear front/
  if(front==1)front();
  else	rear();
	delay(50);
  togofloor=5;/reach surface/
  difference=togofloor-floor;
  if(difference>0)
  {
   up();
  }
  else if(difference<0)
  {
   down();
   difference=~difference;
		difference=difference+1;
  }
  for(;;)
  {
   if(difference==0) break;
   difference=difference-1;
   delay(50);/delay updown/
  }
 
  front();
  floor=5;
  delay(50);/delay for front/
  P2=00;
}





void store(void)
{
 unsigned char togofloor;
 signed char difference;
 rear();
delay(50); /delay rear/
 togofloor=floorchose;
 difference=togofloor-floor;
  if(difference>0)
  {
   up();
  }
  else if(difference<0)
  {
   down();
   difference=~difference;
		difference=difference+1;
  }
  for(;;)
  {
		if(difference==0) break;
   delay(50);/delay updown/
   difference=difference-1;
  }
  if(front==1)rear();
  else	front();
	delay(50);
}

void up(void)
{
 P2=1;
}

void down(void)
{
 P2=2;
}

void flapup(void)
{
 P2=16;
}

void flapdown(void)
{
 P2=32;
}

void front(void)
{
 P2=4;
}
void rear(void)
{
 P2=8;
}

void uprear(void)
{
 P2=9;
}

void upfront(void)
{
 P2=5;
}

void downrear(void)
{
 P2=10;
}

void downfront(void)
{
 P2=6;
}


void delay(unsigned char count)
{
{
unsigned char time=0;
 while(time!=count)
  {
   TMOD=0x01;  //16-bit timer0 selected
   TH0=0x00;   // Loading high byte in TH
   TL0=0x00;   // Loaded low byte in TL
   TR0=1;      // Running the timer
    while(!TF0);   //Checking the timer flag register if it is not equal to 1
   TR0 = 0;      // If TF0=1 stop the timer
   TF0 = 0;      // Clear the Timer Flag bit for next calculation

   time++;
  }

}

}

// lcd commands functions
unsigned char keypad(void)
{
    int x = 0;
P3=255;
 while (x == 0)
    {
        // assign values for first row
        keyrow1 = 0;
        keyrow2 = 1;
        keyrow3 = 1;
        keyrow4 = 1;
        if (keycolumn1 == 0)
        {
            delay(1);
            x = 1;
     //floorchose=1;
            return 1;
        }
        if (keycolumn2 == 0)
        {
            delay(1);
            x = 1;
     //floorchose=2;
            return 2;
        }
        if (keycolumn3 == 0)
        {
            delay(1);
            x = 1;
     //floorchose=3;
            return 3;
        }
				if (keycolumn4 == 0)
        {
            delay(1);
            x = 1;
            return 1;
        }
        // assign values for second row
        keyrow1 = 1;
        keyrow2 = 0;
        keyrow3 = 1;
        keyrow4 = 1;

        if (keycolumn1 == 0)
        {
            delay(1);
            x = 1;
     //floorchose=4;
            return 4;
        }
        if (keycolumn2 == 0)
        {
            delay(1);
            x = 1;
     //floorchose=5;
            return 5;
        }
        if (keycolumn3 == 0)
        {
            delay(1);
            x = 1;
     //floorchose=6;
            return 6;
        }
				if (keycolumn4 == 0)
        {
            delay(1);
            x = 1;
            return 2;
        }
        // assign values for third row
        keyrow1 = 1;
        keyrow2 = 1;
        keyrow3 = 0;
        keyrow4 = 1;
        if (keycolumn1 == 0)
        {
            delay(1);
            x = 1;
     //floorchose=7;
            return 7;
        }
        if (keycolumn2 == 0)
        {
            delay(1);
            x = 1;
     //floorchose=8;
            return 8;
        }
        if (keycolumn3 == 0)
        {
            delay(1);
            x = 1;
     //floorchose=9;
            return 9;
        }
				if (keycolumn4 == 0)
        {
            delay(1);
            x = 1;
     //floorchose=3;
            return ;
        }
        // assign values for forth row
        keyrow1 = 1;
        keyrow2 = 1;
        keyrow3 = 1;
        keyrow4 = 0;

        if (keycolumn1 == 0)
        {
            delay(1);
            x = 1;
            return ;
        }
        if (keycolumn2 == 0)
        {
            delay(1);
            x = 1;
            return ;
        }
        if (keycolumn3 == 0)
        {
            delay(1);
            x = 1;
            return 10;
        }
				if (keycolumn4 == 0)
        {
            delay(1);
            x = 1;
     //floorchose=3;
            return ;
        }
    }
 }

/*for 8051above*/
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
