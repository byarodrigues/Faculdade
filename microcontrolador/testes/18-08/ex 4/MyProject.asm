
_main:

;MyProject.c,1 :: 		void main() {
;MyProject.c,3 :: 		int a = 128; int b = 64; int d = 1;
	MOVLW       128
	MOVWF       main_a_L0+0 
	MOVLW       0
	MOVWF       main_a_L0+1 
	MOVLW       64
	MOVWF       main_b_L0+0 
	MOVLW       0
	MOVWF       main_b_L0+1 
	MOVLW       1
	MOVWF       main_d_L0+0 
	MOVLW       0
	MOVWF       main_d_L0+1 
;MyProject.c,4 :: 		trisd = 0b00000000;
	CLRF        TRISD+0 
;MyProject.c,5 :: 		trisb = 0b00010000;
	MOVLW       16
	MOVWF       TRISB+0 
;MyProject.c,6 :: 		trisb = 0b00000000;
	CLRF        TRISB+0 
;MyProject.c,8 :: 		while(Button(&portb,8,1,0)==255){
L_main0:
	MOVLW       PORTB+0
	MOVWF       FARG_Button_port+0 
	MOVLW       hi_addr(PORTB+0)
	MOVWF       FARG_Button_port+1 
	MOVLW       8
	MOVWF       FARG_Button_pin+0 
	MOVLW       1
	MOVWF       FARG_Button_time_ms+0 
	CLRF        FARG_Button_active_state+0 
	CALL        _Button+0, 0
	MOVF        R0, 0 
	XORLW       255
	BTFSS       STATUS+0, 2 
	GOTO        L_main1
;MyProject.c,10 :: 		portd = a;
	MOVF        main_a_L0+0, 0 
	MOVWF       PORTD+0 
;MyProject.c,11 :: 		portb = d;
	MOVF        main_d_L0+0, 0 
	MOVWF       PORTB+0 
;MyProject.c,12 :: 		delay_ms(500);
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
;MyProject.c,14 :: 		a = a + b;
	MOVF        main_b_L0+0, 0 
	ADDWF       main_a_L0+0, 1 
	MOVF        main_b_L0+1, 0 
	ADDWFC      main_a_L0+1, 1 
;MyProject.c,15 :: 		b = b/2;
	RRCF        main_b_L0+1, 1 
	RRCF        main_b_L0+0, 1 
	BCF         main_b_L0+1, 7 
	BTFSC       main_b_L0+1, 6 
	BSF         main_b_L0+1, 7 
	BTFSS       main_b_L0+1, 7 
	GOTO        L__main4
	BTFSS       STATUS+0, 0 
	GOTO        L__main4
	INFSNZ      main_b_L0+0, 1 
	INCF        main_b_L0+1, 1 
L__main4:
;MyProject.c,16 :: 		d = d*2+1;
	RLCF        main_d_L0+0, 1 
	BCF         main_d_L0+0, 0 
	RLCF        main_d_L0+1, 1 
	INFSNZ      main_d_L0+0, 1 
	INCF        main_d_L0+1, 1 
;MyProject.c,17 :: 		}
	GOTO        L_main0
L_main1:
;MyProject.c,18 :: 		}
L_end_main:
	GOTO        $+0
; end of _main
