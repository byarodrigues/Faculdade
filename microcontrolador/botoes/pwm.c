// Lcd pinout settings
sbit LCD_RS at RE2_bit;
sbit LCD_EN at RE1_bit;
sbit LCD_D7 at RD7_bit;
sbit LCD_D6 at RD6_bit;
sbit LCD_D5 at RD5_bit;
sbit LCD_D4 at RD4_bit;

// Pin direction
sbit LCD_RS_Direction at TRISE2_bit;
sbit LCD_EN_Direction at TRISE1_bit;
sbit LCD_D7_Direction at TRISD7_bit;
sbit LCD_D6_Direction at TRISD6_bit;
sbit LCD_D5_Direction at TRISD5_bit;
sbit LCD_D4_Direction at TRISD4_bit;


void main() {
int aux = 0; char texto [6]; int aux1 = 0; char texto1 [6]; int por = 0;
pwm1_init(5000);
adcon1 = 0b00001100;
lcd_init();
while(1){
         aux = adc_read(0)/4;
         pwm1_set_duty(aux);
         por = aux/2.55;
         wordtostr(aux, texto);
         wordtostr(por, texto1);
         lcd_out(1,1, texto);
         lcd_out(2,1, texto1);



         }
}