//
// Created by Daniel on 01/04/2021.
//

#include "Member.h"
#include "randomString.h"

Member::Member(const std::string &firstname, const std::string &lastname) : firstname(firstname), lastname(lastname), id(rand()),bag() {}

Member::Member(void): firstname(printstring(5)), lastname(printstring(5)), id(rand()),bag() {}

int Member::getId() const {
    return id;
}

const std::string &Member::getFirstname() const {
    return firstname;
}

const std::string &Member::getLastname() const {
    return lastname;
}

const std::vector<Cloth> &Member::getBag() const {
    return bag;
}

void Member::addClohToBag(Cloth cloth){
    Member::bag.push_back(cloth);
}

void  Member::cleanbag() {
    bag.clear();
}