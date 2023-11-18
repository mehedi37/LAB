; chapter 6 qus 8

.MODEL SMALL
.STACK 100H
.DATA

CR EQU 0AH
LF EQU 0DH
MSG1 DB 'ENTER TWO LETTERS : ?$'
MSG2 DB CR, LF, 'ENTER THE SECOND CAPITAL LETTER : $'
MSG3 DB CR, LF, 'OUTPUT: $'
MSG4 DB CR, LF, 'ENTERED LETTER IS ALREADY IN SMALL LETTERS $'
NEXT_LINE DB CR, LF, '$'

.CODE
MAIN PROC

    MOV AX, @DATA
    MOV DS, AX

    LEA DX, MSG1
    MOV AH, 9
    INT 21H

    MOV AH, 1   ; input first character
    INT 21H
    MOV BL, AL

    MOV AH, 1   ; input second character
    INT 21H
    MOV BH, AL


    ; Check alphabetical order
    CMP BL, BH
    ; Display in alphabetical order
    JL @CHK
        MOV CL, BL
        MOV BL, BH
        MOV BH, CL

    @CHK:
    CMP BL, 'a'
    JGE  @CAPITAL1
        ADD BL, 20H
        JMP @CHK2

    @CAPITAL1:
        SUB BL, 20H


    @CHK2:
    CMP BH, 'a'
    JGE  @CAPITAL2
        ADD BH, 20H
        JMP @smaller

    @CAPITAL2:
        SUB BH, 20H

    @smaller:
    LEA DX, NEXT_LINE   ; load and display NEXT_LINE
    MOV AH, 9
    INT 21H

    LEA DX, MSG3
    MOV AH, 9
    INT 21H

    MOV AH, 2     ; set output function
    MOV DL, BH
    INT 21H ; Used for output

    MOV DL, BL
    INT 21H ; Used for output




    ; @INVALID:
    ; LEA DX, MSG4
    ; MOV AH, 9
    ; INT 21H

    @END:

    MOV AH, 4CH
    INT 21H

    MAIN ENDP
    END MAIN
