//
// Created by daniel on 05/05/2021.
//

#include "UnitTests.h"

bool fullTest(){
    /*
    if (testWardrobe()){
        printf("The wardrobe test passed");
    }else{
        printf("The wardrobe test failed");
    }
     */

    if (testFamily()){
        printf("The family test passed \n");
    }else{
        printf("The family test failed \n");
    }
    if (scenario1()){
        printf("The scenario1 test passed \n");
    }else{
        printf("The scenario1 test failed \n");
    }
    if (scenario2()){
        printf("The scenario2 test passed \n");
    }else{
        printf("The scenario2 test failed \n");
    }
    if (scenario3()){
        printf("The scenario3 test passed \n");
    }else{
        printf("The scenario3 test failed \n");
    }


}

bool testFamily(){
    //create a family test
    Family testFamily(20);
    assert((testFamily.family.size() == 20) &&
           "the constructor parametrised family is returning the incorrect amount of member");
    Family testFamily2;
    assert((testFamily2.family.size() == 100) &&
           "the constructor unparametrised family is returning the incorrect amount of member (100)");

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
    assert((result1 == 0) && "The first cloth was not added \n");

    int result2 = objWardrobe->addClothToWardrobe(*testCloth2);
    assert((result2 == -1) && "The second cloth cannot be added: Scenario 1 passed \n");

    return true;
}

bool scenario2(){
    //create a wardrobe test
    WardRobe* objWardrobe = new WardRobe();
    Family testFamily(20);
    Cloth *testCloth1 = new Cloth("test1",testFamily.getRandMember().getId());

    objWardrobe->addClothToWardrobe(*testCloth1);

    //add the bag of every family member into the wardrobe
    std::thread th1(&WardRobe::popClothName,objWardrobe,testCloth1->name);
    printf("The cloth is popped out of the wardrobe with this thread \n");
    std::thread th2(&WardRobe::popClothName,objWardrobe,testCloth1->name);
    printf("The cloth is popped a second time with with this thread \n");

    th1.join();
    th2.join();

    assert((objWardrobe->getAmount("test1")==0) && "The cloth is in the wardrobe: Scenario 2 failed \n");
    return true;
}

bool scenario3(){
    //create a wardrobe test
    WardRobe* objWardrobe = new WardRobe();
    Family testFamily(20);
    Cloth *testCloth1 = new Cloth("test1",testFamily.getRandMember().getId());

    //add the bag of every family member into the wardrobe
    std::thread th2(&WardRobe::addClothToWardrobe,objWardrobe,*testCloth1);
    printf("The cloth is added to the wardrobe with this thread");
    std::thread th1(&WardRobe::popClothName,objWardrobe,testCloth1->name);
    printf("The cloth is poped out with this thread \n");

    th2.join();
    th1.join();
    assert((objWardrobe->getAmount("test1")==0) && "The cloth is in the wardrobe as expected: Scenario 3 failed \n");
    return true;
}
