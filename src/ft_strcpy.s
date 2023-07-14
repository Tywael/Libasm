section .text 
global ft_strcpy

ft_strcpy:
    xor rax, rax

    push rdi
    mov rdi, [rsp+16] 

    .loop:
        mov al, byte [rsi]
        mov byte [rdi], al
        cmp al, 0
        jz .end
        inc rsi
        inc rdi
        jmp .loop
    
    .end:
        pop rax
        ret