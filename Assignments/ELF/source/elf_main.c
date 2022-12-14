#include    "header.h"                                                                    

Elf32_Ehdr *hdr;                                                                  
FILE *fptr;                                                                       
int main(int argc, char *argv[])                                                          
{                                                                                         
        fptr = fopen(argv[1], "r");                                                       
		if( (hdr = malloc(sizeof(Elf32_Ehdr))) == NULL)                                                 
			printf("malloc failed for hdr\n");	
        fread(hdr,sizeof(Elf32_Ehdr),1, fptr);                                            
        Elf_hdr(hdr);                                                                     
		Elf_Shdr();
        return 0;                                                                         
} 
