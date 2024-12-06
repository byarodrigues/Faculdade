
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
;MyProject.c,3 :: 		trisd = 0;
	CLRF        TRISD+0 
;MyProject.c,4 :: 		while(1){
L_main0:
;MyProject.c,5 :: 		while(i<=8){
L_main2:
	MOVLW       128
	MOVWF       R0 
	MOVLW       128
	XORWF       main_i_L0+1, 0 
	SUBWF       R0, 0 
	BTFSS       STATUS+0, 2 
	GOTO        L__main6
	MOVF        main_i_L0+0, 0 
	SUBLW       8
L__main6:
	BTFSS       STATUS+0, 0 
	GOTO        L_main3
;MyProject.c,6 :: 		portd = a;
	MOVF        main_a_L0+0, 0 
	MOVWF       PORTD+0 
;MyProject.c,7 :: 		delay_ms(500);
	MOVLW       6
	MOVWF       R11, 0
	MOVLW       19
	MOVWF       R12, 0
	MOVLW       173
	MOVWF       R13, 0
L_main4:
	DECFSZ      R13, 1, 1
	BRA         L_main4
	DECFSZ      R12, 1, 1
	BRA         L_main4
	DECFSZ      R11, 1, 1
	BRA         L_main4
	NOP
	NOP
;MyProject.c,8 :: 		a = a + b;
	MOVF        main_b_L0+0, 0 
	ADDWF       main_a_L0+0, 1 
	MOVF        main_b_L0+1, 0 
	ADDWFC      main_a_L0+1, 1 
;MyProject.c,9 :: 		b = b/2;
	RRCF        main_b_L0+1, 1 
	RRCF        main_b_L0+0, 1 
	BCF         main_b_L0+1, 7 
	BTFSC       main_b_L0+1, 6 
	BSF         main_b_L0+1, 7 
	BTFSS       main_b_L0+1, 7 
	GOTO        L__main7
	BTFSS       STATUS+0, 0 
	GOTO        L__main7
	INFSNZ      main_b_L0+0, 1 
	INCF        main_b_L0+1, 1 
L__main7:
;MyProject.c,10 :: 		}
	GOTO        L_main2
L_main3:
;MyProject.c,11 :: 		i = 0; a = 128; b = 64;
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
;MyProject.c,12 :: 		}
	GOTO        L_main0
;MyProject.c,13 :: 		}
L_end_main:
	GOTO        $+0
; end of _main
