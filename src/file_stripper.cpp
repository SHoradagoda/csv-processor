//
// Created by L081754 on 3/07/2017.
//

#include "file_stripper.h"
#include "utils.h"

#include <iostream>
#include <fstream>
#include <sstream>
#include <string.h>

int find_last_index ( vector<bool> vec ) {

    int index =0;
    int last_index = 0;
    for (vector<bool>::iterator i = vec.begin(); i != vec.end(); ++i) {
        if ( *i ) {
            last_index = index;
        }
        index++;
    }

    return last_index;
}

string generate_stripped_file ( char* file_name, vector<bool> keep_columns) {


    if (keep_columns.empty() ) {
        cout << "All columns preserved";
        return file_name;
    }

    int last_index = find_last_index ( keep_columns );

    // Read file
    ifstream infile( file_name );

    char* out_file_name = strcat(file_name,".out");


    //Write to file
    remove(out_file_name);
    std::fstream fs;
    fs.open (out_file_name, std::fstream::in | std::fstream::out | std::fstream::app);



    string next_line;
    while (infile >> next_line) {
        string out = strip_string ( next_line, keep_columns , last_index) ;
//        cout << out << endl;
        fs << out << endl;
    }

    fs.close();
    return out_file_name;
}

string strip_string(string orig, vector<bool> keep_columns, int last_index) {
    std::stringstream ss, out_stream;
    ss.str(orig);
    std::string item;
    int counter  = 0;

    while (std::getline(ss, item, ',')) {
        if ( keep_columns.at(counter) ) {
            out_stream << item ;
            if (counter != last_index) {
                out_stream << ",";
            }
        }
        counter++;
    }
    return out_stream.str();
}
