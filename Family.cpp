//
// Created by Daniel on 17/03/2021.
//

#include "Family.h"
#include "main.h"

std::array<Member, 100> generateTestFamily(){
    std::array<Member, 100> toReturnFam;
    for (auto & i : toReturnFam) {
        Member objMember;
        i=objMember;
    }
    return toReturnFam;
};

Family::Family(): family(generateTestFamily()),id(rand()) {}

void Family::goShopping(int numberItems){
    for (int i=0; i<numberItems;i++){
        int idFamMember=rand()%family.size();
        Cloth clothBought(idFamMember);
        family[idFamMember].addClohToBag(clothBought);
    }
}
