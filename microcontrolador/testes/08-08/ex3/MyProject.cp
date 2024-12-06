#line 1 "C:/Users/bya/Desktop/computação/2022.2/microcontroladores/testes/08-08/ex3/MyProject.c"

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

 char texto[6];
 int temp, x;

void main() {
 lcd_init();
 ADCON1 = 0b00001101;

 while(1){
 temp = ADC_Read (2);
 x = temp/2;
 WordToStr(x, texto);
 lcd_out(1,1,texto);
 }

}
