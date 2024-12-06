
_main:

;MyProject.c,1 :: 		void main() {
;MyProject.c,2 :: 		int a = 0;
	CLRF        main_a_L0+0 
	CLRF        main_a_L0+1 
;MyProject.c,3 :: 		tmr0l = 0xf7;
	MOVLW       247
	MOVWF       TMR0L+0 
;MyProject.c,4 :: 		tmr0h = 0xc2;
	MOVLW       194
	MOVWF       TMR0H+0 
;MyProject.c,5 :: 		t0con = 0b10000110;
	MOVLW       134
	MOVWF       T0CON+0 
;MyProject.c,6 :: 		intcon.TMR0IF = 0;
	BCF         INTCON+0, 2 
;MyProject.c,7 :: 		trisd = 0;
	CLRF        TRISD+0 
;MyProject.c,8 :: 		portd = 0;
	CLRF        PORTD+0 
;MyProject.c,9 :: 		while(1){
L_main0:
;MyProject.c,10 :: 		if(intcon.tmr0if == 1){
	BTFSS       INTCON+0, 2 
	GOTO        L_main2
;MyProject.c,11 :: 		tmr0l = 0xf7;
	MOVLW       247
	MOVWF       TMR0L+0 
;MyProject.c,12 :: 		tmr0h = 0xc2;
	MOVLW       194
	MOVWF       TMR0H+0 
;MyProject.c,13 :: 		intcon.TMR0IF = 0;
	BCF         INTCON+0, 2 
;MyProject.c,14 :: 		a = a + 1;
	INFSNZ      main_a_L0+0, 1 
	INCF        main_a_L0+1, 1 
;MyProject.c,15 :: 		if(a == 10){
	MOVLW       0
	XORWF       main_a_L0+1, 0 
	BTFSS       STATUS+0, 2 
	GOTO        L__main5
	MOVLW       10
	XORWF       main_a_L0+0, 0 
L__main5:
	BTFSS       STATUS+0, 2 
	GOTO        L_main3
;MyProject.c,16 :: 		portd = ~portd;
	COMF        PORTD+0, 1 
;MyProject.c,17 :: 		a = 0;
	CLRF        main_a_L0+0 
	CLRF        main_a_L0+1 
;MyProject.c,18 :: 		}
L_main3:
;MyProject.c,19 :: 		}
L_main2:
;MyProject.c,21 :: 		}
	GOTO        L_main0
;MyProject.c,22 :: 		}
L_end_main:
	GOTO        $+0
; end of _main
