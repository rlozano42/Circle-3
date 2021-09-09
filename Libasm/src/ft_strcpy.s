section		.text
global		_ft_strcpy

_ft_strcpy:
		mov rax, 0

while: 
		cmp BYTE[rsi + rax], 0
		jz return
		mov dl,BYTE[rsi + rax]
		mov BYTE[rdi + rax],dl
		inc rax
		jmp while
return:
		mov BYTE[rdi + rax], 0
		mov rax, rdi
		ret
