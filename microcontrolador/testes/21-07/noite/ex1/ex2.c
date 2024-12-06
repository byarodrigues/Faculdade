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
       lcd_init(); //inicia
       lcd_out(1,1,"Bya"); //manda texto pra linha 1 e coluna 1
       lcd_out(2,1,"Rodrigues"); //manda texto pra linha 1 e coluna 1
       //lcd_out_cp(" texto2hjfjiug");  //manda texto pra proximo lugar
       //lcd_cmd(_lcd_clear);  //limpa tela
       //lcd_cmd(_led_cursor_off);

}