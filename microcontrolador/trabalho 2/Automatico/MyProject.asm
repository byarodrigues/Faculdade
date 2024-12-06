
_main:

;MyProject.c,19 :: 		void main() {
;MyProject.c,25 :: 		trisb = 0b00000011;
	MOVLW       3
	MOVWF       TRISB+0 
;MyProject.c,26 :: 		adcon1 = 0b00001100;
	MOVLW       12
	MOVWF       ADCON1+0 
;MyProject.c,27 :: 		trisc = 0;
	CLRF        TRISC+0 
;MyProject.c,28 :: 		lcd_init();
	CALL        _Lcd_Init+0, 0
;MyProject.c,29 :: 		lcd_cmd(_lcd_clear);
	MOVLW       1
	MOVWF       FARG_Lcd_Cmd_out_char+0 
	CALL        _Lcd_Cmd+0, 0
;MyProject.c,30 :: 		lcd_cmd(_lcd_cursor_off);
	MOVLW       12
	MOVWF       FARG_Lcd_Cmd_out_char+0 
	CALL        _Lcd_Cmd+0, 0
;MyProject.c,33 :: 		while(1){
L_main0:
;MyProject.c,34 :: 		if(button(&portb, 0, 1, 0) == 255 ){
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
	GOTO        L_main2
;MyProject.c,35 :: 		lcd_out(1,1, "Sistema Iniciado");
	MOVLW       1
	MOVWF       FARG_Lcd_Out_row+0 
	MOVLW       1
	MOVWF       FARG_Lcd_Out_column+0 
	MOVLW       ?lstr1_MyProject+0
	MOVWF       FARG_Lcd_Out_text+0 
	MOVLW       hi_addr(?lstr1_MyProject+0)
	MOVWF       FARG_Lcd_Out_text+1 
	CALL        _Lcd_Out+0, 0
;MyProject.c,36 :: 		lcd_out(2,1, "Automaticamente");
	MOVLW       2
	MOVWF       FARG_Lcd_Out_row+0 
	MOVLW       1
	MOVWF       FARG_Lcd_Out_column+0 
	MOVLW       ?lstr2_MyProject+0
	MOVWF       FARG_Lcd_Out_text+0 
	MOVLW       hi_addr(?lstr2_MyProject+0)
	MOVWF       FARG_Lcd_Out_text+1 
	CALL        _Lcd_Out+0, 0
;MyProject.c,37 :: 		delay_ms(500);
	MOVLW       6
	MOVWF       R11, 0
	MOVLW       19
	MOVWF       R12, 0
	MOVLW       173
	MOVWF       R13, 0
L_main3:
	DECFSZ      R13, 1, 1
	BRA         L_main3
	DECFSZ      R12, 1, 1
	BRA         L_main3
	DECFSZ      R11, 1, 1
	BRA         L_main3
	NOP
	NOP
;MyProject.c,38 :: 		while(1){
L_main4:
;MyProject.c,40 :: 		wordtostr(ADC_read(2)/2, txtTemperatura);
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
;MyProject.c,42 :: 		lcd_out(1,1, "Temperatura");
	MOVLW       1
	MOVWF       FARG_Lcd_Out_row+0 
	MOVLW       1
	MOVWF       FARG_Lcd_Out_column+0 
	MOVLW       ?lstr3_MyProject+0
	MOVWF       FARG_Lcd_Out_text+0 
	MOVLW       hi_addr(?lstr3_MyProject+0)
	MOVWF       FARG_Lcd_Out_text+1 
	CALL        _Lcd_Out+0, 0
;MyProject.c,43 :: 		lcd_out_cp(txtTemperatura);
	MOVLW       main_txtTemperatura_L0+0
	MOVWF       FARG_Lcd_Out_CP_text+0 
	MOVLW       hi_addr(main_txtTemperatura_L0+0)
	MOVWF       FARG_Lcd_Out_CP_text+1 
	CALL        _Lcd_Out_CP+0, 0
;MyProject.c,44 :: 		portc = 0b00100000;
	MOVLW       32
	MOVWF       PORTC+0 
;MyProject.c,45 :: 		lcd_out(2,1, "Aquecendo      ");
	MOVLW       2
	MOVWF       FARG_Lcd_Out_row+0 
	MOVLW       1
	MOVWF       FARG_Lcd_Out_column+0 
	MOVLW       ?lstr4_MyProject+0
	MOVWF       FARG_Lcd_Out_text+0 
	MOVLW       hi_addr(?lstr4_MyProject+0)
	MOVWF       FARG_Lcd_Out_text+1 
	CALL        _Lcd_Out+0, 0
;MyProject.c,46 :: 		lcd_out(3,-3, "Potencia Maxima   ");
	MOVLW       3
	MOVWF       FARG_Lcd_Out_row+0 
	MOVLW       253
	MOVWF       FARG_Lcd_Out_column+0 
	MOVLW       ?lstr5_MyProject+0
	MOVWF       FARG_Lcd_Out_text+0 
	MOVLW       hi_addr(?lstr5_MyProject+0)
	MOVWF       FARG_Lcd_Out_text+1 
	CALL        _Lcd_Out+0, 0
;MyProject.c,49 :: 		if(button(&portb, 1, 1, 0) == 255){
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
	GOTO        L_main6
;MyProject.c,50 :: 		lcd_cmd(_lcd_clear);
	MOVLW       1
	MOVWF       FARG_Lcd_Cmd_out_char+0 
	CALL        _Lcd_Cmd+0, 0
;MyProject.c,51 :: 		portc = 0;
	CLRF        PORTC+0 
;MyProject.c,52 :: 		break;
	GOTO        L_main5
;MyProject.c,53 :: 		}
L_main6:
;MyProject.c,55 :: 		if(ADC_read(2)/2 >= 28 && ADC_read(2)/2 <= 50){
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
	GOTO        L__main34
	MOVLW       28
	SUBWF       R2, 0 
L__main34:
	BTFSS       STATUS+0, 0 
	GOTO        L_main9
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
	MOVWF       R0 
	MOVF        R3, 0 
	SUBWF       R0, 0 
	BTFSS       STATUS+0, 2 
	GOTO        L__main35
	MOVF        R2, 0 
	SUBLW       50
L__main35:
	BTFSS       STATUS+0, 0 
	GOTO        L_main9
L__main32:
;MyProject.c,56 :: 		portb = 0b00100011;
	MOVLW       35
	MOVWF       PORTB+0 
;MyProject.c,58 :: 		}else if(ADC_read(2)/2 >= 51 && ADC_read(2)/2 <= 69){
	GOTO        L_main10
L_main9:
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
	GOTO        L__main36
	MOVLW       51
	SUBWF       R2, 0 
L__main36:
	BTFSS       STATUS+0, 0 
	GOTO        L_main13
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
	MOVWF       R0 
	MOVF        R3, 0 
	SUBWF       R0, 0 
	BTFSS       STATUS+0, 2 
	GOTO        L__main37
	MOVF        R2, 0 
	SUBLW       69
L__main37:
	BTFSS       STATUS+0, 0 
	GOTO        L_main13
L__main31:
;MyProject.c,59 :: 		portb = 0b01100011;
	MOVLW       99
	MOVWF       PORTB+0 
;MyProject.c,61 :: 		}else if (ADC_read(2)/2 == 70 ){
	GOTO        L_main14
L_main13:
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
	XORWF       R3, 0 
	BTFSS       STATUS+0, 2 
	GOTO        L__main38
	MOVLW       70
	XORWF       R2, 0 
L__main38:
	BTFSS       STATUS+0, 2 
	GOTO        L_main15
;MyProject.c,62 :: 		portb = 0b11100011;
	MOVLW       227
	MOVWF       PORTB+0 
;MyProject.c,63 :: 		}
L_main15:
L_main14:
L_main10:
;MyProject.c,66 :: 		if(ADC_read(2)/2 > 70){
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
	MOVWF       R0 
	MOVF        R3, 0 
	SUBWF       R0, 0 
	BTFSS       STATUS+0, 2 
	GOTO        L__main39
	MOVF        R2, 0 
	SUBLW       70
L__main39:
	BTFSC       STATUS+0, 0 
	GOTO        L_main16
;MyProject.c,67 :: 		lcd_cmd(_lcd_clear);
	MOVLW       1
	MOVWF       FARG_Lcd_Cmd_out_char+0 
	CALL        _Lcd_Cmd+0, 0
;MyProject.c,68 :: 		while(ADC_read(2)/2 > 28){
L_main17:
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
	MOVWF       R0 
	MOVF        R3, 0 
	SUBWF       R0, 0 
	BTFSS       STATUS+0, 2 
	GOTO        L__main40
	MOVF        R2, 0 
	SUBLW       28
L__main40:
	BTFSC       STATUS+0, 0 
	GOTO        L_main18
;MyProject.c,69 :: 		portc = 0b00100100;
	MOVLW       36
	MOVWF       PORTC+0 
;MyProject.c,71 :: 		wordtostr(ADC_read(2)/2, txtTemperatura);
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
;MyProject.c,73 :: 		lcd_out(1,1, "Temperatura");
	MOVLW       1
	MOVWF       FARG_Lcd_Out_row+0 
	MOVLW       1
	MOVWF       FARG_Lcd_Out_column+0 
	MOVLW       ?lstr6_MyProject+0
	MOVWF       FARG_Lcd_Out_text+0 
	MOVLW       hi_addr(?lstr6_MyProject+0)
	MOVWF       FARG_Lcd_Out_text+1 
	CALL        _Lcd_Out+0, 0
;MyProject.c,74 :: 		lcd_out_cp(txtTemperatura);
	MOVLW       main_txtTemperatura_L0+0
	MOVWF       FARG_Lcd_Out_CP_text+0 
	MOVLW       hi_addr(main_txtTemperatura_L0+0)
	MOVWF       FARG_Lcd_Out_CP_text+1 
	CALL        _Lcd_Out_CP+0, 0
;MyProject.c,75 :: 		lcd_out(2,1, "Resfriando");
	MOVLW       2
	MOVWF       FARG_Lcd_Out_row+0 
	MOVLW       1
	MOVWF       FARG_Lcd_Out_column+0 
	MOVLW       ?lstr7_MyProject+0
	MOVWF       FARG_Lcd_Out_text+0 
	MOVLW       hi_addr(?lstr7_MyProject+0)
	MOVWF       FARG_Lcd_Out_text+1 
	CALL        _Lcd_Out+0, 0
;MyProject.c,77 :: 		if(ADC_read(2)/2 == 70){
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
	XORWF       R3, 0 
	BTFSS       STATUS+0, 2 
	GOTO        L__main41
	MOVLW       70
	XORWF       R2, 0 
L__main41:
	BTFSS       STATUS+0, 2 
	GOTO        L_main19
;MyProject.c,78 :: 		portb = 0b11100011;
	MOVLW       227
	MOVWF       PORTB+0 
;MyProject.c,80 :: 		}else if(ADC_read(2)/2 <= 69 && ADC_read(2)/2 >= 51){
	GOTO        L_main20
L_main19:
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
	MOVWF       R0 
	MOVF        R3, 0 
	SUBWF       R0, 0 
	BTFSS       STATUS+0, 2 
	GOTO        L__main42
	MOVF        R2, 0 
	SUBLW       69
L__main42:
	BTFSS       STATUS+0, 0 
	GOTO        L_main23
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
	GOTO        L__main43
	MOVLW       51
	SUBWF       R2, 0 
L__main43:
	BTFSS       STATUS+0, 0 
	GOTO        L_main23
L__main30:
;MyProject.c,81 :: 		portb = 0b01100011;
	MOVLW       99
	MOVWF       PORTB+0 
;MyProject.c,83 :: 		}else if (ADC_read(2)/2 <= 50 && ADC_read(2)/2 >= 28 ){
	GOTO        L_main24
L_main23:
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
	MOVWF       R0 
	MOVF        R3, 0 
	SUBWF       R0, 0 
	BTFSS       STATUS+0, 2 
	GOTO        L__main44
	MOVF        R2, 0 
	SUBLW       50
L__main44:
	BTFSS       STATUS+0, 0 
	GOTO        L_main27
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
	GOTO        L__main45
	MOVLW       28
	SUBWF       R2, 0 
L__main45:
	BTFSS       STATUS+0, 0 
	GOTO        L_main27
L__main29:
;MyProject.c,84 :: 		portb = 0b00100011;
	MOVLW       35
	MOVWF       PORTB+0 
;MyProject.c,85 :: 		}
L_main27:
L_main24:
L_main20:
;MyProject.c,86 :: 		if(button(&portb, 1, 1, 0) == 255){
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
	GOTO        L_main28
;MyProject.c,87 :: 		lcd_cmd(_lcd_clear);
	MOVLW       1
	MOVWF       FARG_Lcd_Cmd_out_char+0 
	CALL        _Lcd_Cmd+0, 0
;MyProject.c,88 :: 		portc = 0;
	CLRF        PORTC+0 
;MyProject.c,89 :: 		break;
	GOTO        L_main18
;MyProject.c,90 :: 		}
L_main28:
;MyProject.c,91 :: 		}
	GOTO        L_main17
L_main18:
;MyProject.c,92 :: 		}
L_main16:
;MyProject.c,93 :: 		}
	GOTO        L_main4
L_main5:
;MyProject.c,94 :: 		}
L_main2:
;MyProject.c,95 :: 		}
	GOTO        L_main0
;MyProject.c,96 :: 		}
L_end_main:
	GOTO        $+0
; end of _main
