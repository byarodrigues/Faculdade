
_main:

;MyProject.c,20 :: 		void main() {
;MyProject.c,21 :: 		lcd_init();
	CALL        _Lcd_Init+0, 0
;MyProject.c,22 :: 		ADCON1 = 0b00001101;
	MOVLW       13
	MOVWF       ADCON1+0 
;MyProject.c,24 :: 		while(1){
L_main0:
;MyProject.c,25 :: 		temp = ADC_Read (2);
	MOVLW       2
	MOVWF       FARG_ADC_Read_channel+0 
	CALL        _ADC_Read+0, 0
	MOVF        R0, 0 
	MOVWF       _temp+0 
	MOVF        R1, 0 
	MOVWF       _temp+1 
;MyProject.c,26 :: 		x = temp/2;
	MOVF        R0, 0 
	MOVWF       R2 
	MOVF        R1, 0 
	MOVWF       R3 
	RRCF        R3, 1 
	RRCF        R2, 1 
	BCF         R3, 7 
	BTFSC       R3, 6 
	BSF         R3, 7 
	BTFSS       R3, 7 
	GOTO        L__main3
	BTFSS       STATUS+0, 0 
	GOTO        L__main3
	INFSNZ      R2, 1 
	INCF        R3, 1 
L__main3:
	MOVF        R2, 0 
	MOVWF       _x+0 
	MOVF        R3, 0 
	MOVWF       _x+1 
;MyProject.c,27 :: 		WordToStr(x, texto);
	MOVF        R2, 0 
	MOVWF       FARG_WordToStr_input+0 
	MOVF        R3, 0 
	MOVWF       FARG_WordToStr_input+1 
	MOVLW       _texto+0
	MOVWF       FARG_WordToStr_output+0 
	MOVLW       hi_addr(_texto+0)
	MOVWF       FARG_WordToStr_output+1 
	CALL        _WordToStr+0, 0
;MyProject.c,28 :: 		lcd_out(1,1,texto);
	MOVLW       1
	MOVWF       FARG_Lcd_Out_row+0 
	MOVLW       1
	MOVWF       FARG_Lcd_Out_column+0 
	MOVLW       _texto+0
	MOVWF       FARG_Lcd_Out_text+0 
	MOVLW       hi_addr(_texto+0)
	MOVWF       FARG_Lcd_Out_text+1 
	CALL        _Lcd_Out+0, 0
;MyProject.c,29 :: 		}
	GOTO        L_main0
;MyProject.c,31 :: 		}
L_end_main:
	GOTO        $+0
; end of _main
