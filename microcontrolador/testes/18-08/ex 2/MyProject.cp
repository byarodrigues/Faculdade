#line 1 "C:/Users/bya/Desktop/computação/2022.2/microcontroladores/testes/18-07/ex 2/MyProject.c"
void main() {
 int i = 0; int a = 128; int b = 64;
 trisd = 0b00000000;
 trisb = 0b00000000;

 while(b<255){
 portd = a;
 delay_ms(500);
 a = a + b;
 b = b/2;
 portb = i;
 delay_ms(500);
 i = i + b;

 }

}
