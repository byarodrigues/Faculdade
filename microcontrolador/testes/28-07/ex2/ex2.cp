#line 1 "C:/Users/bya/Desktop/computação/2022.2/microcontroladores/testes/28-07/ex2/ex2.c"

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
 char texto[6];
 int a = 0;
 lcd_init();
 lcd_cmd(_lcd_clear);
 lcd_cmd(_LCD_CURSOR_OFF);
 while(1){
 trisb = 0b00100000;
 lcd_out(1,1,"Valor led ");
 if (button(&portb,5,1,0)==255){
 a = 0;
 trisb = 0b00000000;
 while(a<=255){
 portb = a;
 WordToStr(a, texto);
 lcd_out(1,1,"Valor led ");
 lcd_out_cp(texto);
 delay_ms(5000);
 a = a*2+1;
 lcd_cmd(_lcd_clear);
 }
 }

 }
}
