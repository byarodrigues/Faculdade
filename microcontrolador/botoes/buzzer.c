void main() {
trisC = 0;
portb = 0b00100000;

while(1){
         if(button(&portb,5,1,0) == 255){
         portc = 0b0000010;
         }else{
         portc = 0;
         }
         }


}