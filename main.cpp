
#include "headersFiles/main.h"
#include "headersFiles/Family.h"
#include "headersFiles/WardRobe.h"
#include <QApplication>
#include "gui/mainwindows.h"


using namespace std;

// uncomment to disable assert()
//#define NDEBUG

/**
 * This project has the following proprieties
 * 1)Team Youth (smallest bag first)
 * 2)Team The unused should go (least used should go)
 * additional feature: to be determined, html interface
 * @param argc
 * @param argv
 * @return
 */

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    mainWindows w;
    w.show();
    return a.exec();


    //create a family test
    Family testFamily(20);
    assert((testFamily.family.size() == 20) &&
           "the constructor parametrised family is returning the correct amount of member");
    Family testFamily2;
    assert((testFamily2.family.size() == 100) &&
           "the constructor unparametrised family is returning the correct amount of member (100)");


    //create a wardrobe test
    WardRobe objWardrobe;

    //send the family shopping
    testFamily.goShopping(10);
    testFamily.goShopping();

    //add the bag of every family member into the wardrobe
    objWardrobe.addFamBagsToWardrobe(testFamily);


    //artificially use randoms cloths
    for (int i = 0; i < 100; ++i) {
        objWardrobe.useRandomCloth();
        sleep(1);
    }



    //clean the wardrobe
    objWardrobe.cleanWardrobe();

    return 0;
}

