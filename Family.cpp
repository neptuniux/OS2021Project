//
// Created by Daniel on 17/03/2021.
//

#include "Family.h"
#include "main.h"
#include "randomString.h"
#include "Member.h"




std::array<Member, 100> generateTestFamily(){
    std::array<Member, 100> toReturnFam;
    for (auto & i : toReturnFam) {
        Member objMember;
        i=objMember;
    }
    return toReturnFam;
};
/*
void generateTestFamily(int size){
    Member family[size];
    for (int i = 0; i <size; ++i) {
        Member objMember;
        family[i] = objMember;
    }

};
*/

Family::Family(): family(generateTestFamily()),id(rand()) {}
