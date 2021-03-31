#include <map>
#include <iostream>
#include <cassert>
#include <vector>
#include "main.h"
#include <pthread.h>
#include "testFamily.h"
#include "operations.h"

void *addToWardrobe(void *threadIdFamily){
    struct thread_data *threadData;
    threadData = (struct thread_data *) threadIdFamily;

    printf("Add to family thread id=%d, family members=%d",threadData->thread_id,threadData->family[0]->id);
    pthread_exit(NULL);
}


int main(int argc, char **argv){
    pthread_t operations[5];
    struct thread_data td[5];
    member* family;
    family = createTestFamily(100);


    for (int i=0;i<5;i++){
        td[i].thread_id = i;
        printf("creating operations id= %d \n",i);
        pthread_create(&operations[i],NULL,addToWardrobe,(void *) i);

    }


    return 0;
}

