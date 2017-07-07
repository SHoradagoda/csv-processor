//
// Created by L081754 on 23/06/2017.
//

#include <fstream>
#include "empty_column_finder.h"
#include "utils.h"
#include <algorithm>
#include <iostream>

void remove_cols_with_data(ifstream &infile,
                           vector<int> &columns_with_no_data);

vector<bool> construct_column_details(
        unsigned int number_of_columns,
        std::vector<int> columns_with_no_data) ;

vector<bool> find_empty_columns (char* file_name ){

    // Read file
    ifstream infile(file_name);
    string nextLine;
    infile >> nextLine;

    vector<int> columns_with_no_data = initialize_columns_with_no_data(nextLine);
    int number_of_cols = split(nextLine).size();

    remove_cols_with_data(infile, columns_with_no_data);

    return construct_column_details(
            number_of_cols,
            columns_with_no_data);

}



vector<int> initialize_columns_with_no_data(string header) {
    vector<int> columns_with_no_data;
    vector<string> header_vec = split ( header );
    for (int i=0;i<header_vec.size();i++) {
        if ( header_vec.at(i).find("_11")  != -1 ) {
            columns_with_no_data.push_back(i);
        }
    };
    return columns_with_no_data;
}

vector<bool> construct_column_details(
        unsigned int number_of_columns,
        std::vector<int> columns_with_no_data) {

    std::vector<bool> result;

    if (columns_with_no_data.empty()) {
        return result;
    }

    for (int i = 0; i < number_of_columns; i++) {

        if  ( std::find( columns_with_no_data.begin(),
                         columns_with_no_data.end(), i)
              != columns_with_no_data.end()) {

            result.push_back(false);
            result.push_back(false);
            i++;
        }
        else {
            result.push_back(true);
        }

    }

    return result;

}

void remove_cols_with_data(ifstream &infile,
                           vector<int> &columns_with_no_data) {
    string nextLine;
    while (infile >> nextLine) {

        vector<string> elems = split(nextLine);

        for (vector<int>::iterator it = columns_with_no_data.begin();
             it != columns_with_no_data.end();) {

            /*cout<< nextLine << " : " << elems[*it] << " " << elems[*it+1] << endl;
            if ( columns_with_no_data.end() == it +1) {
                cout << "END 2";
            }*/
            // If V11 value is empty or V14 value is empty
            if (!elems[*it].empty() || (columns_with_no_data.end() != it +1 && !elems[*it +1].empty())) {

                //Then this is not a column with no data, so remove this element
                columns_with_no_data.erase(it);

                if (columns_with_no_data.empty()) {
                    return;
                }

            } else {
                ++it;
            }

        }
    }
}