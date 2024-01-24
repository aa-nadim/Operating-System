section .text
  global _start

_start:
  ; Set up the stack
  mov esp, stack_space

  ; Load the kernel into memory
  mov ebx, kernel_start
  mov ecx, kernel_size
  mov edx, kernel_location
  mov eax, 0x02
  int 0x13

  ; Jump to the loaded kernel
  jmp kernel_location

section .bss
  stack_space resb 8192

section .data
  kernel_start equ 0x1000
  kernel_location equ 0x8000
  kernel_size equ 0x2000
