section		.text
global		_ft_strcmp

_ft_strcmp:
		mov rax, 0
		mov rcx, 0

while:
		mov al, BYTE[rdi]
		mov dl, BYTE[rsi]
		cmp al, 0
		je calc
		cmp al, dl
		jne calc
		inc rdi
		inc rsi
		jmp while

return:
		ret

calc:
		movzx rax, al
		movzx rcx, dl
		sub rax, rcx
		jmp return