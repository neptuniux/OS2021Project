//
// Created by Daniel on 01/04/2021.
//
#include <map>
#include <pthread.h>
#include <algorithm>
#include <semaphore.h>
#include <iostream>
#include <vector>
#include <ctime>
#include <mutex>

#include "main.h"
#include "Family.h"

#ifndef OS2021PROJECT_WARDROBE_H
#define OS2021PROJECT_WARDROBE_H

void *putBagIntoWardrobe(void *threadarg);
Cloth testPop(int clothid);

class WardRobe {
    int id;
    std::vector<Cloth> wardrobe;

public:
    WardRobe();

    int addFamBagsToWardrobe(Family family);

    void cleanWardrobe(int toClean);

    void cleanWardrobe();

    int getId() const;

    std::vector<Cloth> &getWardrobe();

    int addClothToWardrobe(const Cloth &cloth);

    int useRandomCloth(const Member &member);

    int useRandomCloth();

    Cloth popCloth(int clothid);

private:
    int numberCleanWardrobeThreads = 0;



};

struct thread_data_addBags {
    int thread_id;
    Member *member;
    WardRobe *currentWardrobe;
};

struct thread_data_clean_wardrobe {
    int thread_id;
    int toClean;
    WardRobe *currentWardrobe;
};

//this struct is used to sort the bags with the smallest first
struct {
    bool operator()(const Member &a, const Member &b) const { return a.getBag().size() < b.getBag().size(); }
} smallestBagSize;

//this struct is used to sort the cloth of the wardrobe with the newest first
struct {
    bool operator()(const Cloth &a, const Cloth &b) const { return b.lastUsed < a.lastUsed; }
} newestFirst;


#endif //OS2021PROJECT_WARDROBE_H
