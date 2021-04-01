//
// Created by Daniel on 01/04/2021.
//
#include <map>
#include "main.h"
#include <pthread.h>
#include "Family.h"

#ifndef OS2021PROJECT_WARDROBE_H
#define OS2021PROJECT_WARDROBE_H

void *putBagItoWardrobe(void *threadarg);

class WardRobe {
    int id;
    std::vector<Cloth> wardrobe;

    public:
    //WardRobe(const std::map<int, cloth> &wardrobe);
    WardRobe();
    int addFamBagsToWardrobe(Family family);
    //int addFamBagsToWardrobe(member family[]);
    int cleanWardrobe();
    int getId() const;
    const std::vector<Cloth> &getWardrobe() const;
    int addClothToWardrobe(Cloth cloth);

};

struct thread_data{
    int thread_id;
    Member *member;
    WardRobe *currentWardrobe;
};


#endif //OS2021PROJECT_WARDROBE_H
