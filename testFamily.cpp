//
// Created by Daniel on 17/03/2021.
//

#include "testFamily.h"
#include "main.h"
#include "randomString.h"

member * createTestFamily(int size){
    member family[size];
    for (int i = 0; i < size; ++i) {
        struct member randPers;
        randPers.firstname = printstring(5);
        randPers.lastname=printstring(5);
        randPers.id=i+1;
        family[i] = randPers;
    }
    return family;
}
