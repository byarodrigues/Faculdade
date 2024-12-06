
_main:

;MyProject2.c,1 :: 		void main() {
;MyProject2.c,2 :: 		TRISA = 0; // define a como saída de 4bits
	CLRF        TRISA+0 
;MyProject2.c,3 :: 		TRISD = 0;//define d como saída
	CLRF        TRISD+0 
;MyProject2.c,4 :: 		PORTA = 0b00000100; //define o segmento "2" como saída
	MOVLW       4
	MOVWF       PORTA+0 
;MyProject2.c,5 :: 		PORTD = 0b01001111; //define uma saída para d
	MOVLW       79
	MOVWF       PORTD+0 
;MyProject2.c,6 :: 		}
L_end_main:
	GOTO        $+0
; end of _main
