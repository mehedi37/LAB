.MODEL SMALL
.STACK 100H
.DATA

CR EQU 0AH
LF EQU 0DH
MSG1 DB 'ENTER 3 NUMBERS : $'
MSG2 DB CR, LF, '1st LARGEST : $'
MSG3 DB CR, LF, '2nd LARGEST : $'
MSG4 DB CR, LF, '3rd LARGEST : $'
NEXT_LINE DB CR, LF, '$'

.CODE
MAIN PROC

    MOV AX, @DATA
    MOV DS, AX

    LEA DX, MSG1
    MOV AH, 09H
    INT 21H

    MOV AH, 01H
    INT 21H
    MOV BL, AL

    MOV AH, 01H
    INT 21H
    MOV BH, AL

    MOV AH, 01H
    INT 21H
    MOV CL, AL

    CMP BL, BH
    JL L1
    MOV AL, BL
    MOV BL, BH
    MOV BH, AL
L1:
    CMP BH, CL
    JL L2
    MOV AL, BH
    MOV BH, CL
    MOV CL, AL
L2:
    CMP BL, BH
    JL L3
    MOV AL, BL
    MOV BL, BH
    MOV BH, AL
L3:
    CMP BH, CL
    JL L4
    MOV AL, BH
    MOV BH, CL
    MOV CL, AL
L4:

    ; print the numbers in descending order
    LEA DX, MSG2
    MOV AH, 09H
    INT 21H

    MOV AH, 02H
    MOV DL, CL
    INT 21H

    LEA DX, NEXT_LINE
    MOV AH, 09H
    INT 21H

    LEA DX, MSG3
    MOV AH, 09H
    INT 21H

    MOV AH, 02H
    MOV DL, BH
    INT 21H

    LEA DX, NEXT_LINE
    MOV AH, 09H
    INT 21H

    LEA DX, MSG4
    MOV AH, 09H
    INT 21H

    MOV AH, 02H
    MOV DL, BL
    INT 21H

    LEA DX, NEXT_LINE
    MOV AH, 09H
    INT 21H

    MOV AH, 4CH
    INT 21H

    MAIN ENDP
    END MAIN