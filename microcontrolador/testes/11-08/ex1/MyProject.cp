#line 1 "C:/Users/bya/Desktop/computação/2022.2/microcontroladores/testes/11-08/ex1/MyProject.c"
void main() {
 tmr0l = 0xf7;
 tmr0h = 0xc2;
 t0con = 0b10000110;
 intcon.TMR0IF = 0;
 trisd = 0;
 portd = 0;
 while(1){
 if(intcon.tmr0if == 1){
 tmr0l = 0xf7;
 tmr0h = 0xc2;
 intcon.TMR0IF = 0;
 portd = ~portd;

 }

 }


}
