#include <map>
#include <iostream>
#include <cassert>
#include <vector>
#include "main.h"
#include <pthread.h>
#include "Family.h"
#include "WardRobe.h"
#include "Member.h"


int main(int argc, char **argv){
    /*
    //threads data
    int numberOfThreads =5 ;
    pthread_t operations[numberOfThreads];
    struct thread_data td[numberOfThreads];
    int rc;
*/
    //create a family test
    //Member testFamily[100];
    //generateTestFamily(testFamily, 100);
    Family testFamily;


    //create a wardrobe test
    WardRobe objWardrobe;
    testFamily.goShopping(10);
    objWardrobe.addToWardrobe(testFamily);

/*
    for (int i=0;i<numberOfThreads;i++){
        td[i].thread_id = i;
        td[i].family = testFamily;
        printf("creating operations id= %d \n",i);
        rc=pthread_create(&operations[i],NULL,objWardrobe.addToWardrobe,(void *) &td[i]);

        if (rc) {
            printf("Error:unable to create thread, %d",rc);
            exit(-1);
        }
    }
*/

    return 0;
}

