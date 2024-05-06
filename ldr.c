/*
 * File:   ldr.c
 * Author: quest
 *
 * Created on 16 April, 2024, 9:58 AM
 */


// PIC16F876A Configuration Bit Settings

// 'C' source line config statements

// CONFIG
#pragma config FOSC = XT        // Oscillator Selection bits (XT oscillator)
#pragma config WDTE = OFF       // Watchdog Timer Enable bit (WDT disabled)
#pragma config PWRTE = OFF      // Power-up Timer Enable bit (PWRT disabled)
#pragma config BOREN = OFF      // Brown-out Reset Enable bit (BOR disabled)
#pragma config LVP = OFF        // Low-Voltage (Single-Supply) In-Circuit Serial Programming Enable bit (RB3 is digital I/O, HV on MCLR must be used for programming)
#pragma config CPD = OFF        // Data EEPROM Memory Code Protection bit (Data EEPROM code protection off)
#pragma config WRT = OFF        // Flash Program Memory Write Enable bits (Write protection off; all program memory may be written to by EECON control)
#pragma config CP = OFF         // Flash Program Memory Code Protection bit (Code protection off)
#define _XTAL_FREQ 4000000
// #pragma config statements should precede project file includes.
// Use project enums instead of #define for ON and OFF.

#include <xc.h>
#include<string.h>
#include<stdio.h>

char a[50];


void sent(char a[])
{
    for(int i=0;a[i]!='\0';i++)
    {
    TXREG=a[i];
    while(TRMT==0);
    }
   __delay_ms(1000);
    for(int i=0;i<strlen(a);i++)
        {
    TXREG='\b';
    while(TRMT==0);
    }
    
}

void adc1()
{
    ADCON0=0X41;
            GO=1;
        while(GO==1);
      
        float res1=(ADRESH<<8)|ADRESL;
        
        float volt =res1*4.88;
        float temp=volt/10; 
        
        sprintf(a,"TEMP = %0.2f\r",temp);
        sent(a);
      
       // __delay_ms(1000);
        if(temp>25)
        {
            RC0=1;
        }
        else
        {
            RC0=0;
        }
}
void adc2()
{
    ADCON0=0X49;
            GO=1;
        while(GO==1);
      
        int res=(ADRESH<<8)|ADRESL;
        char onn[]="Led on";
        char off[]="Led off";
        
        
        sprintf(a,"a = %d\r",res);
       // sent(a);
      
       // __delay_ms(1000);
        if(res<200)
        {
            RC1=1;
            sent(onn);
        }
        else
        {
            RC1=0;
            sent(off);
        }
    
    }
//void sw()
//{
//   
//    if(RB0==1)
//    {
//        while(RB0==1);
//        RC4=1;
//    }
//    
//}
void __interrupt () min()
{
        RC4=1;
        INTF=0; 
}

void main(void)
{
    TRISA=0X03;
    TRISC=0X00;
    TRISB=0x0F;
    
    PORTC=0x00;
    ADCON1=0X80;
   
    TXSTA=0X24;
    RCSTA=0X90;
    SPBRG=25;
  
    
    //INTCON=0xC0;
    GIE=1;
    INTE=1;
    INTEDG=1;
    
    while(1)
    {
        adc1();
        adc2();
        //sw();
    }
          
    return;
}
