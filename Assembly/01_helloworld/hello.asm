; basic hello world program in x86 assembly
; written in linux, assembled with nasm :)

section .data
hello:      db 'Hello World!', 10   ; 'Hello World!' with a linefeed char
helloLen:   equ $-hello             ; length of the 'Hello World!' string

section .text
global _start

_start:
    mov eax, 4        ; the system call for write (sys_write)
    mov ebx, 1        ; file descriptor 1 - standard output
    mov ecx, hello    ; put the offset of hello in ecx
    mov edx, helloLen ; getting the value of helloLen

    int 80h           ; call the kernel

    mov eax, 1        ; the system call for exit (sys_exit)
    mov ebx, 0        ; exit with return code 0

    int 80h
