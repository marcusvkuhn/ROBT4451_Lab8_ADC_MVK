/*************************************************************************************************
 * ROBT4451Lab7.c
 * - top level file for Lab 7
 * Demonstrates use of mcp4921Dac.c. A 12 bit DAC with SPI digital interface to uC
 * Assumes MSP430 is interfaced to mcp4921 through SPI with UCSIA0.
 * dcoFreq and sclkDiv can be set by user
 *
 *
 *  Author: Chris Baitz Greg Scutt
 *  Created on: April, 2017
 **************************************************************************************************/



#include <msp430.h> 

#include "adc12.h"
#include "usciUart.h"
#include "stdio.h"

/*
 * main.c
 */

void main(void) {

    WDTCTL = WDTPW | WDTHOLD;					// Stop watchdog timer

    usciA1UartInit();

//    char voltmeterStr[30];
//    double sineMeas[300] = {};
//    int clrLenght;
    i = 0;
    //double measVolt = 0;

    //PxSEL |= BIT0 + BIT1;
    P6SEL |= BIT0 + BIT1 + BIT2 + BIT3 + BIT4 + BIT5 + BIT6 + BIT7;

    adc12Cfg("2V5", 1, 1, 0, 100, 100);

    __enable_interrupt();

//    while(1){
        //__delay_cycles(104800);            // 100ms delay

        //adc12SampSWConv();

        //measVolt = (2.5*adc12Result)/4095;
        //sineMeas[i] = (2.5*adc12Result[i])/4095;
//        sumVolt = sumVolt + measVolt;
        //sineMeas[i]

//        if (i > 200){
//            i = 0;
//            __disable_interrupt();                  // disable global interrupts
//        for(i = 0; i < 200; i++)
//            sineMeas[i] = (2.5*adc12Result[i])/4095;
//
//        }
//       i = 5;
//        if (samples >= 15){
//            measVolt = sumVolt/samples;
//            sumVolt = 0;
//            samples = 0;
//            for (clrLenght = 40; clrLenght != 0; --clrLenght)
//                usciA1UartTxChar(' ');                          // this loop clears the console
//
//            usciA1UartTxChar('\r');                         // returns to beginning of line
//
//            sprintf(voltmeterStr, "Voltage = %.4fV          ", sineMeas[i]);
//            usciA1UartTxString(voltmeterStr);
//        }
//    }

    //__disable_interrupt();					// disable global interrupts
	//return 0;
}
