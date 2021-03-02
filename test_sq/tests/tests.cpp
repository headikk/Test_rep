#include <gtest/gtest.h>
#include "square_library.h"


TEST(sqlib_test, for_zero)
{       
        int from_lib = testspace::square(0);
        
        ASSERT_EQ(from_lib,0);

}

TEST(sqlib_test, for_five)
{       
        
        int from_lib = testspace::square(5);
        
        ASSERT_EQ(from_lib, 25);

}

TEST(sqlib_test, for_neg)
{       
        int from_lib = testspace::square(-50);
        
        ASSERT_GT(from_lib, 0);

}

int main(int argc, char* argv[])
{
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}