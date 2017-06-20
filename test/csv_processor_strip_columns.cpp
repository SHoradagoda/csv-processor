#include "gtest/gtest.h"
#include "example.h"
#include <iostream>
#include "csv_processor.h"

using namespace std;

TEST(example, divide)
{
    double res;
    res = subtract_numbers(1.0, 2.0);
    ASSERT_NEAR(res, -1.0, 1.0e-11);
}

