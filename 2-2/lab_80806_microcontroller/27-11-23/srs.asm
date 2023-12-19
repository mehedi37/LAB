.MODEL SMALL
.STACK 100H
.DATA
  NUM DB 0
  TEMP DB 0
  MSG1 DB 0DH, 0AH, 'ENTER NUMBER: $'
  MSG2 DB 0DH, 0AH, 'PRIME $'
  MSG3 DB 0DH, 0AH, 'NOT PRIME $'

.CODE
MAIN PROC
  MOV AX, @DATA
  MOV DS, AX

  LEA DX, MSG1
  MOV AH, 9
  INT 21H

  XOR BX, BX
  XOR CX, CX

inputLoop:
  MOV AH, 1
  INT 21H

  CMP AL, 0DH
  JE @END

  CMP AL, '0'
  JNGE @NOTDIGIT

  CMP AL, '9'
  JNLE @NOTDIGIT

  SUB AL, '0'
  MOV TEMP, AL

  MOV AL, NUM
  MOV BX, 10
  MUL BX
  MOV NUM, AL
  MOV AL, TEMP
  ADD NUM, AL
  JMP inputLoop
@END:
  JMP @START

@NOTDIGIT:
  MOV AH, 2
  MOV DL, 0DH
  INT 21H
  MOV DL, 0AH
  INT 21H
  JMP inputLoop

@START:

  ; Check if the number is prime or not
  MOV AL, NUM
  CMP AL,1
  JLE LEVEL2            ; if AL <= 1, then goto level2(not prime msg)
  MOV AH,0
  CMP AL,3
  JLE LEVEL3            ; if AL <= 3 then goto level3<prime msg)
  MOV AH,0

  MOV CL,2              ; divides the entered number by 2 and stores the quotient it in CL
  DIV CL
  MOV CL,AL

LEVEL1:

  MOV AH,0
  MOV AL,NUM
  DIV CL
  CMP AH,0              ; if there is no remainder in any division, it jumps to level2
  JZ LEVEL2
  DEC CL
  CMP CL,1
  JNE LEVEL1   ; if CL is not equal to 1, it continues the loop
  JMP LEVEL3   ; otherwise it jumps to level3

LEVEL2:

  MOV AH,9
  LEA DX,MSG3
  INT 21H
  JMP EXIT

LEVEL3:

  MOV AH,9
  LEA DX,MSG2
  INT 21H

EXIT:
  MOV AH, 4CH
  INT 21H
MAIN ENDP
END MAIN
