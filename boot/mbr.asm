[bits 16]
[org 0x7c00]

real_mode_entry:

    cli

    xor ax, ax

    mov ds, ax
    mov es, ax
    mov ss, ax

    mov sp, 0x7c00

    sti

print_string:

    mov si, message

    .next_character:

        lodsb

        cmp al, 0x00
        jz end

        mov ah, 0x0e
        int 0x10

        jmp .next_character

end:
    cli
    hlt
    jmp end

message: db "Hello, World!", 0x00

times (0x01fe - ($ - $$)) db 0x00

db 0x55
db 0xaa
