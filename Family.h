//
// Created by Daniel on 17/03/2021.
//

#ifndef OS2021PROJECT_FAMILY_H
#define OS2021PROJECT_FAMILY_H
#include "main.h"
#include "Member.h"
#include <array>

std::array<Member, 100> generateTestFamily();

class Family {
public:
    int id;
    std::array<Member,100> family;
    Family();
};
#endif //OS2021PROJECT_FAMILY_H
