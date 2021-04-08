//
// Created by Daniel on 01/04/2021.
//
#include <map>
#include <pthread.h>
#include <pthread.h>
#include <algorithm>
#include <semaphore.h>
#include <iostream>
#include <vector>
#include <ctime>

#include "main.h"
#include "Family.h"

#ifndef OS2021PROJECT_WARDROBE_H
#define OS2021PROJECT_WARDROBE_H

void *putBagIntoWardrobe(void *threadarg);

class WardRobe {
    int id;
    std::vector<Cloth> wardrobe;

    public:
    WardRobe();
    int addFamBagsToWardrobe(Family family);
    void cleanWardrobe(int toClean);
    void cleanWardrobe();
    [[nodiscard]] int getId() const;
    [[nodiscard]] const std::vector<Cloth> &getWardrobe() const;
    int addClothToWardrobe(const Cloth& cloth);
    int useRandomCloth(const Member& member);
    int useRandomCloth();
    Cloth popCloth(int clothid);

};

struct thread_data{
    int thread_id;
    Member *member;
    WardRobe *currentWardrobe;
};


#endif //OS2021PROJECT_WARDROBE_H
