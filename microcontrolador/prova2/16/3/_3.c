void main() {
     int a = 128;
     int b = 128;
     trisd = 0;
     while(1){
          portd = a;
          a = a+b/2;
          b = b/2;
          delay_ms(500);
     }
}