#line 1 "C:/Users/bya/Desktop/computação/2022.2/microcontroladores/prova2/21/2/MyProject.c"

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
 char txt[6];
 int pot;
 lcd_init();
 lcd_cmd(_lcd_cursor_off);
 while(1){
 adcon1 = 0b00001101;
 pot = adc_read(1);
 wordtostr(pot,txt);
 lcd_out(1,1,txt);
 }
}
