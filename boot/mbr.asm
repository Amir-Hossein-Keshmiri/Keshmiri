[bits 16]
[org 0x7c00]

 print_character:
    mov ah, 0x0e
    mov al, 'A'
    int 0x10

end:
    jmp end

times (0x01fe - ($ - $$)) db 0x00

db 0x55
db 0xaa
