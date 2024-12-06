#line 1 "C:/Users/bya/Desktop/computação/2022.2/microcontroladores/prova2/12/6/MyProject.c"
void main() {
 trisd = 0;
 while(1){
 portd = 0b11111111;
 delay_ms(2000);
 portd = 0b00000000;
 delay_ms(2000);
 }
}
