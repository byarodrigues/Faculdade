#line 1 "C:/Users/bya/Desktop/computação/2022.2/microcontroladores/testes/21-07/noite/ex3/ex2.c"

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
 lcd_init();

 while(1){
 lcd_out(1,1,"texto1-teste");
 delay_ms(2000);
 lcd_cmd(_lcd_clear);
 lcd_out(1,1,"2 texto");
 delay_ms(2000);
 }
}
