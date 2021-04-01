//
// Created by Daniel on 01/04/2021.
//

#include "WardRobe.h"
#include "testCloths.h"
#include "Family.h"

int id;
std::map<int , Cloth> locWardrobe;


WardRobe::WardRobe() : wardrobe(locWardrobe),id(rand()%1000) {}

//this method will be use when the family object work
int WardRobe::addToWardrobe(Family family){
    /*
    struct thread_data *threadData;
    threadData = (struct thread_data *) threadIdFamily;

    printf("Add to family thread id=%d, family members=%s \n",threadData->thread_id,threadData->family[0].firstname.c_str());
    //pthread_exit(NULL);
     */
    //TODO: here comes the part with the threads strategy
    printf("test clean wardrobe with the id %d and the family size of %s",id,family.family.front().getFirstname().c_str());
    return 0;
}


int WardRobe::cleanWardrobe(){
    return -1;
}

int WardRobe::getId() const {
    return id;
}

