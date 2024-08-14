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
