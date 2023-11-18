; digit and char both
.MODEL SMALL
.STACK 100H

.DATA
  PROMPT_1  DB  'Enter the Hex digit (1-9 & A-F) : $'
  PROMPT_2  DB  0DH,0AH,'The corresponding Decimal dgit is : $'

.CODE
  MAIN PROC
    MOV AX, @DATA                ; initialize DS
    MOV DS, AX

    LEA DX, PROMPT_1             ; load and display PROMPT_1
    MOV AH, 9
    INT 21H

    MOV AH, 1                    ; read the hex digit
    INT 21H

    MOV BL, AL                   ; save the hex digit into BL

    LEA DX, PROMPT_2             ; load and display PROMPT_2
    MOV AH, 9
    INT 21H

    CMP BL, '9'
    JBE PRINT

    MOV AH, 2                    ; display the first decimal digit i.e. 1
    MOV DL, '1'
    INT 21H

    SUB BL, 11H                  ; convert the character into second digit  | 'A' = 41H | 41H - 11H = 30H | 30H = '0'

  PRINT:
    MOV DL, BL                   ; display the second digit
    MOV AH, 2
    INT 21H

    MOV AH, 4CH                  ; return control to DOS
    INT 21H
  MAIN ENDP
  END MAIN
