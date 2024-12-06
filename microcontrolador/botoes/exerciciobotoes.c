void ex1(){
int aux = 1;
trisd = 0;
portd = 0;
delay_ms(50);

while(aux<=255){
portd = aux;
aux = (aux*2)+1;
delay_ms(50);
}
}




void main() {
int aux = 255;
trisD = 0;
portd = aux;

}
