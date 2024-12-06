
_main:

;MyProject.c,1 :: 		void main() {
;MyProject.c,2 :: 		trisd = 0;
	CLRF        TRISD+0 
;MyProject.c,3 :: 		portd = 0b11111111;
	MOVLW       255
	MOVWF       PORTD+0 
;MyProject.c,5 :: 		}
L_end_main:
	GOTO        $+0
; end of _main
