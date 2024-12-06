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
     int i = 1;
     char txt[6];
     trisb = 0b000000011;
     trisa = 0;
     lcd_init();
     lcd_cmd(_lcd_cursor_off);
     tmr0h = 0xc2;
     tmr0l = 0xf7;
     t0con = 0b10000110;

     while(1){
              lcd_out(1,1,"Seja bem vindo! ");
              lcd_out(2,1,"Aperte b0 ou b1 ");
              if(button(&portb,0,1,0)){
                   trisb = 0;
                   portb = 0;
                   intcon.TMR0IF = 0;
                   lcd_cmd(_lcd_clear);
                   lcd_out(1,1,"Vezes LED2:");
                   lcd_out(2,1,"Vezes LED1:");
                   while(i<15){
                        trisd = 0;
                        if(intcon.tmr0if == 1){
                             portb = ~portb;
                             portd = ~portd;
                             intcon.tmr0if = 0;
                             tmr0h = 0xc2;
                             tmr0l = 0xf7;
                             i = i + 1;
                             wordtostr(i/2,txt);
                             lcd_out(1,12,txt);
                             portd = 255;
                        }

                   }
                   i = i + 1;
              }
     }
}