
_main:

;MyProject.c,1 :: 		void main() {
;MyProject.c,2 :: 		int i = 0;
	CLRF        main_i_L0+0 
	CLRF        main_i_L0+1 
;MyProject.c,3 :: 		trisb = 0b00000010;
	MOVLW       2
	MOVWF       TRISB+0 
;MyProject.c,4 :: 		TRISA = 0; // define a como saída de 4bits
	CLRF        TRISA+0 
;MyProject.c,5 :: 		TRISD = 0;//define d como saída
	CLRF        TRISD+0 
;MyProject.c,6 :: 		PORTA = 0b00001100; //define o segmento "2" como saída
	MOVLW       12
	MOVWF       PORTA+0 
;MyProject.c,8 :: 		while(1){
L_main0:
;MyProject.c,11 :: 		for(i=0;i<10;i++){
	CLRF        main_i_L0+0 
	CLRF        main_i_L0+1 
L_main2:
	MOVLW       128
	XORWF       main_i_L0+1, 0 
	MOVWF       R0 
	MOVLW       128
	SUBWF       R0, 0 
	BTFSS       STATUS+0, 2 
	GOTO        L__main14
	MOVLW       10
	SUBWF       main_i_L0+0, 0 
L__main14:
	BTFSC       STATUS+0, 0 
	GOTO        L_main3
;MyProject.c,12 :: 		porta = 0b00000100;
	MOVLW       4
	MOVWF       PORTA+0 
;MyProject.c,13 :: 		portd = 0b00000110;
	MOVLW       6
	MOVWF       PORTD+0 
;MyProject.c,14 :: 		delay_ms(20);
	MOVLW       52
	MOVWF       R12, 0
	MOVLW       241
	MOVWF       R13, 0
L_main5:
	DECFSZ      R13, 1, 1
	BRA         L_main5
	DECFSZ      R12, 1, 1
	BRA         L_main5
	NOP
	NOP
;MyProject.c,15 :: 		porta = 0b00001000;
	MOVLW       8
	MOVWF       PORTA+0 
;MyProject.c,16 :: 		portd = 0b00111111;
	MOVLW       63
	MOVWF       PORTD+0 
;MyProject.c,17 :: 		delay_ms(30);
	MOVLW       78
	MOVWF       R12, 0
	MOVLW       235
	MOVWF       R13, 0
L_main6:
	DECFSZ      R13, 1, 1
	BRA         L_main6
	DECFSZ      R12, 1, 1
	BRA         L_main6
;MyProject.c,11 :: 		for(i=0;i<10;i++){
	INFSNZ      main_i_L0+0, 1 
	INCF        main_i_L0+1, 1 
;MyProject.c,18 :: 		}
	GOTO        L_main2
L_main3:
;MyProject.c,19 :: 		porta = 0b00001100;
	MOVLW       12
	MOVWF       PORTA+0 
;MyProject.c,20 :: 		portd = 0b00000110;
	MOVLW       6
	MOVWF       PORTD+0 
;MyProject.c,21 :: 		delay_ms(500);
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
;MyProject.c,22 :: 		for(i=0;i<10;i++){
	CLRF        main_i_L0+0 
	CLRF        main_i_L0+1 
L_main8:
	MOVLW       128
	XORWF       main_i_L0+1, 0 
	MOVWF       R0 
	MOVLW       128
	SUBWF       R0, 0 
	BTFSS       STATUS+0, 2 
	GOTO        L__main15
	MOVLW       10
	SUBWF       main_i_L0+0, 0 
L__main15:
	BTFSC       STATUS+0, 0 
	GOTO        L_main9
;MyProject.c,23 :: 		porta = 0b00000100;
	MOVLW       4
	MOVWF       PORTA+0 
;MyProject.c,24 :: 		portd = 0b00000110;
	MOVLW       6
	MOVWF       PORTD+0 
;MyProject.c,25 :: 		delay_ms(20);
	MOVLW       52
	MOVWF       R12, 0
	MOVLW       241
	MOVWF       R13, 0
L_main11:
	DECFSZ      R13, 1, 1
	BRA         L_main11
	DECFSZ      R12, 1, 1
	BRA         L_main11
	NOP
	NOP
;MyProject.c,26 :: 		porta = 0b00001000;
	MOVLW       8
	MOVWF       PORTA+0 
;MyProject.c,27 :: 		portd = 91;
	MOVLW       91
	MOVWF       PORTD+0 
;MyProject.c,28 :: 		delay_ms(30);
	MOVLW       78
	MOVWF       R12, 0
	MOVLW       235
	MOVWF       R13, 0
L_main12:
	DECFSZ      R13, 1, 1
	BRA         L_main12
	DECFSZ      R12, 1, 1
	BRA         L_main12
;MyProject.c,22 :: 		for(i=0;i<10;i++){
	INFSNZ      main_i_L0+0, 1 
	INCF        main_i_L0+1, 1 
;MyProject.c,29 :: 		}
	GOTO        L_main8
L_main9:
;MyProject.c,34 :: 		}
	GOTO        L_main0
;MyProject.c,36 :: 		}
L_end_main:
	GOTO        $+0
; end of _main
