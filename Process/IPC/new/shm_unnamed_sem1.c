#include	<stdio.h>
#include	<stdlib.h>
#include	<semaphore.h>
#include	<unistd.h>
#include	<sys/types.h>
#include	<fcntl.h>
#include	<sys/stat.h>
#include	<signal.h>
#include	<sys/mman.h>
#include	<strings.h>
#include	<string.h>

struct shared {

	char buff[30];
	
};

sem_t *sem;

struct shared *reg;

int shm;

void action(int sig_num)

{

	 if(munmap(sem, sizeof(struct shared)+sizeof(sem_t)) != 0){

        perror("munmap");

        exit(EXIT_FAILURE);

    }

	sem_destroy(sem);

    shm_unlink("/bikshu");

	exit(EXIT_SUCCESS);
}

int main(void)

{

	signal(SIGINT, action);

	if((shm = shm_open("/bikshu", (O_CREAT | O_RDWR), 0777)) < 0){

        perror("shm_open\n");

        exit(EXIT_FAILURE);

    }

    if(ftruncate(shm, sizeof(struct shared)) != 0){

        perror("ftruncate");

        exit(EXIT_FAILURE);

    }
	
	reg = (struct shared*)mmap(NULL, sizeof(struct shared) + sizeof(sem_t ), (PROT_READ | PROT_WRITE), MAP_SHARED, shm, 0);

    if(reg == NULL){

        perror("mmap");

        exit(EXIT_FAILURE);

    }

	sem = (sem_t *)reg;
	reg = reg + sizeof(sem_t);

	if(sem_init(sem, 1, 1) == -1){

		perror("sem_init");

		exit(EXIT_FAILURE);
	
	}
	
	while(1){

		sem_wait(sem);

		printf("message : %s\n", reg->buff);

		bzero(reg->buff, 30);

/*		puts("Enter msg...\n");

		if(NULL == fgets(reg->buff, 30, stdin)){

			perror("fgets");

			exit(EXIT_FAILURE)	;

		}*/

		strcpy(reg->buff, "bye");

		sem_post(sem);

		sleep(3);

	}

	return  0;
}
		
	


