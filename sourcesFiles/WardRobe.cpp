//
// Created by Daniel on 01/04/2021.
//

#include "../headersFiles/WardRobe.h"

//these mutex is used to lock the access to the wardrobe
std::mutex use_cloth_mutex;
sem_t mutexAddBags;
sem_t mutexClean;
pthread_t cleaning_operations[20];
struct thread_data_clean_wardrobe cleaning_td[20];


WardRobe::WardRobe() : wardrobe(), id(rand() % 1000) {}


int WardRobe::addFamBagsToWardrobe(Family family) {
    //threads data

    int numberOfThreads = (int) family.family.size();
    pthread_t operations[numberOfThreads];
    struct thread_data_addBags td[numberOfThreads];
    int rc;

    //this sort locally the family with the smallest bag first
    std::sort(family.family.begin(), family.family.end(), smallestBagSize);

    sem_init(&mutexAddBags, 0, 1);

    for (int i = 0; i < numberOfThreads; i++) {
        td[i].thread_id = i;
        td[i].member = &family.family[i];
        td[i].currentWardrobe = this;
        printf("Member with id %d open the wardrobe: step %d / %d\n", td[i].member->getId(), i + 1, numberOfThreads);
        rc = pthread_create(&operations[i], NULL, putBagIntoWardrobe, (void *) &td[i]);
        pthread_join(operations[i], NULL);
        if (rc) {
            printf("Error:unable to create thread, %d", rc);
            exit(-1);
        }
    }
    sem_destroy(&mutexAddBags);
    return 0;
}

//This method is call by every member to put the cloths into the wardrobe
void *putBagIntoWardrobe(void *threadarg) {
    //Lock the access to the wardrobe
    sem_wait(&mutexAddBags);

    struct thread_data_addBags *threadData;
    threadData = (struct thread_data_addBags *) threadarg;
    int bagSize = (int) threadData->member->getBag().size();
    std::vector<Cloth> currentBag = threadData->member->getBag();


    for (int i = 0; i < bagSize; ++i) {
        printf("the member id: %d is putting the cloth id %d into the wardrobe \n", threadData->member->getId(),
               currentBag.at(
                       static_cast<unsigned int>(i)).id);

        threadData->currentWardrobe->addClothToWardrobe(currentBag[i]);
    }
    printf("the member id: %d close the wardrobe \n", threadData->member->getId());

    //release the access to the wardrobe
    sem_post(&mutexAddBags);
    //this methode is called at the end in case of error, one could use it to roll back.
    threadData->member->cleanbag();
    //pthread_exit(nullptr);

}


int WardRobe::addClothToWardrobe(const Cloth &cloth) {
    std::lock_guard<std::mutex> guard(use_cloth_mutex);
    bool flag = false;
    for (auto &item : wardrobe) {
        if (cloth.id == item.id && cloth.name == item.name && cloth.ownerID == item.ownerID) {
            flag = true;
        }
    }

    if (!flag){
        wardrobe.push_back(cloth);
        return 0;
    } else{
        printf("The cloth is already in the closet");
        return -1;
    }
}

//the parameter is the amount of cloth to clean
void *cleanWardrobeThreaded(void *threadArgs) {
    sem_wait(&mutexClean);
    struct thread_data_clean_wardrobe *threadData;
    threadData = (struct thread_data_clean_wardrobe *) (threadArgs);
    int toClean = reinterpret_cast<int>(threadData->toClean);


    std::sort(threadData->currentWardrobe->getWardrobe().begin(), threadData->currentWardrobe->getWardrobe().end(),
              newestFirst);
    if (toClean > threadData->currentWardrobe->getWardrobe().size()) {
        toClean = threadData->currentWardrobe->getWardrobe().size();
    }

    for (int i = 0; i < toClean; ++i) {
        tm *gmtm = gmtime(&threadData->currentWardrobe->getWardrobe().back().lastUsed);
        char *dt = asctime(gmtm);

        threadData->currentWardrobe->getWardrobe().pop_back();
        printf("The wardrobe was cleaned of the cloth with the id %d because it was %s old \n",
               threadData->currentWardrobe->getWardrobe().back().id, dt);
    }
    sem_post(&mutexClean);
    pthread_exit(nullptr);
}


void WardRobe::cleanWardrobe(int toClean) {
    //threads data
    if (numberCleanWardrobeThreads == 0) {
        sem_init(&mutexClean, 0, 1);
    }

    numberCleanWardrobeThreads++;
    int rc;

    cleaning_td[numberCleanWardrobeThreads].thread_id = numberCleanWardrobeThreads;
    cleaning_td[numberCleanWardrobeThreads].toClean = toClean;
    cleaning_td[numberCleanWardrobeThreads].currentWardrobe = this;
    printf("Cleaning process started: amount %d,  step %d / %d\n", cleaning_td[numberCleanWardrobeThreads].toClean,
           numberCleanWardrobeThreads + 1, numberCleanWardrobeThreads);
    rc = pthread_create(&cleaning_operations[numberCleanWardrobeThreads], NULL, cleanWardrobeThreaded,
                        (void *) &cleaning_td[numberCleanWardrobeThreads]);
    pthread_join(cleaning_operations[numberCleanWardrobeThreads], nullptr);
    if (rc) {
        printf("Error:unable to create thread, %d", rc);
        exit(-1);
    }


    if (numberCleanWardrobeThreads == 0) {
        sem_destroy(&mutexClean);
    }
    numberCleanWardrobeThreads--;

}

void WardRobe::cleanWardrobe() {
    cleanWardrobe(this->wardrobe.size() / 2);
}


int WardRobe::getId() const {
    return id;
}

std::vector<Cloth> &WardRobe::getWardrobe() {
    return wardrobe;
}


Cloth WardRobe::popCloth(int clothid) {
    std::lock_guard<std::mutex> guard(use_cloth_mutex);
    int i = 0;
    for (auto &item : wardrobe) {
        if (item.ownerID == clothid) {
            wardrobe[i].updateUseDate();
            Cloth toreturn = wardrobe[i];
            wardrobe.erase(wardrobe.begin() + i);
            printf("Poped the cloth id: %d \n", toreturn.id);
            return toreturn;
        }
        i++;
    }
    printf("WARNING: The cloth %d could not be found \n",clothid);
    return static_cast<Cloth>(NULL);
}

Cloth WardRobe::popClothName(std::string clothname) {
    std::lock_guard<std::mutex> guard(use_cloth_mutex);
    int i = 0;
    for (auto &item : wardrobe) {
        if (item.name == clothname) {
            wardrobe[i].updateUseDate();
            Cloth toreturn = wardrobe[i];
            wardrobe.erase(wardrobe.begin() + i);
            printf("Poped the cloth id: %d \n", toreturn.id);
            return toreturn;
        }
        i++;
    }
    printf("WARNING: The cloth ");
    printf(clothname.c_str());
    printf(" could not be found");
    return static_cast<Cloth>(NULL);
}


//this method use a random cloth of a specified member and return the id of the cloth used
int WardRobe::useRandomCloth(const Member &member) {
    std::lock_guard<std::mutex> guard(use_cloth_mutex);
    std::vector<Cloth *> clothOf;
    for (Cloth item : wardrobe) {
        if (item.ownerID == member.getId()) {
            clothOf.push_back(&item);
        }
    }
    Cloth *toReturn = clothOf.at(rand() % clothOf.size());
    toReturn->updateUseDate();
    return toReturn->id;
}

//this method use a random cloth and return the id of the cloth used
int WardRobe::useRandomCloth() {
    std::lock_guard<std::mutex> guard(use_cloth_mutex);
    Cloth *toreturn = &wardrobe.at(rand() % wardrobe.size());
    toreturn->updateUseDate();
    return toreturn->id;
}

int WardRobe::getAmount(std::string name) {
    std::lock_guard<std::mutex> guard(use_cloth_mutex);
    int toreturn=0;
    for (Cloth item : wardrobe) {
        if (item.name == name) {
            toreturn++;
        }
    }
    return toreturn;
}





