/*
 * File:   main.c
 * Author: Paul
 *
 * Created on January 6, 2024, 9:22 PM
 */


#include <xc.h>
#pragma config FOSC = XT 
#define _XTAL_FREQ 4000000 //4Mhz

#define led PORTCbits.RC4

#define f1 PORTDbits.RD0
#define f2 PORTDbits.RD1
#define f3 PORTDbits.RD2
#define f4 PORTDbits.RD3
#define c1 PORTDbits.RD4
#define c2 PORTDbits.RD5
#define c3 PORTDbits.RD6
#define c4 PORTDbits.RD7


int posicion = 0;
int numDec1 = 0;
int numDec2 = 0;
int numVar[2] = {0, 0};

void titilar (int num);
int teclado (void);
int calNum(int* numPass);

void main(void) {
    TRISD = 0b11110000;
    TRISC4 = 0;
    f1 = 0;
    f2 = 0;
    f3 = 0;
    f4 = 0;
    int resul;
    
    while (1){
        int resul = teclado();
        if(resul != 255)
            titilar(resul);
        __delay_ms(10);
    }
    return;
}

void titilar (int numAux)
{
    for(int i=0; i<numAux; i++){
        led = 1;
        __delay_ms(100);
        led = 0;
        __delay_ms(100);
    }
}
int teclado (void){
    int numero = 255;
    const int demora = 100;
    f4 = 0;
    f1 = 1;
    __delay_ms(demora);
    if(c1 == 1){ numero = 7;}
    if(c2 == 1){ numero = 8;}
    if(c3 == 1){ numero = 9;}
    if(c4 == 1){numero = 10;}                    // Division
    f1 = 0;
    f2 = 1;
    __delay_ms(demora);
    if(c1 == 1){ numero = 4;}
    if(c2 == 1){ numero = 5;}
    if(c3 == 1){ numero = 6;}
    if(c4 == 1){ numero = 11;}                    // Multiplicacion
    f2 = 0;
    f3 = 1;
    __delay_ms(demora);
    if(c1 == 1){ numero = 1;}
    if(c2 == 1){ numero = 2;}
    if(c3 == 1){ numero = 3;}
    if(c4 == 1){ numero = 12;}                    // Resta
    f3 = 0;
    f4 = 1;
    __delay_ms(demora);
    if(c1 == 1){ numero = 14;}                    //Enter
    if(c2 == 1){ numero = 0;}
    if(c3 == 1){ numero = 15;}                    //Igual
    if(c4 == 1){ numero = 13;}                    // Suma
    f4 = 0;    
   
    return numero;       
}

int calNum(int* numPass)
{   
    int num = 0;
    num = numPass[0]*10 + numPass[1];
    return num;
}