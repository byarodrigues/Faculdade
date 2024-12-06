void main() {
int aux = 0;
trisb = 0b00000011;
trisA = 0;
TrisD = 0;
portA = 0b00111100;

while(1){
if(button(&portb, 1,1,0) == 255){
aux++;
delay_ms(50);
}

switch(aux){
case 0:
portd = 0x3F;
break;
case 1:
portd = 0x06;
break;
case 2:
portd = 0x5B;
break;
case 3:
portd = 0x4F;
break;
case 4:
portd = 0x66;
break;
case 5:
portd = 0x6D;
break;
case 6:
portd = 0x7D;
break;
case 7:
portd = 0x07;
break;
case 8:
portd = 0x7D;
break;
case 9:
portd = 0x67;
break;

}
}
}
