#line 1 "C:/Users/bya/Desktop/computação/2022.2/microcontroladores/testes/21-07/ex2/MyProject.c"
void main() {
 int i = 0;
 trisb = 0b00000010;
 TRISA = 0;
 TRISD = 0;
 PORTA = 0b00001100;

 while(1){


 for(i=0;i<10;i++){
 porta = 0b00000100;
 portd = 0b00000110;
 delay_ms(20);
 porta = 0b00001000;
 portd = 0b00111111;
 delay_ms(30);
 }
 porta = 0b00001100;
 portd = 0b00000110;
 delay_ms(500);
 for(i=0;i<10;i++){
 porta = 0b00000100;
 portd = 0b00000110;
 delay_ms(20);
 porta = 0b00001000;
 portd = 91;
 delay_ms(30);
 }




 }

}
