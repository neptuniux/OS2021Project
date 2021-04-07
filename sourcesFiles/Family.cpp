//
// Created by Daniel on 17/03/2021.
//

#include "../headersFiles/Family.h"
#include "../headersFiles/main.h"

std::vector<Member> generateTestFamily(int amount){
    std::vector<Member> toReturnFam;
    for (int i = 0; i < amount ; ++i) {
        Member newMember;
        toReturnFam.push_back(newMember);
    }
    return toReturnFam;
};

//constructor if the amount of member is not defined
Family::Family(): family(generateTestFamily(100)),id(rand()) {}
//constructor with the amount of member defined
Family::Family(int amount): family(generateTestFamily(amount)),id(rand()) {}

//this method send the family shopping for specified amount of cloth
void Family::goShopping(int numberItems){
    for (int i=0; i<numberItems;i++){
        int idFamMember=rand()%family.size();
        Cloth clothBought(family[idFamMember].getId());
        family[idFamMember].addClohToBag(clothBought);
    }
}

void Family::goShopping(){
    goShopping(100);
}

Member Family::getRandMember(){
    return family.at(rand()%family.size());

}
