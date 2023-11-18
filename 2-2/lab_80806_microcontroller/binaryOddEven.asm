    .MODEL SMALL
    .STACK 100H
    .DATA
        MSG DB 'ENTER THE 8-BIT BINARY NUMBER: $'
        binary dw ?
        ERR_MSG DB 'NOT A BINARY NUMBER !$'
        ODD_MSG DB 'THE NUMBER IS ODD$'
        EVEN_MSG DB 'THE NUMBER IS EVEN$'
        NEW_LINE DB 0DH, 0AH, '$'

    .code
    main proc
    MOV ax, @data
    MOV ds, ax

    ; display MSG and read the binary number
    LEA DX, MSG
    MOV AH, 09H
    INT 21H

    MOV CX, 8             ; number of bits to read

  read_loop:
    MOV AH, 01H
    INT 21H
    CMP AL, '0'   ; jump if AL (input) is bellow 0
    JB not_binary

    CMP AL, '1'   ; jump if AL (input) is above 1
    JA not_binary

    SUB AL, '0'           ; convert ASCII to binary
    SHL binary, 1
    OR binary, AX     ; store the bit in the binary number, bcz binary is initially 0
    LOOP read_loop

    MOV BX, binary

    TEST BL, 1
    JZ @even

  odd:
    LEA DX, NEW_LINE
    MOV AH, 09H
    INT 21H

    LEA DX, ODD_MSG
    MOV AH, 09H
    INT 21H
    JMP @end

  @even:
    LEA DX, NEW_LINE
    MOV AH, 09H
    INT 21H

    LEA DX, EVEN_MSG
    MOV AH, 09H
    INT 21H
    JMP @end

  not_binary:
    LEA DX, ERR_MSG
    MOV AH, 09H
    INT 21H

  @end:
    MOV AH, 4Ch  ; exit program
    INT 21H

    main endp
    end main