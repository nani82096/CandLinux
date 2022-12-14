   #include <stdlib.h>
   #include <stdio.h>
   #include <sys/mman.h> // Needed for mlockall()
   #include <unistd.h> // needed for sysconf(int name);
   #include <malloc.h>
   #include <sys/time.h> // needed for getrusage
   #include <sys/resource.h> // needed for getrusage
   

   #define SOMESIZE (1024*1024) // 100MB
   

   int main(int argc, char* argv[])
   {
       // Allocate some memory
       int i, page_size;
       char* buffer;
       struct rusage usage;
       

       // Now lock all current and future pages from preventing of being paged
       if (mlockall(MCL_CURRENT | MCL_FUTURE ))
       {
           perror("mlockall failed:");
       }
       

       // Turn off malloc trimming.
       mallopt (M_TRIM_THRESHOLD, -1);
       

       // Turn off mmap usage.
       mallopt (M_MMAP_MAX, 0);
       

       page_size = sysconf(_SC_PAGESIZE);
       buffer = malloc(SOMESIZE);
       

       getrusage(RUSAGE_SELF, &usage);
       printf("Major-pagefaults:%d, Minor Pagefaults:%d\n", usage.ru_majflt, usage.ru_minflt);
       

       // Touch page to prove there will be no page fault later
       for (i=0; i < SOMESIZE; i+=page_size)
       {
           // Each write to this buffer will *not* generate a pagefault.
           // Even if nothing has been written to the newly allocated memory, the physical page
           //  is still provisioned to the process because mlockall() has been called with
           //  the MCL_FUTURE flag
           buffer[i] = 0;
           // print the number of major and minor pagefaults this application has triggered
           getrusage(RUSAGE_SELF, &usage);
           printf("Major-pagefaults:%d, Minor Pagefaults:%d\n", usage.ru_majflt, usage.ru_minflt);
       }
       free(buffer);
       // buffer is now released. As glibc is configured such that it never gives back memory to
       // the kernel, the memory allocated above is locked for this process. All malloc() and new()
       // calls come from the memory pool reserved and locked above. Issuing free() and delete()
       // does NOT make this locking undone. So, with this locking mechanism we can build C++ applications
       // that will never run into a major/minor pagefault, even with swapping enabled.
       

       //<do your RT-thing>
       

       return 0;
   }

