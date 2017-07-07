//
// Created by L081754 on 3/07/2017.
//


#include <string>
#include <vector>

#ifndef CSV_PROCESSOR_UTILS_H
#define CSV_PROCESSOR_UTILS_H

using namespace std;

string print_vector (vector<int> vec);


vector<string> split(const string &s);

vector<string> split(const string &s, char delim);


struct col_details {
    int col_num;
    bool include;
};


#endif //CSV_PROCESSOR_UTILS_H
