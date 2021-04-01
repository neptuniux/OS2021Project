//
// Created by Daniel on 01/04/2021.
//

#include "Cloth.h"
#include <ctime>

Cloth::Cloth(const std::string &name, int ownerId) :    name(name),
                                                        id(rand()%10000),
                                                        ownerID(ownerId),
                                                        created(time(0)),
                                                        lastUsed(0)
                                                        {}
