
_main:

;MyProject.c,17 :: 		void main() {
;MyProject.c,20 :: 		adcon1 = 0b00001110;
	MOVLW       14
	MOVWF       ADCON1+0 
;MyProject.c,21 :: 		lcd_init();
	CALL        _Lcd_Init+0, 0
;MyProject.c,22 :: 		lcd_cmd(_lcd_clear);
	MOVLW       1
	MOVWF       FARG_Lcd_Cmd_out_char+0 
	CALL        _Lcd_Cmd+0, 0
;MyProject.c,23 :: 		lcd_cmd(_lcd_cursor_off);
	MOVLW       12
	MOVWF       FARG_Lcd_Cmd_out_char+0 
	CALL        _Lcd_Cmd+0, 0
;MyProject.c,24 :: 		lcd_out(1,1,"ANO: ");
	MOVLW       1
	MOVWF       FARG_Lcd_Out_row+0 
	MOVLW       1
	MOVWF       FARG_Lcd_Out_column+0 
	MOVLW       ?lstr1_MyProject+0
	MOVWF       FARG_Lcd_Out_text+0 
	MOVLW       hi_addr(?lstr1_MyProject+0)
	MOVWF       FARG_Lcd_Out_text+1 
	CALL        _Lcd_Out+0, 0
;MyProject.c,25 :: 		pwm1_init(5000);
	BSF         T2CON+0, 0, 0
	BCF         T2CON+0, 1, 0
	MOVLW       99
	MOVWF       PR2+0, 0
	CALL        _PWM1_Init+0, 0
;MyProject.c,26 :: 		pwm1_start();
	CALL        _PWM1_Start+0, 0
;MyProject.c,27 :: 		while(1){
L_main0:
;MyProject.c,28 :: 		leitura_AD = adc_read(0);
	CLRF        FARG_ADC_Read_channel+0 
	CALL        _ADC_Read+0, 0
	MOVF        R0, 0 
	MOVWF       main_leitura_AD_L0+0 
	MOVF        R1, 0 
	MOVWF       main_leitura_AD_L0+1 
;MyProject.c,29 :: 		leitura_AD = leitura_AD/4;
	MOVLW       4
	MOVWF       R4 
	MOVLW       0
	MOVWF       R5 
	CALL        _Div_16x16_S+0, 0
	MOVF        R0, 0 
	MOVWF       main_leitura_AD_L0+0 
	MOVF        R1, 0 
	MOVWF       main_leitura_AD_L0+1 
;MyProject.c,30 :: 		wordtostr(leitura_AD, texto);
	MOVF        R0, 0 
	MOVWF       FARG_WordToStr_input+0 
	MOVF        R1, 0 
	MOVWF       FARG_WordToStr_input+1 
	MOVLW       main_texto_L0+0
	MOVWF       FARG_WordToStr_output+0 
	MOVLW       hi_addr(main_texto_L0+0)
	MOVWF       FARG_WordToStr_output+1 
	CALL        _WordToStr+0, 0
;MyProject.c,31 :: 		lcd_out(1,5,texto);
	MOVLW       1
	MOVWF       FARG_Lcd_Out_row+0 
	MOVLW       5
	MOVWF       FARG_Lcd_Out_column+0 
	MOVLW       main_texto_L0+0
	MOVWF       FARG_Lcd_Out_text+0 
	MOVLW       hi_addr(main_texto_L0+0)
	MOVWF       FARG_Lcd_Out_text+1 
	CALL        _Lcd_Out+0, 0
;MyProject.c,32 :: 		pwm1_set_duty(leitura_AD);
	MOVF        main_leitura_AD_L0+0, 0 
	MOVWF       FARG_PWM1_Set_Duty_new_duty+0 
	CALL        _PWM1_Set_Duty+0, 0
;MyProject.c,33 :: 		}
	GOTO        L_main0
;MyProject.c,35 :: 		}
L_end_main:
	GOTO        $+0
; end of _main
