//
// Created by Daniel on 01/04/2021.
//

#ifndef OS2021PROJECT_MEMBER_H
#define OS2021PROJECT_MEMBER_H


#include <string>
#include <vector>
#include "Cloth.h"

class Member {
    int id;
    std::string firstname;
    std::string lastname;
    std::vector<Cloth> bag;
public:
    Member(const std::string &firstname, const std::string &lastname);

    Member(void);

    int getId() const;

    const std::string &getFirstname() const;

    const std::string &getLastname() const;

    const std::vector<Cloth> &getBag() const;

};


#endif //OS2021PROJECT_MEMBER_H
