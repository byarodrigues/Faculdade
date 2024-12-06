
_main:

;MyProject.c,1 :: 		void main() {
;MyProject.c,2 :: 		trisd = 0;
	CLRF        TRISD+0 
;MyProject.c,3 :: 		portd = 0b11111111;
	MOVLW       255
	MOVWF       PORTD+0 
;MyProject.c,4 :: 		delay_ms(2000);
	MOVLW       21
	MOVWF       R11, 0
	MOVLW       75
	MOVWF       R12, 0
	MOVLW       190
	MOVWF       R13, 0
L_main0:
	DECFSZ      R13, 1, 1
	BRA         L_main0
	DECFSZ      R12, 1, 1
	BRA         L_main0
	DECFSZ      R11, 1, 1
	BRA         L_main0
	NOP
;MyProject.c,5 :: 		portd = 0;
	CLRF        PORTD+0 
;MyProject.c,6 :: 		delay_ms(3000);
	MOVLW       31
	MOVWF       R11, 0
	MOVLW       113
	MOVWF       R12, 0
	MOVLW       30
	MOVWF       R13, 0
L_main1:
	DECFSZ      R13, 1, 1
	BRA         L_main1
	DECFSZ      R12, 1, 1
	BRA         L_main1
	DECFSZ      R11, 1, 1
	BRA         L_main1
	NOP
;MyProject.c,7 :: 		portd = 0b00001111;
	MOVLW       15
	MOVWF       PORTD+0 
;MyProject.c,8 :: 		delay_ms(4000);
	MOVLW       41
	MOVWF       R11, 0
	MOVLW       150
	MOVWF       R12, 0
	MOVLW       127
	MOVWF       R13, 0
L_main2:
	DECFSZ      R13, 1, 1
	BRA         L_main2
	DECFSZ      R12, 1, 1
	BRA         L_main2
	DECFSZ      R11, 1, 1
	BRA         L_main2
;MyProject.c,9 :: 		portd = 0;
	CLRF        PORTD+0 
;MyProject.c,11 :: 		}
L_end_main:
	GOTO        $+0
; end of _main
