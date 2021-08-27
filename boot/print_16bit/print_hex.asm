ASCII db 0x30
HEXCHAR db '0x0000', 0

print_hex:
    mov dx, bx
    mov cx, 0
    mov eax, HEXCHAR + 5

print_hex_loop:
    mov bx, dx
    shr bx, cl
    and bx, 0x0f
    add bl, [ASCII]
    mov [eax], bl
    dec eax
    
    add cl, 4
    cmp cl, 16
    je finish_hex
    jne print_hex_loop

finish_hex:
    mov bx, HEXCHAR
    call print_string
    jmp finish
    
finish:
    ret