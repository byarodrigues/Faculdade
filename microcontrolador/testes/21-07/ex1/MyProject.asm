
_main:

;MyProject.c,1 :: 		void main() {
;MyProject.c,2 :: 		trisb = 0b00000001; //rb0 entrada
	MOVLW       1
	MOVWF       TRISB+0 
;MyProject.c,3 :: 		trisd = 0b00000000; //rd0 saida
	CLRF        TRISD+0 
;MyProject.c,4 :: 		while(1){
L_main0:
;MyProject.c,5 :: 		if(button(&portb,0,1,0)){
	MOVLW       PORTB+0
	MOVWF       FARG_Button_port+0 
	MOVLW       hi_addr(PORTB+0)
	MOVWF       FARG_Button_port+1 
	CLRF        FARG_Button_pin+0 
	MOVLW       1
	MOVWF       FARG_Button_time_ms+0 
	CLRF        FARG_Button_active_state+0 
	CALL        _Button+0, 0
	MOVF        R0, 1 
	BTFSC       STATUS+0, 2 
	GOTO        L_main2
;MyProject.c,6 :: 		portd = 0b00000001;
	MOVLW       1
	MOVWF       PORTD+0 
;MyProject.c,7 :: 		delay_ms(500);
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
;MyProject.c,8 :: 		}
L_main2:
;MyProject.c,9 :: 		portd = 0;
	CLRF        PORTD+0 
;MyProject.c,10 :: 		}
	GOTO        L_main0
;MyProject.c,11 :: 		}
L_end_main:
	GOTO        $+0
; end of _main
