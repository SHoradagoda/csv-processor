//
// Created by L081754 on 23/06/2017.
//

#ifndef CSV_PROCESSOR_EMPTY_COLUMN_FINDER_H
#define CSV_PROCESSOR_EMPTY_COLUMN_FINDER_H

#include <vector>
#include "utils.h"

using namespace std;

vector<int> initialize_columns_with_no_data (string header );

vector<bool> find_empty_columns ( char* file_name );

#endif //CSV_PROCESSOR_EMPTY_COLUMN_FINDER_H
