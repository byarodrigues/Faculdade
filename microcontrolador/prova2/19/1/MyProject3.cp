#line 1 "C:/Users/bya/Desktop/computa��o/2022.2/microcontroladores/prova2/19/1/MyProject3.c"

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
 int i = 0;
 char txt[6];
 trisd = 0;
 portd = 0;
 trisb = 255;
 portb = 0;
 lcd_init();
 lcd_out(1,1,"Seja bem vindo!");
 lcd_out(2,1,"Aperte b0 ou b1");
 while(1){
 if(button (&portb,0,1,0)==255){
 while(i < 16){
 lcd_cmd(_lcd_clear);
 lcd_out(1,1,"vezes LED2:");
 lcd_out(2,1,"vezes LED1:");
 trisb = 0;
 portb = ~portb;
 wordtostr(i/2,txt);
 lcd_out(13,1,txt);
 i = i + 1;
 }
 }
 }
}
