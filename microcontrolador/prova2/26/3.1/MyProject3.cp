#line 1 "C:/Users/bya/Desktop/computação/2022.2/microcontroladores/prova2/26/3.1/MyProject3.c"

sbit LCD_RS at RE2_bit;
sbit LCD_EN at RE1_bit;
sbit LCD_D7 at RD7_bit;
sbit LCD_D6 at RD6_bit;
sbit LCD_D5 at RD5_bit;
sbit LCD_D4 at RD4_bit;


sbit LCD_RS_Direction at TRISE2_bit;
sbit LCD_EN_Direction at TRISE1_bit;
sbit LCD_D7_Direction at TRISD7_bit;
sbit LCD_D6_Direction at TRISD6_bit;
sbit LCD_D5_Direction at TRISD5_bit;
sbit LCD_D4_Direction at TRISD4_bit;

void main() {
 int i = 1;
 char txt[6];
 trisb = 255;
 tmr0h = 0xc2;
 tmr0l = 0xf7;
 t0con = 0b10000110;
 lcd_init();
 Lcd_Cmd(_LCD_CURSOR_OFF);
 lcd_out(1,1,"Seja bem vindo!");
 lcd_out(2,1,"Aperte b0 ou b1");
 while(1){
 if(button (&portb,0,1,0)==255){
 intcon.tmr0if = 0;
 trisb = 0;
 portb = 0;
 lcd_cmd(_lcd_clear);
 lcd_out(1,1,"vezes LED2:");
 lcd_out(2,1,"vezes LED1:");
 trisd = 0;
 portd = 255;
 while(i<15){
 lcd_out(1,13,"0");
 lcd_out(2,13,"1");
 if(intcon.tmr0if == 1){
 portb = ~portb;
 portd = ~portd;
 intcon.tmr0if = 0;
 tmr0h = 0xc2;
 tmr0l = 0xf7;
 i = i + 1;
 wordtostr(i/2,txt);
 lcd_out(1,12,txt);
 portd = 255;
 }

 }
 }
 }
}
