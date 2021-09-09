section		.text
global		_ft_strdup
extern		_malloc
extern		_ft_strcpy

_ft_strdup:
		mov rax, 0;
		mov rcx, 0

while:
		cmp BYTE[rdi + rcx], 0
		jne plus
		inc rcx
		push rdi
		mov  rdi, rcx
		call _malloc
		cmp BYTE[rax], 0
		jne return
		pop rdi
		mov rsi, rdi
		mov rdi, rax
		call _ft_strcpy

return:
		ret 

plus: 
	inc rcx
	jmp while
