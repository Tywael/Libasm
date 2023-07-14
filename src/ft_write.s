extern __errno_location

global ft_write
section .text

ft_write:
    mov rax, 1
    syscall
    cmp rax, 0
    jl error
    ret

error:
    neg rax
    mov rdi, rax
    call  [rel __errno_location wrt ..got]
    mov [rax], rdi
    mov rax, -1
    ret