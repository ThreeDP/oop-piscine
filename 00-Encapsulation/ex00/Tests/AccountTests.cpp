# include "../gtest/gtest.h"
# include "../Account.hpp"

class AccountTests : public ::testing::Test {
protected:
    void SetUp() override {

    }
};

TEST_F(AccountTests, CreateAccount) {
    EXPECT_EQ(5, 5);
}

int main(int argc, char **argv) {
    // Setup
	::testing::InitGoogleTest(&argc, argv);

    // Run
	int num = RUN_ALL_TESTS();

    // Clean
    return num;
}