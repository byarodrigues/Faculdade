void main() {
     trisd = 0;
     portd = 0b11111111;
     delay_ms(2000);
     portd = 0;
     delay_ms(3000);
     portd = 0b00001111;
     delay_ms(4000);
     portd = 0;

}