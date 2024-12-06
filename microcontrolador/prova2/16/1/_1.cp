#line 1 "C:/Users/bya/Desktop/computação/2022.2/microcontroladores/prova2/16/1/_1.c"
void main() {
 trisb = 255;
 trisd = 0;
 while(1){
 int i = 0;
 int a = 1;
 if(button(&portb,5,1,0)==255){
 while(i<9){
 portd = a;
 delay_ms(500);
 a = a*2+1;
 i = i + 1;
 }
 }
 }
}
