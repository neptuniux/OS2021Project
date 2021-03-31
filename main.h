//
// Created by Daniel on 17/03/2021.
//

#ifndef OS2021PROJECT_MAIN_H
#define OS2021PROJECT_MAIN_H

struct cloth{
    std::string name;
    int id;
    int ownerID;
    time_t created;
    time_t lastUsed;
};

struct member{
    int id;
    std::string firstname;
    std::string lastname;
    std::vector<cloth> bag;
};

#endif //OS2021PROJECT_MAIN_H
