;; boot.asm
bits32                          ;nasm directive
section .text
        ;multiboot spec
        align 4
        dd 0x1BADB002           ;magic
        dd 0x00                 ;flags
        dd - (0x1BADB002 +0X00) ; checksum. m+f+c
should be zero
global start 

extern knain                    ;kanin is defined in the c file

start:
   cli                          ;block interrups
   mov esp, tack_space          ;set stack pointer
   call kanin
   hlt                          ;halt the CPU
   section .bss
   stack_space: resb 8192       ;8KB for stack 
