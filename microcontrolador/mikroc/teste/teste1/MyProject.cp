#line 1 "C:/Users/bya/Desktop/computação/2022.2/microcontroladores/mikroc/teste/teste1/MyProject.c"
void main() {
 int a = 1;
 int i = 0;

 TRISD = 0;
 TRISA = 0;
 PORTA = 0b00111100;
 while(i<8){
 PORTD = a;
 delay_ms (1000);
 a = a*2;
 i = i + 1;
 }
}
