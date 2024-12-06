
_main:

;MyProject.c,20 :: 		void main() {
;MyProject.c,27 :: 		trisb = 0b00000011;
	MOVLW       3
	MOVWF       TRISB+0 
;MyProject.c,28 :: 		adcon1 = 0b00001100;
	MOVLW       12
	MOVWF       ADCON1+0 
;MyProject.c,29 :: 		trisc = 0;
	CLRF        TRISC+0 
;MyProject.c,30 :: 		lcd_init();
	CALL        _Lcd_Init+0, 0
;MyProject.c,31 :: 		lcd_cmd(_lcd_clear);
	MOVLW       1
	MOVWF       FARG_Lcd_Cmd_out_char+0 
	CALL        _Lcd_Cmd+0, 0
;MyProject.c,32 :: 		lcd_cmd(_lcd_cursor_off);
	MOVLW       12
	MOVWF       FARG_Lcd_Cmd_out_char+0 
	CALL        _Lcd_Cmd+0, 0
;MyProject.c,36 :: 		while(1){
L_main0:
;MyProject.c,37 :: 		if(button(&portb, 0, 1, 0) == 255 && adc_read(0)/10.23 > 10 ){
	MOVLW       PORTB+0
	MOVWF       FARG_Button_port+0 
	MOVLW       hi_addr(PORTB+0)
	MOVWF       FARG_Button_port+1 
	CLRF        FARG_Button_pin+0 
	MOVLW       1
	MOVWF       FARG_Button_time_ms+0 
	CLRF        FARG_Button_active_state+0 
	CALL        _Button+0, 0
	MOVF        R0, 0 
	XORLW       255
	BTFSS       STATUS+0, 2 
	GOTO        L_main4
	CLRF        FARG_ADC_Read_channel+0 
	CALL        _ADC_Read+0, 0
	CALL        _word2double+0, 0
	MOVLW       20
	MOVWF       R4 
	MOVLW       174
	MOVWF       R5 
	MOVLW       35
	MOVWF       R6 
	MOVLW       130
	MOVWF       R7 
	CALL        _Div_32x32_FP+0, 0
	MOVF        R0, 0 
	MOVWF       R4 
	MOVF        R1, 0 
	MOVWF       R5 
	MOVF        R2, 0 
	MOVWF       R6 
	MOVF        R3, 0 
	MOVWF       R7 
	MOVLW       0
	MOVWF       R0 
	MOVLW       0
	MOVWF       R1 
	MOVLW       32
	MOVWF       R2 
	MOVLW       130
	MOVWF       R3 
	CALL        _Compare_Double+0, 0
	MOVLW       1
	BTFSC       STATUS+0, 0 
	MOVLW       0
	MOVWF       R0 
	MOVF        R0, 1 
	BTFSC       STATUS+0, 2 
	GOTO        L_main4
L__main44:
;MyProject.c,38 :: 		while(1){
L_main5:
;MyProject.c,41 :: 		wordtostr(ADC_read(2)/2, txtTemperatura);
	MOVLW       2
	MOVWF       FARG_ADC_Read_channel+0 
	CALL        _ADC_Read+0, 0
	MOVF        R0, 0 
	MOVWF       FARG_WordToStr_input+0 
	MOVF        R1, 0 
	MOVWF       FARG_WordToStr_input+1 
	RRCF        FARG_WordToStr_input+1, 1 
	RRCF        FARG_WordToStr_input+0, 1 
	BCF         FARG_WordToStr_input+1, 7 
	MOVLW       main_txtTemperatura_L0+0
	MOVWF       FARG_WordToStr_output+0 
	MOVLW       hi_addr(main_txtTemperatura_L0+0)
	MOVWF       FARG_WordToStr_output+1 
	CALL        _WordToStr+0, 0
;MyProject.c,43 :: 		lcd_out(1,1, "Temperatura");
	MOVLW       1
	MOVWF       FARG_Lcd_Out_row+0 
	MOVLW       1
	MOVWF       FARG_Lcd_Out_column+0 
	MOVLW       ?lstr1_MyProject+0
	MOVWF       FARG_Lcd_Out_text+0 
	MOVLW       hi_addr(?lstr1_MyProject+0)
	MOVWF       FARG_Lcd_Out_text+1 
	CALL        _Lcd_Out+0, 0
;MyProject.c,44 :: 		lcd_out_cp(txtTemperatura);
	MOVLW       main_txtTemperatura_L0+0
	MOVWF       FARG_Lcd_Out_CP_text+0 
	MOVLW       hi_addr(main_txtTemperatura_L0+0)
	MOVWF       FARG_Lcd_Out_CP_text+1 
	CALL        _Lcd_Out_CP+0, 0
;MyProject.c,45 :: 		portc = 0b00100000;
	MOVLW       32
	MOVWF       PORTC+0 
;MyProject.c,46 :: 		lcd_out(2,1, "Aquecendo");
	MOVLW       2
	MOVWF       FARG_Lcd_Out_row+0 
	MOVLW       1
	MOVWF       FARG_Lcd_Out_column+0 
	MOVLW       ?lstr2_MyProject+0
	MOVWF       FARG_Lcd_Out_text+0 
	MOVLW       hi_addr(?lstr2_MyProject+0)
	MOVWF       FARG_Lcd_Out_text+1 
	CALL        _Lcd_Out+0, 0
;MyProject.c,47 :: 		x = adc_read(0)/10.23;
	CLRF        FARG_ADC_Read_channel+0 
	CALL        _ADC_Read+0, 0
	CALL        _word2double+0, 0
	MOVLW       20
	MOVWF       R4 
	MOVLW       174
	MOVWF       R5 
	MOVLW       35
	MOVWF       R6 
	MOVLW       130
	MOVWF       R7 
	CALL        _Div_32x32_FP+0, 0
	CALL        _double2int+0, 0
	MOVF        R0, 0 
	MOVWF       main_x_L0+0 
	MOVF        R1, 0 
	MOVWF       main_x_L0+1 
;MyProject.c,48 :: 		wordtostr(x, txtPotenciometro);
	MOVF        R0, 0 
	MOVWF       FARG_WordToStr_input+0 
	MOVF        R1, 0 
	MOVWF       FARG_WordToStr_input+1 
	MOVLW       main_txtPotenciometro_L0+0
	MOVWF       FARG_WordToStr_output+0 
	MOVLW       hi_addr(main_txtPotenciometro_L0+0)
	MOVWF       FARG_WordToStr_output+1 
	CALL        _WordToStr+0, 0
;MyProject.c,49 :: 		lcd_out(3,-3, "Potencia");
	MOVLW       3
	MOVWF       FARG_Lcd_Out_row+0 
	MOVLW       253
	MOVWF       FARG_Lcd_Out_column+0 
	MOVLW       ?lstr3_MyProject+0
	MOVWF       FARG_Lcd_Out_text+0 
	MOVLW       hi_addr(?lstr3_MyProject+0)
	MOVWF       FARG_Lcd_Out_text+1 
	CALL        _Lcd_Out+0, 0
;MyProject.c,50 :: 		lcd_out_cp(txtPotenciometro);
	MOVLW       main_txtPotenciometro_L0+0
	MOVWF       FARG_Lcd_Out_CP_text+0 
	MOVLW       hi_addr(main_txtPotenciometro_L0+0)
	MOVWF       FARG_Lcd_Out_CP_text+1 
	CALL        _Lcd_Out_CP+0, 0
;MyProject.c,51 :: 		portc = 0b00100000;
	MOVLW       32
	MOVWF       PORTC+0 
;MyProject.c,52 :: 		lcd_out_cp("%");
	MOVLW       ?lstr4_MyProject+0
	MOVWF       FARG_Lcd_Out_CP_text+0 
	MOVLW       hi_addr(?lstr4_MyProject+0)
	MOVWF       FARG_Lcd_Out_CP_text+1 
	CALL        _Lcd_Out_CP+0, 0
;MyProject.c,53 :: 		if(button(&portb, 1, 1, 0) == 255){
	MOVLW       PORTB+0
	MOVWF       FARG_Button_port+0 
	MOVLW       hi_addr(PORTB+0)
	MOVWF       FARG_Button_port+1 
	MOVLW       1
	MOVWF       FARG_Button_pin+0 
	MOVLW       1
	MOVWF       FARG_Button_time_ms+0 
	CLRF        FARG_Button_active_state+0 
	CALL        _Button+0, 0
	MOVF        R0, 0 
	XORLW       255
	BTFSS       STATUS+0, 2 
	GOTO        L_main7
;MyProject.c,54 :: 		lcd_cmd(_lcd_clear);
	MOVLW       1
	MOVWF       FARG_Lcd_Cmd_out_char+0 
	CALL        _Lcd_Cmd+0, 0
;MyProject.c,55 :: 		portc = 0;
	CLRF        PORTC+0 
;MyProject.c,56 :: 		break;
	GOTO        L_main6
;MyProject.c,57 :: 		}
L_main7:
;MyProject.c,59 :: 		if((x > 10) && (x <=35) && (ADC_read(2)/2 >= 40)){
	MOVLW       128
	MOVWF       R0 
	MOVLW       128
	XORWF       main_x_L0+1, 0 
	SUBWF       R0, 0 
	BTFSS       STATUS+0, 2 
	GOTO        L__main46
	MOVF        main_x_L0+0, 0 
	SUBLW       10
L__main46:
	BTFSC       STATUS+0, 0 
	GOTO        L_main10
	MOVLW       128
	MOVWF       R0 
	MOVLW       128
	XORWF       main_x_L0+1, 0 
	SUBWF       R0, 0 
	BTFSS       STATUS+0, 2 
	GOTO        L__main47
	MOVF        main_x_L0+0, 0 
	SUBLW       35
L__main47:
	BTFSS       STATUS+0, 0 
	GOTO        L_main10
	MOVLW       2
	MOVWF       FARG_ADC_Read_channel+0 
	CALL        _ADC_Read+0, 0
	MOVF        R0, 0 
	MOVWF       R2 
	MOVF        R1, 0 
	MOVWF       R3 
	RRCF        R3, 1 
	RRCF        R2, 1 
	BCF         R3, 7 
	MOVLW       0
	SUBWF       R3, 0 
	BTFSS       STATUS+0, 2 
	GOTO        L__main48
	MOVLW       40
	SUBWF       R2, 0 
L__main48:
	BTFSS       STATUS+0, 0 
	GOTO        L_main10
L__main43:
;MyProject.c,60 :: 		while( x <= 35){
L_main11:
	MOVLW       128
	MOVWF       R0 
	MOVLW       128
	XORWF       main_x_L0+1, 0 
	SUBWF       R0, 0 
	BTFSS       STATUS+0, 2 
	GOTO        L__main49
	MOVF        main_x_L0+0, 0 
	SUBLW       35
L__main49:
	BTFSS       STATUS+0, 0 
	GOTO        L_main12
;MyProject.c,61 :: 		portc = 0b00100100;
	MOVLW       36
	MOVWF       PORTC+0 
;MyProject.c,63 :: 		wordtostr(ADC_read(2)/2, txtTemperatura);
	MOVLW       2
	MOVWF       FARG_ADC_Read_channel+0 
	CALL        _ADC_Read+0, 0
	MOVF        R0, 0 
	MOVWF       FARG_WordToStr_input+0 
	MOVF        R1, 0 
	MOVWF       FARG_WordToStr_input+1 
	RRCF        FARG_WordToStr_input+1, 1 
	RRCF        FARG_WordToStr_input+0, 1 
	BCF         FARG_WordToStr_input+1, 7 
	MOVLW       main_txtTemperatura_L0+0
	MOVWF       FARG_WordToStr_output+0 
	MOVLW       hi_addr(main_txtTemperatura_L0+0)
	MOVWF       FARG_WordToStr_output+1 
	CALL        _WordToStr+0, 0
;MyProject.c,65 :: 		lcd_out(1,1, "Temperatura");
	MOVLW       1
	MOVWF       FARG_Lcd_Out_row+0 
	MOVLW       1
	MOVWF       FARG_Lcd_Out_column+0 
	MOVLW       ?lstr5_MyProject+0
	MOVWF       FARG_Lcd_Out_text+0 
	MOVLW       hi_addr(?lstr5_MyProject+0)
	MOVWF       FARG_Lcd_Out_text+1 
	CALL        _Lcd_Out+0, 0
;MyProject.c,66 :: 		lcd_out_cp(txtTemperatura);
	MOVLW       main_txtTemperatura_L0+0
	MOVWF       FARG_Lcd_Out_CP_text+0 
	MOVLW       hi_addr(main_txtTemperatura_L0+0)
	MOVWF       FARG_Lcd_Out_CP_text+1 
	CALL        _Lcd_Out_CP+0, 0
;MyProject.c,67 :: 		lcd_out(2,1, "Resfriando");
	MOVLW       2
	MOVWF       FARG_Lcd_Out_row+0 
	MOVLW       1
	MOVWF       FARG_Lcd_Out_column+0 
	MOVLW       ?lstr6_MyProject+0
	MOVWF       FARG_Lcd_Out_text+0 
	MOVLW       hi_addr(?lstr6_MyProject+0)
	MOVWF       FARG_Lcd_Out_text+1 
	CALL        _Lcd_Out+0, 0
;MyProject.c,68 :: 		x = adc_read(0)/10.23;
	CLRF        FARG_ADC_Read_channel+0 
	CALL        _ADC_Read+0, 0
	CALL        _word2double+0, 0
	MOVLW       20
	MOVWF       R4 
	MOVLW       174
	MOVWF       R5 
	MOVLW       35
	MOVWF       R6 
	MOVLW       130
	MOVWF       R7 
	CALL        _Div_32x32_FP+0, 0
	CALL        _double2int+0, 0
	MOVF        R0, 0 
	MOVWF       main_x_L0+0 
	MOVF        R1, 0 
	MOVWF       main_x_L0+1 
;MyProject.c,69 :: 		wordtostr(x, txtPotenciometro);
	MOVF        R0, 0 
	MOVWF       FARG_WordToStr_input+0 
	MOVF        R1, 0 
	MOVWF       FARG_WordToStr_input+1 
	MOVLW       main_txtPotenciometro_L0+0
	MOVWF       FARG_WordToStr_output+0 
	MOVLW       hi_addr(main_txtPotenciometro_L0+0)
	MOVWF       FARG_WordToStr_output+1 
	CALL        _WordToStr+0, 0
;MyProject.c,70 :: 		lcd_out(3,-3, "Potencia");
	MOVLW       3
	MOVWF       FARG_Lcd_Out_row+0 
	MOVLW       253
	MOVWF       FARG_Lcd_Out_column+0 
	MOVLW       ?lstr7_MyProject+0
	MOVWF       FARG_Lcd_Out_text+0 
	MOVLW       hi_addr(?lstr7_MyProject+0)
	MOVWF       FARG_Lcd_Out_text+1 
	CALL        _Lcd_Out+0, 0
;MyProject.c,71 :: 		lcd_out_cp(txtPotenciometro);
	MOVLW       main_txtPotenciometro_L0+0
	MOVWF       FARG_Lcd_Out_CP_text+0 
	MOVLW       hi_addr(main_txtPotenciometro_L0+0)
	MOVWF       FARG_Lcd_Out_CP_text+1 
	CALL        _Lcd_Out_CP+0, 0
;MyProject.c,72 :: 		portc = 0b00100000;
	MOVLW       32
	MOVWF       PORTC+0 
;MyProject.c,73 :: 		lcd_out_cp("%");
	MOVLW       ?lstr8_MyProject+0
	MOVWF       FARG_Lcd_Out_CP_text+0 
	MOVLW       hi_addr(?lstr8_MyProject+0)
	MOVWF       FARG_Lcd_Out_CP_text+1 
	CALL        _Lcd_Out_CP+0, 0
;MyProject.c,74 :: 		if(button(&portb, 1, 1, 0) == 255){
	MOVLW       PORTB+0
	MOVWF       FARG_Button_port+0 
	MOVLW       hi_addr(PORTB+0)
	MOVWF       FARG_Button_port+1 
	MOVLW       1
	MOVWF       FARG_Button_pin+0 
	MOVLW       1
	MOVWF       FARG_Button_time_ms+0 
	CLRF        FARG_Button_active_state+0 
	CALL        _Button+0, 0
	MOVF        R0, 0 
	XORLW       255
	BTFSS       STATUS+0, 2 
	GOTO        L_main13
;MyProject.c,75 :: 		lcd_cmd(_lcd_clear);
	MOVLW       1
	MOVWF       FARG_Lcd_Cmd_out_char+0 
	CALL        _Lcd_Cmd+0, 0
;MyProject.c,76 :: 		portc = 0;
	CLRF        PORTC+0 
;MyProject.c,77 :: 		break;
	GOTO        L_main12
;MyProject.c,78 :: 		}
L_main13:
;MyProject.c,79 :: 		}
	GOTO        L_main11
L_main12:
;MyProject.c,82 :: 		}else if ((x > 35) && (x <=50) && (ADC_read(2)/2 >= 50)){
	GOTO        L_main14
L_main10:
	MOVLW       128
	MOVWF       R0 
	MOVLW       128
	XORWF       main_x_L0+1, 0 
	SUBWF       R0, 0 
	BTFSS       STATUS+0, 2 
	GOTO        L__main50
	MOVF        main_x_L0+0, 0 
	SUBLW       35
L__main50:
	BTFSC       STATUS+0, 0 
	GOTO        L_main17
	MOVLW       128
	MOVWF       R0 
	MOVLW       128
	XORWF       main_x_L0+1, 0 
	SUBWF       R0, 0 
	BTFSS       STATUS+0, 2 
	GOTO        L__main51
	MOVF        main_x_L0+0, 0 
	SUBLW       50
L__main51:
	BTFSS       STATUS+0, 0 
	GOTO        L_main17
	MOVLW       2
	MOVWF       FARG_ADC_Read_channel+0 
	CALL        _ADC_Read+0, 0
	MOVF        R0, 0 
	MOVWF       R2 
	MOVF        R1, 0 
	MOVWF       R3 
	RRCF        R3, 1 
	RRCF        R2, 1 
	BCF         R3, 7 
	MOVLW       0
	SUBWF       R3, 0 
	BTFSS       STATUS+0, 2 
	GOTO        L__main52
	MOVLW       50
	SUBWF       R2, 0 
L__main52:
	BTFSS       STATUS+0, 0 
	GOTO        L_main17
L__main42:
;MyProject.c,83 :: 		while(x <= 50){
L_main18:
	MOVLW       128
	MOVWF       R0 
	MOVLW       128
	XORWF       main_x_L0+1, 0 
	SUBWF       R0, 0 
	BTFSS       STATUS+0, 2 
	GOTO        L__main53
	MOVF        main_x_L0+0, 0 
	SUBLW       50
L__main53:
	BTFSS       STATUS+0, 0 
	GOTO        L_main19
;MyProject.c,84 :: 		portc = 0b00100100;
	MOVLW       36
	MOVWF       PORTC+0 
;MyProject.c,86 :: 		wordtostr(ADC_read(2)/2, txtTemperatura);
	MOVLW       2
	MOVWF       FARG_ADC_Read_channel+0 
	CALL        _ADC_Read+0, 0
	MOVF        R0, 0 
	MOVWF       FARG_WordToStr_input+0 
	MOVF        R1, 0 
	MOVWF       FARG_WordToStr_input+1 
	RRCF        FARG_WordToStr_input+1, 1 
	RRCF        FARG_WordToStr_input+0, 1 
	BCF         FARG_WordToStr_input+1, 7 
	MOVLW       main_txtTemperatura_L0+0
	MOVWF       FARG_WordToStr_output+0 
	MOVLW       hi_addr(main_txtTemperatura_L0+0)
	MOVWF       FARG_WordToStr_output+1 
	CALL        _WordToStr+0, 0
;MyProject.c,88 :: 		lcd_out(1,1, "Temperatura");
	MOVLW       1
	MOVWF       FARG_Lcd_Out_row+0 
	MOVLW       1
	MOVWF       FARG_Lcd_Out_column+0 
	MOVLW       ?lstr9_MyProject+0
	MOVWF       FARG_Lcd_Out_text+0 
	MOVLW       hi_addr(?lstr9_MyProject+0)
	MOVWF       FARG_Lcd_Out_text+1 
	CALL        _Lcd_Out+0, 0
;MyProject.c,89 :: 		lcd_out_cp(txtTemperatura);
	MOVLW       main_txtTemperatura_L0+0
	MOVWF       FARG_Lcd_Out_CP_text+0 
	MOVLW       hi_addr(main_txtTemperatura_L0+0)
	MOVWF       FARG_Lcd_Out_CP_text+1 
	CALL        _Lcd_Out_CP+0, 0
;MyProject.c,90 :: 		lcd_out(2,1, "Resfriando");
	MOVLW       2
	MOVWF       FARG_Lcd_Out_row+0 
	MOVLW       1
	MOVWF       FARG_Lcd_Out_column+0 
	MOVLW       ?lstr10_MyProject+0
	MOVWF       FARG_Lcd_Out_text+0 
	MOVLW       hi_addr(?lstr10_MyProject+0)
	MOVWF       FARG_Lcd_Out_text+1 
	CALL        _Lcd_Out+0, 0
;MyProject.c,91 :: 		x = adc_read(0)/10.23;
	CLRF        FARG_ADC_Read_channel+0 
	CALL        _ADC_Read+0, 0
	CALL        _word2double+0, 0
	MOVLW       20
	MOVWF       R4 
	MOVLW       174
	MOVWF       R5 
	MOVLW       35
	MOVWF       R6 
	MOVLW       130
	MOVWF       R7 
	CALL        _Div_32x32_FP+0, 0
	CALL        _double2int+0, 0
	MOVF        R0, 0 
	MOVWF       main_x_L0+0 
	MOVF        R1, 0 
	MOVWF       main_x_L0+1 
;MyProject.c,92 :: 		wordtostr(x, txtPotenciometro);
	MOVF        R0, 0 
	MOVWF       FARG_WordToStr_input+0 
	MOVF        R1, 0 
	MOVWF       FARG_WordToStr_input+1 
	MOVLW       main_txtPotenciometro_L0+0
	MOVWF       FARG_WordToStr_output+0 
	MOVLW       hi_addr(main_txtPotenciometro_L0+0)
	MOVWF       FARG_WordToStr_output+1 
	CALL        _WordToStr+0, 0
;MyProject.c,93 :: 		lcd_out(3,-3, "Potencia");
	MOVLW       3
	MOVWF       FARG_Lcd_Out_row+0 
	MOVLW       253
	MOVWF       FARG_Lcd_Out_column+0 
	MOVLW       ?lstr11_MyProject+0
	MOVWF       FARG_Lcd_Out_text+0 
	MOVLW       hi_addr(?lstr11_MyProject+0)
	MOVWF       FARG_Lcd_Out_text+1 
	CALL        _Lcd_Out+0, 0
;MyProject.c,94 :: 		lcd_out_cp(txtPotenciometro);
	MOVLW       main_txtPotenciometro_L0+0
	MOVWF       FARG_Lcd_Out_CP_text+0 
	MOVLW       hi_addr(main_txtPotenciometro_L0+0)
	MOVWF       FARG_Lcd_Out_CP_text+1 
	CALL        _Lcd_Out_CP+0, 0
;MyProject.c,95 :: 		portc = 0b00100000;
	MOVLW       32
	MOVWF       PORTC+0 
;MyProject.c,96 :: 		lcd_out_cp("%");
	MOVLW       ?lstr12_MyProject+0
	MOVWF       FARG_Lcd_Out_CP_text+0 
	MOVLW       hi_addr(?lstr12_MyProject+0)
	MOVWF       FARG_Lcd_Out_CP_text+1 
	CALL        _Lcd_Out_CP+0, 0
;MyProject.c,97 :: 		if(button(&portb, 1, 1, 0) == 255){
	MOVLW       PORTB+0
	MOVWF       FARG_Button_port+0 
	MOVLW       hi_addr(PORTB+0)
	MOVWF       FARG_Button_port+1 
	MOVLW       1
	MOVWF       FARG_Button_pin+0 
	MOVLW       1
	MOVWF       FARG_Button_time_ms+0 
	CLRF        FARG_Button_active_state+0 
	CALL        _Button+0, 0
	MOVF        R0, 0 
	XORLW       255
	BTFSS       STATUS+0, 2 
	GOTO        L_main20
;MyProject.c,98 :: 		lcd_cmd(_lcd_clear);
	MOVLW       1
	MOVWF       FARG_Lcd_Cmd_out_char+0 
	CALL        _Lcd_Cmd+0, 0
;MyProject.c,99 :: 		portc = 0;
	CLRF        PORTC+0 
;MyProject.c,100 :: 		break;
	GOTO        L_main19
;MyProject.c,101 :: 		}
L_main20:
;MyProject.c,102 :: 		}
	GOTO        L_main18
L_main19:
;MyProject.c,104 :: 		}else if ((x > 50) && (x <=75) && (ADC_read(2)/2 >= 60)){
	GOTO        L_main21
L_main17:
	MOVLW       128
	MOVWF       R0 
	MOVLW       128
	XORWF       main_x_L0+1, 0 
	SUBWF       R0, 0 
	BTFSS       STATUS+0, 2 
	GOTO        L__main54
	MOVF        main_x_L0+0, 0 
	SUBLW       50
L__main54:
	BTFSC       STATUS+0, 0 
	GOTO        L_main24
	MOVLW       128
	MOVWF       R0 
	MOVLW       128
	XORWF       main_x_L0+1, 0 
	SUBWF       R0, 0 
	BTFSS       STATUS+0, 2 
	GOTO        L__main55
	MOVF        main_x_L0+0, 0 
	SUBLW       75
L__main55:
	BTFSS       STATUS+0, 0 
	GOTO        L_main24
	MOVLW       2
	MOVWF       FARG_ADC_Read_channel+0 
	CALL        _ADC_Read+0, 0
	MOVF        R0, 0 
	MOVWF       R2 
	MOVF        R1, 0 
	MOVWF       R3 
	RRCF        R3, 1 
	RRCF        R2, 1 
	BCF         R3, 7 
	MOVLW       0
	SUBWF       R3, 0 
	BTFSS       STATUS+0, 2 
	GOTO        L__main56
	MOVLW       60
	SUBWF       R2, 0 
L__main56:
	BTFSS       STATUS+0, 0 
	GOTO        L_main24
L__main41:
;MyProject.c,105 :: 		while(x <=75){
L_main25:
	MOVLW       128
	MOVWF       R0 
	MOVLW       128
	XORWF       main_x_L0+1, 0 
	SUBWF       R0, 0 
	BTFSS       STATUS+0, 2 
	GOTO        L__main57
	MOVF        main_x_L0+0, 0 
	SUBLW       75
L__main57:
	BTFSS       STATUS+0, 0 
	GOTO        L_main26
;MyProject.c,106 :: 		portc = 0b00100100;
	MOVLW       36
	MOVWF       PORTC+0 
;MyProject.c,108 :: 		wordtostr(ADC_read(2)/2, txtTemperatura);
	MOVLW       2
	MOVWF       FARG_ADC_Read_channel+0 
	CALL        _ADC_Read+0, 0
	MOVF        R0, 0 
	MOVWF       FARG_WordToStr_input+0 
	MOVF        R1, 0 
	MOVWF       FARG_WordToStr_input+1 
	RRCF        FARG_WordToStr_input+1, 1 
	RRCF        FARG_WordToStr_input+0, 1 
	BCF         FARG_WordToStr_input+1, 7 
	MOVLW       main_txtTemperatura_L0+0
	MOVWF       FARG_WordToStr_output+0 
	MOVLW       hi_addr(main_txtTemperatura_L0+0)
	MOVWF       FARG_WordToStr_output+1 
	CALL        _WordToStr+0, 0
;MyProject.c,110 :: 		lcd_out(1,1, "Temperatura");
	MOVLW       1
	MOVWF       FARG_Lcd_Out_row+0 
	MOVLW       1
	MOVWF       FARG_Lcd_Out_column+0 
	MOVLW       ?lstr13_MyProject+0
	MOVWF       FARG_Lcd_Out_text+0 
	MOVLW       hi_addr(?lstr13_MyProject+0)
	MOVWF       FARG_Lcd_Out_text+1 
	CALL        _Lcd_Out+0, 0
;MyProject.c,111 :: 		lcd_out_cp(txtTemperatura);
	MOVLW       main_txtTemperatura_L0+0
	MOVWF       FARG_Lcd_Out_CP_text+0 
	MOVLW       hi_addr(main_txtTemperatura_L0+0)
	MOVWF       FARG_Lcd_Out_CP_text+1 
	CALL        _Lcd_Out_CP+0, 0
;MyProject.c,112 :: 		lcd_out(2,1, "Resfriando");
	MOVLW       2
	MOVWF       FARG_Lcd_Out_row+0 
	MOVLW       1
	MOVWF       FARG_Lcd_Out_column+0 
	MOVLW       ?lstr14_MyProject+0
	MOVWF       FARG_Lcd_Out_text+0 
	MOVLW       hi_addr(?lstr14_MyProject+0)
	MOVWF       FARG_Lcd_Out_text+1 
	CALL        _Lcd_Out+0, 0
;MyProject.c,113 :: 		x = adc_read(0)/10.23;
	CLRF        FARG_ADC_Read_channel+0 
	CALL        _ADC_Read+0, 0
	CALL        _word2double+0, 0
	MOVLW       20
	MOVWF       R4 
	MOVLW       174
	MOVWF       R5 
	MOVLW       35
	MOVWF       R6 
	MOVLW       130
	MOVWF       R7 
	CALL        _Div_32x32_FP+0, 0
	CALL        _double2int+0, 0
	MOVF        R0, 0 
	MOVWF       main_x_L0+0 
	MOVF        R1, 0 
	MOVWF       main_x_L0+1 
;MyProject.c,114 :: 		wordtostr(x, txtPotenciometro);
	MOVF        R0, 0 
	MOVWF       FARG_WordToStr_input+0 
	MOVF        R1, 0 
	MOVWF       FARG_WordToStr_input+1 
	MOVLW       main_txtPotenciometro_L0+0
	MOVWF       FARG_WordToStr_output+0 
	MOVLW       hi_addr(main_txtPotenciometro_L0+0)
	MOVWF       FARG_WordToStr_output+1 
	CALL        _WordToStr+0, 0
;MyProject.c,115 :: 		lcd_out(3,-3, "Potencia");
	MOVLW       3
	MOVWF       FARG_Lcd_Out_row+0 
	MOVLW       253
	MOVWF       FARG_Lcd_Out_column+0 
	MOVLW       ?lstr15_MyProject+0
	MOVWF       FARG_Lcd_Out_text+0 
	MOVLW       hi_addr(?lstr15_MyProject+0)
	MOVWF       FARG_Lcd_Out_text+1 
	CALL        _Lcd_Out+0, 0
;MyProject.c,116 :: 		lcd_out_cp(txtPotenciometro);
	MOVLW       main_txtPotenciometro_L0+0
	MOVWF       FARG_Lcd_Out_CP_text+0 
	MOVLW       hi_addr(main_txtPotenciometro_L0+0)
	MOVWF       FARG_Lcd_Out_CP_text+1 
	CALL        _Lcd_Out_CP+0, 0
;MyProject.c,117 :: 		portc = 0b00100000;
	MOVLW       32
	MOVWF       PORTC+0 
;MyProject.c,118 :: 		lcd_out_cp("%");
	MOVLW       ?lstr16_MyProject+0
	MOVWF       FARG_Lcd_Out_CP_text+0 
	MOVLW       hi_addr(?lstr16_MyProject+0)
	MOVWF       FARG_Lcd_Out_CP_text+1 
	CALL        _Lcd_Out_CP+0, 0
;MyProject.c,119 :: 		if(button(&portb, 1, 1, 0) == 255){
	MOVLW       PORTB+0
	MOVWF       FARG_Button_port+0 
	MOVLW       hi_addr(PORTB+0)
	MOVWF       FARG_Button_port+1 
	MOVLW       1
	MOVWF       FARG_Button_pin+0 
	MOVLW       1
	MOVWF       FARG_Button_time_ms+0 
	CLRF        FARG_Button_active_state+0 
	CALL        _Button+0, 0
	MOVF        R0, 0 
	XORLW       255
	BTFSS       STATUS+0, 2 
	GOTO        L_main27
;MyProject.c,120 :: 		lcd_cmd(_lcd_clear);
	MOVLW       1
	MOVWF       FARG_Lcd_Cmd_out_char+0 
	CALL        _Lcd_Cmd+0, 0
;MyProject.c,121 :: 		portc = 0;
	CLRF        PORTC+0 
;MyProject.c,122 :: 		break;
	GOTO        L_main26
;MyProject.c,123 :: 		}
L_main27:
;MyProject.c,124 :: 		}
	GOTO        L_main25
L_main26:
;MyProject.c,126 :: 		}else if ((x > 75) && (x <=99) && (ADC_read(2)/2 >= 70)){
	GOTO        L_main28
L_main24:
	MOVLW       128
	MOVWF       R0 
	MOVLW       128
	XORWF       main_x_L0+1, 0 
	SUBWF       R0, 0 
	BTFSS       STATUS+0, 2 
	GOTO        L__main58
	MOVF        main_x_L0+0, 0 
	SUBLW       75
L__main58:
	BTFSC       STATUS+0, 0 
	GOTO        L_main31
	MOVLW       128
	MOVWF       R0 
	MOVLW       128
	XORWF       main_x_L0+1, 0 
	SUBWF       R0, 0 
	BTFSS       STATUS+0, 2 
	GOTO        L__main59
	MOVF        main_x_L0+0, 0 
	SUBLW       99
L__main59:
	BTFSS       STATUS+0, 0 
	GOTO        L_main31
	MOVLW       2
	MOVWF       FARG_ADC_Read_channel+0 
	CALL        _ADC_Read+0, 0
	MOVF        R0, 0 
	MOVWF       R2 
	MOVF        R1, 0 
	MOVWF       R3 
	RRCF        R3, 1 
	RRCF        R2, 1 
	BCF         R3, 7 
	MOVLW       0
	SUBWF       R3, 0 
	BTFSS       STATUS+0, 2 
	GOTO        L__main60
	MOVLW       70
	SUBWF       R2, 0 
L__main60:
	BTFSS       STATUS+0, 0 
	GOTO        L_main31
L__main40:
;MyProject.c,127 :: 		while(x <100){
L_main32:
	MOVLW       128
	XORWF       main_x_L0+1, 0 
	MOVWF       R0 
	MOVLW       128
	SUBWF       R0, 0 
	BTFSS       STATUS+0, 2 
	GOTO        L__main61
	MOVLW       100
	SUBWF       main_x_L0+0, 0 
L__main61:
	BTFSC       STATUS+0, 0 
	GOTO        L_main33
;MyProject.c,128 :: 		portc = 0b00100100;
	MOVLW       36
	MOVWF       PORTC+0 
;MyProject.c,130 :: 		wordtostr(ADC_read(2)/2, txtTemperatura);
	MOVLW       2
	MOVWF       FARG_ADC_Read_channel+0 
	CALL        _ADC_Read+0, 0
	MOVF        R0, 0 
	MOVWF       FARG_WordToStr_input+0 
	MOVF        R1, 0 
	MOVWF       FARG_WordToStr_input+1 
	RRCF        FARG_WordToStr_input+1, 1 
	RRCF        FARG_WordToStr_input+0, 1 
	BCF         FARG_WordToStr_input+1, 7 
	MOVLW       main_txtTemperatura_L0+0
	MOVWF       FARG_WordToStr_output+0 
	MOVLW       hi_addr(main_txtTemperatura_L0+0)
	MOVWF       FARG_WordToStr_output+1 
	CALL        _WordToStr+0, 0
;MyProject.c,132 :: 		lcd_out(1,1, "Temperatura");
	MOVLW       1
	MOVWF       FARG_Lcd_Out_row+0 
	MOVLW       1
	MOVWF       FARG_Lcd_Out_column+0 
	MOVLW       ?lstr17_MyProject+0
	MOVWF       FARG_Lcd_Out_text+0 
	MOVLW       hi_addr(?lstr17_MyProject+0)
	MOVWF       FARG_Lcd_Out_text+1 
	CALL        _Lcd_Out+0, 0
;MyProject.c,133 :: 		lcd_out_cp(txtTemperatura);
	MOVLW       main_txtTemperatura_L0+0
	MOVWF       FARG_Lcd_Out_CP_text+0 
	MOVLW       hi_addr(main_txtTemperatura_L0+0)
	MOVWF       FARG_Lcd_Out_CP_text+1 
	CALL        _Lcd_Out_CP+0, 0
;MyProject.c,134 :: 		lcd_out(2,1, "Resfriando");
	MOVLW       2
	MOVWF       FARG_Lcd_Out_row+0 
	MOVLW       1
	MOVWF       FARG_Lcd_Out_column+0 
	MOVLW       ?lstr18_MyProject+0
	MOVWF       FARG_Lcd_Out_text+0 
	MOVLW       hi_addr(?lstr18_MyProject+0)
	MOVWF       FARG_Lcd_Out_text+1 
	CALL        _Lcd_Out+0, 0
;MyProject.c,135 :: 		x = adc_read(0)/10.23;
	CLRF        FARG_ADC_Read_channel+0 
	CALL        _ADC_Read+0, 0
	CALL        _word2double+0, 0
	MOVLW       20
	MOVWF       R4 
	MOVLW       174
	MOVWF       R5 
	MOVLW       35
	MOVWF       R6 
	MOVLW       130
	MOVWF       R7 
	CALL        _Div_32x32_FP+0, 0
	CALL        _double2int+0, 0
	MOVF        R0, 0 
	MOVWF       main_x_L0+0 
	MOVF        R1, 0 
	MOVWF       main_x_L0+1 
;MyProject.c,136 :: 		wordtostr(x, txtPotenciometro);
	MOVF        R0, 0 
	MOVWF       FARG_WordToStr_input+0 
	MOVF        R1, 0 
	MOVWF       FARG_WordToStr_input+1 
	MOVLW       main_txtPotenciometro_L0+0
	MOVWF       FARG_WordToStr_output+0 
	MOVLW       hi_addr(main_txtPotenciometro_L0+0)
	MOVWF       FARG_WordToStr_output+1 
	CALL        _WordToStr+0, 0
;MyProject.c,137 :: 		lcd_out(3,-3, "Potencia");
	MOVLW       3
	MOVWF       FARG_Lcd_Out_row+0 
	MOVLW       253
	MOVWF       FARG_Lcd_Out_column+0 
	MOVLW       ?lstr19_MyProject+0
	MOVWF       FARG_Lcd_Out_text+0 
	MOVLW       hi_addr(?lstr19_MyProject+0)
	MOVWF       FARG_Lcd_Out_text+1 
	CALL        _Lcd_Out+0, 0
;MyProject.c,138 :: 		lcd_out_cp(txtPotenciometro);
	MOVLW       main_txtPotenciometro_L0+0
	MOVWF       FARG_Lcd_Out_CP_text+0 
	MOVLW       hi_addr(main_txtPotenciometro_L0+0)
	MOVWF       FARG_Lcd_Out_CP_text+1 
	CALL        _Lcd_Out_CP+0, 0
;MyProject.c,139 :: 		portc = 0b00100000;
	MOVLW       32
	MOVWF       PORTC+0 
;MyProject.c,140 :: 		lcd_out_cp("%");
	MOVLW       ?lstr20_MyProject+0
	MOVWF       FARG_Lcd_Out_CP_text+0 
	MOVLW       hi_addr(?lstr20_MyProject+0)
	MOVWF       FARG_Lcd_Out_CP_text+1 
	CALL        _Lcd_Out_CP+0, 0
;MyProject.c,141 :: 		if(button(&portb, 1, 1, 0) == 255){
	MOVLW       PORTB+0
	MOVWF       FARG_Button_port+0 
	MOVLW       hi_addr(PORTB+0)
	MOVWF       FARG_Button_port+1 
	MOVLW       1
	MOVWF       FARG_Button_pin+0 
	MOVLW       1
	MOVWF       FARG_Button_time_ms+0 
	CLRF        FARG_Button_active_state+0 
	CALL        _Button+0, 0
	MOVF        R0, 0 
	XORLW       255
	BTFSS       STATUS+0, 2 
	GOTO        L_main34
;MyProject.c,142 :: 		lcd_cmd(_lcd_clear);
	MOVLW       1
	MOVWF       FARG_Lcd_Cmd_out_char+0 
	CALL        _Lcd_Cmd+0, 0
;MyProject.c,143 :: 		portc = 0;
	CLRF        PORTC+0 
;MyProject.c,144 :: 		break;
	GOTO        L_main33
;MyProject.c,145 :: 		}
L_main34:
;MyProject.c,146 :: 		}
	GOTO        L_main32
L_main33:
;MyProject.c,147 :: 		}if (x == 100){
L_main31:
L_main28:
L_main21:
L_main14:
	MOVLW       0
	XORWF       main_x_L0+1, 0 
	BTFSS       STATUS+0, 2 
	GOTO        L__main62
	MOVLW       100
	XORWF       main_x_L0+0, 0 
L__main62:
	BTFSS       STATUS+0, 2 
	GOTO        L_main35
;MyProject.c,150 :: 		delay_ms(5000);
	MOVLW       51
	MOVWF       R11, 0
	MOVLW       187
	MOVWF       R12, 0
	MOVLW       223
	MOVWF       R13, 0
L_main36:
	DECFSZ      R13, 1, 1
	BRA         L_main36
	DECFSZ      R12, 1, 1
	BRA         L_main36
	DECFSZ      R11, 1, 1
	BRA         L_main36
	NOP
	NOP
;MyProject.c,151 :: 		if(button(&portb, 1, 1, 0) == 255){
	MOVLW       PORTB+0
	MOVWF       FARG_Button_port+0 
	MOVLW       hi_addr(PORTB+0)
	MOVWF       FARG_Button_port+1 
	MOVLW       1
	MOVWF       FARG_Button_pin+0 
	MOVLW       1
	MOVWF       FARG_Button_time_ms+0 
	CLRF        FARG_Button_active_state+0 
	CALL        _Button+0, 0
	MOVF        R0, 0 
	XORLW       255
	BTFSS       STATUS+0, 2 
	GOTO        L_main37
;MyProject.c,152 :: 		lcd_cmd(_lcd_clear);
	MOVLW       1
	MOVWF       FARG_Lcd_Cmd_out_char+0 
	CALL        _Lcd_Cmd+0, 0
;MyProject.c,153 :: 		portc = 0;
	CLRF        PORTC+0 
;MyProject.c,154 :: 		porta = 0;
	CLRF        PORTA+0 
;MyProject.c,155 :: 		portd = 0;
	CLRF        PORTD+0 
;MyProject.c,156 :: 		break;
	GOTO        L_main6
;MyProject.c,157 :: 		}
L_main37:
;MyProject.c,158 :: 		x = adc_read(0)/10.23;
	CLRF        FARG_ADC_Read_channel+0 
	CALL        _ADC_Read+0, 0
	CALL        _word2double+0, 0
	MOVLW       20
	MOVWF       R4 
	MOVLW       174
	MOVWF       R5 
	MOVLW       35
	MOVWF       R6 
	MOVLW       130
	MOVWF       R7 
	CALL        _Div_32x32_FP+0, 0
	CALL        _double2int+0, 0
	MOVF        R0, 0 
	MOVWF       main_x_L0+0 
	MOVF        R1, 0 
	MOVWF       main_x_L0+1 
;MyProject.c,159 :: 		if(x == 100){
	MOVLW       0
	XORWF       R1, 0 
	BTFSS       STATUS+0, 2 
	GOTO        L__main63
	MOVLW       100
	XORWF       R0, 0 
L__main63:
	BTFSS       STATUS+0, 2 
	GOTO        L_main38
;MyProject.c,160 :: 		trisa = 0;
	CLRF        TRISA+0 
;MyProject.c,161 :: 		trisd = 0;
	CLRF        TRISD+0 
;MyProject.c,162 :: 		porta = 0b00000100;
	MOVLW       4
	MOVWF       PORTA+0 
;MyProject.c,164 :: 		portd = 0b01111001;
	MOVLW       121
	MOVWF       PORTD+0 
;MyProject.c,165 :: 		delay_ms(800);
	MOVLW       9
	MOVWF       R11, 0
	MOVLW       30
	MOVWF       R12, 0
	MOVLW       228
	MOVWF       R13, 0
L_main39:
	DECFSZ      R13, 1, 1
	BRA         L_main39
	DECFSZ      R12, 1, 1
	BRA         L_main39
	DECFSZ      R11, 1, 1
	BRA         L_main39
	NOP
;MyProject.c,167 :: 		portc = 0;
	CLRF        PORTC+0 
;MyProject.c,168 :: 		porta = 0;
	CLRF        PORTA+0 
;MyProject.c,169 :: 		portd = 0;
	CLRF        PORTD+0 
;MyProject.c,170 :: 		break;
	GOTO        L_main6
;MyProject.c,172 :: 		}
L_main38:
;MyProject.c,174 :: 		}
L_main35:
;MyProject.c,175 :: 		}
	GOTO        L_main5
L_main6:
;MyProject.c,176 :: 		}
L_main4:
;MyProject.c,177 :: 		}
	GOTO        L_main0
;MyProject.c,178 :: 		}
L_end_main:
	GOTO        $+0
; end of _main
