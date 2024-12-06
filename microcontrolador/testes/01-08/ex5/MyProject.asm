
_main:

;MyProject.c,17 :: 		void main() {
;MyProject.c,22 :: 		float pote1, x1 = 0;
	CLRF        main_x1_L0+0 
	CLRF        main_x1_L0+1 
	CLRF        main_x1_L0+2 
	CLRF        main_x1_L0+3 
;MyProject.c,24 :: 		lcd_init();
	CALL        _Lcd_Init+0, 0
;MyProject.c,25 :: 		lcd_cmd(_lcd_clear);
	MOVLW       1
	MOVWF       FARG_Lcd_Cmd_out_char+0 
	CALL        _Lcd_Cmd+0, 0
;MyProject.c,26 :: 		lcd_cmd(_LCD_CURSOR_OFF);
	MOVLW       12
	MOVWF       FARG_Lcd_Cmd_out_char+0 
	CALL        _Lcd_Cmd+0, 0
;MyProject.c,28 :: 		while(1){
L_main0:
;MyProject.c,29 :: 		ADCON1 = 0b00001101;
	MOVLW       13
	MOVWF       ADCON1+0 
;MyProject.c,31 :: 		pote = ADC_Read (0);
	CLRF        FARG_ADC_Read_channel+0 
	CALL        _ADC_Read+0, 0
	CALL        _word2double+0, 0
	MOVF        R0, 0 
	MOVWF       FLOC__main+0 
	MOVF        R1, 0 
	MOVWF       FLOC__main+1 
	MOVF        R2, 0 
	MOVWF       FLOC__main+2 
	MOVF        R3, 0 
	MOVWF       FLOC__main+3 
	MOVLW       0
	MOVWF       R4 
	MOVLW       192
	MOVWF       R5 
	MOVLW       127
	MOVWF       R6 
	MOVLW       136
	MOVWF       R7 
	MOVF        FLOC__main+0, 0 
	MOVWF       R0 
	MOVF        FLOC__main+1, 0 
	MOVWF       R1 
	MOVF        FLOC__main+2, 0 
	MOVWF       R2 
	MOVF        FLOC__main+3, 0 
	MOVWF       R3 
	CALL        _Div_32x32_FP+0, 0
;MyProject.c,32 :: 		x = (pote/1023)*100;
	MOVLW       0
	MOVWF       R4 
	MOVLW       0
	MOVWF       R5 
	MOVLW       72
	MOVWF       R6 
	MOVLW       133
	MOVWF       R7 
	CALL        _Mul_32x32_FP+0, 0
	MOVF        R0, 0 
	MOVWF       main_x_L0+0 
	MOVF        R1, 0 
	MOVWF       main_x_L0+1 
	MOVF        R2, 0 
	MOVWF       main_x_L0+2 
	MOVF        R3, 0 
	MOVWF       main_x_L0+3 
;MyProject.c,33 :: 		WordToStr(pote, texto);
	MOVF        FLOC__main+0, 0 
	MOVWF       R0 
	MOVF        FLOC__main+1, 0 
	MOVWF       R1 
	MOVF        FLOC__main+2, 0 
	MOVWF       R2 
	MOVF        FLOC__main+3, 0 
	MOVWF       R3 
	CALL        _double2word+0, 0
	MOVF        R0, 0 
	MOVWF       FARG_WordToStr_input+0 
	MOVF        R1, 0 
	MOVWF       FARG_WordToStr_input+1 
	MOVLW       main_texto_L0+0
	MOVWF       FARG_WordToStr_output+0 
	MOVLW       hi_addr(main_texto_L0+0)
	MOVWF       FARG_WordToStr_output+1 
	CALL        _WordToStr+0, 0
;MyProject.c,34 :: 		WordToStr(x, porcent);
	MOVF        main_x_L0+0, 0 
	MOVWF       R0 
	MOVF        main_x_L0+1, 0 
	MOVWF       R1 
	MOVF        main_x_L0+2, 0 
	MOVWF       R2 
	MOVF        main_x_L0+3, 0 
	MOVWF       R3 
	CALL        _double2word+0, 0
	MOVF        R0, 0 
	MOVWF       FARG_WordToStr_input+0 
	MOVF        R1, 0 
	MOVWF       FARG_WordToStr_input+1 
	MOVLW       main_porcent_L0+0
	MOVWF       FARG_WordToStr_output+0 
	MOVLW       hi_addr(main_porcent_L0+0)
	MOVWF       FARG_WordToStr_output+1 
	CALL        _WordToStr+0, 0
;MyProject.c,35 :: 		lcd_out(1,1,texto);
	MOVLW       1
	MOVWF       FARG_Lcd_Out_row+0 
	MOVLW       1
	MOVWF       FARG_Lcd_Out_column+0 
	MOVLW       main_texto_L0+0
	MOVWF       FARG_Lcd_Out_text+0 
	MOVLW       hi_addr(main_texto_L0+0)
	MOVWF       FARG_Lcd_Out_text+1 
	CALL        _Lcd_Out+0, 0
;MyProject.c,36 :: 		lcd_out_cp(porcent);
	MOVLW       main_porcent_L0+0
	MOVWF       FARG_Lcd_Out_CP_text+0 
	MOVLW       hi_addr(main_porcent_L0+0)
	MOVWF       FARG_Lcd_Out_CP_text+1 
	CALL        _Lcd_Out_CP+0, 0
;MyProject.c,38 :: 		pote1 = ADC_Read (1);
	MOVLW       1
	MOVWF       FARG_ADC_Read_channel+0 
	CALL        _ADC_Read+0, 0
	CALL        _word2double+0, 0
	MOVF        R0, 0 
	MOVWF       FLOC__main+0 
	MOVF        R1, 0 
	MOVWF       FLOC__main+1 
	MOVF        R2, 0 
	MOVWF       FLOC__main+2 
	MOVF        R3, 0 
	MOVWF       FLOC__main+3 
	MOVLW       0
	MOVWF       R4 
	MOVLW       192
	MOVWF       R5 
	MOVLW       127
	MOVWF       R6 
	MOVLW       136
	MOVWF       R7 
	MOVF        FLOC__main+0, 0 
	MOVWF       R0 
	MOVF        FLOC__main+1, 0 
	MOVWF       R1 
	MOVF        FLOC__main+2, 0 
	MOVWF       R2 
	MOVF        FLOC__main+3, 0 
	MOVWF       R3 
	CALL        _Div_32x32_FP+0, 0
;MyProject.c,39 :: 		x1 = (pote1/1023)*100;
	MOVLW       0
	MOVWF       R4 
	MOVLW       0
	MOVWF       R5 
	MOVLW       72
	MOVWF       R6 
	MOVLW       133
	MOVWF       R7 
	CALL        _Mul_32x32_FP+0, 0
	MOVF        R0, 0 
	MOVWF       main_x1_L0+0 
	MOVF        R1, 0 
	MOVWF       main_x1_L0+1 
	MOVF        R2, 0 
	MOVWF       main_x1_L0+2 
	MOVF        R3, 0 
	MOVWF       main_x1_L0+3 
;MyProject.c,40 :: 		WordToStr(pote1, texto);
	MOVF        FLOC__main+0, 0 
	MOVWF       R0 
	MOVF        FLOC__main+1, 0 
	MOVWF       R1 
	MOVF        FLOC__main+2, 0 
	MOVWF       R2 
	MOVF        FLOC__main+3, 0 
	MOVWF       R3 
	CALL        _double2word+0, 0
	MOVF        R0, 0 
	MOVWF       FARG_WordToStr_input+0 
	MOVF        R1, 0 
	MOVWF       FARG_WordToStr_input+1 
	MOVLW       main_texto_L0+0
	MOVWF       FARG_WordToStr_output+0 
	MOVLW       hi_addr(main_texto_L0+0)
	MOVWF       FARG_WordToStr_output+1 
	CALL        _WordToStr+0, 0
;MyProject.c,41 :: 		WordToStr(x1, porcent1);
	MOVF        main_x1_L0+0, 0 
	MOVWF       R0 
	MOVF        main_x1_L0+1, 0 
	MOVWF       R1 
	MOVF        main_x1_L0+2, 0 
	MOVWF       R2 
	MOVF        main_x1_L0+3, 0 
	MOVWF       R3 
	CALL        _double2word+0, 0
	MOVF        R0, 0 
	MOVWF       FARG_WordToStr_input+0 
	MOVF        R1, 0 
	MOVWF       FARG_WordToStr_input+1 
	MOVLW       main_porcent1_L0+0
	MOVWF       FARG_WordToStr_output+0 
	MOVLW       hi_addr(main_porcent1_L0+0)
	MOVWF       FARG_WordToStr_output+1 
	CALL        _WordToStr+0, 0
;MyProject.c,42 :: 		lcd_out(2,1,texto);
	MOVLW       2
	MOVWF       FARG_Lcd_Out_row+0 
	MOVLW       1
	MOVWF       FARG_Lcd_Out_column+0 
	MOVLW       main_texto_L0+0
	MOVWF       FARG_Lcd_Out_text+0 
	MOVLW       hi_addr(main_texto_L0+0)
	MOVWF       FARG_Lcd_Out_text+1 
	CALL        _Lcd_Out+0, 0
;MyProject.c,43 :: 		lcd_out_cp(porcent1);
	MOVLW       main_porcent1_L0+0
	MOVWF       FARG_Lcd_Out_CP_text+0 
	MOVLW       hi_addr(main_porcent1_L0+0)
	MOVWF       FARG_Lcd_Out_CP_text+1 
	CALL        _Lcd_Out_CP+0, 0
;MyProject.c,44 :: 		}
	GOTO        L_main0
;MyProject.c,46 :: 		}
L_end_main:
	GOTO        $+0
; end of _main
