    .MODEL SMALL
    .STACK 100H
    .DATA
        MSG DB 'ENTER THE 8-BIT BINARY NUMBER: $'
        binary DW ?
        ERR_MSG DB 'NOT A BINARY NUMBER !$'
        COUNT_MSG DB ' THIS BINARY HAS ZEROS: $'
        count DB '0'
        NEW_LINE DB 0DH, 0AH, '$'
        revBin DW 0

    .code
    main proc
    MOV ax, @data
    MOV ds, ax

    LEA DX, MSG
    MOV AH, 09H
    INT 21H

    MOV CX, 8             ; Loop 8 times to enter the binary number
  read_loop:
    MOV AH, 01H
    INT 21H
    CMP AL, '0'           ; jump if AL (input) is bellow 0
    JB not_binary

    CMP AL, '1'           ; jump if AL (input) is above 1
    JA not_binary

    SUB AL, '0'           ; convert ASCII to binary
    SHL binary, 1
    OR binary, AX         ; store the bit in the binary number, bcz binary is initially 0
    LOOP read_loop

    LEA DX, NEW_LINE
    MOV AH, 09H
    INT 21H
    INT 21H

    MOV CX, 8         ; Loop 8 times to enter reverse the binary number
revBinary:
    SHL revBin, 1
    SHR binary, 1
    JNC zero          ; jump if carry is 0
    OR revBin, 1
    JMP one

  zero:
    INC count      ; count the zeros

    MOV AH, 02H
    MOV DL, '0'
    INT 21H
    JMP continue

  one:
    MOV AH, 02H
    MOV DL, '1'
    INT 21H
  continue:
    LOOP revBinary

    LEA DX, COUNT_MSG
    MOV AH, 09H
    INT 21H

    MOV DL, count
    MOV AH, 02H
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