section .text

extern main
global _start

_start:
    call main

end:
    cli
    hlt
    jmp end
