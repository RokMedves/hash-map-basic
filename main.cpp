#include <iostream>
#include "hash-map.hh"


int main(){

    std::cout << "works" << std::endl;
    HashMap<double> dict;

    dict["3"] = 3.4;
    dict["2"] = 2.2;
    dict["4"] = 11;
    std::cout << dict << std::endl;

    return 0;
}
