section .text
global ft_strcmp

ft_strcmp:
    xor rax, rax

.loop:
    mov al, byte [rdi]
    sub al, byte [rsi]
    jnz .end
    inc rdi
    inc rsi
    cmp byte [rdi], 0
    jz .end
    cmp byte [rsi], 0
    jz .end
    test ax, ax
    jnz .loop

.end:
    movsx rax, al
    ret
