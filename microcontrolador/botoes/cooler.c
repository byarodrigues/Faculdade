void main() {
trisb = 0b00001111;
trisc = 0;
pwm1_init(5000);
while(1){
         if(button(&portb, 0,1,0) == 255){
                                          pwm1_set_duty(63);
                                          pwm1_start();
                                          portc = 0b00000100;

                                          }
         if(button(&portb, 1,1,0) == 255){
                                          pwm1_set_duty(127);
                                          pwm1_start();
                                          portc = 0b00000100;

                                          }
         if(button(&portb, 2,1,0) == 255){
                                          pwm1_set_duty(200);
                                          pwm1_start();
                                          portc = 0b00000100;

                                          }
         if(button(&portb, 3,1,0) == 255){
                                          pwm1_set_duty(255);
                                          pwm1_start();
                                          portc = 0b00000100;
                                          portc = 0b00000010;

                                          }
                                          
       }

}