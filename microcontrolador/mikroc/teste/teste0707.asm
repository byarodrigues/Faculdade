
_main:

;teste0707.c,1 :: 		void main() {
;teste0707.c,2 :: 		int a = 1;
	MOVLW       1
	MOVWF       main_a_L0+0 
	MOVLW       0
	MOVWF       main_a_L0+1 
	CLRF        main_i_L0+0 
	CLRF        main_i_L0+1 
;teste0707.c,5 :: 		TRISD = 0;//define d como saída
	CLRF        TRISD+0 
;teste0707.c,6 :: 		TRISA = 0; // define a como saída de 4bits
	CLRF        TRISA+0 
;teste0707.c,7 :: 		PORTA = 0b00111100; //define o segmento "2" como saída
	MOVLW       60
	MOVWF       PORTA+0 
;teste0707.c,8 :: 		while(i<8){
L_main0:
	MOVLW       128
	XORWF       main_i_L0+1, 0 
	MOVWF       R0 
	MOVLW       128
	SUBWF       R0, 0 
	BTFSS       STATUS+0, 2 
	GOTO        L__main4
	MOVLW       8
	SUBWF       main_i_L0+0, 0 
L__main4:
	BTFSC       STATUS+0, 0 
	GOTO        L_main1
;teste0707.c,9 :: 		PORTD = a; //define uma saída para d
	MOVF        main_a_L0+0, 0 
	MOVWF       PORTD+0 
;teste0707.c,10 :: 		delay_ms (1000);
	MOVLW       11
	MOVWF       R11, 0
	MOVLW       38
	MOVWF       R12, 0
	MOVLW       93
	MOVWF       R13, 0
L_main2:
	DECFSZ      R13, 1, 1
	BRA         L_main2
	DECFSZ      R12, 1, 1
	BRA         L_main2
	DECFSZ      R11, 1, 1
	BRA         L_main2
	NOP
	NOP
;teste0707.c,11 :: 		a = a*2;
	RLCF        main_a_L0+0, 1 
	BCF         main_a_L0+0, 0 
	RLCF        main_a_L0+1, 1 
;teste0707.c,12 :: 		i = i + 1;
	INFSNZ      main_i_L0+0, 1 
	INCF        main_i_L0+1, 1 
;teste0707.c,13 :: 		}
	GOTO        L_main0
L_main1:
;teste0707.c,16 :: 		}
L_end_main:
	GOTO        $+0
; end of _main
