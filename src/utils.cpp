//
// Created by L081754 on 3/07/2017.
//

#include <sstream>
#include "utils.h"
//TEMP
string print_vector (vector<int> vec) {
    stringstream string1;
    if (vec.empty()) {
        return "";
    }
    for (vector<int>::iterator i = vec.begin(); i != vec.end(); ++i)
        string1  << *i << ' ';
    return string1.str();
}



template<typename Out>
void split(const std::string &s, char delim, Out result) {
    std::stringstream ss;
    ss.str(s);
    std::string item;
    while (std::getline(ss, item, delim)) {
        *(result++) = item;
    }
}


std::vector<std::string> split(const std::string &s) {
    return  split(s, ',');
}

std::vector<std::string> split(const std::string &s, char delim) {
    std::vector<std::string> elems;
    split(s, delim, std::back_inserter(elems));
    return elems;
}


