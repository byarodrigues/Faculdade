void main() {
     int i = 0;
     int a = 1;
     trisd = 0;
     while(1){
          while(i<8){
              portd = a;
              a = a*2;
              i = i + 1;
              delay_ms(500);
          }
          i = 1;
          while(i<9){
              portd = a;
              a = a/2;
              delay_ms(500);
              i = i + 1;
          }
     }
}