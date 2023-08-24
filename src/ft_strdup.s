global ft_strdup
section .text

ft_strdup:
    xor rcx, rcx

strlen:
    cmp byte [rdi], 0
    je allocate
    inc rcx
    inc rdi
    jmp strlen

allocate:
    inc rcx
    push rdi
    mov rdi, rcx
    extern _malloc
    call _malloc
    pop rdi
    mov rsi, rax
    cmp rsi, 0
    je exit

cpy:
    mov al, [rdi]
    mov [rsi], al
    inc rsi
    inc rdi
    dec rcx
    cmp rcx, 0
    jne cpy
    mov [rsi], byte 0
    mov rax, rsi
    ret

exit:
    xor rax, rax
    ret


