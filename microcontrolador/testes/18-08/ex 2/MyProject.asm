
_main:

;MyProject.c,1 :: 		void main() {
;MyProject.c,2 :: 		int i = 0; int a = 128; int b = 64;
	CLRF        main_i_L0+0 
	CLRF        main_i_L0+1 
	MOVLW       128
	MOVWF       main_a_L0+0 
	MOVLW       0
	MOVWF       main_a_L0+1 
	MOVLW       64
	MOVWF       main_b_L0+0 
	MOVLW       0
	MOVWF       main_b_L0+1 
;MyProject.c,3 :: 		trisd = 0b00000000;
	CLRF        TRISD+0 
;MyProject.c,4 :: 		trisb = 0b00000000;
	CLRF        TRISB+0 
;MyProject.c,6 :: 		while(b<255){
L_main0:
	MOVLW       128
	XORWF       main_b_L0+1, 0 
	MOVWF       R0 
	MOVLW       128
	SUBWF       R0, 0 
	BTFSS       STATUS+0, 2 
	GOTO        L__main5
	MOVLW       255
	SUBWF       main_b_L0+0, 0 
L__main5:
	BTFSC       STATUS+0, 0 
	GOTO        L_main1
;MyProject.c,7 :: 		portd = a;
	MOVF        main_a_L0+0, 0 
	MOVWF       PORTD+0 
;MyProject.c,8 :: 		delay_ms(500);
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
;MyProject.c,9 :: 		a = a + b;
	MOVF        main_b_L0+0, 0 
	ADDWF       main_a_L0+0, 1 
	MOVF        main_b_L0+1, 0 
	ADDWFC      main_a_L0+1, 1 
;MyProject.c,10 :: 		b = b/2;
	RRCF        main_b_L0+1, 1 
	RRCF        main_b_L0+0, 1 
	BCF         main_b_L0+1, 7 
	BTFSC       main_b_L0+1, 6 
	BSF         main_b_L0+1, 7 
	BTFSS       main_b_L0+1, 7 
	GOTO        L__main6
	BTFSS       STATUS+0, 0 
	GOTO        L__main6
	INFSNZ      main_b_L0+0, 1 
	INCF        main_b_L0+1, 1 
L__main6:
;MyProject.c,11 :: 		portb = i;
	MOVF        main_i_L0+0, 0 
	MOVWF       PORTB+0 
;MyProject.c,12 :: 		delay_ms(500);
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
;MyProject.c,13 :: 		i = i + b;
	MOVF        main_b_L0+0, 0 
	ADDWF       main_i_L0+0, 1 
	MOVF        main_b_L0+1, 0 
	ADDWFC      main_i_L0+1, 1 
;MyProject.c,15 :: 		}
	GOTO        L_main0
L_main1:
;MyProject.c,17 :: 		}
L_end_main:
	GOTO        $+0
; end of _main
