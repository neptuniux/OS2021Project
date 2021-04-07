//
// Created by Daniel on 01/04/2021.
//

#include "../headersFiles/Cloth.h"
#include <ctime>
#include <utility>
#include "../headersFiles/randomString.h"

Cloth::Cloth(std::string name, int ownerId) :    name(std::move(name)),
                                                        id(rand()%10000),
                                                        ownerID(ownerId),
                                                        created(time(0)),
                                                        lastUsed(time(0))
                                                        {}

Cloth::Cloth(int ownerId) :name(printstring(5)),
                id(rand()%10000),
                ownerID(ownerId),
                created(time(0)),
                lastUsed(time(0))
{}

void Cloth::updateUseDate(){
    lastUsed = time(0);
}
