
_main:

;ex2.c,18 :: 		void main() {
;ex2.c,20 :: 		int a = 0;
	CLRF        main_a_L0+0 
	CLRF        main_a_L0+1 
;ex2.c,21 :: 		lcd_init();
	CALL        _Lcd_Init+0, 0
;ex2.c,22 :: 		lcd_cmd(_lcd_clear);
	MOVLW       1
	MOVWF       FARG_Lcd_Cmd_out_char+0 
	CALL        _Lcd_Cmd+0, 0
;ex2.c,23 :: 		lcd_cmd(_LCD_CURSOR_OFF);
	MOVLW       12
	MOVWF       FARG_Lcd_Cmd_out_char+0 
	CALL        _Lcd_Cmd+0, 0
;ex2.c,24 :: 		while(1){
L_main0:
;ex2.c,25 :: 		trisb = 0b00100000;
	MOVLW       32
	MOVWF       TRISB+0 
;ex2.c,26 :: 		lcd_out(1,1,"Valor led ");
	MOVLW       1
	MOVWF       FARG_Lcd_Out_row+0 
	MOVLW       1
	MOVWF       FARG_Lcd_Out_column+0 
	MOVLW       ?lstr1_ex2+0
	MOVWF       FARG_Lcd_Out_text+0 
	MOVLW       hi_addr(?lstr1_ex2+0)
	MOVWF       FARG_Lcd_Out_text+1 
	CALL        _Lcd_Out+0, 0
;ex2.c,27 :: 		if (button(&portb,5,1,0)==255){
	MOVLW       PORTB+0
	MOVWF       FARG_Button_port+0 
	MOVLW       hi_addr(PORTB+0)
	MOVWF       FARG_Button_port+1 
	MOVLW       5
	MOVWF       FARG_Button_pin+0 
	MOVLW       1
	MOVWF       FARG_Button_time_ms+0 
	CLRF        FARG_Button_active_state+0 
	CALL        _Button+0, 0
	MOVF        R0, 0 
	XORLW       255
	BTFSS       STATUS+0, 2 
	GOTO        L_main2
;ex2.c,28 :: 		a = 0;
	CLRF        main_a_L0+0 
	CLRF        main_a_L0+1 
;ex2.c,29 :: 		trisb = 0b00000000;
	CLRF        TRISB+0 
;ex2.c,30 :: 		while(a<=255){
L_main3:
	MOVLW       128
	MOVWF       R0 
	MOVLW       128
	XORWF       main_a_L0+1, 0 
	SUBWF       R0, 0 
	BTFSS       STATUS+0, 2 
	GOTO        L__main7
	MOVF        main_a_L0+0, 0 
	SUBLW       255
L__main7:
	BTFSS       STATUS+0, 0 
	GOTO        L_main4
;ex2.c,31 :: 		portb = a;
	MOVF        main_a_L0+0, 0 
	MOVWF       PORTB+0 
;ex2.c,32 :: 		WordToStr(a, texto);
	MOVF        main_a_L0+0, 0 
	MOVWF       FARG_WordToStr_input+0 
	MOVF        main_a_L0+1, 0 
	MOVWF       FARG_WordToStr_input+1 
	MOVLW       main_texto_L0+0
	MOVWF       FARG_WordToStr_output+0 
	MOVLW       hi_addr(main_texto_L0+0)
	MOVWF       FARG_WordToStr_output+1 
	CALL        _WordToStr+0, 0
;ex2.c,33 :: 		lcd_out(1,1,"Valor led ");
	MOVLW       1
	MOVWF       FARG_Lcd_Out_row+0 
	MOVLW       1
	MOVWF       FARG_Lcd_Out_column+0 
	MOVLW       ?lstr2_ex2+0
	MOVWF       FARG_Lcd_Out_text+0 
	MOVLW       hi_addr(?lstr2_ex2+0)
	MOVWF       FARG_Lcd_Out_text+1 
	CALL        _Lcd_Out+0, 0
;ex2.c,34 :: 		lcd_out_cp(texto);
	MOVLW       main_texto_L0+0
	MOVWF       FARG_Lcd_Out_CP_text+0 
	MOVLW       hi_addr(main_texto_L0+0)
	MOVWF       FARG_Lcd_Out_CP_text+1 
	CALL        _Lcd_Out_CP+0, 0
;ex2.c,35 :: 		delay_ms(5000);
	MOVLW       7
	MOVWF       R11, 0
	MOVLW       88
	MOVWF       R12, 0
	MOVLW       89
	MOVWF       R13, 0
L_main5:
	DECFSZ      R13, 1, 1
	BRA         L_main5
	DECFSZ      R12, 1, 1
	BRA         L_main5
	DECFSZ      R11, 1, 1
	BRA         L_main5
	NOP
	NOP
;ex2.c,36 :: 		a = a*2+1;
	RLCF        main_a_L0+0, 1 
	BCF         main_a_L0+0, 0 
	RLCF        main_a_L0+1, 1 
	INFSNZ      main_a_L0+0, 1 
	INCF        main_a_L0+1, 1 
;ex2.c,37 :: 		lcd_cmd(_lcd_clear);
	MOVLW       1
	MOVWF       FARG_Lcd_Cmd_out_char+0 
	CALL        _Lcd_Cmd+0, 0
;ex2.c,38 :: 		}
	GOTO        L_main3
L_main4:
;ex2.c,39 :: 		}
L_main2:
;ex2.c,41 :: 		}
	GOTO        L_main0
;ex2.c,42 :: 		}
L_end_main:
	GOTO        $+0
; end of _main
