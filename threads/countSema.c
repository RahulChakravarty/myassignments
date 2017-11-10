#include<stdio.h>
#include <pthread.h>
#include<stdio.h>
#include <semaphore.h>
#define MAX 4
#define FAIL -999
#define SUCCESS 1
              
sem_t resSem; 
int resource[MAX];
int resCount=MAX;
int count = 10;

	int initialize(){
	//int  initSuccess;

		if(sem_init(&resSem,0, MAX) == -1){
		
			perror("Error creating semaphore\n");
			return FAIL;
		
		}
	printf("initialization successful\n");
	return SUCCESS;
	}
	
	int getResource(){
      int sval;
       if(sem_wait(&resSem) == -1){
       	perror("error in wait\n");
       	return FAIL;
       }else{
       		sem_getvalue(&resSem, &sval);
       		printf("The value of sem is %d\n",sval);
       		if(resCount > 0){
       			resCount--;
       		 	printf("resource allocated\n resource left %d\n",resCount);
       		}else{
       			printf("resource unavailable\n");
       		}
       }
      return SUCCESS;
	}
	
	int releaseResource(){
		int sval;
		if(sem_post(&resSem)==-1){
			perror("error in wait\n");
       		return FAIL;
		}else{
       		sem_getvalue(&resSem, &sval);
       		printf("The value of sem is %d\n",sval);
			if(resCount < MAX){
       			resCount++;
       		 	printf("resource deallocated\n resource left %d\n",resCount);
       		}else{
       			printf("bad resource count\n");
       		}
       }
      return SUCCESS;

	}
	

	 


	void* incCount(void * attr){
		while(count < 13){
		getResource();
			count++;
			printf("In inc %d \n",count);
		releaseResource();
		}
	}
	
	void* decCount(void * attr){
		while(count > 7){
		getResource();
			count--;
			printf("In dec %d \n",count);
		releaseResource();
		}
	}


	void* add(void * attr){
		while(count < 13){
		getResource();
			count++;
			printf("In add %d \n",count);
		releaseResource();
		}
	}
	
	
	void* mul(void * attr){
		while(count < 13){
		getResource();
			count++;
			printf("In mul %d \n",count);
		releaseResource();
		}
	}
	
	
	void* sub(void * attr){
		while(count < 13){
		getResource();
			count++;
			printf("In sub %d \n",count);
		releaseResource();
		}
	}
	
	void* div(void * attr){
		while(count < 13){
		getResource();
			count++;
			printf("In div %d \n",count);
		releaseResource();
		}
	}


	int main(){
	int incTh ,decTh;
	void* exitStatusInc,*exitStatusDec;
	pthread_t incThread, decThread,addt,subt,mult,divt;
	incTh = pthread_create(&incThread, NULL,incCount, NULL);
		if(incTh!=0){
			perror("Error creatring inc thread thread");
		
		}
	
	decTh = pthread_create(&decThread, NULL,decCount, NULL);
		if(decTh!=0){
			perror("Error creatring inc thread thread");
		
		}
		
		pthread_create(&addt, NULL,add, NULL);
		pthread_create(&subt, NULL,sub, NULL);
		pthread_create(&mult, NULL,mul, NULL);
		pthread_create(&divt, NULL,div, NULL);
		initialize();
		
	pthread_join(incThread,NULL);
	pthread_join(decThread,NULL);
	
	//pthread_exit(&exitStatusInc);
	//pthread_exit(&exitStatusDec);
	

	}
