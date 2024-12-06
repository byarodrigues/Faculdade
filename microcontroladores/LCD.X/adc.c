/* ########################################################################

   PICsim - PIC simulator http://sourceforge.net/projects/picsim/

   ########################################################################

   Copyright (c) : 2015  Luis Claudio Gambôa Lopes

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.

   For e-mail suggestions :  lcgamboa@yahoo.com
   ######################################################################## */

#include <xc.h>
#include "adc.h"


void adc_init(void)
{

    ADCON0 = 0x01;              //ADCON0bits.ADON=1; conversor ligado inicializa o resto do ADCON0 com 0
    
    ADCON1bits.VCFG0 = 0;       //VCFG0=1 Referencia de tensão positiva no AN3
    ADCON1bits.VCFG1 = 0;       //VCFG1=1 Referencia de tensão negativa no AN2
    ADCON1bits.PCFG = 0b1110;   //Entradas analógicas somente em AN0 

    ADCON2bits.ADFM = 0;        //Justificado a esquerda, resultado nos bits mais significativos
    ADCON2bits.ADCS = 0b101;    //Fosc/16; Tad=16/16Mhz=1us; 0,7us<1us<25us
    ADCON2bits.ACQT = 0b010;    //4 Tad = 4us
    //4 Tad para carga do capacitor + 11 Tad para a conversão + 1 Tad para descarga =16 Tad = 16us



}

unsigned int adc_amostra(unsigned char canal)
{


    switch(canal)
    {
      case 0: 
        ADCON0bits.CHS = 0b0000; //AN0 ADCON0=0x01;    0b00000001
        break;
      case 1: 
        ADCON0bits.CHS = 0b0001; //AN1 ADCON0=0x05;    0b00000101
        break;
      case 2: 
        ADCON0bits.CHS = 0b0010; //AN3 ADCON0=0x09;    //00001001
        break;
    }

   
    ADCON0bits.GO=1;            //inicia conversão
    while(ADCON0bits.GO == 1);  //aguarda o termino

   return ((((unsigned int)ADRESH)<<2)|(ADRESL>>6)); //Ajusta posição dos bits (justificado a esquerda)
}

//                                                           7 6 5 4 3 2 1 0:7 6 5 4 3 2 1 0
//conversor de 10bits justificado a esquerda ADRESH:ADRESL = H H H H H H H H:L L 0 0 0 0 0 0

//                                  unsigned int (16 bits)     15 14 13 12 11 10 9 8 7 6 5 4 3 2 1 0
//                                          ADRESH<<2                            H H H H H H H H 0 0
//                                          ADRESL>>6                            0 0 0 0 0 0 0 0 L L
//    Operador lógico ou                  ADRESH | ADRESL                        H H H H H H H H L L