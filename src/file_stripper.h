//
// Created by L081754 on 3/07/2017.
//

#ifndef CSV_PROCESSOR_GENERATE_STRIPPED_FILE_H
#define CSV_PROCESSOR_GENERATE_STRIPPED_FILE_H

#include <string>
#include <vector>
#include "utils.h"

using namespace std;

string strip_string ( string orig, vector<bool> keep_columns, int last_index );

string generate_stripped_file ( char* file_name, vector<bool> keep_columns );

#endif //CSV_PROCESSOR_GENERATE_STRIPPED_FILE_H
