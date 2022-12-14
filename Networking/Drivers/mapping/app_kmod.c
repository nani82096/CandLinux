#include <stdio.h>
#include <sys/mman.h>
#include <fcntl.h>

void hexDump (char *desc, void *addr, int len) 
{
    int i;
    unsigned char buff[17];
    unsigned char *pc = (unsigned char*)addr;

    // Output description if given.
    if (desc != NULL)
        printf ("%s:\n", desc);

    if (len == 0) {
        printf("  ZERO LENGTH\n");
        return;
    }
	printf ("length = %d\n", len);
    if (len < 0) {
        printf("  NEGATIVE LENGTH: %i\n",len);
        return;
    }

    // Process every byte in the data.
	printf ("\t");	
	for (i = 0; i < 16; i++)
		printf ("%02x ", i);
	printf ("\n\n");
    for (i = 0; i < len; i++) {

        if ((i % 16) == 0) {
            if (i != 0)
		  		printf ("\n");

            // Output the offset.
            printf ("  %04x ", i);
        }

        // Now the hex code for the specific character.
        printf (" %02x", pc[i]);

        // And store a printable ASCII character for later.
        if ((pc[i] < 0x20) || (pc[i] > 0x7e))
            buff[i % 16] = '.';
        else
            buff[i % 16] = pc[i];
        buff[(i % 16) + 1] = '\0';
    }

    // Pad out last line if not exactly 16 characters.
    while ((i % 16) != 0) {
        printf ("   ");
        i++;
    }

	printf ("\n");
}


int main()
{

   int fd;

   fd = open("/dev/myChar", O_RDWR);

   char *ptr = mmap(NULL, (size_t )4096, PROT_READ , MAP_SHARED, fd, (off_t )0);
   if (ptr ==  MAP_FAILED ){
	printf ("mmap failed\n");
   }

   if (fd < 0)
	   perror("Unable to open the device");
   else
	   printf("File opened Successfully %d\n", fd);

   close(fd);
   
   hexDump("Desc", ptr, 256);

   return 0;
}
