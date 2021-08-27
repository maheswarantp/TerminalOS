gdt_start:

gdt_null:
    dd 0x0          ; mandatory null descriptor
    dd 0x0          ; spans 8 bytes

gdt_code:           ; code segment
    ; base = 0x00, limit = 0xfffff
    ; 1st flags
    ; type flags
    ; 2nd flags
    dw 0xffff       ; limit 0-15
    dw 0x0          ; base 0-15     (2 bytes)
    db 0x0          ; base 16-23    (1 byte)
    db 10011010b    ; 1st flags, type flags
    db 11001111b    ; 2nd flags, Limit (bits 16-19)
    db 0x0          ; Base 24-31

gdt_data:
    dw 0xffff       ; limit 0-15
    dw 0x0          ; base 0-15     (2 bytes)
    db 0x0          ; base 16-23    (1 byte)
    db 10010010b    ; 1st flags, type flags
    db 11001111b    ; 2nd flags, Limit (bits 16-19)
    db 0x0          ; Base 24-31

gdt_end:            ; to calculate size of gdt

gdt_descriptor:
    dw gdt_end - gdt_start - 1  ; size of gdt
    dd gdt_start                ; start address of gdt

CODE_SEG equ gdt_code - gdt_start
DATA_SEG equ gdt_data - gdt_start
