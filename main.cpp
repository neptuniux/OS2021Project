#include <map>
#include <iostream>
#include <cassert>
#include <vector>
#include "main.h"
#include <pthread.h>
#include "Family.h"
#include "WardRobe.h"
#include "Member.h"


int main(int argc, char **argv){

    //create a family test
    Family testFamily;


    //create a wardrobe test
    WardRobe objWardrobe;

    //send the family shopping
    testFamily.goShopping(1000);

    //add each other bag into the wardrobe
    objWardrobe.addFamBagsToWardrobe(testFamily);
    printf("The object of the wardrobe at the id 1 is %d",objWardrobe.getWardrobe().at(1).id);

    return 0;
}

