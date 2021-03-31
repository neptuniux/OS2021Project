//
// Created by Daniel on 17/03/2021.
//

#include <map>
#include "main.h"
#include <pthread.h>

void *addToWardrobe(void *threadIdFamily){
    struct thread_data *threadData;
    threadData = (struct thread_data *) threadIdFamily;

    printf("Add to family thread id=%d, family members=%s \n",threadData->thread_id,threadData->family[0].firstname.c_str());
    pthread_exit(NULL);
}

int *cleanWardrobe(std::map<int , cloth> *wardrobe){

}
