[org 0x7c00]
KERNEL_OFFSET equ 0x1000

    mov [BOOT_DRIVE], dl 

    mov bp, 0x9000
    mov sp, bp 

    mov bx, MSG_REAL_MODE
    call print_string 

    mov bx, NOTHING
    call print_string

    call load_kernel 
    call switch_to_pm

; hang:
;     jmp hang

%include "./boot/print_16bit/print.asm"
%include "./boot/print_16bit/print_hex.asm"
%include "./boot/extend_16bit/extend_disk.asm"
%include "./boot/gdt/gdt.asm"
%include "./boot/print_32bit/print.asm"
%include "./boot/32bit_switch/switch.asm"

[bits 16]
load_kernel:
    mov bx, MSG_LOAD_KERNEL
    call print_string

    mov bx, KERNEL_OFFSET
    mov dh, 15
    mov dl, [BOOT_DRIVE]
    call disk_load

    mov bx, MSG_READ_DISK
    call print_string
    ret

[bits 32]
BEGIN_PM:
    mov ebx, MSG_PROTECTED_MODE
    call print_string_pm

    call KERNEL_OFFSET      ; call c code from here

hang:
    jmp hang

MSG_REAL_MODE db 'Entered Real mode', 0xd, 10, 0
MSG_LOAD_KERNEL db 'Kernel Loaded', 0xd, 10, 0
MSG_READ_DISK db 'Disk read successfull', 0xd, 10, 0
MSG_PROTECTED_MODE db 'Entered protected mode', 0xd, 10, 0

BOOT_DRIVE db 0
NOTHING db 0xd,10,0
done:
    times 510 - ($-$$) db 0
    dw 0xaa55
