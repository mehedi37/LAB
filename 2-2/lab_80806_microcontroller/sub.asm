    .MODEL SMALL
    .STACK 100H
    .DATA
        CR          EQU 0DH
        LF          EQU 0AH
        MSG1        DB CR, LF, "Enter 1st digit: $"
        MSG2        DB CR, LF, "Enter 2nd digit: $"
        firstAlph   DB 0DH,0AH,''
        CHAR1       DB ?,
        secAlph     DB '-'
        CHAR2       DB ?,
        thirdAlph   DB ' = '
        CHAR3       DB ?, '$'

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

    ; input 2
    lea dx, MSG2
    mov ah, 09h
    int 21h
    mov ah, 01h
    int 21h
    mov CHAR2, al

    ; convert to integer
    mov al, CHAR1
    sub al, CHAR2
    mov CHAR3, al

    ; convert to ASCII
    add CHAR3, 30h
    lea dx, firstAlph
    mov ah, 09h
    int 21h
    main endp
    end main