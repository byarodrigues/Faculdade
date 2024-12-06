
_main:

;MyProject.c,1 :: 		void main() {
;MyProject.c,2 :: 		trisa = 0;
	CLRF        TRISA+0 
;MyProject.c,3 :: 		trisd = 0;
	CLRF        TRISD+0 
;MyProject.c,4 :: 		while(1){
L_main0:
;MyProject.c,5 :: 		porta = 0b00000100;
	MOVLW       4
	MOVWF       PORTA+0 
;MyProject.c,6 :: 		portd = 0b00000001;
	MOVLW       1
	MOVWF       PORTD+0 
;MyProject.c,7 :: 		portd = 0b00000010;
	MOVLW       2
	MOVWF       PORTD+0 
;MyProject.c,8 :: 		portd = 0b00000100;
	MOVLW       4
	MOVWF       PORTD+0 
;MyProject.c,9 :: 		portd = 0b00001000;
	MOVLW       8
	MOVWF       PORTD+0 
;MyProject.c,10 :: 		portd = 0b00010000;
	MOVLW       16
	MOVWF       PORTD+0 
;MyProject.c,11 :: 		portd = 0b00100000;
	MOVLW       32
	MOVWF       PORTD+0 
;MyProject.c,12 :: 		portd = 0b01000000;
	MOVLW       64
	MOVWF       PORTD+0 
;MyProject.c,13 :: 		portd = 0b10000000;
	MOVLW       128
	MOVWF       PORTD+0 
;MyProject.c,14 :: 		}
	GOTO        L_main0
;MyProject.c,15 :: 		}
L_end_main:
	GOTO        $+0
; end of _main
