#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

int SIZE = 100;
int array[7];
int avg = 0, max = 0, min = 0;

void* avgThread1()
{
	int i = 0; 
	for(i=0; i<SIZE;i++)
	{
		printf("%d, ", array[i]);
		avg += array[i];
	}
	avg /= SIZE;
	printf("The average value is %d\n", avg);
}

void* maxThread2()
{
	int i = 0;
	max = array[i];
	for(i=0;i<SIZE;i++)
	{
		printf("%d, ", array[i]);
		if(array[i] > max)
			max = array[i];
	}
	printf("The maximum value is %d\n", max);

}

void* minThread3()
{
	int i = 0;
	min = array[i];
	for(i=0;i<SIZE;i++)
	{
		printf("%d, ", array[i]);
		if(array[i] < min)
			min = array[i];
	}
	printf("The minimum value is %d\n", min);
}

int main(int argc, char* argv[])
{
	
	int i, j;
	pthread_t thread1;
	pthread_t thread2;
	pthread_t thread3;
	SIZE = argc-1;
	
	for(i = 1; i<argc; i++)
		array[i-1] = atoi(argv[i]);

	j = pthread_create(&thread1, NULL, &avgThread1,NULL);
	pthread_join(thread1, NULL);
	
	j = pthread_create(&thread2, NULL, &maxThread2, NULL);
	pthread_join(thread2, NULL);

	j = pthread_create(&thread3, NULL, &minThread3, NULL);
	pthread_join(thread3, NULL);
	

	return 0;
}	
