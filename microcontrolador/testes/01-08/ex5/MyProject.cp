#line 1 "C:/Users/bya/Desktop/computação/2022.2/microcontroladores/testes/01-08/ex5/MyProject.c"

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
 char texto[6]; char porcent[6];
 float pote, x, temp;

 char texto1[6]; char porcent1[6];
 float pote1, x1 = 0;

 lcd_init();
 lcd_cmd(_lcd_clear);
 lcd_cmd(_LCD_CURSOR_OFF);

 while(1){
 ADCON1 = 0b00001101;

 pote = ADC_Read (0);
 x = (pote/1023)*100;
 WordToStr(pote, texto);
 WordToStr(x, porcent);
 lcd_out(1,1,texto);
 lcd_out_cp(porcent);

 pote1 = ADC_Read (1);
 x1 = (pote1/1023)*100;
 WordToStr(pote1, texto);
 WordToStr(x1, porcent1);
 lcd_out(2,1,texto);
 lcd_out_cp(porcent1);
 }

}
