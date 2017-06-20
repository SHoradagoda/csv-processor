//
// Created by Siddath Horadagoda on 20/06/2017.
//

#include "csv_processor.h"
#include <fstream>
#include <iostream>
#include <string>
#include <sys/stat.h>

using namespace std;

int strip_columns ( string file_name ) {
    // Read file
    ifstream infile( file_name );
    struct stat buffer;
    cout  << "file exists = " << (stat (file_name.c_str(), &buffer) == 0)  << endl;

    string nextLine;
    while ( infile >> nextLine ) {
        cout << nextLine ;
    }
    return 3;
}