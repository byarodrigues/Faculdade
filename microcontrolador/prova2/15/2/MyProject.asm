
_main:

;MyProject.c,1 :: 		void main() {
;MyProject.c,2 :: 		trisd = 0;
	CLRF        TRISD+0 
;MyProject.c,3 :: 		trisa = 0;
	CLRF        TRISA+0 
;MyProject.c,5 :: 		porta = 0b00000100;
	MOVLW       4
	MOVWF       PORTA+0 
;MyProject.c,6 :: 		portd = 0x3F;
	MOVLW       63
	MOVWF       PORTD+0 
;MyProject.c,7 :: 		delay_ms(1000);
	MOVLW       11
	MOVWF       R11, 0
	MOVLW       38
	MOVWF       R12, 0
	MOVLW       93
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
;MyProject.c,8 :: 		porta = 0b00001000;
	MOVLW       8
	MOVWF       PORTA+0 
;MyProject.c,9 :: 		portd = 0x06;
	MOVLW       6
	MOVWF       PORTD+0 
;MyProject.c,10 :: 		delay_ms(1000);
	MOVLW       11
	MOVWF       R11, 0
	MOVLW       38
	MOVWF       R12, 0
	MOVLW       93
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
;MyProject.c,11 :: 		porta = 0b00010000;
	MOVLW       16
	MOVWF       PORTA+0 
;MyProject.c,12 :: 		portd = 0x5B;
	MOVLW       91
	MOVWF       PORTD+0 
;MyProject.c,13 :: 		delay_ms(1000);
	MOVLW       11
	MOVWF       R11, 0
	MOVLW       38
	MOVWF       R12, 0
	MOVLW       93
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
;MyProject.c,14 :: 		porta = 0b00100000;
	MOVLW       32
	MOVWF       PORTA+0 
;MyProject.c,15 :: 		portd = 0x4F;
	MOVLW       79
	MOVWF       PORTD+0 
;MyProject.c,16 :: 		delay_ms(1000);
	MOVLW       11
	MOVWF       R11, 0
	MOVLW       38
	MOVWF       R12, 0
	MOVLW       93
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
;MyProject.c,17 :: 		porta = 0b00000100;
	MOVLW       4
	MOVWF       PORTA+0 
;MyProject.c,18 :: 		portd = 0x66;
	MOVLW       102
	MOVWF       PORTD+0 
;MyProject.c,19 :: 		delay_ms(1000);
	MOVLW       11
	MOVWF       R11, 0
	MOVLW       38
	MOVWF       R12, 0
	MOVLW       93
	MOVWF       R13, 0
L_main6:
	DECFSZ      R13, 1, 1
	BRA         L_main6
	DECFSZ      R12, 1, 1
	BRA         L_main6
	DECFSZ      R11, 1, 1
	BRA         L_main6
	NOP
	NOP
;MyProject.c,20 :: 		porta = 0b00001000;
	MOVLW       8
	MOVWF       PORTA+0 
;MyProject.c,21 :: 		portd = 0x6D;
	MOVLW       109
	MOVWF       PORTD+0 
;MyProject.c,22 :: 		delay_ms(1000);
	MOVLW       11
	MOVWF       R11, 0
	MOVLW       38
	MOVWF       R12, 0
	MOVLW       93
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
;MyProject.c,23 :: 		porta = 0b00010000;
	MOVLW       16
	MOVWF       PORTA+0 
;MyProject.c,24 :: 		portd = 0x7D;
	MOVLW       125
	MOVWF       PORTD+0 
;MyProject.c,25 :: 		delay_ms(1000);
	MOVLW       11
	MOVWF       R11, 0
	MOVLW       38
	MOVWF       R12, 0
	MOVLW       93
	MOVWF       R13, 0
L_main8:
	DECFSZ      R13, 1, 1
	BRA         L_main8
	DECFSZ      R12, 1, 1
	BRA         L_main8
	DECFSZ      R11, 1, 1
	BRA         L_main8
	NOP
	NOP
;MyProject.c,26 :: 		porta = 0b00100000;
	MOVLW       32
	MOVWF       PORTA+0 
;MyProject.c,27 :: 		portd = 0x07;
	MOVLW       7
	MOVWF       PORTD+0 
;MyProject.c,28 :: 		delay_ms(1000);
	MOVLW       11
	MOVWF       R11, 0
	MOVLW       38
	MOVWF       R12, 0
	MOVLW       93
	MOVWF       R13, 0
L_main9:
	DECFSZ      R13, 1, 1
	BRA         L_main9
	DECFSZ      R12, 1, 1
	BRA         L_main9
	DECFSZ      R11, 1, 1
	BRA         L_main9
	NOP
	NOP
;MyProject.c,29 :: 		porta = 0b00000100;
	MOVLW       4
	MOVWF       PORTA+0 
;MyProject.c,30 :: 		portd = 0x7F;
	MOVLW       127
	MOVWF       PORTD+0 
;MyProject.c,31 :: 		delay_ms(1000);
	MOVLW       11
	MOVWF       R11, 0
	MOVLW       38
	MOVWF       R12, 0
	MOVLW       93
	MOVWF       R13, 0
L_main10:
	DECFSZ      R13, 1, 1
	BRA         L_main10
	DECFSZ      R12, 1, 1
	BRA         L_main10
	DECFSZ      R11, 1, 1
	BRA         L_main10
	NOP
	NOP
;MyProject.c,32 :: 		porta = 0b00001000;
	MOVLW       8
	MOVWF       PORTA+0 
;MyProject.c,33 :: 		portd = 0x6F;
	MOVLW       111
	MOVWF       PORTD+0 
;MyProject.c,34 :: 		delay_ms(1000);
	MOVLW       11
	MOVWF       R11, 0
	MOVLW       38
	MOVWF       R12, 0
	MOVLW       93
	MOVWF       R13, 0
L_main11:
	DECFSZ      R13, 1, 1
	BRA         L_main11
	DECFSZ      R12, 1, 1
	BRA         L_main11
	DECFSZ      R11, 1, 1
	BRA         L_main11
	NOP
	NOP
;MyProject.c,36 :: 		while(1){
L_main12:
;MyProject.c,37 :: 		porta = 0b00000100;
	MOVLW       4
	MOVWF       PORTA+0 
;MyProject.c,38 :: 		portd = 0b00111111;
	MOVLW       63
	MOVWF       PORTD+0 
;MyProject.c,39 :: 		porta = 0b00001000;
	MOVLW       8
	MOVWF       PORTA+0 
;MyProject.c,40 :: 		portd = 0b00111111;
	MOVLW       63
	MOVWF       PORTD+0 
;MyProject.c,41 :: 		}
	GOTO        L_main12
;MyProject.c,43 :: 		}
L_end_main:
	GOTO        $+0
; end of _main
