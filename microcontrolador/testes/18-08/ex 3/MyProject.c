void main() {
     int i = 0; int a = 128; int b = 64; int c = 1; int d = 1;
     trisd = 0b00000000;
     trisb = 0b00000000;

     while(1){
     portd = a;
     portb = d;
     delay_ms(500);

     a = a + b;
     b = b/2;
     d = d*2+1;
 }
 
 }