//
// Created by Daniel on 01/04/2021.
//

#include "../headersFiles/Cloth.h"

#include "../headersFiles/randomString.h"

Cloth::Cloth(std::string name, int ownerId) : name(std::move(name)),
                                              id(rand() % 10000),
                                              ownerID(ownerId),
                                              created(time(nullptr)),
                                              lastUsed(time(nullptr)) {}

Cloth::Cloth(int ownerId) : name(printstring(5)),
                            id(rand() % 10000),
                            ownerID(ownerId),
                            created(time(nullptr)),
                            lastUsed(time(nullptr)) {}

void Cloth::updateUseDate() {
    lastUsed = time(nullptr);
}
