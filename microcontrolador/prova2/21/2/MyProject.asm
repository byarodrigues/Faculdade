
_main:

;MyProject.c,17 :: 		void main() {
;MyProject.c,20 :: 		lcd_init();
	CALL        _Lcd_Init+0, 0
;MyProject.c,21 :: 		lcd_cmd(_lcd_cursor_off);
	MOVLW       12
	MOVWF       FARG_Lcd_Cmd_out_char+0 
	CALL        _Lcd_Cmd+0, 0
;MyProject.c,22 :: 		while(1){
L_main0:
;MyProject.c,23 :: 		adcon1 = 0b00001101;
	MOVLW       13
	MOVWF       ADCON1+0 
;MyProject.c,24 :: 		pot = adc_read(1);
	MOVLW       1
	MOVWF       FARG_ADC_Read_channel+0 
	CALL        _ADC_Read+0, 0
;MyProject.c,25 :: 		wordtostr(pot,txt);
	MOVF        R0, 0 
	MOVWF       FARG_WordToStr_input+0 
	MOVF        R1, 0 
	MOVWF       FARG_WordToStr_input+1 
	MOVLW       main_txt_L0+0
	MOVWF       FARG_WordToStr_output+0 
	MOVLW       hi_addr(main_txt_L0+0)
	MOVWF       FARG_WordToStr_output+1 
	CALL        _WordToStr+0, 0
;MyProject.c,26 :: 		lcd_out(1,1,txt);
	MOVLW       1
	MOVWF       FARG_Lcd_Out_row+0 
	MOVLW       1
	MOVWF       FARG_Lcd_Out_column+0 
	MOVLW       main_txt_L0+0
	MOVWF       FARG_Lcd_Out_text+0 
	MOVLW       hi_addr(main_txt_L0+0)
	MOVWF       FARG_Lcd_Out_text+1 
	CALL        _Lcd_Out+0, 0
;MyProject.c,27 :: 		}
	GOTO        L_main0
;MyProject.c,28 :: 		}
L_end_main:
	GOTO        $+0
; end of _main
