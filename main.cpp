#include <map>
#include <iostream>
#include <cassert>
#include <vector>
#include "main.h"
#include <pthread.h>
#include "testFamily.h"

int main(int argc, char **argv){
    pthread_t opperations[5];
    struct thread_data td[5];
    member familyx[100];
    familyx = createTestFamily(100);


    for (int i=0;i<5;i++){
        td[i].thread_id = i;
        printf("creating operations id= %d",i);

    }


    return 0;
}

