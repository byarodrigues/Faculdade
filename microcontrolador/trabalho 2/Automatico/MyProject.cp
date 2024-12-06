#line 1 "G:/Meu Drive/IFMG/Periodo 9/Microcontrolador/Trabalho2/Automatico/MyProject.c"

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

 char txtTemperatura[6];
 char txtPotenciometro[6];
 int result, x, atual ;

 trisb = 0b00000011;
 adcon1 = 0b00001100;
 trisc = 0;
 lcd_init();
 lcd_cmd(_lcd_clear);
 lcd_cmd(_lcd_cursor_off);


 while(1){
 if(button(&portb, 0, 1, 0) == 255 ){
 lcd_out(1,1, "Sistema Iniciado");
 lcd_out(2,1, "Automaticamente");
 delay_ms(500);
 while(1){

 wordtostr(ADC_read(2)/2, txtTemperatura);

 lcd_out(1,1, "Temperatura");
 lcd_out_cp(txtTemperatura);
 portc = 0b00100000;
 lcd_out(2,1, "Aquecendo      ");
 lcd_out(3,-3, "Potencia Maxima   ");


 if(button(&portb, 1, 1, 0) == 255){
 lcd_cmd(_lcd_clear);
 portc = 0;
 break;
 }

 if(ADC_read(2)/2 >= 28 && ADC_read(2)/2 <= 50){
 portb = 0b00100011;

 }else if(ADC_read(2)/2 >= 51 && ADC_read(2)/2 <= 69){
 portb = 0b01100011;

 }else if (ADC_read(2)/2 == 70 ){
 portb = 0b11100011;
 }


 if(ADC_read(2)/2 > 70){
 lcd_cmd(_lcd_clear);
 while(ADC_read(2)/2 > 28){
 portc = 0b00100100;

 wordtostr(ADC_read(2)/2, txtTemperatura);

 lcd_out(1,1, "Temperatura");
 lcd_out_cp(txtTemperatura);
 lcd_out(2,1, "Resfriando");

 if(ADC_read(2)/2 == 70){
 portb = 0b11100011;

 }else if(ADC_read(2)/2 <= 69 && ADC_read(2)/2 >= 51){
 portb = 0b01100011;

 }else if (ADC_read(2)/2 <= 50 && ADC_read(2)/2 >= 28 ){
 portb = 0b00100011;
 }
 if(button(&portb, 1, 1, 0) == 255){
 lcd_cmd(_lcd_clear);
 portc = 0;
 break;
 }
 }
 }
 }
 }
 }
}
