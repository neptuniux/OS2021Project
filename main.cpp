
#include "headersFiles/main.h"
#include "unitTests/UnitTests.h"

#include <QApplication>
#include "gui/mainwindows.h"



using namespace std;

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
    fullTest();

    QApplication a(argc, argv);
    mainWindows w;
    w.show();
    return a.exec();

}

