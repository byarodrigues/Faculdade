#line 1 "C:/Users/bya/Desktop/computação/2022.2/microcontroladores/prova2/16/6/MyProject.c"
void main() {
 int i = 0;
 trisb = 255;
 trisd = 0;
 portb = 0;
 portd = 0;
 while(1){
 i = 0;
 if(button(&portb,5,1,0)==255){
 i = 1;
 if(i=1){
 portd = 0x06;
 delay_ms(500);
 }
 else if(i=2){
 portd = 0x5B;
 }
 i = i+1;
 }

 }
}
