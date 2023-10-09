.DATA
MSG DB 'Enter a no: $'   ; $ is the string terminator


.code
main proc
    LEA DX, MSG  ; load effective address of MSG into DX
    MOV AH, 9  ; 'Enter a no: '
    INT 21H

    ; case convertion
    ; A -> a = 41 h -> 61 h | so add 20 h to convert
    ; A -> a = 65 d -> 97 d | so add 32 d to convert
