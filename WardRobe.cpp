//
// Created by Daniel on 01/04/2021.
//

#include "WardRobe.h"
#include "Family.h"
#include <pthread.h>



WardRobe::WardRobe() : wardrobe(), id(rand() % 1000) {}

//this method will be use when the family object work
int WardRobe::addFamBagsToWardrobe(Family family){
    //threads data
    int numberOfThreads = family.family.size();
    pthread_t operations[numberOfThreads];
    struct thread_data td[numberOfThreads];
    int rc;

    //TODO sort the family, smallest bag comes first.


    for (int i=0;i<numberOfThreads;i++){
        td[i].thread_id = i;
        td[i].member = &family.family[i];
        printf("Member with id %d open the wardrobe: step %d / %d\n",td[i].member->getId(),i,numberOfThreads);
        rc=pthread_create(&operations[i],NULL,putBagItoWardrobe,(void *) &td[i]);

        if (rc) {
            printf("Error:unable to create thread, %d",rc);
            exit(-1);
        }
    }
    return 0;
}

void *putBagItoWardrobe(void *threadarg) {
    struct thread_data *threadData;
    threadData = (struct thread_data *) threadarg;
    int bagSize = threadData->member->getBag().size();
    std::vector<Cloth> currentBag = threadData->member->getBag();

    for (int i = 0; i < bagSize; ++i) {
        printf("the member id: %d is putting the cloth id %d into the wardrobe \n",threadData->member->getId(),currentBag.at(i).id);
        //TODO solve this problem
        // addClothToWardrobe(currentBag[i]);

    }
    pthread_exit(NULL);
}


int WardRobe::addClothToWardrobe(Cloth cloth){
    wardrobe.insert(std::pair<int,Cloth>(wardrobe.size(),cloth));
    return -1;
}

int WardRobe::cleanWardrobe(){
    return -1;
}

int WardRobe::getId() const {
    return id;
}

const std::map<int, Cloth> &WardRobe::getWardrobe() const {
    return wardrobe;
}

