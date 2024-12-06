//1 – Fazer um programa que a cada segundo acenda
//    led à led do LSB para MSB da porta B. Usar timer.


void main() {
t0con = 0b10000110;
tmr0l = 0xf7;
tmr0h = 0xc2;
intcon.tmr0if = 0;
trisb = 0;
portb = 0XFF;
while(1){
         if(intcon.tmr0if == 1){
                            tmr0l = 0xf7;
                            tmr0h = 0xc2;
                            intcon.tmr0if = 0;
                            portb = ~portb;
                          }
         }


}