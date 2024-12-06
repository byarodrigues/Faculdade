void main() {
     trisd = 0;
     while(1){
              portd = 0b11111111;
              delay_ms(2000);
              portd = 0b00000000;
              delay_ms(2000);
     }
}