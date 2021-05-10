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

#include "usciSpi.h"
#include "ucsControl.h"
#include "mcp4921Dac.h"
#include "usciUart.h"
#include "waveformGenerator.h"
#include "timerA0.h"
#include "adc12.h"


#define dcoFreq 20							//MHz.
#define sclkDiv 1							//SPI sclk divide. SCLK MAX to the DAC is 20MHz.
											// sclkDiv will slow down transfer rate to DAC

#define DAC_TST_WORD 0xBF8

/*
 * main.c
 */



unsigned char rxFlag = 0;
int main(void) {

	//unsigned int *address = (unsigned int*)0x2400;
	unsigned char oscFail = 1;
//	unsigned int dacWord = 0;

	unsigned int dacCtrl = (~DAC_CFG_WR & ~DAC_CFG_BUF & (DAC_CFG_GA + DAC_CFG_SHDN)) & 0xF000;

								// count direction
    WDTCTL = WDTPW | WDTHOLD;					// Stop watchdog timer

    /*********Set clock frequency*********************************************/
    //unsigned char testPass = 1;
    ucsSelSource(1,1,1,1);
    oscFail = ucsDcoFreqSet (dcoFreq, 2, 1);			//set sclk to dcoFreq
    if (oscFail)
    	return 1;
    /***End***Set clock frequency*********************************************/

    usciA0SpiInit(sclkDiv);
    usciA1UartInit();

    initDac();

    j = 0;

    P6SEL |= BIT0;

    adc12Cfg("2V5", 0, 1, 0);

    __enable_interrupt();                   // enable global device interrupts

    while(1){
        if (j >= 200){
            j = 0;
        }
        if(writeDac){
            dacWriteWord(adc12Result[j], dacCtrl);
            writeDac = 0;
        }
    }

    __disable_interrupt();					// disable global interrupts
	return 0;
}
