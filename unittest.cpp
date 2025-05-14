#include "add.h"
#include <gtest/gtest.h>


TEST(Calculator, Add) {
    Calculator C;
    EXPECT_EQ(C.Add(1, 3), 4);
}

TEST(Calculator, Add2) {
    Calculator C;
    EXPECT_EQ(C.Add(2, 3), 5);
}


int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
