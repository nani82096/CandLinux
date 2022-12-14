#include	"header.h"
extern Elf32_Ehdr *hdr;                                                                          
extern FILE *fptr;
void Elf_Shdr(void)
{
	Elf32_Shdr shdr[hdr->e_shnum];
	printf("Section Headers:\n"
			"  [Nr] Name              Type            Addr     Off    Size   ES Flg  Lk Inf Al\n");
	char *ptr = NULL;
	if ( (ptr = (char *)malloc(sizeof(shdr[hdr->e_shnum])*hdr->e_shentsize)) == NULL )
		printf("Malloc failed to allocate memory for character pointer\n");
	fseek(fptr, hdr->e_shoff, 0); /*seekset = 0*/	
	fread(shdr,sizeof(Elf32_Shdr)*(hdr->e_shnum), 1, fptr);
	fseek(fptr, shdr[hdr->e_shstrndx].sh_offset, 0); /*seekset = 0*/
	fread(ptr, sizeof(shdr[hdr->e_shnum])*hdr->e_shentsize, 1, fptr);
	int i = 0;
	
	for ( i = 0; i < hdr->e_shnum; i++) {
		
		printf("  [%2d] %-18s", i , ptr+shdr[i].sh_name);
		switch(shdr[i].sh_type) {
			case SHT_NULL:
				printf("%-16s","NULL");
				break;
			case SHT_PROGBITS:
				printf("%-16s","PROGBITS");
				break;
			case SHT_SYMTAB:
				printf("%-16s","SYMTAB");
				break;
			case SHT_STRTAB:
				printf("%-16s","STRTAB");
				break;
			case SHT_RELA:
				printf("%-16s","RELA");
				break;
			case SHT_HASH:
				printf("%-16s","HASH");
				break;
			case SHT_DYNAMIC:
				printf("%-16s","DYNAMIC");
				break;
			case SHT_NOTE:
				printf("%-16s","NOTE");
				break;
			case SHT_NOBITS:
				printf("%-16s","NOBITS");
				break;
			case SHT_REL:
				printf("%-16s","REL");
				break;
			case SHT_SHLIB:
				printf("%-16s","SHLIB");
				break;
			case SHT_DYNSYM:
				printf("%-16s","DYNSYM");
				break;
			case SHT_LOPROC:
				printf("%-16s","LOPROC");
				break;
			case SHT_HIPROC:
				printf("%-16s","HIPROC");                                                 
                break;
            case SHT_LOUSER:
				printf("%-16s","LOUSER");                                                 
                break;
            case SHT_HIUSER:
				printf("%-16s","HIUSER");                                                 
                break;
			case SHT_GNU_verdef:
				printf("%-16s","VERDEF");
				break;            
			case SHT_GNU_verneed:
				printf("%-16s","VERNEED");
				break;
			case SHT_GNU_versym:
				printf("%-16s","VERSYM");
				break;
			case SHT_GNU_HASH:
				printf("%-16s","GNU_HASH");
				break;
			case SHT_INIT_ARRAY:
				printf("%-16s","INIT_ARRAY");
				break;
			case SHT_FINI_ARRAY:
				printf("%-16s","FINI_ARRAY");
				break;
			default:
				printf("%-16s"," ");
		}

		printf("%08x "
				"%06x "
				"%06x "
				"%02x ",shdr[i].sh_addr, shdr[i].sh_offset, shdr[i].sh_size, shdr[i].sh_entsize);
		if ( shdr[i].sh_flags & SHF_WRITE)
			printf("%1s","W");
		else
			printf(" ");
		if ( shdr[i].sh_flags & SHF_ALLOC)
			printf("%1s","A");
		else
			printf(" ");
		if ( shdr[i].sh_flags & SHF_EXECINSTR) 
			printf("%1s","X");
		else
			printf(" ");
		if ( shdr[i].sh_flags & SHF_MASKPROC)
			printf("%1s","MS");
		else
			printf(" ");
		printf("%3d"
				"%3d"
				"%3d\n",shdr[i].sh_link, shdr[i].sh_info, shdr[i].sh_addralign);
				
	}
	
}
