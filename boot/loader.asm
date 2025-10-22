[bits 16]
[org 0x7e00]


load_kernel:

    mov word[si + 0x00], 0x10
    mov word[si + 0x02], 0x64
    mov word[si + 0x04], 0x00
    mov word[si + 0x06], 0x1000

    mov dword[si + 0x08], 0x06
    mov dword[si + 0x0c], 0x00

    mov ah, 0x42
    int 0x13


set_text_mode:

    mov ax, 0x03
    int 0x10

    cli
    lgdt [gdt_32Ptr]
    lidt [idt_32_ptr]

    mov eax, cr0
    or eax, 0x1
    mov cr0, eax

    jmp 0x08:protected_mode_entry


end:
    cli
    hlt
    jmp end


[bits 32]


protected_mode_entry:

    mov ax, 0x10
    
    mov ds, ax
    mov es, ax
    mov ss, ax
    
    mov esp, 0x7c00

    cld
    mov edi, 0x070000
    xor eax, eax
    mov ecx, 0x010000 / 0x04
    rep stosd
    
    mov dword[0x070000], 0x071007
    mov dword[0x071000], 0x87

    lgdt [gdt_64_ptr]

    mov eax, cr4
    or eax, (0x1 << 0x05)
    mov cr4, eax

    mov eax, 0x070000
    mov cr3, eax

    mov ecx, 0xC0000080
    rdmsr
    or eax, (0x01 << 0x08)
    wrmsr

    mov eax, cr0
    or eax, (0x01 << 0x1f)
    mov cr0, eax

    jmp 0x08:long_mode_entry


protected_mode_end:
    cli
    hlt
    jmp protected_mode_end


[bits 64]


long_mode_entry:

    mov rsp, 0x7c00

    cld
    mov rdi, 0x200000
    mov rsi, 0x010000
    mov rcx, 0xc800 / 0x08
    rep movsq

    jmp 0x200000


long_mode_end:
    cli
    hlt
    jmp long_mode_end


gdt_32:
    dq 0x00

code_32:
    dw 0xffff
    dw 0x00
    db 0x00
    db 0x9a
    db 0xcf
    db 0x00

data_32:
    dw 0xffff
    dw 0x00
    db 0x00
    db 0x92
    db 0xcf
    db 0x00

gdt_32_len: equ ($ - gdt_32)

gdt_32Ptr: dw (gdt_32_len - 0x1)
            dd gdt_32

idt_32_ptr: dw 0x00
            dd 0x00


gdt_64:
    dq 0x00
    dq 0x0020980000000000

gdt_64_len: equ ($ - gdt_64)


gdt_64_ptr: dw (gdt_64_len - 1)
            dd gdt_64
