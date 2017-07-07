//
// Created by Siddath Horadagoda on 20/06/2017.
//

#include <fstream>
#include <iostream>
#include <sys/stat.h>
#include <vector>
#include "empty_column_finder.h"
#include "file_stripper.h"


using namespace std;


bool file_exists(char *file_name) {

    struct stat buffer;
    return (stat(file_name, &buffer) == 0);

}

int strip_columns(char *file_name) {

    try {
        vector<bool> emptyCols = find_empty_columns(file_name);

        generate_stripped_file(file_name, emptyCols);

        return 0;
    } catch ( exception e ) {
        cout << e.what() << endl;
        return 1;
    }
}



int main(int num_args, char *arg[]) {

    if (num_args != 1) {
        cerr << "Usage csv_processor.exe <file_name> " << endl;
        return 1;
    }

    if (!file_exists(arg[0])) {
        cerr << "File " << arg[0] << " does not exist" << endl;
        return 1;

    }
    return strip_columns(arg[0]);

}


