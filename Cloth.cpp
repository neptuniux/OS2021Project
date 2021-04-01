//
// Created by Daniel on 01/04/2021.
//

#include "Cloth.h"
#include <ctime>
#include "randomString.h"

Cloth::Cloth(const std::string &name, int ownerId) :    name(name),
                                                        id(rand()%10000),
                                                        ownerID(ownerId),
                                                        created(time(0)),
                                                        lastUsed(0)
                                                        {}

Cloth::Cloth(int ownerId) :name(printstring(5)),
                id(rand()%10000),
                ownerID(ownerId),
                created(time(0)),
                lastUsed(0)
{}
