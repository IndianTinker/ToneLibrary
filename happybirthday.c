//Tone Library/Function Club
//Hardware based PWM Frequency

//By: Rohit Gupta
//All Rights Reserved under VegBurgerware License :)
//Restricted For Commercial Use!
//Tones From : http://www.phy.mtu.edu/~suits/notefreqs.html
//They all a digital representations correct upto 2 decimal places.
//and Yes! they are octave 4. ( I am a music noob!)
//Happy Birthday Tone!
#include <msp430g2231.h>
#define SPK BIT6  //TA0.1
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
#define cH 1911
unsigned int dur=100;
void tone(int tone,int duration)  //Tone macro and duration in millisecs.Play other frq simply divide it (smclk/notef) and feed it into the function
{   int i;
	for(i=0;i<duration;i++)
	{ CCR0=tone;       //Tone length
	  CCR1=tone/2;     //Half Tone ON and Half tone OFF i.e 50% duty!
	  _delay_cycles(1000);
	}
}
void delay_ms(unsigned int ms )
{
      unsigned int i;
      for (i = 0; i<= ms; i++)
        __delay_cycles(1000);               //Built-in function that suspends the execution for 500 cycles
}

void notone(int i)        //To stop the tone can`t use delay_ms as its a hardware PWM not software!
{

	//CCR0=0; //make main period zero..it doesnt work when you set CCR1 to zero because it will always set-reset at zero.
	//delay_ms(i);
}

void toneInit()       //Initialise The Timers
{

			 CCTL1 = OUTMOD_7;          // CCR1 reset/set

			 TACTL = TASSEL_2 + MC_1;   // SMCLK, up mode
}
void seq1()
{
tone(c,200);
notone(dur);
tone(c,200);
notone(dur);
tone(d,270);
notone(dur);
tone(c,200);
notone(dur);
tone(f,200);
notone(dur);
tone(e,270);
notone(400);//One Segment
tone(c,200);
notone(dur);
tone(c,200);
notone(dur);
tone(d,270);
notone(dur);
tone(c,200);
notone(dur);
tone(g,200);
notone(dur);
tone(f,290);
notone(300);//Two Segment
tone(c,200);
notone(dur);
tone(c,200);
notone(dur);
tone(cH,250);
notone(dur);
tone(a,200);
notone(dur);
tone(aSH,200);
notone(dur);
tone(g,200);
notone(300);//Three Segment
tone(a,250);
notone(dur);
tone(a,200);
notone(dur);
tone(aSH,200);
notone(dur);
tone(f,200);
notone(dur);
tone(g,200);
notone(dur);
tone(f,290);
notone(dur);
}
void main(void)
{
	WDTCTL = WDTPW + WDTHOLD; //Stop the Bow...Boww
	P1DIR|=SPK; //Spk as output
	P1SEL|=SPK; //Speaker as TA0.1
	toneInit(); //iNITIALISE
    while(1)
{
    seq1();
    delay_ms(5000); //Dont Repeat Too Fast

}
}
