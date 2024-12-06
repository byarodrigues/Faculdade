
_main:

;MyProject.c,1 :: 		void main() {
;MyProject.c,2 :: 		trisb = 0;
	CLRF        TRISB+0 
;MyProject.c,3 :: 		trisd = 0;
	CLRF        TRISD+0 
;MyProject.c,4 :: 		while(1){
L_main0:
;MyProject.c,5 :: 		portd = 0b11111111;
	MOVLW       255
	MOVWF       PORTD+0 
;MyProject.c,6 :: 		portb = 0b00000000;
	CLRF        PORTB+0 
;MyProject.c,7 :: 		delay_ms(500);
	MOVLW       6
	MOVWF       R11, 0
	MOVLW       19
	MOVWF       R12, 0
	MOVLW       173
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
;MyProject.c,8 :: 		portd = 0b00000000;
	CLRF        PORTD+0 
;MyProject.c,9 :: 		portb = 0b11111111;
	MOVLW       255
	MOVWF       PORTB+0 
;MyProject.c,10 :: 		delay_ms(500);
	MOVLW       6
	MOVWF       R11, 0
	MOVLW       19
	MOVWF       R12, 0
	MOVLW       173
	MOVWF       R13, 0
L_main3:
	DECFSZ      R13, 1, 1
	BRA         L_main3
	DECFSZ      R12, 1, 1
	BRA         L_main3
	DECFSZ      R11, 1, 1
	BRA         L_main3
	NOP
	NOP
;MyProject.c,12 :: 		}
	GOTO        L_main0
;MyProject.c,13 :: 		}
L_end_main:
	GOTO        $+0
; end of _main
