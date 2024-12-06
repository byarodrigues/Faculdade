
_main:

;ex2.c,18 :: 		void main() {
;ex2.c,19 :: 		lcd_init(); //inicia
	CALL        _Lcd_Init+0, 0
;ex2.c,20 :: 		lcd_out(1,4,"Engenharia"); //manda texto pra linha 1 e coluna 1
	MOVLW       1
	MOVWF       FARG_Lcd_Out_row+0 
	MOVLW       4
	MOVWF       FARG_Lcd_Out_column+0 
	MOVLW       ?lstr1_ex2+0
	MOVWF       FARG_Lcd_Out_text+0 
	MOVLW       hi_addr(?lstr1_ex2+0)
	MOVWF       FARG_Lcd_Out_text+1 
	CALL        _Lcd_Out+0, 0
;ex2.c,21 :: 		lcd_out(2,4,"Computação"); //manda texto pra linha 1 e coluna 1
	MOVLW       2
	MOVWF       FARG_Lcd_Out_row+0 
	MOVLW       4
	MOVWF       FARG_Lcd_Out_column+0 
	MOVLW       ?lstr2_ex2+0
	MOVWF       FARG_Lcd_Out_text+0 
	MOVLW       hi_addr(?lstr2_ex2+0)
	MOVWF       FARG_Lcd_Out_text+1 
	CALL        _Lcd_Out+0, 0
;ex2.c,26 :: 		}
L_end_main:
	GOTO        $+0
; end of _main
