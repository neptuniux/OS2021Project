//
// Created by Daniel on 01/04/2021.
//

#include "../headersFiles/WardRobe.h"


//this struct is used to sort the bags with the smallest first
struct {
    bool operator()(const Member& a, const Member& b) const { return a.getBag().size() < b.getBag().size(); }
} smallestBagSize;

//this struct is used to sort the cloth of the wardrobe with the newest first
struct {
    bool operator()(const Cloth& a, const Cloth& b) const { return b.lastUsed < a.lastUsed; }
} newestFirst;

//this mutex is used to lock the access to the wardrobe
sem_t mutex;

WardRobe::WardRobe() : wardrobe(), id(rand() % 1000) {}


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
        printf("Member with id %d open the wardrobe: step %d / %d\n",td[i].member->getId(),i+1,numberOfThreads);
        rc= pthread_create(&operations[i], nullptr, putBagIntoWardrobe, (void *) &td[i]);
        pthread_join(operations[i],nullptr);
        if (rc) {
            printf("Error:unable to create thread, %d",rc);
            exit(-1);
        }
    }
    sem_destroy(&mutex);
    return 0;
}

//This method is call by every member to put the cloths into the wardrobe
void *putBagIntoWardrobe(void *threadarg) {
    //Lock the access to the wardrobe
    sem_wait(&mutex);

    struct thread_data *threadData;
    threadData = (struct thread_data *) threadarg;
    int bagSize = threadData->member->getBag().size();
    std::vector<Cloth> currentBag = threadData->member->getBag();


    for (int i = 0; i < bagSize; ++i) {
        printf("the member id: %d is putting the cloth id %d into the wardrobe \n",threadData->member->getId(),currentBag.at(
                static_cast<unsigned int>(i)).id);

        threadData->currentWardrobe->addClothToWardrobe(currentBag[i]);
    }
    printf("the member id: %d close the wardrobe \n",threadData->member->getId());

    //release the access to the wardrobe
    sem_post(&mutex);
    //this methode is called at the end in case of error, one could use it to roll back.
    threadData->member->cleanbag();
    pthread_exit(nullptr);
    return nullptr;
}


int WardRobe::addClothToWardrobe(const Cloth& cloth){
    wardrobe.push_back(cloth);
    return 0;
}

//the parameter is the amount of cloth to clean
void WardRobe::cleanWardrobe(int toClean){
    std::sort(wardrobe.begin(),wardrobe.end(),newestFirst);
    if (toClean>wardrobe.size()){
        toClean=wardrobe.size();
    }
    for (int i = 0; i < toClean; ++i) {
        tm *gmtm = gmtime(&wardrobe.back().lastUsed);
        char *dt = asctime(gmtm);
        printf("The wardrobe was cleaned of the cloth with the id %d because it was %s old \n",wardrobe.back().id,dt);
        wardrobe.pop_back();
    }
}

//if no parameter is provided the amount cleaned is 50% of the current used wardrobe
void WardRobe::cleanWardrobe(){
    cleanWardrobe(static_cast<int>(wardrobe.size()/2));
}


int WardRobe::getId() const {
    return id;
}

const std::vector<Cloth> &WardRobe::getWardrobe() const {
    return wardrobe;
}

//this method could be used in the future
Cloth WardRobe::popCloth(int clothid){
    int i = 0;
    for (const auto &item : wardrobe) {
        if (item.ownerID == clothid) {
            wardrobe[i].updateUseDate();
            Cloth toreturn = wardrobe[i];
            wardrobe.erase(wardrobe.begin()+i);
            return toreturn;
        }
        i++;
    }
    return static_cast<Cloth>(NULL);
}


//this method use a random cloth of a specified member and return the id of the cloth used
int WardRobe::useRandomCloth(const Member& member){
    std::vector<Cloth*> clothOf;
    for (Cloth item : wardrobe) {
        if (item.ownerID == member.getId()) {
            clothOf.push_back(&item);
        }
    }
    Cloth *toReturn = clothOf.at(rand()%clothOf.size());
    toReturn->updateUseDate();
    return toReturn->id;
}

//this method use a random cloth and return the id of the cloth used
int WardRobe::useRandomCloth(){
    Cloth *toreturn = &wardrobe.at(rand()%wardrobe.size());
    toreturn->updateUseDate();
    return toreturn->id;
}


