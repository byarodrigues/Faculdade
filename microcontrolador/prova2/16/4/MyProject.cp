#line 1 "C:/Users/bya/Desktop/computação/2022.2/microcontroladores/prova2/16/4/MyProject.c"
void main() {
 int i = 0;
 int a = 1;
 trisd = 0;
 while(1){
 while(i<8){
 portd = a;
 a = a*2;
 i = i + 1;
 delay_ms(500);
 }
 i = 1;
 while(i<9){
 portd = a;
 a = a/2;
 delay_ms(500);
 i = i + 1;
 }
 }
}
