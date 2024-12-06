
_CustomChar:

;MyProject.c,19 :: 		void CustomChar(char pos_row, char pos_char) {
;MyProject.c,21 :: 		Lcd_Cmd(64);
	MOVLW       64
	MOVWF       FARG_Lcd_Cmd_out_char+0 
	CALL        _Lcd_Cmd+0, 0
;MyProject.c,22 :: 		for (i = 0; i<=7; i++) Lcd_Chr_CP(character[i]);
	CLRF        CustomChar_i_L0+0 
L_CustomChar0:
	MOVF        CustomChar_i_L0+0, 0 
	SUBLW       7
	BTFSS       STATUS+0, 0 
	GOTO        L_CustomChar1
	MOVLW       _character+0
	ADDWF       CustomChar_i_L0+0, 0 
	MOVWF       TBLPTR+0 
	MOVLW       hi_addr(_character+0)
	MOVWF       TBLPTR+1 
	MOVLW       0
	ADDWFC      TBLPTR+1, 1 
	MOVLW       higher_addr(_character+0)
	MOVWF       TBLPTR+2 
	MOVLW       0
	ADDWFC      TBLPTR+2, 1 
	TBLRD*+
	MOVFF       TABLAT+0, FARG_Lcd_Chr_CP_out_char+0
	CALL        _Lcd_Chr_CP+0, 0
	INCF        CustomChar_i_L0+0, 1 
	GOTO        L_CustomChar0
L_CustomChar1:
;MyProject.c,23 :: 		Lcd_Cmd(_LCD_RETURN_HOME);
	MOVLW       2
	MOVWF       FARG_Lcd_Cmd_out_char+0 
	CALL        _Lcd_Cmd+0, 0
;MyProject.c,24 :: 		Lcd_Chr(pos_row, pos_char, 0);
	MOVF        FARG_CustomChar_pos_row+0, 0 
	MOVWF       FARG_Lcd_Chr_row+0 
	MOVF        FARG_CustomChar_pos_char+0, 0 
	MOVWF       FARG_Lcd_Chr_column+0 
	CLRF        FARG_Lcd_Chr_out_char+0 
	CALL        _Lcd_Chr+0, 0
;MyProject.c,25 :: 		}
L_end_CustomChar:
	RETURN      0
; end of _CustomChar

_CustomChar2:

;MyProject.c,28 :: 		void CustomChar2(char pos_row, char pos_char) {
;MyProject.c,30 :: 		Lcd_Cmd(72);
	MOVLW       72
	MOVWF       FARG_Lcd_Cmd_out_char+0 
	CALL        _Lcd_Cmd+0, 0
;MyProject.c,31 :: 		for (i = 0; i<=7; i++) Lcd_Chr_CP(character2[i]);
	CLRF        CustomChar2_i_L0+0 
L_CustomChar23:
	MOVF        CustomChar2_i_L0+0, 0 
	SUBLW       7
	BTFSS       STATUS+0, 0 
	GOTO        L_CustomChar24
	MOVLW       _character2+0
	ADDWF       CustomChar2_i_L0+0, 0 
	MOVWF       TBLPTR+0 
	MOVLW       hi_addr(_character2+0)
	MOVWF       TBLPTR+1 
	MOVLW       0
	ADDWFC      TBLPTR+1, 1 
	MOVLW       higher_addr(_character2+0)
	MOVWF       TBLPTR+2 
	MOVLW       0
	ADDWFC      TBLPTR+2, 1 
	TBLRD*+
	MOVFF       TABLAT+0, FARG_Lcd_Chr_CP_out_char+0
	CALL        _Lcd_Chr_CP+0, 0
	INCF        CustomChar2_i_L0+0, 1 
	GOTO        L_CustomChar23
L_CustomChar24:
;MyProject.c,32 :: 		Lcd_Cmd(_LCD_RETURN_HOME);
	MOVLW       2
	MOVWF       FARG_Lcd_Cmd_out_char+0 
	CALL        _Lcd_Cmd+0, 0
;MyProject.c,33 :: 		Lcd_Chr(pos_row, pos_char, 1);
	MOVF        FARG_CustomChar2_pos_row+0, 0 
	MOVWF       FARG_Lcd_Chr_row+0 
	MOVF        FARG_CustomChar2_pos_char+0, 0 
	MOVWF       FARG_Lcd_Chr_column+0 
	MOVLW       1
	MOVWF       FARG_Lcd_Chr_out_char+0 
	CALL        _Lcd_Chr+0, 0
;MyProject.c,34 :: 		}
L_end_CustomChar2:
	RETURN      0
; end of _CustomChar2

_main:

;MyProject.c,36 :: 		void main() {
;MyProject.c,37 :: 		Lcd_init();
	CALL        _Lcd_Init+0, 0
;MyProject.c,38 :: 		CustomChar(1,1);
	MOVLW       1
	MOVWF       FARG_CustomChar_pos_row+0 
	MOVLW       1
	MOVWF       FARG_CustomChar_pos_char+0 
	CALL        _CustomChar+0, 0
;MyProject.c,39 :: 		CustomChar2(1,2);
	MOVLW       1
	MOVWF       FARG_CustomChar2_pos_row+0 
	MOVLW       2
	MOVWF       FARG_CustomChar2_pos_char+0 
	CALL        _CustomChar2+0, 0
;MyProject.c,40 :: 		}
L_end_main:
	GOTO        $+0
; end of _main
