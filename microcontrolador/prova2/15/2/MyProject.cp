#line 1 "C:/Users/bya/Desktop/computação/2022.2/microcontroladores/prova2/15/2/MyProject.c"
void main() {
 trisd = 0;
 trisa = 0;
 while(1){
 porta = 0b00000100;
 portd = 0x3F;
 delay_ms(1000);
 porta = 0b00001000;
 portd = 0x06;
 delay_ms(1000);
 porta = 0b00010000;
 portd = 0x5B;
 delay_ms(1000);
 porta = 0b00100000;
 portd = 0x4F;
 delay_ms(1000);
 porta = 0b00000100;
 portd = 0x66;
 delay_ms(1000);
 porta = 0b00001000;
 portd = 0x6D;
 delay_ms(1000);
 porta = 0b00010000;
 portd = 0x7D;
 delay_ms(1000);
 porta = 0b00100000;
 portd = 0x07;
 delay_ms(1000);
 porta = 0b00000100;
 portd = 0x7F;
 delay_ms(1000);
 porta = 0b00001000;
 portd = 0x6F;
 delay_ms(1000);

 while(1){
 porta = 0b00000100;
 portd = 0b00111111;
 porta = 0b00001000;
 portd = 0b00111111;
 }
 }
}
