
_main:

;MyProject.c,1 :: 		void main() {
;MyProject.c,2 :: 		int i = 0;
	CLRF        main_i_L0+0 
	CLRF        main_i_L0+1 
	MOVLW       1
	MOVWF       main_a_L0+0 
	MOVLW       0
	MOVWF       main_a_L0+1 
;MyProject.c,4 :: 		trisd = 0;
	CLRF        TRISD+0 
;MyProject.c,5 :: 		while(1){
L_main0:
;MyProject.c,6 :: 		while(i<8){
L_main2:
	MOVLW       128
	XORWF       main_i_L0+1, 0 
	MOVWF       R0 
	MOVLW       128
	SUBWF       R0, 0 
	BTFSS       STATUS+0, 2 
	GOTO        L__main9
	MOVLW       8
	SUBWF       main_i_L0+0, 0 
L__main9:
	BTFSC       STATUS+0, 0 
	GOTO        L_main3
;MyProject.c,7 :: 		portd = a;
	MOVF        main_a_L0+0, 0 
	MOVWF       PORTD+0 
;MyProject.c,8 :: 		a = a*2;
	RLCF        main_a_L0+0, 1 
	BCF         main_a_L0+0, 0 
	RLCF        main_a_L0+1, 1 
;MyProject.c,9 :: 		i = i + 1;
	INFSNZ      main_i_L0+0, 1 
	INCF        main_i_L0+1, 1 
;MyProject.c,10 :: 		delay_ms(500);
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
;MyProject.c,11 :: 		}
	GOTO        L_main2
L_main3:
;MyProject.c,12 :: 		i = 1;
	MOVLW       1
	MOVWF       main_i_L0+0 
	MOVLW       0
	MOVWF       main_i_L0+1 
;MyProject.c,13 :: 		while(i<9){
L_main5:
	MOVLW       128
	XORWF       main_i_L0+1, 0 
	MOVWF       R0 
	MOVLW       128
	SUBWF       R0, 0 
	BTFSS       STATUS+0, 2 
	GOTO        L__main10
	MOVLW       9
	SUBWF       main_i_L0+0, 0 
L__main10:
	BTFSC       STATUS+0, 0 
	GOTO        L_main6
;MyProject.c,14 :: 		portd = a;
	MOVF        main_a_L0+0, 0 
	MOVWF       PORTD+0 
;MyProject.c,15 :: 		a = a/2;
	RRCF        main_a_L0+1, 1 
	RRCF        main_a_L0+0, 1 
	BCF         main_a_L0+1, 7 
	BTFSC       main_a_L0+1, 6 
	BSF         main_a_L0+1, 7 
	BTFSS       main_a_L0+1, 7 
	GOTO        L__main11
	BTFSS       STATUS+0, 0 
	GOTO        L__main11
	INFSNZ      main_a_L0+0, 1 
	INCF        main_a_L0+1, 1 
L__main11:
;MyProject.c,16 :: 		delay_ms(500);
	MOVLW       6
	MOVWF       R11, 0
	MOVLW       19
	MOVWF       R12, 0
	MOVLW       173
	MOVWF       R13, 0
L_main7:
	DECFSZ      R13, 1, 1
	BRA         L_main7
	DECFSZ      R12, 1, 1
	BRA         L_main7
	DECFSZ      R11, 1, 1
	BRA         L_main7
	NOP
	NOP
;MyProject.c,17 :: 		i = i + 1;
	INFSNZ      main_i_L0+0, 1 
	INCF        main_i_L0+1, 1 
;MyProject.c,18 :: 		}
	GOTO        L_main5
L_main6:
;MyProject.c,19 :: 		}
	GOTO        L_main0
;MyProject.c,20 :: 		}
L_end_main:
	GOTO        $+0
; end of _main
