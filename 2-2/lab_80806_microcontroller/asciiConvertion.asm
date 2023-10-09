    .MODEL SMALL
    .STACK 100H
    .DATA
        CR          EQU 0DH
        LF          EQU 0AH
        MSG1        DB "Enter 3 initials : $"
        firstAlph   DB 0DH,0AH,'1st initial in small case: '
        CHAR1       DB ?, '$'
        secAlph     DB 0DH,0AH,'2nd initial in small case: '
        CHAR2       DB ?, '$'
        thirdAlph   DB 0DH,0AH,'3rd initial in small case: '
        CHAR3       DB ?, '$'

    .code
    main proc
        mov ax, @data
        mov ds, ax

        ; print
        lea dx, MSG1
        mov ah, 09h
        int 21h

    ; input
        mov ah, 01h
        int 21h
        add al, 20h     ; convert to lower case
        mov CHAR1, al

        mov ah, 01h
        int 21h
        add al, 20h     ; convert to lower case
        mov CHAR2, al

        mov ah, 01h
        int 21h
        add al, 20h     ; convert to lower case
        mov CHAR3, al

    ; output
        lea dx, firstAlph
        mov ah, 09h
        int 21h

        lea dx, secAlph
        mov ah, 09h
        int 21h

        lea dx, thirdAlph
        mov ah, 09h
        int 21h
    main endp
end main
