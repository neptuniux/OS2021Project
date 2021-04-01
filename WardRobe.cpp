//
// Created by Daniel on 01/04/2021.
//

#include "WardRobe.h"
#include <pthread.h>
#include <algorithm>

struct {
    bool operator()(Member a, Member b) const { return a.getBag().size() < b.getBag().size(); }
} smallestBagSize;

WardRobe::WardRobe() : wardrobe(), id(rand() % 1000) {}

//this method will be use when the family object work
int WardRobe::addFamBagsToWardrobe(Family family){
    //threads data
    int numberOfThreads = family.family.size();
    pthread_t operations[numberOfThreads];
    struct thread_data td[numberOfThreads];
    int rc;

    //this sort locally the family with the smallest bag first
    std::sort(family.family.begin(),family.family.end(),smallestBagSize);

    for (int i=0;i<numberOfThreads;i++){
        td[i].thread_id = i;
        td[i].member = &family.family[i];
        td[i].currentWardrobe = this;
        printf("Member with id %d open the wardrobe: step %d / %d\n",td[i].member->getId(),i,numberOfThreads);
        rc=pthread_create(&operations[i],NULL,putBagItoWardrobe,(void *) &td[i]);
        pthread_join(operations[i-1],NULL);
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
        //printf("the member id: %d is putting the cloth id %d into the wardrobe \n",threadData->member->getId(),currentBag.at(i).id);
        threadData->currentWardrobe->addClothToWardrobe(currentBag[i]);
    }
    printf("the member id: %d close the wardrobe \n",threadData->member->getId());
    pthread_exit(NULL);
}


int WardRobe::addClothToWardrobe(Cloth cloth){
    wardrobe.push_back(cloth);
    return 0;
}

int WardRobe::cleanWardrobe(){
    return -1;
}

int WardRobe::getId() const {
    return id;
}

const std::vector<Cloth> &WardRobe::getWardrobe() const {
    return wardrobe;
}

