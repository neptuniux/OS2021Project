//
// Created by Daniel on 01/04/2021.
//

#include "WardRobe.h"
#include <pthread.h>
#include <algorithm>
#include <semaphore.h>

struct {
    bool operator()(Member a, Member b) const { return a.getBag().size() < b.getBag().size(); }
} smallestBagSize;

//this mutex is used to lock the access to the wardrobe
sem_t mutex;

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

    sem_init(&mutex,0,1);

    for (int i=0;i<numberOfThreads;i++){
        td[i].thread_id = i;
        td[i].member = &family.family[i];
        td[i].currentWardrobe = this;
        printf("Member with id %d open the wardrobe: step %d / %d\n",td[i].member->getId(),i,numberOfThreads);
        rc=pthread_create(&operations[i],NULL,putBagItoWardrobe,(void *) &td[i]);
        pthread_join(operations[i],NULL);
        if (rc) {
            printf("Error:unable to create thread, %d",rc);
            exit(-1);
        }
    }
    sem_destroy(&mutex);
    return 0;
}

//This method is call by every member to put the cloths into the wardrobe
void *putBagItoWardrobe(void *threadarg) {
    //Lock the access to the wardrobe
    sem_wait(&mutex);

    struct thread_data *threadData;
    threadData = (struct thread_data *) threadarg;
    int bagSize = threadData->member->getBag().size();
    std::vector<Cloth> currentBag = threadData->member->getBag();


    for (int i = 0; i < bagSize; ++i) {
        //printf("the member id: %d is putting the cloth id %d into the wardrobe \n",threadData->member->getId(),currentBag.at(i).id);
        threadData->currentWardrobe->addClothToWardrobe(currentBag[i]);
    }
    printf("the member id: %d close the wardrobe \n",threadData->member->getId());
    //release the access to the wardrobe
    sem_post(&mutex);
    //this methode is called at the end in case of error, one could use it to roll back.
    threadData->member->cleanbag();
    pthread_exit(nullptr);
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

