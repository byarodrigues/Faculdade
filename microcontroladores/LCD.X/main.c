/*
 * File:   main.c
 * Author: Talles Portilho
 *
 * Created on 9 de Setembro de 2020, 21:15
 */

// PIC18F4550 Configuration Bit Settings

// 'C' source line config statements

#include "config.h"


unsigned int tempoLED = 0;
uint8_t contaDebounce = 0;
bool flag1Botao1 = 0;


void main(void) {
    
    bool flag1Botao2 = 0;
    bool flag2Botao1 = 0;
    uint8_t funcaoRB0 = 0;
    char str[6];
    unsigned int tmpi;

    //Configura o clock
    OSCCONbits.SCS = 0b00;          // 11 O oscilador inteno é definido como clock do sistema 00 cristal externo

    //Configura as portas
    TRISA = 0b00000001;             //Portas para conversão A/D devem ser configuradas com entradas    
    TRISB = 0b00000011;             //2 botões RB0 e RB1
    TRISC = 0;                      //RC2 aquecedor
    TRISD = 0;
    TRISE = 0;

    //Inicializa as portas
    PORTA=0x00;
    PORTB=0x00;
    PORTC=0x00;
    PORTD=0x00;
    PORTE=0x00;
        
    
    //Configurar o TIMER0
    T0CONbits.TMR0ON = 1;       //habilita o timer0
    T0CONbits.T08BIT = 1;       //seleciona contador de 8 bits
    T0CONbits.T0CS = 0;         //seleciona o clock interno (ciclo de máquina, Fosc/4)
    T0CONbits.PSA = 0;          //O sinal de clock vem do prescaler
    T0CONbits.T0PS = 0b110;     //Divide o ciclo de máquina por 128
    TMR0=217;                   //TMR0IF é setado quando TMR0 vai de 255 para 0 (256-39=217)
    //Incrementa o timer em 39*128*4*(1/16MHz)= 1,25ms
    
        
    //Configura as interrupções
    RCONbits.IPEN = 1;          // habilita a prioridade das interrupções
    
    INTCONbits.TMR0IE = 1;      // habilita a interrupção pelo estouro do timer0
    INTCON2bits.TMR0IP = 1;     // Alta prioridade no TMR0

    INTCONbits.GIEH = 1;        //habilita interrupção de alta prioridade
    INTCONbits.GIEL = 1;        //habilita interrupção de baixa prioridade

    
    
    lcd_init();                 //Configura e inicializa LCD
    
    adc_init();                 //Configura e inicializa adc
 

    lcd_cmd(L_NCR);

    while(1){


        
        if(tempoLED>=240){                //240*1,25ms=300ms pisca LED
            PORTBbits.RB3 = ~PORTBbits.RB3;
            tempoLED = 0;
        
        
            //Mostra temperatura
        
            tmpi=(((unsigned int) adc_amostra(0)*10)/8)-150; //conversão AD
        
            itoa(str,tmpi,10); //sprintf(str, "%u.%u", value / 10, value % 10); C90 C99 standard

           //lcd_cmd(L_CLR);
            lcd_cmd(L_L1);
            lcd_str("Conv. A/D e LCD");
            lcd_cmd(L_L2);
            lcd_str("Temp.: ");
            lcd_dat(str[0]);
            lcd_dat(str[1]);
            lcd_dat(',');
            lcd_dat(str[2]);
            //lcd_dat(str[3]);
            //lcd_dat(str[4]);
            //lcd_dat(str[5]);   
            lcd_dat('C');

        }  

   
        if(!flag1Botao1 && !PORTBbits.RB0 && !flag2Botao1){
            flag1Botao1=true;   // inicia incremento de contaDebounce no timer
        }    
        if(contaDebounce >= 6){
            if(!PORTBbits.RB0){
                flag2Botao1 = true;

                flag1Botao1 = false;
                contaDebounce = 0;
            }
        }    
        if(flag2Botao1 && PORTBbits.RB0){ //Aqui é inserido código para ser executado após soltar o botão
            funcaoRB0++;
            if(funcaoRB0>=3){
                funcaoRB0 = 0;
            }
            flag2Botao1 = false;
        }     
        if(funcaoRB0 == 0){
            PORTBbits.RB2 = 0;
            PORTCbits.RC2 = 0;
        }
        if(funcaoRB0 == 1){
            PORTBbits.RB2 = PORTBbits.RB3;
            PORTCbits.RC2 = PORTBbits.RB3;
        }    
        if(funcaoRB0 == 2){
            PORTBbits.RB2 = 1;
            PORTCbits.RC2 = 1;
        } 


  }  
    
}


void __interrupt() rotinaAltaPrioridade(void){               //endereço da memória 0x008
    INTCONbits.GIEH = 0;
    
    if(INTCONbits.TMR0IF){      //testa a flag

        if(flag1Botao1){
            contaDebounce++;
        }
        
        tempoLED++; 
        
        INTCONbits.TMR0IF = 0;
        TMR0=217;
    }
    
     INTCONbits.GIEH = 1;
}

void __interrupt(low_priority) rotinaBaixaPrioridade(void){  //endereço da memória 0x018
    INTCONbits.GIEH = 0;    // INTCONbits.GIEL = 0; para permitir desvio para interrupção de alta prioridade
    

    INTCONbits.GIEH = 1;    // INTCONbits.GIEL = 1; complementar ao comentário superior   
    
}


