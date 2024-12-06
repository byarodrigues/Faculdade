void main() {
     int a = 1;
     int i = 0;
     
     TRISD = 0;//define d como saída
     TRISA = 0; // define a como saída de 4bits
     PORTA = 0b00111100; //define o segmento "2" como saída
     while(i<8){
                PORTD = a; //define uma saída para d
                delay_ms (1000);
                a = a*2;
                i = i + 1;
     }
     

}