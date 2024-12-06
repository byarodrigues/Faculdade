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
trisb = 0;
trisd = 0;
portb = 0;
portd = 0;
lcd_init();
lcd_out(1,1, "Digite b0 ou b1");
trisb = 0b00000011;
while(1){
  if(button(&portb,0,1,0)==255){
    lcd_cmd(_LCD_CLEAR);
    lcd_out(1,1, "teste");
  }


}

}