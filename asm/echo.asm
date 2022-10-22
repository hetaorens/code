; A macro with two parameters
; Implements the write system call
   %macro write_string 2 
      mov   eax, 4   
      push eax
      mov eax ,12
      pop eax
      mov   ebx, 1
      mov   ecx, %1
      mov   edx, %2
      int   80h
   %endmacro

   %macro fun1 2
   mov eax ,4
   push eax
   mov eax,12
   pop eax
   mov ebx,1
   mov ecx ,%1
   mov edx ,%2
   int 80h
   %endmacro


section	.text
   global _start            ;must be declared for using gcc
_start:                     ;tell linker entry point
   write_string msg1, len1               
   write_string msg2, len2    
   write_string msg3, len3
   write_string msg4, len4
   fun1 msg4 ,len4  
   mov eax,1                ;system call number (sys_exit)
   int 0x80                 ;call kernel
section	.data
msg1 db	'Hello, programmers!',0xA,0xD 	
len1 equ $ - msg1			
msg2 db 'Welcome to the world of,', 0xA,0xD 
len2 equ $- msg2
msg3 db 'Linux assembly programming! ',0xA,0xD
len3 equ $- msg3
msg4 db 'Wdasd  asd ad as d asd ',0xa,0xd
len4 equ $-msg4
