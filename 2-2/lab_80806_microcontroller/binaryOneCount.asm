.MODEL SMALL
.STACK 100H
.DATA
  MSG DB 'ENTER THE 8-BIT BINARY NUMBER: $'
  binary dw ?
  count db 0
  ERR_MSG DB 'NOT A BINARY NUMBER$'

.CODE
MAIN PROC
  MOV AX, @DATA
  MOV DS, AX

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
  MOV CL, 8             ; number of bits to check / loop counter

count_loop:
  SHR BX, 1             ; shift right
  JNC skip_increment    ; if carry flag is not set, skip
  INC count
skip_increment:
  LOOP count_loop       ; decrease CL by 1 and loop if CX not zero

  MOV DL, 0AH
  MOV AH, 02H
  INT 21H

  ; display the count
  MOV DL, count
  ADD DL, '0'
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

MAIN ENDP
END MAIN