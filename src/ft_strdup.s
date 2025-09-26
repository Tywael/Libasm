global ft_strdup
extern malloc
section .text

ft_strdup:
    cmp rdi, 0
    je _exit
    xor rcx, rcx

_strlen:
    cmp byte [rdi + rcx], 0
    je _allocate
    inc rcx
    jmp _strlen

_allocate:
    push rdi
    mov rdi, rcx
    inc rdi
    call [rel malloc wrt ..got]
    test rax, rax
    je _exit
    pop rdi
    mov rsi, rax
    xor rcx, rcx
    xor rax, rax

_copy:
    mov al, [rdi + rcx]
    mov [rsi + rcx], al
    inc rcx
    cmp al, 0
    jne _copy

    mov rax, rsi
    ret

_exit:
    xor rax, rax
    ret