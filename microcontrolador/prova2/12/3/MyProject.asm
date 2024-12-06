
_main:

;MyProject.c,1 :: 		void main() {
;MyProject.c,2 :: 		trisd = 0;
	CLRF        TRISD+0 
;MyProject.c,3 :: 		portd = 0b11110000;
	MOVLW       240
	MOVWF       PORTD+0 
;MyProject.c,4 :: 		}
L_end_main:
	GOTO        $+0
; end of _main
