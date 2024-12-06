
_main:

;MyProject.c,1 :: 		void main() {
;MyProject.c,2 :: 		int a = 1;
	MOVLW       1
	MOVWF       main_a_L0+0 
	MOVLW       0
	MOVWF       main_a_L0+1 
;MyProject.c,3 :: 		trisb = 255;
	MOVLW       255
	MOVWF       TRISB+0 
;MyProject.c,4 :: 		trisd = 0;
	CLRF        TRISD+0 
;MyProject.c,5 :: 		portb = 0;
	CLRF        PORTB+0 
;MyProject.c,6 :: 		portd = 0;
	CLRF        PORTD+0 
;MyProject.c,7 :: 		while(1){
L_main0:
;MyProject.c,8 :: 		if(button(&portb,5,1,0)==255){
	MOVLW       PORTB+0
	MOVWF       FARG_Button_port+0 
	MOVLW       hi_addr(PORTB+0)
	MOVWF       FARG_Button_port+1 
	MOVLW       5
	MOVWF       FARG_Button_pin+0 
	MOVLW       1
	MOVWF       FARG_Button_time_ms+0 
	CLRF        FARG_Button_active_state+0 
	CALL        _Button+0, 0
	MOVF        R0, 0 
	XORLW       255
	BTFSS       STATUS+0, 2 
	GOTO        L_main2
;MyProject.c,9 :: 		portd = a;
	MOVF        main_a_L0+0, 0 
	MOVWF       PORTD+0 
;MyProject.c,10 :: 		a = a*2+1;
	RLCF        main_a_L0+0, 1 
	BCF         main_a_L0+0, 0 
	RLCF        main_a_L0+1, 1 
	INFSNZ      main_a_L0+0, 1 
	INCF        main_a_L0+1, 1 
;MyProject.c,11 :: 		delay_ms(500);
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
L_main2:
;MyProject.c,13 :: 		}
	GOTO        L_main0
;MyProject.c,14 :: 		}
L_end_main:
	GOTO        $+0
; end of _main
