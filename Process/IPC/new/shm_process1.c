#include	<stdio.h>
#include	<stdlib.h>
#include	<fcntl.h>
#include	<sys/types.h>
#include	<sys/stat.h>
#include	<sys/mman.h>
#include	<semaphore.h>

struct shared{

	int in;
	int out;

};

sem_t *sem;

int main(void)

{

	int shm;

	struct shared *reg;

	if((shm = shm_open("/bikshu", (O_CREAT | O_RDWR), 0777)) < 0){

		perror("shm_open\n");

		exit(EXIT_FAILURE);

	}

	if(ftruncate(shm, sizeof(struct shared)) != 0){

		perror("ftruncate");

		exit(EXIT_FAILURE);

	}

	if((sem = sem_open("/sem1", O_CREAT, 0777, 1 )) < 0){

		perror("SEM_OPEN");

		exit(EXIT_FAILURE);

	}

	reg = (struct shared*)mmap(NULL, sizeof(struct shared), (PROT_READ | PROT_WRITE), MAP_SHARED, shm, 0);

	if(reg == NULL){

		perror("mmap");

		exit(EXIT_FAILURE);

	}

	int val1 = 0;
	int val2 = 20;

	while(1){

//		sleep(2);

		sem_wait(sem);

		printf("values : %d\t%d\n", reg->in, reg->out);
		
		reg->in = val2;
	
		reg -> out = val1;

		val1++;
		
		val2--;

		sem_post(sem);

		sleep(3);
		
		if(val1 == val2)

			break;


	}

	if(munmap(reg, sizeof(struct shared)) != 0){

		perror("munmap");

		exit(EXIT_FAILURE);

	}

	sem_close(sem);

	//shm_unlink("/bikshu");

	return 0;

}

	
		
		

		

	
	
