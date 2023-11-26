.MODEL SMALL
.STACK 100H
.DATA
  MSG1 DB 'WORD LENGTH OF SENTENCE (including space): $'
  MSG2 DB 'ENTER A SENTENCE: $'
  LEN dw 0
  ASTERISK DW '*'

  BASE_POINT dw 100h
  END_POINT dw 100h
  MIDDLE_END_POINT dw 100h

  OUTPUT_MSG DB 'REVERSED SENTENCE IS: $'
  NEW_LINE DB 0DH, 0AH, '$'

.code
  main proc
  MOV ax, @data
  MOV ds, ax

  LEA dx, MSG2
  MOV ah, 09H
  INT 21H

INPUT:
  MOV ah, 01H
  INT 21H
  CMP al, 0Dh   ; compare input with carriage return
  JE INPUT_END      ; if input is carriage return, end input
  PUSH AX
  CMP AL, ' '
  JNE SPACE_NOT_FOUND
  PUSH ASTERISK
  PUSH ASTERISK

  SPACE_NOT_FOUND:
    JMP INPUT

INPUT_END:
  LEA dx, OUTPUT_MSG
  MOV ah, 09H
  INT 21H

  MOV BX, ' '
  PUSH BX
  MOV BX, '$'
  PUSH BX
  PUSH BX
  PUSH BX

  MOV END_POINT, SP

  LEA DX, NEW_LINE
  MOV ah, 09H
  INT 21H

RETURN_BASE:
  MOV SP, BASE_POINT

LOOP_TILL_SPACE:
  CMP SP, END_POINT
  JE end_program
  POP ax
  CMP al, ' '
  JE SPACE_FOUND
  PUSH ax
  SUB SP, 2
  JMP LOOP_TILL_SPACE

SPACE_FOUND:
  MOV MIDDLE_END_POINT, SP
  MOV AH, 02H
  MOV DL, ' '
  INT 21H

PRINT_SEGMENT:
  POP DX
  MOV ah, 02H
  INT 21H

  CMP SP, BASE_POINT
  JNE PRINT_SEGMENT

  SUB MIDDLE_END_POINT, 8
  MOV BX, MIDDLE_END_POINT
  MOV BASE_POINT, BX
  MOV SP, BX
  ADD BASE_POINT, 2
  JMP LOOP_TILL_SPACE

end_program:
  MOV ah, 4CH
  INT 21H

  main ENDP
  END MAIN
