#include <map>
#include <iostream>
#include <cassert>
#include <vector>
#include "main.h"
#include <pthread.h>
#include "testFamily.h"
#include "operations.h"


int main(int argc, char **argv){

    pthread_t operations[5];
    struct thread_data td[5];

    member testFamily[100];
    createTestFamily(testFamily);
    int rc;



    for (int i=0;i<5;i++){
        td[i].thread_id = i;
        td[i].family = testFamily;
        printf("creating operations id= %d \n",i);
        rc=pthread_create(&operations[i],NULL,addToWardrobe,(void *) &td[i]);

        if (rc) {
            printf("Error:unable to create thread, %d",rc);
            exit(-1);
        }
    }


    return 0;
}

