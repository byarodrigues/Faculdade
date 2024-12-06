
_main:

;MyProject.c,17 :: 		void main() {
;MyProject.c,25 :: 		lcd_init();
	CALL        _Lcd_Init+0, 0
;MyProject.c,26 :: 		lcd_cmd(_lcd_cursor_off);
	MOVLW       12
	MOVWF       FARG_Lcd_Cmd_out_char+0 
	CALL        _Lcd_Cmd+0, 0
;MyProject.c,27 :: 		while(1){
L_main0:
;MyProject.c,28 :: 		adcon1 = 0b00001110;
	MOVLW       14
	MOVWF       ADCON1+0 
;MyProject.c,29 :: 		pot1 = adc_read(0);
	CLRF        FARG_ADC_Read_channel+0 
	CALL        _ADC_Read+0, 0
	MOVF        R0, 0 
	MOVWF       main_pot1_L0+0 
	MOVF        R1, 0 
	MOVWF       main_pot1_L0+1 
;MyProject.c,30 :: 		wordtostr(pot1,txt1);
	MOVF        R0, 0 
	MOVWF       FARG_WordToStr_input+0 
	MOVF        R1, 0 
	MOVWF       FARG_WordToStr_input+1 
	MOVLW       main_txt1_L0+0
	MOVWF       FARG_WordToStr_output+0 
	MOVLW       hi_addr(main_txt1_L0+0)
	MOVWF       FARG_WordToStr_output+1 
	CALL        _WordToStr+0, 0
;MyProject.c,31 :: 		wordtostr(pot1/10.23,porc1);
	MOVF        main_pot1_L0+0, 0 
	MOVWF       R0 
	MOVF        main_pot1_L0+1, 0 
	MOVWF       R1 
	CALL        _int2double+0, 0
	MOVLW       20
	MOVWF       R4 
	MOVLW       174
	MOVWF       R5 
	MOVLW       35
	MOVWF       R6 
	MOVLW       130
	MOVWF       R7 
	CALL        _Div_32x32_FP+0, 0
	CALL        _double2word+0, 0
	MOVF        R0, 0 
	MOVWF       FARG_WordToStr_input+0 
	MOVF        R1, 0 
	MOVWF       FARG_WordToStr_input+1 
	MOVLW       main_porc1_L0+0
	MOVWF       FARG_WordToStr_output+0 
	MOVLW       hi_addr(main_porc1_L0+0)
	MOVWF       FARG_WordToStr_output+1 
	CALL        _WordToStr+0, 0
;MyProject.c,32 :: 		lcd_out(1,1,txt1);
	MOVLW       1
	MOVWF       FARG_Lcd_Out_row+0 
	MOVLW       1
	MOVWF       FARG_Lcd_Out_column+0 
	MOVLW       main_txt1_L0+0
	MOVWF       FARG_Lcd_Out_text+0 
	MOVLW       hi_addr(main_txt1_L0+0)
	MOVWF       FARG_Lcd_Out_text+1 
	CALL        _Lcd_Out+0, 0
;MyProject.c,33 :: 		lcd_out(1,8,porc1);
	MOVLW       1
	MOVWF       FARG_Lcd_Out_row+0 
	MOVLW       8
	MOVWF       FARG_Lcd_Out_column+0 
	MOVLW       main_porc1_L0+0
	MOVWF       FARG_Lcd_Out_text+0 
	MOVLW       hi_addr(main_porc1_L0+0)
	MOVWF       FARG_Lcd_Out_text+1 
	CALL        _Lcd_Out+0, 0
;MyProject.c,35 :: 		adcon1 = 0b00001101;
	MOVLW       13
	MOVWF       ADCON1+0 
;MyProject.c,36 :: 		pot2 = adc_read(1);
	MOVLW       1
	MOVWF       FARG_ADC_Read_channel+0 
	CALL        _ADC_Read+0, 0
	MOVF        R0, 0 
	MOVWF       main_pot2_L0+0 
	MOVF        R1, 0 
	MOVWF       main_pot2_L0+1 
;MyProject.c,37 :: 		wordtostr(pot2,txt2);
	MOVF        R0, 0 
	MOVWF       FARG_WordToStr_input+0 
	MOVF        R1, 0 
	MOVWF       FARG_WordToStr_input+1 
	MOVLW       main_txt2_L0+0
	MOVWF       FARG_WordToStr_output+0 
	MOVLW       hi_addr(main_txt2_L0+0)
	MOVWF       FARG_WordToStr_output+1 
	CALL        _WordToStr+0, 0
;MyProject.c,38 :: 		wordtostr(pot2/10.23,porc2);
	MOVF        main_pot2_L0+0, 0 
	MOVWF       R0 
	MOVF        main_pot2_L0+1, 0 
	MOVWF       R1 
	CALL        _int2double+0, 0
	MOVLW       20
	MOVWF       R4 
	MOVLW       174
	MOVWF       R5 
	MOVLW       35
	MOVWF       R6 
	MOVLW       130
	MOVWF       R7 
	CALL        _Div_32x32_FP+0, 0
	CALL        _double2word+0, 0
	MOVF        R0, 0 
	MOVWF       FARG_WordToStr_input+0 
	MOVF        R1, 0 
	MOVWF       FARG_WordToStr_input+1 
	MOVLW       main_porc2_L0+0
	MOVWF       FARG_WordToStr_output+0 
	MOVLW       hi_addr(main_porc2_L0+0)
	MOVWF       FARG_WordToStr_output+1 
	CALL        _WordToStr+0, 0
;MyProject.c,39 :: 		lcd_out(2,1,txt2);
	MOVLW       2
	MOVWF       FARG_Lcd_Out_row+0 
	MOVLW       1
	MOVWF       FARG_Lcd_Out_column+0 
	MOVLW       main_txt2_L0+0
	MOVWF       FARG_Lcd_Out_text+0 
	MOVLW       hi_addr(main_txt2_L0+0)
	MOVWF       FARG_Lcd_Out_text+1 
	CALL        _Lcd_Out+0, 0
;MyProject.c,40 :: 		lcd_out(2,8,porc2);
	MOVLW       2
	MOVWF       FARG_Lcd_Out_row+0 
	MOVLW       8
	MOVWF       FARG_Lcd_Out_column+0 
	MOVLW       main_porc2_L0+0
	MOVWF       FARG_Lcd_Out_text+0 
	MOVLW       hi_addr(main_porc2_L0+0)
	MOVWF       FARG_Lcd_Out_text+1 
	CALL        _Lcd_Out+0, 0
;MyProject.c,41 :: 		}
	GOTO        L_main0
;MyProject.c,42 :: 		}
L_end_main:
	GOTO        $+0
; end of _main
