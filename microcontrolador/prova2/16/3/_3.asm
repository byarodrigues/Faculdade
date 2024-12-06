
_main:

;_3.c,1 :: 		void main() {
;_3.c,2 :: 		int a = 128;
	MOVLW       128
	MOVWF       main_a_L0+0 
	MOVLW       0
	MOVWF       main_a_L0+1 
	MOVLW       128
	MOVWF       main_b_L0+0 
	MOVLW       0
	MOVWF       main_b_L0+1 
;_3.c,4 :: 		trisd = 0;
	CLRF        TRISD+0 
;_3.c,5 :: 		while(1){
L_main0:
;_3.c,6 :: 		portd = a;
	MOVF        main_a_L0+0, 0 
	MOVWF       PORTD+0 
;_3.c,7 :: 		a = a+b/2;
	MOVF        main_b_L0+0, 0 
	MOVWF       R0 
	MOVF        main_b_L0+1, 0 
	MOVWF       R1 
	RRCF        R1, 1 
	RRCF        R0, 1 
	BCF         R1, 7 
	BTFSC       R1, 6 
	BSF         R1, 7 
	BTFSS       R1, 7 
	GOTO        L__main4
	BTFSS       STATUS+0, 0 
	GOTO        L__main4
	INFSNZ      R0, 1 
	INCF        R1, 1 
L__main4:
	MOVF        R0, 0 
	ADDWF       main_a_L0+0, 1 
	MOVF        R1, 0 
	ADDWFC      main_a_L0+1, 1 
;_3.c,8 :: 		b = b/2;
	MOVF        R0, 0 
	MOVWF       main_b_L0+0 
	MOVF        R1, 0 
	MOVWF       main_b_L0+1 
;_3.c,9 :: 		delay_ms(500);
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
;_3.c,10 :: 		}
	GOTO        L_main0
;_3.c,11 :: 		}
L_end_main:
	GOTO        $+0
; end of _main
