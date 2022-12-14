#include	"header.h"

void Elf_hdr(Elf32_Ehdr *hdr)
{
		int i;
		printf("ELF Header:\n"
						"  Magic:   ");
		for ( i = 0; i < EI_NIDENT; i++) {
				printf("%02x ",hdr->e_ident[i]);
		}
		printf("\n");
		printf("  Class:\t\t\t\t");
		switch(hdr->e_ident[EI_CLASS]) {
				case ELFCLASSNONE:
						printf("Invalid calss\n");
						break;
				case ELFCLASS32:
						printf("ELF32\n");
						break;
				case ELFCLASS64:
						printf("ELF64\n");
						break;
				default:
						printf("<unknown : %x>\n",hdr->e_ident[EI_CLASS]);
						break;
		}
		printf("  Data:\t\t\t\t\t");
		switch(hdr->e_ident[EI_DATA]) {
				case ELFDATANONE:
						printf("Unknown data format\n");
						break;
				case ELFDATA2LSB:
						printf("2's complement, little-endian.\n");
						break;
				case ELFDATA2MSB:                                                                 
						printf("2's complement, Big-endian.\n");                                 
						break;   	
				default:
						printf("<unknown : %x>\n",hdr->e_ident[EI_DATA]);
		}
		printf("  Version:\t\t\t\t");
		switch(hdr->e_ident[EI_VERSION]) {                                                             
				case EV_NONE:                                                                 
						printf("Invalid version\n");                                              
						break;                                                                        
				case EV_CURRENT:                                                                 
						printf("1 (current)\n");                                   
						break;                                                       
				default:
						printf("%d <unknown : %%lx>\n",hdr->e_ident[EI_VERSION]);
		}
		printf("  OS/ABI:\t\t\t\t");
		switch(hdr->e_ident[EI_OSABI]) {
				/*case ELFOSABI_NONE:
				  printf("Same as ELFOSABI_SYSV\n");
				  break;*/
				case ELFOSABI_SYSV:
						printf("UNIX System V ABI.\n");
						break;
				case ELFOSABI_HPUX:
						printf("HP-UX ABI.\n");
						break;
				case ELFOSABI_NETBSD:
						printf("NetBSD ABI.\n");
						break;
				case ELFOSABI_LINUX:
						printf("Linux ABI.\n");
						break;
				case ELFOSABI_SOLARIS:
						printf("Solaris ABI.\n");
						break;
				case ELFOSABI_IRIX:
						printf("IRIX ABI.\n");
						break;
				case ELFOSABI_FREEBSD:
						printf("FreeBSD ABI.\n");
						break;
				case ELFOSABI_TRU64:
						printf("TRU64 UNIX ABI.\n");
						break;
				case ELFOSABI_ARM:
						printf("ARM architecture ABI.\n");
						break;
				case ELFOSABI_STANDALONE:
						printf("Stand-alone (embedded) ABI.\n");
						break;
				default:
						printf("<unknown : %x>\n",hdr->e_ident[EI_OSABI]);
		}
		printf("  ABI Version:\t\t\t\t%d\n",hdr->e_ident[EI_ABIVERSION]);
		printf("  Type:\t\t\t\t\t");
		switch(hdr->e_type){
				case ET_NONE:
						printf("An unknown type.\n");
						break;
				case ET_REL:
						printf("REL (Relocatable file)\n");
						break;
				case ET_EXEC:
						printf("EXEC (Executable file)\n");
						break;
				case ET_DYN:
						printf("A shared object\n");
						break;
				case ET_CORE:
						printf("A core file.\n");
						break;

				default:
						printf("<unknown : %x>\n",hdr->e_type);
		}
		printf("  Machine:\t\t\t\t");
		switch(hdr->e_machine){
				case EM_NONE:
						printf("An unknown machine.\n");
						break;
				case EM_M32:
						printf("AT&T WE 32100.\n");
						break;
				case EM_SPARC:
						printf("Sun Microsystems SPARC.\n");
						break;	
				case EM_386:                                                                         
						printf("Intel 80386.\n");                                                  
						break;                                                                            
				case EM_68K:
						printf("Motorola 68000.\n");
						break;

				case EM_88K:                                                                          
						printf("Motorola 88000.\n");                                                      
						break; 
				case EM_860:      
						printf("Intel 80860.\n");
						break;
				case EM_MIPS:
						printf("MIPS RS3000 (big-endian only).\n");
						break;
				case EM_PARISC:
						printf("HP/PA.\n");
						break;
				case EM_SPARC32PLUS:
						printf("SPARC with enhanced instruction set.\n");
						break;
				case EM_PPC:
						printf("PowerPC.\n");
						break;
				case EM_PPC64:
						printf("PowerPC 64-bit.\n");
						break;
				case EM_S390:
						printf("IBM S/390\n");
						break;
				case EM_ARM:
						printf("Advanced RISC Machines\n");
						break;
				case EM_SH:
						printf("Renesas SuperH\n");
						break;
				case EM_SPARCV9:
						printf("SPARC v9 64-bit.\n");
						break;
				case EM_IA_64:
						printf("Intel Itanium\n");
						break;
				case EM_X86_64:
						printf("AMD x86-64\n");
						break;
				case EM_VAX:
						printf("DEC Vax.\n");
						break;
				default:
						printf("<unknown : %x>\n",hdr->e_machine);
		}
		printf("  Version:\t\t\t\t");
		if (hdr->e_version == EV_CURRENT)
				printf("0x%x\n", hdr->e_version);
		else 
				printf("0x%x\n", hdr->e_version);
		printf("  Entry point address:\t\t\t0x%x\n"
						"  Start of program headers:\t\t%d (bytes into file)\n"
						"  Start of section headers:\t\t%d (bytes into file)\n"
						"  Flags:\t\t\t\t0x%x\n"
						"  Size of this header:\t\t\t%d (bytes)\n"
						"  Size of program headers:\t\t%d (bytes)\n"
						"  Number of program headers:\t\t%d\n"
						"  Size of section headers:\t\t%d (bytes)\n"
						"  Number of section headers:\t\t%d\n"
						"  Section header string table index:\t%d\n",hdr->e_entry, hdr->e_phoff, hdr->e_shoff, hdr->e_flags, hdr->e_ehsize, hdr->e_phentsize, hdr->e_phnum, hdr->e_shentsize, hdr->e_shnum, hdr->e_shstrndx);
}
