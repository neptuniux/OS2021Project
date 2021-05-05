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
    Member(std::string firstname, std::string lastname);

    Member();

    int addClohToBag(const Cloth &cloth);

    [[nodiscard]] int getId() const;

    [[nodiscard]] const std::string &getFirstname() const;

    [[nodiscard]] const std::string &getLastname() const;

    [[nodiscard]] const std::vector<Cloth> &getBag() const;

    void cleanbag();

};


#endif //OS2021PROJECT_MEMBER_H
