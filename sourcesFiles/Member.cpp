//
// Created by Daniel on 01/04/2021.
//

#include "../headersFiles/Member.h"
#include "../headersFiles/randomString.h"

Member::Member(std::string firstname, std::string lastname) : firstname(std::move(firstname)),
                                                              lastname(std::move(lastname)), id(rand()), bag() {}

Member::Member() : firstname(printstring(5)), lastname(printstring(5)), id(rand()), bag() {}

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

int Member::addClohToBag(const Cloth &cloth) {
    Member::bag.push_back(cloth);
    return 0;
}

void Member::cleanbag() {
    bag.clear();
}

