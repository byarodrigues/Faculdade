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
     int i = 0;
     trisb = 255;
     PORTb = 0b00000100; //define o segmento "2" como saída
     lcd_init(); //inicia

     while(1){
              if(button(&portb,5,1,0)==255){
              lcd_out(1,i,"5");
              delay_ms(2000);
              i++;
              }
     }
}