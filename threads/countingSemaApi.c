#include<stdio.h>
#include <semaphore.h>
#define MAX 4
#define FAIL -999
#define SUCCESS 1

sem_t resSem; 
int resource[MAX];
int resCount=MAX;

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
	

	
	
	
	
	
	
	
	
	
