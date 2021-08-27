print_string:
    mov al, [bx]
    cmp al, 0
    je finish_print
    call print_char
    inc bx
    jne print_string

print_char:
    mov ah, 0x0e
    int 0x10
    ret 

finish_print:
    ret


print_newline:
    pusha
    
    mov ah, 0x0e
    mov al, 10    ; newline char
    int 0x10
    mov al, 0xd    ; return to carriage
    int 0x10

    popa
    ret