//
// Created by L081754 on 3/07/2017.
//

#include "gtest/gtest.h"
#include <empty_column_finder.h>
#include <windows.h>
#include <tchar.h>

using namespace std;

void assert_cols ( bool* expected, vector<bool> cols) {
    for (int i =0;i< sizeof(expected);i++ ) {
        ASSERT_EQ(expected[i], cols.at(i));
    }
}


TEST(empty_column_finder, initialize_columns_with_no_data_one_col) {
    vector<int> columns_with_no_data = initialize_columns_with_no_data(
            "key1,key2,col_1_11,col_1_14");

    ASSERT_EQ (1, columns_with_no_data.size());
    ASSERT_EQ (2, columns_with_no_data[0]);

}


TEST(empty_column_finder, initialize_columns_with_no_data_two_cols) {
    vector<int> columns_with_no_data = initialize_columns_with_no_data(
            "key1,key2,col_1_11,col_1_14,col_2_11,col_2_14");

    ASSERT_EQ (2, columns_with_no_data.size());
    ASSERT_EQ (2, columns_with_no_data[0]);
    ASSERT_EQ (4, columns_with_no_data[1]);

}

vector<bool> find_cols_test ( string name ) {
    TCHAR full_path[MAX_PATH];
    string relative_path = "../test/resources/" + name;
    GetFullPathName(_T(relative_path.c_str()), MAX_PATH, full_path, NULL);
    return find_empty_columns(full_path);
}

TEST(find_cols, both_cols) {

    vector<bool> cols = find_cols_test("both_cols_populated.csv");
    ASSERT_EQ (5, cols.size());
    bool expected [5] =  { true,true,true,false,false };
    assert_cols ( expected, cols);
}

TEST(find_cols, only_11) {

    vector<bool> cols = find_cols_test("only_11_cols_populated.csv");
    ASSERT_EQ (5, cols.size());
    bool expected [5] =  { true,true,true,false,false };
    assert_cols ( expected, cols);

}


TEST(find_cols, only_14) {

    vector<bool> cols = find_cols_test("only_14_cols_populated.csv");
    ASSERT_EQ (5, cols.size());
    bool expected [5] =  { true,true,true,false,false };
    assert_cols ( expected, cols);

}

TEST(find_cols, three_cols) {

    vector<bool> cols = find_cols_test("three_cols.csv");
    ASSERT_EQ (7, cols.size());
    bool expected [7] =  { true,true,true,true,true,false,false };
    assert_cols ( expected, cols);

}

TEST(find_cols, all_cols) {

    vector<bool> cols = find_cols_test("all_cols_populated.csv");
    ASSERT_EQ (0, cols.size());
}

