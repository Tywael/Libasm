section .text
global ft_strcmp

ft_strcmp:
    xor rax, rax
    test rdi, rdi
    ret
