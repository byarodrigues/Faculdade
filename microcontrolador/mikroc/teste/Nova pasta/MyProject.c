void main() {
     int i = 0; int a = 128; int b = 64;
     trisd = 0;
     while(1){
              while(i<=8){
              portd = a;
              delay_ms(500);
              a = a + b;
              b = b/2;
              }
              i = 0; a = 128; b = 64;
     }
}