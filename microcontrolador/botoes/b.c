void main() {
int aux = 0;
trisb = 0b00100000;
while(1){
         if(button(&portb, 5,1,0) == 255){
          aux++;
          if(aux > 2){
                 aux = 0;
          }
         }
switch(aux){
case 0:
portd = 0;
break;
case 1:
trisA = 0;
portA = 0b00100000;
trisD = 0;
portd = 0x3F;
break;
case 2:
trisA = 0;
portA = 0b00010000;
trisd = 0;
portd = 0x3F;
break;
}
}


}
