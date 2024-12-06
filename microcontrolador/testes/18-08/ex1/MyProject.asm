
_main:

;MyProject.c,5 :: 		void main() {
;MyProject.c,6 :: 		int a = 0;
	CLRF        main_a_L0+0 
	CLRF        main_a_L0+1 
;MyProject.c,7 :: 		tmr0l = 0xf7;
	MOVLW       247
	MOVWF       TMR0L+0 
;MyProject.c,8 :: 		tmr0h = 0xc2;
	MOVLW       194
	MOVWF       TMR0H+0 
;MyProject.c,9 :: 		t0con = 0b10000110;
	MOVLW       134
	MOVWF       T0CON+0 
;MyProject.c,10 :: 		intcon.TMR0IF = 0;
	BCF         INTCON+0, 2 
;MyProject.c,11 :: 		trisd = 0;
	CLRF        TRISD+0 
;MyProject.c,12 :: 		portd = 0;
	CLRF        PORTD+0 
;MyProject.c,13 :: 		while(1){
L_main0:
;MyProject.c,14 :: 		while(intcon.tmr0if == 1){
L_main2:
	BTFSS       INTCON+0, 2 
	GOTO        L_main3
;MyProject.c,15 :: 		tmr0l = 0xf7;
	MOVLW       247
	MOVWF       TMR0L+0 
;MyProject.c,16 :: 		tmr0h = 0xc2;
	MOVLW       194
	MOVWF       TMR0H+0 
;MyProject.c,17 :: 		intcon.TMR0IF = 0;
	BCF         INTCON+0, 2 
;MyProject.c,18 :: 		portd = a;
	MOVF        main_a_L0+0, 0 
	MOVWF       PORTD+0 
;MyProject.c,19 :: 		a = a*2+1;
	RLCF        main_a_L0+0, 1 
	BCF         main_a_L0+0, 0 
	RLCF        main_a_L0+1, 1 
	INFSNZ      main_a_L0+0, 1 
	INCF        main_a_L0+1, 1 
;MyProject.c,20 :: 		}
	GOTO        L_main2
L_main3:
;MyProject.c,22 :: 		}
	GOTO        L_main0
;MyProject.c,23 :: 		}
L_end_main:
	GOTO        $+0
; end of _main
