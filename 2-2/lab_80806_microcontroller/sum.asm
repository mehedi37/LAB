    .MODEL SMALL
    .STACK 100H
    .DATA
        CR          EQU 0DH
        LF          EQU 0AH
        MSG1        DB CR, LF, "?$"
        firstAlph   DB 0DH,0AH,''
        CHAR1       DB ?
        secAlph     DB '+ '
        CHAR2       DB ?
        thirdAlph   DB ' = '
        CHAR3       DB ?, '$'
        ERROR_MSG   DB CR, LF, 'ERROR SUM >= 10$'


    .code
    main proc
    mov ax, @data
    mov ds, ax

    ; input 1
    lea dx, MSG1
    mov ah, 09h
    int 21h

    mov ah, 01h
    int 21h
    mov CHAR1, al

    mov ah, 01h
    int 21h
    mov CHAR2, al

    MOV AL, CHAR1
    ADD AL, CHAR2
    MOV CHAR3, AL
    SUB CHAR3, '0'
    CMP CHAR3, '9'
    JBE PRINT
ERROR:
    LEA DX, ERROR_MSG
    MOV AH, 09H
    INT 21H
    JMP @end


PRINT:
    LEA DX, firstAlph
    MOV AH, 09h
    INT 21H
@end:
    mov ah, 4ch
    int 21h

    main endp
    end main