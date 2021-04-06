#include <map>
#include <iostream>
#include <cassert>
#include <vector>
#include "main.h"
#include <pthread.h>
#include "Family.h"
#include "WardRobe.h"
#include "Member.h"

/**
 * This project has the following proprieties
 * 1)Team Youth (smallest bag first)
 * 2)Team The unused should go (least used should go)
 * additional feature: to be determined
 * @param argc
 * @param argv
 * @return
 */


int main(int argc, char **argv){

    //create a family test
    Family testFamily;

    //create a wardrobe test
    WardRobe objWardrobe;

    //send the family shopping
    testFamily.goShopping(100);

    //add each other bag into the wardrobe
    objWardrobe.addFamBagsToWardrobe(testFamily);
    printf("The object of the wardrobe at the id 1 is %d ant the name is %s",objWardrobe.getWardrobe().front().id,objWardrobe.getWardrobe().front().name.c_str());

    return 0;
}

