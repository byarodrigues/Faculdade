void main() {
     int i = 0;
     trisb = 0b00000010;
     TRISA = 0; // define a como saída de 4bits
     TRISD = 0;//define d como saída
     PORTA = 0b00001100; //define o segmento "2" como saída
     while(1){
              i = 1;
              if(button(&portb,5,1,0)==255){
                       portd = 0;
                       porta = 0b00001000;
                       portd = 0b00000110;
                       delay_ms(500);
              }
              i=0;
     }
}