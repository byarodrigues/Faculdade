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


#define LENA  PORTEbits.RE1     //E enable
#define LDAT  PORTEbits.RE0     //RS
#define LPORT PORTD             //DATA


#define L_CFG   0x38            //defini interface 8bits duas linhas e fontes 5x8

//Controle do display/cursor
#define L_ON	0x0F            //Liga cursor piscando
#define L_NCR	0x0C            //Dips ligado, desliga cursor
#define L_OFF	0x08            //disp off
#define L_CLR	0x01            //Limpa disp volta para posição inicial

//Posicionamento do cursor
#define L_L1	0x80            //Endereço CGRAM linha 1 
#define L_L2	0xC0            //Endereço CGRAM linha 2 // lcd_cmd(L_L1+5);




void lcd_init(void);
void lcd_cmd(unsigned char val); 
void lcd_dat(unsigned char val);
void lcd_str(const char* str);
