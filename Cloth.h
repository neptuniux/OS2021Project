//
// Created by Daniel on 01/04/2021.
//

#ifndef OS2021PROJECT_CLOTH_H
#define OS2021PROJECT_CLOTH_H
#include <string>

class Cloth {
public:
    std::string name;
    int id;
    int ownerID;
    time_t created;
    time_t lastUsed;

    Cloth(const std::string &name, int ownerId);

    Cloth(int ownerId);

};


#endif //OS2021PROJECT_CLOTH_H
