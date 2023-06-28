section .text
global ft_strlen

ft_strlen:
    xor rax, rax           ; Initialize RAX register to 0 (counter)

.loop:
    cmp [rdi + rax], byte 0       ; Compare the byte with 0
    jz .done                      ; If it is zero, jump to the 'done' label

    inc rax                       ; Increment the counter
    jmp .loop                     ; Jump back to the beginning of the loop

.done:
    ret