section		.text
global		_ft_write
extern 		___error

_ft_write:
		mov rax, 0x2000004
		syscall
		jc _error
		ret

_error:
		push rax
		call ___error
		mov rdi, rax
		pop  rax
		mov [rdi], rax
		mov rax, -1
		ret