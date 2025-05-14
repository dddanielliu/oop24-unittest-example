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

TEST(Calculator, Sub) {
    Calculator C;
    EXPECT_EQ(C.Sub(3, 1), 2);
}

TEST(Calculator, Multiply) {
    Calculator C;
    EXPECT_EQ(C.Multiply(2, 3), 6);
}


int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
