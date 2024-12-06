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


//Manual

void main() {


     char txtTemperatura[6];
     char txtPotenciometro[6];
     int result, x, atual ;
     // botão rb0 (liga), rb1(desliga), rb2(emergencia)
     trisb = 0b00000011;
     adcon1 = 0b00001100;
     trisc = 0;
     lcd_init();
     lcd_cmd(_lcd_clear);
     lcd_cmd(_lcd_cursor_off);



     while(1){
              if(button(&portb, 0, 1, 0) == 255 && adc_read(0)/10.23 > 10 ){
                                while(1){
                                
                                  //le a temperatura atual e transforma para char
                                  wordtostr(ADC_read(2)/2, txtTemperatura);
                                  //escreve a temperatura atual
                                  lcd_out(1,1, "Temperatura");
                                  lcd_out_cp(txtTemperatura);
                                  portc = 0b00100000;
                                  lcd_out(2,1, "Aquecendo");
                                  x = adc_read(0)/10.23;
                                  wordtostr(x, txtPotenciometro);
                                  lcd_out(3,-3, "Potencia");
                                  lcd_out_cp(txtPotenciometro);
                                  portc = 0b00100000;
                                  lcd_out_cp("%");
                                  if(button(&portb, 1, 1, 0) == 255){
                                    lcd_cmd(_lcd_clear);
                                    portc = 0;
                                    break;
                                  }

                                  if((x > 10) && (x <=35) && (ADC_read(2)/2 >= 40)){
                                        while( x <= 35){
                                          portc = 0b00100100;
                                          //le a temperatura atual e transforma para char
                                          wordtostr(ADC_read(2)/2, txtTemperatura);
                                          //escreve a temperatura atual
                                          lcd_out(1,1, "Temperatura");
                                          lcd_out_cp(txtTemperatura);
                                          lcd_out(2,1, "Resfriando");
                                          x = adc_read(0)/10.23;
                                          wordtostr(x, txtPotenciometro);
                                          lcd_out(3,-3, "Potencia");
                                          lcd_out_cp(txtPotenciometro);
                                          portc = 0b00100000;
                                          lcd_out_cp("%");
                                          if(button(&portb, 1, 1, 0) == 255){
                                            lcd_cmd(_lcd_clear);
                                            portc = 0;
                                            break;
                                           }
                                        }


                                  }else if ((x > 35) && (x <=50) && (ADC_read(2)/2 >= 50)){
                                        while(x <= 50){
                                          portc = 0b00100100;
                                          //le a temperatura atual e transforma para char
                                          wordtostr(ADC_read(2)/2, txtTemperatura);
                                          //escreve a temperatura atual
                                          lcd_out(1,1, "Temperatura");
                                          lcd_out_cp(txtTemperatura);
                                          lcd_out(2,1, "Resfriando");
                                          x = adc_read(0)/10.23;
                                          wordtostr(x, txtPotenciometro);
                                          lcd_out(3,-3, "Potencia");
                                          lcd_out_cp(txtPotenciometro);
                                          portc = 0b00100000;
                                          lcd_out_cp("%");
                                          if(button(&portb, 1, 1, 0) == 255){
                                            lcd_cmd(_lcd_clear);
                                            portc = 0;
                                            break;
                                          }
                                        }

                                  }else if ((x > 50) && (x <=75) && (ADC_read(2)/2 >= 60)){
                                        while(x <=75){
                                          portc = 0b00100100;
                                          //le a temperatura atual e transforma para char
                                          wordtostr(ADC_read(2)/2, txtTemperatura);
                                          //escreve a temperatura atual
                                          lcd_out(1,1, "Temperatura");
                                          lcd_out_cp(txtTemperatura);
                                          lcd_out(2,1, "Resfriando");
                                          x = adc_read(0)/10.23;
                                          wordtostr(x, txtPotenciometro);
                                          lcd_out(3,-3, "Potencia");
                                          lcd_out_cp(txtPotenciometro);
                                          portc = 0b00100000;
                                          lcd_out_cp("%");
                                          if(button(&portb, 1, 1, 0) == 255){
                                            lcd_cmd(_lcd_clear);
                                            portc = 0;
                                            break;
                                          }
                                        }

                                  }else if ((x > 75) && (x <=99) && (ADC_read(2)/2 >= 70)){
                                        while(x <100){
                                          portc = 0b00100100;
                                          //le a temperatura atual e transforma para char
                                          wordtostr(ADC_read(2)/2, txtTemperatura);
                                          //escreve a temperatura atual
                                          lcd_out(1,1, "Temperatura");
                                          lcd_out_cp(txtTemperatura);
                                          lcd_out(2,1, "Resfriando");
                                          x = adc_read(0)/10.23;
                                          wordtostr(x, txtPotenciometro);
                                          lcd_out(3,-3, "Potencia");
                                          lcd_out_cp(txtPotenciometro);
                                          portc = 0b00100000;
                                          lcd_out_cp("%");
                                          if(button(&portb, 1, 1, 0) == 255){
                                            lcd_cmd(_lcd_clear);
                                            portc = 0;
                                            break;
                                          }
                                        }
                                  }if (x == 100){
                                            // usuario tem 5 segundo para abaixar a potencia
                                            //abaixo de 100, senão o sistema acusara Erro
                                            delay_ms(5000);
                                            if(button(&portb, 1, 1, 0) == 255){
                                              lcd_cmd(_lcd_clear);
                                              portc = 0;
                                              porta = 0;
                                              portd = 0;
                                              break;
                                            }
                                            x = adc_read(0)/10.23;
                                            if(x == 100){
                                              trisa = 0;
                                              trisd = 0;
                                              porta = 0b00000100;
                                              // mostra a letra E no display 1, a letra E significa erro
                                              portd = 0b01111001;
                                              delay_ms(800)
                                             break;

                                            }
                                        //portd = 0;
                                   }
                                }
              }
     }
}