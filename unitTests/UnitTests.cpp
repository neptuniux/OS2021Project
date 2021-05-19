//
// Created by daniel on 05/05/2021.
//

#include "UnitTests.h"

bool fullTest(){
    if (testWardrobe()){
        printf("The wardrobe test passed");
    }else{
        printf("The wardrobe test failed");
    }

    if (testFamily()){
        printf("The family test passed");
    }else{
        printf("The family test failed");
    }
    if (scenario1()){
        printf("The scenario1 test passed");
    }else{
        printf("The scenario1 test failed");
    }
    if (scenario23()){
        printf("The scenario23 test passed");
    }else{
        printf("The scenario23 test failed");
    }

}

bool testFamily(){
    //create a family test
    Family testFamily(20);
    assert((testFamily.family.size() == 20) &&
           "the constructor parametrised family is returning the correct amount of member");
    Family testFamily2;
    assert((testFamily2.family.size() == 100) &&
           "the constructor unparametrised family is returning the correct amount of member (100)");

    //send the family shopping
    testFamily.goShopping(10);
    testFamily.goShopping();

    return true;
}



bool testWardrobe(){
    //create a wardrobe test
    WardRobe* objWardrobe = new WardRobe();
    Family testFamily(20);
    testFamily.goShopping(100);
    //add the bag of every family member into the wardrobe
    std::thread th1(&WardRobe::addFamBagsToWardrobe,objWardrobe,testFamily);
    printf("first add bags thread launched and ");
    std::thread th2(&WardRobe::addFamBagsToWardrobe,objWardrobe,testFamily);
    printf("second add bags thread launched \n");
    objWardrobe->addFamBagsToWardrobe(testFamily);

    //artificially use randoms cloths
    for (int i = 0; i < 100; ++i) {
        objWardrobe->useRandomCloth();
        printf("Using random cloth %d of 100 \n",i);
        sleep(1);
    }
    int idToTest = objWardrobe->getWardrobe().back().id;
    std::thread th3(&WardRobe::popCloth,objWardrobe,idToTest);
    printf("first pop thread launched and");
    std::thread th4(&WardRobe::popCloth,objWardrobe,idToTest);
    printf("second pop thread launched \n");

    th1.join();
    th2.join();
    th3.join();
    th4.join();

    return true;
}

bool scenario1(){
    //create a wardrobe test
    WardRobe* objWardrobe = new WardRobe();
    Family testFamily(20);
    Member randmember = testFamily.getRandMember();

    Cloth *testCloth1 = new Cloth("test1",randmember.getId());
    Cloth *testCloth2 = testCloth1;
    int result1= objWardrobe->addClothToWardrobe(*testCloth1);
    assert((result1 == 0) && "The first cloth can be added nicely");

    int result2 = objWardrobe->addClothToWardrobe(*testCloth2);
    assert((result2 == -1) && "The second cloth cannot be added");


    return true;
}

bool scenario23(){
    //create a wardrobe test
    WardRobe* objWardrobe = new WardRobe();
    Family testFamily(20);

    Cloth *testCloth1 = new Cloth("test1",testFamily.getRandMember().getId());

    objWardrobe->addClothToWardrobe(*testCloth1);
    Cloth tempCloth = objWardrobe->popClothName("test1");

    int result1=testFamily.getRandMember().addClohToBag(tempCloth);
    assert((result1 == 0) && "The cloth has been transferred to a member1 bag's");

    objWardrobe->addFamBagsToWardrobe(testFamily);

    int result2=testFamily.getRandMember().addClohToBag(objWardrobe->popClothName("test1"));
    assert((result2 == 0) && "The cloth has been transferred to a member2 bag's");

    return true;


}
