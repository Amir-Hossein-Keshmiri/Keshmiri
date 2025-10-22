section .text

extern main
global start

start:
    call main

end:
    cli
    hlt
    jmp end
