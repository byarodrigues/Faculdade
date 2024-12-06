
_main:

;MyProject.c,1 :: 		void main() {
;MyProject.c,2 :: 		tmr0l = 0xf7;
	MOVLW       247
	MOVWF       TMR0L+0 
;MyProject.c,3 :: 		tmr0h = 0xc2;
	MOVLW       194
	MOVWF       TMR0H+0 
;MyProject.c,4 :: 		t0con = 0b10000110;
	MOVLW       134
	MOVWF       T0CON+0 
;MyProject.c,5 :: 		intcon.TMR0IF = 0;
	BCF         INTCON+0, 2 
;MyProject.c,6 :: 		trisd = 0;
	CLRF        TRISD+0 
;MyProject.c,7 :: 		portd = 0;
	CLRF        PORTD+0 
;MyProject.c,8 :: 		while(1){
L_main0:
;MyProject.c,9 :: 		if(intcon.tmr0if == 1){
	BTFSS       INTCON+0, 2 
	GOTO        L_main2
;MyProject.c,10 :: 		tmr0l = 0xf7;
	MOVLW       247
	MOVWF       TMR0L+0 
;MyProject.c,11 :: 		tmr0h = 0xc2;
	MOVLW       194
	MOVWF       TMR0H+0 
;MyProject.c,12 :: 		intcon.TMR0IF = 0;
	BCF         INTCON+0, 2 
;MyProject.c,13 :: 		portd = ~portd;
	COMF        PORTD+0, 1 
;MyProject.c,15 :: 		}
L_main2:
;MyProject.c,17 :: 		}
	GOTO        L_main0
;MyProject.c,20 :: 		}
L_end_main:
	GOTO        $+0
; end of _main
