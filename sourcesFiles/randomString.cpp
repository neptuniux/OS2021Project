//
// Created by Daniel on 17/03/2021.
//

#include <string>
#include "../headersFiles/randomString.h"

std::string printstring(int n)
{
    const int MAX_SIZE = 27;
    char letters[MAX_SIZE] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q',
                              'r','s','t','u','v','w','x',
                              'y','z', ' '};
    std::string ran = "";
    for (int i=0;i<n;i++)
        ran=ran + letters[rand() % MAX_SIZE];
    return ran;
}