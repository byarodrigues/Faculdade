void main() {
     trisb = 0b00000011;


     while(1){
     trisD = 0;
     portd = 255;

       if(button(&portb, 0, 1, 0) == 255 ){
       trisD = 0;
       portd = 0;
       delay_ms(500);

}}    }