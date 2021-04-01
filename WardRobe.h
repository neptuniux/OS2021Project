//
// Created by Daniel on 01/04/2021.
//
#include <map>
#include "main.h"
#include <pthread.h>
#include "Family.h"

#ifndef OS2021PROJECT_WARDROBE_H
#define OS2021PROJECT_WARDROBE_H



class WardRobe {
    int id;
    std::map<int , Cloth> wardrobe;

    public:
    //WardRobe(const std::map<int, cloth> &wardrobe);
    WardRobe();
    int addToWardrobe(Family family);
    //int addToWardrobe(member family[]);
    int cleanWardrobe();
    int getId() const;


};


#endif //OS2021PROJECT_WARDROBE_H
