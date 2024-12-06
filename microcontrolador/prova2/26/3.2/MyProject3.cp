#line 1 "C:/Users/bya/Desktop/computa��o/2022.2/microcontroladores/prova2/26/3.2/MyProject3.c"

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
 lcd_init();
 lcd_cmd(_lcd_cursor_off);
 lcd_out(1,1,"Seja bem vindo!");
 lcd_out(2,1,"Aperte b0 ou b1");
 trisd = 0;
 t0con = 0b10000110;
 while(1){
 trisb = 255;
 portb = 1;
 if(button(&portb,0,1,0)==255){
 lcd_cmd(_lcd_clear);
 lcd_out(1,1,"Vezes LED2:");
 lcd_out(2,1,"Vezes LED1:");
 trisb = 0;
 portb = 255;
 portd = 0;
 tmr0h = 0xc2;
 tmr0l = 0xf7;
 intcon.tmr0if = 0;
 while(i<16){
 if(intcon.TMR0IF == 1){
 portb = ~portb;
 portd = ~portd;
 wordtostr(i/2,txt);
 lcd_out(1,12,txt);
 tmr0h = 0xc2;
 tmr0l = 0xf7;
 intcon.TMR0IF = 0;
 }
 i = i+1;
 }
 }
 }
}
