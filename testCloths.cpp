//
// Created by Daniel on 17/03/2021.
//
/*
#include <cstdlib>
#include <vector>
#include "testCloths.h"
#include "main.h"
#include "randomString.h"
#include <ctime>
#include "Family.h"


cloth * createTestCloths(int clothsSize, member *family[]){
    cloth wardRobe[clothsSize];

    bool found = false;
    std::vector<int> clothIds;

    for (int i = 0; i < clothsSize; ++i) {
        struct cloth randomValue;
        randomValue.name = printstring(10);

        do {
            randomValue.id = rand();
            found = false;
            for (
                auto &elem: clothIds) {
                if (elem == randomValue.id) {
                    found = true;
                    break;
                }
            }
        } while (found);

        randomValue.created = time(0);
        randomValue.lastUsed = 0;
        randomValue.ownerID = family[i % 10]->id;
        wardRobe[i]=randomValue;
    }
    return wardRobe;
}

cloth * createTestCloths(member *family,int clothsSize) {
    //TODO watchout withe the sizeof
    family = generateTestFamily(family,sizeof family);
    cloth *toReturn;
    toReturn = createTestCloths(clothsSize,&family);
    return toReturn;

}

cloth * createTestBag(int clothsSize, int memberId) {
    cloth bag[clothsSize];
    bool found = false;
    std::vector<int> clothIds;

    for (int i = 0; i < clothsSize; ++i) {
        struct cloth randomValue;
        randomValue.name = printstring(10);

        do {
            randomValue.id = rand();
            found = false;
            for (
                auto &elem: clothIds) {
                if (elem == randomValue.id) {
                    found = true;
                    break;
                }
            }
        } while (found);

        randomValue.created = time(0);
        randomValue.lastUsed = 0;
        randomValue.ownerID = memberId;
        bag[i]= static_cast<cloth &&>(randomValue);
    }
    return bag;

}

testCloths::testCloths(cloth *cloths) : cloths(cloths) {}
testCloths::testCloths() : cloths(cloths) {}
*/