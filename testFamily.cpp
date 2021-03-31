//
// Created by Daniel on 17/03/2021.
//

#include "testFamily.h"
#include "main.h"
#include "randomString.h"



TestFamily::TestFamily(member *family) : family(createTestFamily(family)) {}


member * createTestFamily(member *family){

    for (int i = 0; i <sizeof family; ++i) {
        struct member randPers;
        randPers.firstname = printstring(5);
        randPers.lastname=printstring(5);
        randPers.id=i+1;
        family[i] = randPers;
    }
};




