#include <map>
#include <iostream>
#include <cassert>
#include <vector>
#include "main.h"

int main(int argc, char **argv){
    int keyTolook;
    std::map<int , cloth> m;



    std::cout << m[keyTolook].name << '\n';
    auto i = m.find(keyTolook);
    assert(i != m.end());
    std::cout << "Key: " << i->first << " Value: " << i->second.name << '\n';
    return 0;
}

