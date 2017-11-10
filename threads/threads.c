#include<stdio.h>
#include <pthread.h>

      // int pthread_create(pthread_t *thread, const pthread_attr_t *attr,
        //                  void *(*start_routine) (void *), void *arg); 

int count = 10;

	void* incCount(void * attr){
		count++;
		printf("In inc %d ",count);

	}
	
	void* decCount(void * attr){
		count--;
		printf("In dec %d ",count);

	}



	int main(){
	int incTh ,decTh;
	void* exitStatusInc,*exitStatusDec;
	pthread_t incThread, decThread;
	incTh = pthread_create(&incThread, NULL,incCount, NULL);
		if(incTh!=0){
			perror("Error creatring inc thread thread");
		
		}
	
	decTh = pthread_create(&decThread, NULL,decCount, NULL);
		if(decTh!=0){
			perror("Error creatring inc thread thread");
		
		}
		
	pthread_join(incThread,NULL);
	pthread_join(decThread,NULL);
	
	//pthread_exit(&exitStatusInc);
	//pthread_exit(&exitStatusDec);
	

	}
