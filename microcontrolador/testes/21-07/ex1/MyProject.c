void main() {
     trisb = 0b00000001; //rb0 entrada
     trisd = 0b00000000; //rd0 saida
     while(1){
              if(button(&portb,0,1,0)){
                    portd = 0b00000001;
                    delay_ms(500);
              }
              portd = 0;
     }
}