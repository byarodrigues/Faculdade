
_main:

;MyProject.c,18 :: 		void main() {
;MyProject.c,19 :: 		lcd_init();
	CALL        _Lcd_Init+0, 0
;MyProject.c,20 :: 		lcd_out(1,1,"texto1");
	MOVLW       1
	MOVWF       FARG_Lcd_Out_row+0 
	MOVLW       1
	MOVWF       FARG_Lcd_Out_column+0 
	MOVLW       ?lstr1_MyProject+0
	MOVWF       FARG_Lcd_Out_text+0 
	MOVLW       hi_addr(?lstr1_MyProject+0)
	MOVWF       FARG_Lcd_Out_text+1 
	CALL        _Lcd_Out+0, 0
;MyProject.c,21 :: 		lcd_out_cp(" texto2hjfjiug");
	MOVLW       ?lstr2_MyProject+0
	MOVWF       FARG_Lcd_Out_CP_text+0 
	MOVLW       hi_addr(?lstr2_MyProject+0)
	MOVWF       FARG_Lcd_Out_CP_text+1 
	CALL        _Lcd_Out_CP+0, 0
;MyProject.c,24 :: 		}
L_end_main:
	GOTO        $+0
; end of _main
