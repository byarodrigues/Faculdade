
_main:

;ex4.c,18 :: 		void main() {
;ex4.c,19 :: 		int i = 0;
	CLRF        main_i_L0+0 
	CLRF        main_i_L0+1 
;ex4.c,20 :: 		trisb = 255;
	MOVLW       255
	MOVWF       TRISB+0 
;ex4.c,21 :: 		PORTb = 0b00000100; //define o segmento "2" como saída
	MOVLW       4
	MOVWF       PORTB+0 
;ex4.c,22 :: 		lcd_init(); //inicia
	CALL        _Lcd_Init+0, 0
;ex4.c,24 :: 		while(1){
L_main0:
;ex4.c,25 :: 		if(button(&portb,5,1,0)==255){
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
;ex4.c,26 :: 		lcd_out(1,i,"5");
	MOVLW       1
	MOVWF       FARG_Lcd_Out_row+0 
	MOVF        main_i_L0+0, 0 
	MOVWF       FARG_Lcd_Out_column+0 
	MOVLW       ?lstr1_ex4+0
	MOVWF       FARG_Lcd_Out_text+0 
	MOVLW       hi_addr(?lstr1_ex4+0)
	MOVWF       FARG_Lcd_Out_text+1 
	CALL        _Lcd_Out+0, 0
;ex4.c,27 :: 		delay_ms(2000);
	MOVLW       21
	MOVWF       R11, 0
	MOVLW       75
	MOVWF       R12, 0
	MOVLW       190
	MOVWF       R13, 0
L_main3:
	DECFSZ      R13, 1, 1
	BRA         L_main3
	DECFSZ      R12, 1, 1
	BRA         L_main3
	DECFSZ      R11, 1, 1
	BRA         L_main3
	NOP
;ex4.c,28 :: 		i++;
	INFSNZ      main_i_L0+0, 1 
	INCF        main_i_L0+1, 1 
;ex4.c,29 :: 		}
L_main2:
;ex4.c,30 :: 		}
	GOTO        L_main0
;ex4.c,31 :: 		}
L_end_main:
	GOTO        $+0
; end of _main
