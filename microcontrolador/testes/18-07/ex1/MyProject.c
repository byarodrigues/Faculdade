void main() {
     trisb = 0;
     trisd = 0;
     while(1){
              portd = 0b11111111;
              portb = 0b00000000;
              delay_ms(500);
              portd = 0b00000000;
              portb = 0b11111111;
              delay_ms(500);

     }
}