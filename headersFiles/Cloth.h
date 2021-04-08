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

    Cloth(std::string name, int ownerId);

    explicit Cloth(int ownerId);
    void updateUseDate();

};


#endif //OS2021PROJECT_CLOTH_H
