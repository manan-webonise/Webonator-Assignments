#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<semaphore.h>
#include<unistd.h>

sem_t room;
sem_t chopsticks[5];

void * allotchopsticks(void *);
void eat(int);
int main()
{
	int i,a[5];
	pthread_t thread_id[5];
	
	sem_init(&room,0,4);
	
	for(i=0;i<5;i++)
		sem_init(&chopsticks[i],0,1);
		
	for(i=0;i<5;i++){
		a[i]=i;
		pthread_create(&thread_id[i],NULL,allotchopsticks,(void *)&a[i]);
	}
	for(i=0;i<5;i++)
		pthread_join(thread_id[i],NULL);
}

void * allotchopsticks(void * num)
{
	int phil_num=*(int *)num;

	sem_wait(&room);
	printf("Philosopher %d has sat on the table\n",phil_num+1);
	sem_wait(&chopsticks[phil_num]);
	sem_wait(&chopsticks[(phil_num+1)%5]);

	eat(phil_num);
	sleep(5);
	
	printf("Philosopher %d has eaten\n",phil_num+1);

	sem_post(&chopsticks[(phil_num+1)%5]);
	sem_post(&chopsticks[phil_num]);
	sem_post(&room);
}

void eat(int phil_num)
{
	printf("Philosopher %d is eating\n",phil_num+1);
}
