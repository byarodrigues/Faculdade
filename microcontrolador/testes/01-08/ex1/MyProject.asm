
_main:

;MyProject.c,17 :: 		void main() {
;MyProject.c,20 :: 		lcd_init();
	CALL        _Lcd_Init+0, 0
;MyProject.c,21 :: 		lcd_cmd(_lcd_clear);
	MOVLW       1
	MOVWF       FARG_Lcd_Cmd_out_char+0 
	CALL        _Lcd_Cmd+0, 0
;MyProject.c,22 :: 		lcd_cmd(_LCD_CURSOR_OFF);
	MOVLW       12
	MOVWF       FARG_Lcd_Cmd_out_char+0 
	CALL        _Lcd_Cmd+0, 0
;MyProject.c,23 :: 		while(1){
L_main0:
;MyProject.c,24 :: 		ADCON1 = 0b00001110;
	MOVLW       14
	MOVWF       ADCON1+0 
;MyProject.c,25 :: 		pote = ADC_Read (0);
	CLRF        FARG_ADC_Read_channel+0 
	CALL        _ADC_Read+0, 0
;MyProject.c,26 :: 		WordToStr(pote, texto);
	MOVF        R0, 0 
	MOVWF       FARG_WordToStr_input+0 
	MOVF        R1, 0 
	MOVWF       FARG_WordToStr_input+1 
	MOVLW       main_texto_L0+0
	MOVWF       FARG_WordToStr_output+0 
	MOVLW       hi_addr(main_texto_L0+0)
	MOVWF       FARG_WordToStr_output+1 
	CALL        _WordToStr+0, 0
;MyProject.c,27 :: 		lcd_out(1,1,texto);
	MOVLW       1
	MOVWF       FARG_Lcd_Out_row+0 
	MOVLW       1
	MOVWF       FARG_Lcd_Out_column+0 
	MOVLW       main_texto_L0+0
	MOVWF       FARG_Lcd_Out_text+0 
	MOVLW       hi_addr(main_texto_L0+0)
	MOVWF       FARG_Lcd_Out_text+1 
	CALL        _Lcd_Out+0, 0
;MyProject.c,28 :: 		}
	GOTO        L_main0
;MyProject.c,30 :: 		}
L_end_main:
	GOTO        $+0
; end of _main
