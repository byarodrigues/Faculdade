#line 1 "C:/Users/bya/Desktop/computação/2022.2/microcontroladores/testes/15-08/ex1/MyProject.c"

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
 int leitura_AD;
 char texto[6];
 adcon1 = 0b00001110;
 lcd_init();
 lcd_cmd(_lcd_clear);
 lcd_cmd(_lcd_cursor_off);
 lcd_out(1,1,"ANO: ");
 pwm1_init(5000);
 pwm1_start();
 while(1){
 leitura_AD = adc_read(0);
 leitura_AD = leitura_AD/4;
 wordtostr(leitura_AD, texto);
 lcd_out(1,5,texto);
 pwm1_set_duty(leitura_AD);
 }

}
