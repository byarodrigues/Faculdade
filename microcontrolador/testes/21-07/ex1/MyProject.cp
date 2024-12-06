#line 1 "C:/Users/bya/Desktop/computação/2022.2/microcontroladores/testes/21-07/ex1/MyProject.c"
void main() {
 trisb = 0b00000001;
 trisd = 0b00000000;
 while(1){
 if(button(&portb,0,1,0)){
 portd = 0b00000001;
 delay_ms(500);
 }
 portd = 0;
 }
}
