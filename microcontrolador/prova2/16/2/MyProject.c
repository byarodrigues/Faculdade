void main(){
     trisb = 0;
     while(1){
                  portb = 0b11110000;
                  delay_ms(2000);
                  portb = 0b00001111;
                  delay_ms(2000);
     }
}