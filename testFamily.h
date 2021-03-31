//
// Created by Daniel on 17/03/2021.
//

#ifndef OS2021PROJECT_TESTFAMILY_H
#define OS2021PROJECT_TESTFAMILY_H
#include "main.h"

member *createTestFamily(member *family);

class TestFamily {
public:
    member *family;
    TestFamily(member *family);
};
#endif //OS2021PROJECT_TESTFAMILY_H
