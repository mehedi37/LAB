.MODEL SMALL
.STACK 100H
.DATA
  MSG1 DB 'ENTER THE NUMBER OF DIGITS: $'
  MSG2 DB 'ENTER THE DECIMAL NUMBER: $'
  digit db ?
  ERR_MSG DB 'NOT A VALID NUMBER$'
  ODD_MSG DB 'THE NUMBER IS ODD$'
  EVEN_MSG DB 'THE NUMBER IS EVEN$'
  NEW_LINE DB 0DH, 0AH, '$'

.CODE
MAIN PROC
  MOV AX, @DATA
  MOV DS, AX

  ; display MSG1 and read the number of digits
  LEA DX, MSG1
  MOV AH, 09H
  INT 21H

  MOV AH, 01H
  INT 21H

  MOV BL, AL

  SUB BL, '0'

  CMP BL, 0
  JB not_valid
  CMP BL, 9
  JA not_valid
  MOV digit, BL

  LEA DX, NEW_LINE
  MOV AH, 09H
  INT 21H

  ; display MSG2 and read the decimal number
  LEA DX, MSG2
  MOV AH, 09H
  INT 21H

read_loop:
  MOV AH, 01H
  INT 21H

  MOV BL, AL

  SUB BL, '0'
  JC not_valid
  CMP BL, 9
  JA not_valid
  DEC digit
  JNZ read_loop

  ; check if the last digit is odd or even
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

not_valid:
  LEA DX, ERR_MSG
  MOV AH, 09H
  INT 21H

@end:
  MOV AH, 4Ch  ; exit program
  INT 21H

MAIN ENDP
END MAIN