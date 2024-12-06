void main() {
     int i = 0; int a = 1; int b = 128;
     trisd = 0b00000000;
     trisb = 0b00000000;
     
     while(1){
              a = 1; i = 0;
              while(i<=8){
              portd = a;
              delay_ms(500);
              a = a*2+1;
              }
     }
     
}