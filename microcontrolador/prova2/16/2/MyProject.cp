#line 1 "C:/Users/bya/Desktop/computa��o/2022.2/microcontroladores/prova2/16/2/MyProject.c"
void main(){
 trisb = 0;
 while(1){
 portb = 0b11110000;
 delay_ms(2000);
 portb = 0b00001111;
 delay_ms(2000);
 }
}
