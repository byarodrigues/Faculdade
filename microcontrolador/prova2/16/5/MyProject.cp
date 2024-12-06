#line 1 "C:/Users/bya/Desktop/computação/2022.2/microcontroladores/prova2/16/5/MyProject.c"
void main() {
 int a = 1;
 trisb = 255;
 trisd = 0;
 portb = 0;
 portd = 0;
 while(1){
 if(button(&portb,5,1,0)==255){
 portd = a;
 a = a*2+1;
 delay_ms(500);
 }
 }
}
