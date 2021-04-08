//
// Created by Daniel on 17/03/2021.
//

#ifndef OS2021PROJECT_FAMILY_H
#define OS2021PROJECT_FAMILY_H
#include "main.h"
#include "Member.h"
//#include <array>

std::vector<Member> generateTestFamily(int amount);

class Family {
public:
    int id;
    std::vector<Member> family;

    Family();
    explicit Family(int amount);
    void goShopping(int numberItems);
    void goShopping();
    Member getRandMember();

};
#endif //OS2021PROJECT_FAMILY_H
