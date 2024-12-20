#line 1 "C:/Users/bya/Desktop/computação/2022.2/microcontroladores/prova2/21/7/MyProject.c"

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
 int pot1;
 int pot2;
 char porc1[6];
 char porc2[6];
 char txt1[6];
 char txt2[6];

 lcd_init();
 lcd_cmd(_lcd_cursor_off);
 while(1){
 adcon1 = 0b00001110;
 pot1 = adc_read(0);
 wordtostr(pot1,txt1);
 wordtostr(pot1/10.23,porc1);
 lcd_out(1,1,txt1);
 lcd_out(1,8,porc1);

 adcon1 = 0b00001101;
 pot2 = adc_read(1);
 wordtostr(pot2,txt2);
 wordtostr(pot2/10.23,porc2);
 lcd_out(2,1,txt2);
 lcd_out(2,8,porc2);
 }
}
