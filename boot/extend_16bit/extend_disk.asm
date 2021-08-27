disk_load:
    pusha 
    push dx    ; store sector value to stack

    mov ah, 0x02
    mov al, dh
    mov cl, 0x02
    mov ch, 0x00
    mov dh, 0x00

    int 0x13
    jc disk_error

    pop dx
    cmp al, dh
    jne sector_error

    mov bx, DISK_READ_SUCCESS
    call print_string

    call print_newline

    popa
    ret

disk_error:
    mov bx, DISKERROR 
    call print_string 
    
    mov ah, 0x0e
    mov al, ' '
    int 0x10

    mov dx, 0x00
    mov dh, ah
    call print_hex
    jmp hang 

sector_error:
    mov bx, SECTORERROR 
    call print_string
    
    mov ah, 0x0e
    mov al, ' '
    int 0x10

    mov dx, 0x00
    mov dh, ah
    call print_hex 
    
    jmp hang


WHITE_SPACE db ' ',0
DISKERROR db "Disk error", 0
SECTORERROR db 'Sector error', 0
DISK_READ_SUCCESS db 'Success in disk read',0