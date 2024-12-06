void main() {
     int i = 0;
     trisb = 0b00000010;
     TRISA = 0; // define a como saída de 4bits
     TRISD = 0;//define d como saída
     PORTA = 0b00001100; //define o segmento "2" como saída
     
     while(1){
     
             // if(button(&portb,1,1,0)){
                  for(i=0;i<10;i++){
                       porta = 0b00000100;
                       portd = 0b00000110;
                       delay_ms(20);
                       porta = 0b00001000;
                       portd = 0b00111111;
                       delay_ms(30);
                  }
                  porta = 0b00001100;
                  portd = 0b00000110;
                  delay_ms(500);
                  for(i=0;i<10;i++){
                       porta = 0b00000100;
                       portd = 0b00000110;
                       delay_ms(20);
                       porta = 0b00001000;
                       portd = 91;
                       delay_ms(30);
                  }


             // }

     }

}