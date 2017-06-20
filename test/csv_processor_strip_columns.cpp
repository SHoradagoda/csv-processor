#include "gtest/gtest.h"
#include <iostream>
#include "csv_processor.h"

#include <limits.h>
#include <stdlib.h>

using namespace std;

TEST(csv_proc, no_file)
{
    int stripped = strip_columns("file");
    ASSERT_EQ ( 1, stripped );
}

TEST(csv_proc, strip)
{
    char *full_path = realpath("../test/resources/simple.csv", NULL);
    int stripped = strip_columns(full_path);
    ASSERT_EQ ( 1, stripped );
}


