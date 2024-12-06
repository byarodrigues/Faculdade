#line 1 "C:/Users/bya/Desktop/computação/2022.2/microcontroladores/prova2/12/5/MyProject.c"
void main() {
 trisd = 0;
 portd = 0b11111111;
 delay_ms(2000);
 portd = 0;
 delay_ms(3000);
 portd = 0b00001111;
 delay_ms(4000);
 portd = 0;

}
