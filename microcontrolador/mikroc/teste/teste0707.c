void main() {
     int a = 1;
     int i = 0;
     
     TRISD = 0;//define d como sa�da
     TRISA = 0; // define a como sa�da de 4bits
     PORTA = 0b00111100; //define o segmento "2" como sa�da
     while(i<8){
                PORTD = a; //define uma sa�da para d
                delay_ms (1000);
                a = a*2;
                i = i + 1;
     }
     

}