
#include "headersFiles/main.h"
#include "headersFiles/Family.h"
#include "headersFiles/WardRobe.h"
#include "UnitTests.h"

#include <QApplication>
#include "gui/mainwindows.h"



using namespace std;

// uncomment to disable assert()
//#define NDEBUG

/**
 * This project has the following proprieties
 * 1)Team Youth (smallest bag first)
 * 2)Team The unused should go (least used should go)
 * additional feature: a QT interface
 * @param argc
 * @param argv
 * @return
 */

int main(int argc, char *argv[]) {

    QApplication a(argc, argv);
    mainWindows w;
    w.show();
    return a.exec();

}

