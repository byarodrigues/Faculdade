void main() {
     TRISA = 0; // define a como sa�da de 4bits
     TRISD = 0;//define d como sa�da
     PORTA = 0b00000100; //define o segmento "2" como sa�da
     PORTD = 0b01001111; //define uma sa�da para d
     //PORTD = 0b00000001; //define uma sa�da no seguimento de cima
     //PORTD = 0b00000010; //define uma sa�da no seguimento da direita em cima
     //PORTD = 0b00000100; //define uma sa�da no seguimento da direita em baixo
     //PORTD = 0b00001000; //define uma sa�da no seguimento de baixo
     //PORTD = 0b00010000; //define uma sa�da no seguimento da esquerda em baixo
     //PORTD = 0b00100000; //define uma sa�da no seguimento da esquerda em cima
     //PORTD = 0b01000000; //define uma sa�da no seguimento do meio
     //PORTD = 0b10000000; //define uma sa�da no seguimento "ponto"

}
