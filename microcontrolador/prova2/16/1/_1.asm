
_main:

;_1.c,1 :: 		void main() {
;_1.c,2 :: 		trisb = 255;
	MOVLW       255
	MOVWF       TRISB+0 
;_1.c,3 :: 		trisd = 0;
	CLRF        TRISD+0 
;_1.c,4 :: 		while(1){
L_main0:
;_1.c,5 :: 		int i = 0;
	CLRF        main_i_L1+0 
	CLRF        main_i_L1+1 
	MOVLW       1
	MOVWF       main_a_L1+0 
	MOVLW       0
	MOVWF       main_a_L1+1 
;_1.c,7 :: 		if(button(&portb,5,1,0)==255){
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
;_1.c,8 :: 		while(i<9){
L_main3:
	MOVLW       128
	XORWF       main_i_L1+1, 0 
	MOVWF       R0 
	MOVLW       128
	SUBWF       R0, 0 
	BTFSS       STATUS+0, 2 
	GOTO        L__main7
	MOVLW       9
	SUBWF       main_i_L1+0, 0 
L__main7:
	BTFSC       STATUS+0, 0 
	GOTO        L_main4
;_1.c,9 :: 		portd = a;
	MOVF        main_a_L1+0, 0 
	MOVWF       PORTD+0 
;_1.c,10 :: 		delay_ms(500);
	MOVLW       6
	MOVWF       R11, 0
	MOVLW       19
	MOVWF       R12, 0
	MOVLW       173
	MOVWF       R13, 0
L_main5:
	DECFSZ      R13, 1, 1
	BRA         L_main5
	DECFSZ      R12, 1, 1
	BRA         L_main5
	DECFSZ      R11, 1, 1
	BRA         L_main5
	NOP
	NOP
;_1.c,11 :: 		a = a*2+1;
	RLCF        main_a_L1+0, 1 
	BCF         main_a_L1+0, 0 
	RLCF        main_a_L1+1, 1 
	INFSNZ      main_a_L1+0, 1 
	INCF        main_a_L1+1, 1 
;_1.c,12 :: 		i = i + 1;
	INFSNZ      main_i_L1+0, 1 
	INCF        main_i_L1+1, 1 
;_1.c,13 :: 		}
	GOTO        L_main3
L_main4:
;_1.c,14 :: 		}
L_main2:
;_1.c,15 :: 		}
	GOTO        L_main0
;_1.c,16 :: 		}
L_end_main:
	GOTO        $+0
; end of _main
