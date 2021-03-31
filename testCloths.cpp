//
// Created by Daniel on 17/03/2021.
//

#include <cstdlib>
#include <vector>
#include "testCloths.h"
#include "main.h"
#include "randomString.h"
#include <ctime>
#include "testFamily.h"

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
        randomValue.ownerID = family[i % 10].id;
        wardRobe[i]=randomValue;
    }
    return wardRobe;
}

cloth * createTestCloths(int clothsSize, int familySize) {
    member *family;
    family = createTestFamily(familySize);
    return createTestCloths(clothsSize,family);

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

}