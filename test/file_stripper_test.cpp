//
// Created by L081754 on 6/07/2017.
//
#include "gtest/gtest.h"
#include <windows.h>
#include <tchar.h>
#include <fstream>
#include <file_stripper.h>

using namespace std;


void strip_string_test(string input, const bool columns_to_keep[],
                       int size_of_columns_to_keep, int last_index, string expected) {
    std::vector<bool> v(columns_to_keep, columns_to_keep + size_of_columns_to_keep);
    string result = strip_string(input, v, last_index);
    ASSERT_EQ(expected, result);
}

TEST (strip_string, all) {
    strip_string_test("x,y,z", new bool[3]{true, false, true}, 3, 2, "x,z");
    strip_string_test("x,y,", new bool[3]{true, false, true}, 3, 2, "x,");
    strip_string_test("x,,z", new bool[3]{true, false, true}, 3, 2, "x,z");
    strip_string_test("x,y,z,a", new bool[4]{true, false, false, false}, 4, 0, "x");
    strip_string_test("x,y,z,a", new bool[4]{true, false, true, false}, 4, 2, "x,z");
}


string strip_cols_test(string name, const bool columns_to_keep[],
                       int size_of_columns_to_keep) {

    std::vector<bool> v(columns_to_keep, columns_to_keep + size_of_columns_to_keep);

    TCHAR full_path[MAX_PATH];
    string relative_path = "../test/resources/" + name;
    GetFullPathName(_T(relative_path.c_str()), MAX_PATH, full_path, NULL);
    string out_file = generate_stripped_file(full_path, v);

    return out_file;
}

void assert_file_contains(string stripped_file_name, string expected_line) {
    ifstream infile(stripped_file_name.c_str());
    string next_line;
    while (infile >> next_line) {
        if (next_line == expected_line) {
            return;
        }
    }
    cerr << "Could not find " << expected_line << endl;
    FAIL();
}


TEST(strip_file, both_cols) {

    bool columns_to_keep[5] = {true, true, true, false, false};
    string stripped_file = strip_cols_test("both_cols_populated.csv", columns_to_keep, 5);

    assert_file_contains(stripped_file, "key,keep1_11,keep1_14");
    assert_file_contains(stripped_file, "x,11,14");
    assert_file_contains(stripped_file, "y,11,14");
    assert_file_contains(stripped_file, "z,11,14");

}
