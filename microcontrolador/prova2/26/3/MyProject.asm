
_main:

;MyProject.c,17 :: 		void main() {
;MyProject.c,18 :: 		int i = 1;
	MOVLW       1
	MOVWF       main_i_L0+0 
	MOVLW       0
	MOVWF       main_i_L0+1 
;MyProject.c,20 :: 		trisb = 0b000000011;
	MOVLW       3
	MOVWF       TRISB+0 
;MyProject.c,21 :: 		lcd_init();
	CALL        _Lcd_Init+0, 0
;MyProject.c,22 :: 		lcd_cmd(_lcd_cursor_off);
	MOVLW       12
	MOVWF       FARG_Lcd_Cmd_out_char+0 
	CALL        _Lcd_Cmd+0, 0
;MyProject.c,23 :: 		tmr0h = 0xc2;
	MOVLW       194
	MOVWF       TMR0H+0 
;MyProject.c,24 :: 		tmr0l = 0xf7;
	MOVLW       247
	MOVWF       TMR0L+0 
;MyProject.c,25 :: 		t0con = 0b10000110;
	MOVLW       134
	MOVWF       T0CON+0 
;MyProject.c,27 :: 		while(1){
L_main0:
;MyProject.c,28 :: 		lcd_out(1,1,"Seja bem vindo! ");
	MOVLW       1
	MOVWF       FARG_Lcd_Out_row+0 
	MOVLW       1
	MOVWF       FARG_Lcd_Out_column+0 
	MOVLW       ?lstr1_MyProject+0
	MOVWF       FARG_Lcd_Out_text+0 
	MOVLW       hi_addr(?lstr1_MyProject+0)
	MOVWF       FARG_Lcd_Out_text+1 
	CALL        _Lcd_Out+0, 0
;MyProject.c,29 :: 		lcd_out(2,1,"Aperte b0 ou b1 ");
	MOVLW       2
	MOVWF       FARG_Lcd_Out_row+0 
	MOVLW       1
	MOVWF       FARG_Lcd_Out_column+0 
	MOVLW       ?lstr2_MyProject+0
	MOVWF       FARG_Lcd_Out_text+0 
	MOVLW       hi_addr(?lstr2_MyProject+0)
	MOVWF       FARG_Lcd_Out_text+1 
	CALL        _Lcd_Out+0, 0
;MyProject.c,30 :: 		portd = 0;
	CLRF        PORTD+0 
;MyProject.c,31 :: 		if(button(&portb,0,1,0)){
	MOVLW       PORTB+0
	MOVWF       FARG_Button_port+0 
	MOVLW       hi_addr(PORTB+0)
	MOVWF       FARG_Button_port+1 
	CLRF        FARG_Button_pin+0 
	MOVLW       1
	MOVWF       FARG_Button_time_ms+0 
	CLRF        FARG_Button_active_state+0 
	CALL        _Button+0, 0
	MOVF        R0, 1 
	BTFSC       STATUS+0, 2 
	GOTO        L_main2
;MyProject.c,32 :: 		trisb = 0;
	CLRF        TRISB+0 
;MyProject.c,33 :: 		portb = 0;
	CLRF        PORTB+0 
;MyProject.c,34 :: 		intcon.TMR0IF = 0;
	BCF         INTCON+0, 2 
;MyProject.c,35 :: 		lcd_cmd(_lcd_clear);
	MOVLW       1
	MOVWF       FARG_Lcd_Cmd_out_char+0 
	CALL        _Lcd_Cmd+0, 0
;MyProject.c,36 :: 		lcd_out(1,1,"Vezes LED2:");
	MOVLW       1
	MOVWF       FARG_Lcd_Out_row+0 
	MOVLW       1
	MOVWF       FARG_Lcd_Out_column+0 
	MOVLW       ?lstr3_MyProject+0
	MOVWF       FARG_Lcd_Out_text+0 
	MOVLW       hi_addr(?lstr3_MyProject+0)
	MOVWF       FARG_Lcd_Out_text+1 
	CALL        _Lcd_Out+0, 0
;MyProject.c,37 :: 		lcd_out(2,1,"Vezes LED1:");
	MOVLW       2
	MOVWF       FARG_Lcd_Out_row+0 
	MOVLW       1
	MOVWF       FARG_Lcd_Out_column+0 
	MOVLW       ?lstr4_MyProject+0
	MOVWF       FARG_Lcd_Out_text+0 
	MOVLW       hi_addr(?lstr4_MyProject+0)
	MOVWF       FARG_Lcd_Out_text+1 
	CALL        _Lcd_Out+0, 0
;MyProject.c,38 :: 		while(i<15){
L_main3:
	MOVLW       128
	XORWF       main_i_L0+1, 0 
	MOVWF       R0 
	MOVLW       128
	SUBWF       R0, 0 
	BTFSS       STATUS+0, 2 
	GOTO        L__main7
	MOVLW       15
	SUBWF       main_i_L0+0, 0 
L__main7:
	BTFSC       STATUS+0, 0 
	GOTO        L_main4
;MyProject.c,39 :: 		trisd = 0;
	CLRF        TRISD+0 
;MyProject.c,41 :: 		if(intcon.tmr0if == 1){
	BTFSS       INTCON+0, 2 
	GOTO        L_main5
;MyProject.c,42 :: 		portb = ~portb;
	COMF        PORTB+0, 1 
;MyProject.c,43 :: 		portd = ~portd;
	COMF        PORTD+0, 1 
;MyProject.c,44 :: 		intcon.tmr0if = 0;
	BCF         INTCON+0, 2 
;MyProject.c,45 :: 		tmr0h = 0xc2;
	MOVLW       194
	MOVWF       TMR0H+0 
;MyProject.c,46 :: 		tmr0l = 0xf7;
	MOVLW       247
	MOVWF       TMR0L+0 
;MyProject.c,47 :: 		i = i + 1;
	INFSNZ      main_i_L0+0, 1 
	INCF        main_i_L0+1, 1 
;MyProject.c,48 :: 		wordtostr(i/2,txt);
	MOVF        main_i_L0+0, 0 
	MOVWF       FARG_WordToStr_input+0 
	MOVF        main_i_L0+1, 0 
	MOVWF       FARG_WordToStr_input+1 
	RRCF        FARG_WordToStr_input+1, 1 
	RRCF        FARG_WordToStr_input+0, 1 
	BCF         FARG_WordToStr_input+1, 7 
	BTFSC       FARG_WordToStr_input+1, 6 
	BSF         FARG_WordToStr_input+1, 7 
	BTFSS       FARG_WordToStr_input+1, 7 
	GOTO        L__main8
	BTFSS       STATUS+0, 0 
	GOTO        L__main8
	INFSNZ      FARG_WordToStr_input+0, 1 
	INCF        FARG_WordToStr_input+1, 1 
L__main8:
	MOVLW       main_txt_L0+0
	MOVWF       FARG_WordToStr_output+0 
	MOVLW       hi_addr(main_txt_L0+0)
	MOVWF       FARG_WordToStr_output+1 
	CALL        _WordToStr+0, 0
;MyProject.c,49 :: 		lcd_out(1,12,txt);
	MOVLW       1
	MOVWF       FARG_Lcd_Out_row+0 
	MOVLW       12
	MOVWF       FARG_Lcd_Out_column+0 
	MOVLW       main_txt_L0+0
	MOVWF       FARG_Lcd_Out_text+0 
	MOVLW       hi_addr(main_txt_L0+0)
	MOVWF       FARG_Lcd_Out_text+1 
	CALL        _Lcd_Out+0, 0
;MyProject.c,50 :: 		portd = 255;
	MOVLW       255
	MOVWF       PORTD+0 
;MyProject.c,51 :: 		}
L_main5:
;MyProject.c,53 :: 		}
	GOTO        L_main3
L_main4:
;MyProject.c,56 :: 		}
L_main2:
;MyProject.c,58 :: 		}
	GOTO        L_main0
;MyProject.c,59 :: 		}
L_end_main:
	GOTO        $+0
; end of _main
