	BITS 32
	org 0x08048000
ehdr:
	db 0x7F, "ELF"
	db 1,1,1,0,0 ;e_indent = magic numbers, 32objects, 2compl, arch
	;times 8 db 0 ; to the end of e_indent buffer (e_indent[16])
	;PROGRAM EMBEDDED IN ELF HEADER
_start:
	mov bl, 42
	xor eax, eax
	inc eax
	int 0x80
	dw 2; e_type (2 == executable type)
	dw 3; e_machine (3 == intel_80386)
	dd 1; e_version (1 == current_version)
	dd _start; e_entry
	dd phdr - $$; e_phoff (size between this struct and struct phdr)
	dd 0; e_shoff -----> why is offset 0? == org ?
	dd 0; e_flags (should some processor specific flags, do not know value 0)
	dw ehdr_size; e_ehsize
	dw phdr_size; e_phentsize
	dw 1; e_phnum (real number of program headers, do not know what it means)
	dw 0; e_shentsize (because e_shoff == 0)
	dw 0; e_shnum
	dw 0; e_shstrndx

ehdr_size equ $ - ehdr

phdr:
	dd 1; p_type (1 == loadable program segment)
	dd 0; p_offset (segment file offset, but why 0, beginning?)
	dd $$; p_vaddr (segment virtual address, $$ == org)
	dd $$; p_paddr (segment physical address, $$ == org)
	dd file_size; p_filesz (segment size in file)
	dd file_size; p_memsz (segment size in memory)
	dd 5; p_flags (((1<<0) | (1<<2))) == segment is readable and executable)
	dd 0x1000; p_align (segment alignment - 4096 page alignment)

phdr_size equ $ - phdr
file_size equ $ - $$
