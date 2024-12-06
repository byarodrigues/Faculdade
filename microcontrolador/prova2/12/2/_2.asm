
_main:

;_2.c,1 :: 		void main() {
;_2.c,2 :: 		trisd = 0;
	CLRF        TRISD+0 
;_2.c,3 :: 		portd = 0b00001111;
	MOVLW       15
	MOVWF       PORTD+0 
;_2.c,4 :: 		}
L_end_main:
	GOTO        $+0
; end of _main
