
_main:

;MyProject.c,1 :: 		void main() {
;MyProject.c,2 :: 		trisd = 0;
	CLRF        TRISD+0 
;MyProject.c,3 :: 		while(1){
L_main0:
;MyProject.c,4 :: 		portd = 0b11111111;
	MOVLW       255
	MOVWF       PORTD+0 
;MyProject.c,5 :: 		delay_ms(2000);
	MOVLW       21
	MOVWF       R11, 0
	MOVLW       75
	MOVWF       R12, 0
	MOVLW       190
	MOVWF       R13, 0
L_main2:
	DECFSZ      R13, 1, 1
	BRA         L_main2
	DECFSZ      R12, 1, 1
	BRA         L_main2
	DECFSZ      R11, 1, 1
	BRA         L_main2
	NOP
;MyProject.c,6 :: 		portd = 0b00000000;
	CLRF        PORTD+0 
;MyProject.c,7 :: 		delay_ms(2000);
	MOVLW       21
	MOVWF       R11, 0
	MOVLW       75
	MOVWF       R12, 0
	MOVLW       190
	MOVWF       R13, 0
L_main3:
	DECFSZ      R13, 1, 1
	BRA         L_main3
	DECFSZ      R12, 1, 1
	BRA         L_main3
	DECFSZ      R11, 1, 1
	BRA         L_main3
	NOP
;MyProject.c,8 :: 		}
	GOTO        L_main0
;MyProject.c,9 :: 		}
L_end_main:
	GOTO        $+0
; end of _main
