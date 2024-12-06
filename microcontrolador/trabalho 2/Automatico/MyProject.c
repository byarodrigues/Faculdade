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

     char txtTemperatura[6];
     char txtPotenciometro[6];
     int result, x, atual ;
     // botão rb0 (liga), rb1(desliga)
     trisb = 0b00000011;
     //liga os potenciometros e lm35
     adcon1 = 0b00001100;
     trisc = 0;
     lcd_init();
     lcd_cmd(_lcd_clear);
     lcd_cmd(_lcd_cursor_off);
     //ligar o sistema
     // ler o potenciometro 1
     while(1){
       if(button(&portb, 0, 1, 0) == 255 ){
       lcd_out(1,1, "Sistema Iniciado");
       lcd_out(2,1, "Automaticamente");
       delay_ms(500);
         while(1){
                  //le a temperatura atual e transforma para char
                  wordtostr(ADC_read(2)/2, txtTemperatura);
                  //escreve a temperatura atual
                  lcd_out(1,1, "Temperatura");
                  lcd_out_cp(txtTemperatura);
                  //liga resistor
                  portc = 0b00100000;
                  lcd_out(2,1, "Aquecendo      ");
                  lcd_out(3,-3, "Potencia Maxima   ");
                   
                  //função para desligar o sistema
                  if(button(&portb, 1, 1, 0) == 255){
                                    lcd_cmd(_lcd_clear);
                                    portc = 0;
                                    break;
                  }
                  // se temperatura >= 28 and temperatura <= 50 liga B5
                  if(ADC_read(2)/2 >= 28 && ADC_read(2)/2 <= 50){
                        portb = 0b00100011;
                  // se temperatura >= 51 and temperatura <= 69 liga B5, B6
                  }else if(ADC_read(2)/2 >= 51 && ADC_read(2)/2 <= 69){
                        portb = 0b01100011;
                  // se temperatura == 70 liga B5, B6, B7
                  }else if (ADC_read(2)/2 == 70 ){
                        portb = 0b11100011;
                  }
                  //se a tempetura passar de 70 graus o cooler liga e começa a resfriar
                  //mesmo com o o heater ligado
                  if(ADC_read(2)/2 > 70){
                                   lcd_cmd(_lcd_clear);
                                   while(ADC_read(2)/2 > 28){
                                                       portc = 0b00100100;
                                                       //le a temperatura atual e transforma para char
                                                       wordtostr(ADC_read(2)/2, txtTemperatura);
                                                       //escreve a temperatura atual
                                                       lcd_out(1,1, "Temperatura");
                                                       lcd_out_cp(txtTemperatura);
                                                       lcd_out(2,1, "Resfriando");
                                                       //desligar o sistema
                                                       if(ADC_read(2)/2 == 70){
                                                             portb = 0b11100011;
                                                       // se temperatura >= 51 and temperatura <= 69 desliga B5, B6
                                                       }else if(ADC_read(2)/2 <= 69 && ADC_read(2)/2 >= 51){
                                                             portb = 0b01100011;
                                                       // se temperatura == 70 desliga B5, B6, B7
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