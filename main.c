//Tone Library/Function Club
//Hardware based PWM Frequency
//Cool Implementation
//By: Rohit Gupta
//www.indiantinker.wordpress.com
//All Rights Reserved under VegBurgerware License :)
#include <msp430g2231.h>
#define SPK BIT6  //TA0.1
//Tones From : http://www.phy.mtu.edu/~suits/notefreqs.html
//They all a digital representations correct upto 2 decimal places.
//and Yes! they are octave 4. ( I am a music noob!)
#define c 3824
#define cSH 3608
#define d 3405
#define dSH 3214
#define e 3034
#define f 2863
#define fSH 2703
#define g 2551
#define gSH 2408
#define a 2273
#define aSH 2145
#define b 2025
void tone(int tone,int duration)  //Tone macro and duration in millisecs
{   int i;
	for(i=0;i<duration;i++)
	{ CCR0=tone;
	  CCR1=tone/2;
	  _delay_cycles(100);
	}
}
void delay_ms(unsigned int ms )
{
      unsigned int i;
      for (i = 0; i<= ms; i++)
        __delay_cycles(500);               //Built-in function that suspends the execution for 500 cycles
}

void notone(int i)
{

	CCR0=0; //make main period zero..it doesnt work when you set CCR1 to sero because it will always set-reset at zero.
	delay_ms(i);
}

void toneInit()
{

			 CCTL1 = OUTMOD_7;          // CCR1 reset/set

			 TACTL = TASSEL_2 + MC_1;   // SMCLK, up mode
}
void seq1()   //change sequence according to your need!
{ tone(b,1000);   
  notone(100);   
  tone(c,1000);
  notone(100);
  tone(c,1000);
  notone(100);
  tone(cSH,1000);
  notone(100);
  tone(c,1000);
  notone(100);

}
void main(void)
{
	WDTCTL = WDTPW + WDTHOLD;  //Stop Bow..Bow!
	P1DIR|=SPK; //Speaker as output
	P1SEL|=SPK;//Speaker being used as TA0.1
        toneInit(); //Initialise the Timers
        while(1) //Go on..
{
    seq1();
    delay_ms(100);   //Pause between sequences!

}
}
