# include "../gtest/gtest.h"
# include "../Bank.hpp"

class BankTests : public ::testing::Test {
    protected:
        void SetUp() override {

        }
};

TEST_F(BankTests, WhenCreateBanks_IdNeverShouldBeTheSame) {
    // Arrange & Act
    Bank bankOne = Bank("bank One", 200);
    Bank bankTwo = Bank("bank Two", 400);
    Bank bankThree = Bank("bank Three", 1200);

    // Assert
    EXPECT_EQ(1, bankOne.GetBankId());
    EXPECT_EQ(2, bankTwo.GetBankId());
    EXPECT_EQ(3, bankThree.GetBankId());
}

TEST_F(BankTests, CreateAccounts_AccountIdNeverShouldBeTheSame_WhenIsTheSameBankAndAnotherBank) {
    // Arrange
    Bank bankOne = Bank("NuBank", 100000);
    Bank bankTwo = Bank("Itau", 100000);

    // Act & Assert
    EXPECT_EQ(100001, bankOne.OpenAccount("UserBankOne_1", 100));
    EXPECT_EQ(100001, bankTwo.OpenAccount("UserBankTwo_1", 100));
    EXPECT_EQ(100002, bankOne.OpenAccount("UserBankOne_2", 100));
    EXPECT_EQ(100002, bankTwo.OpenAccount("UserBankTwo_2", 100));
    EXPECT_EQ(100003, bankTwo.OpenAccount("UserBankTwo_3", 100));
    EXPECT_EQ(100003, bankOne.OpenAccount("UserBankOne_3", 100));
}

TEST_F(BankTests, WhenCreateAccount_the_banks_liquidity_increases_by_5_percent_of_the_amount_deposited) {
    // Arrange
    Bank bankOne = Bank("NuBank", 1000);

    // Act & Assert
    bankOne.OpenAccount("UserBankOne_1", 100);
    EXPECT_EQ(1005, bankOne.GetBankLiquidity());
    bankOne.OpenAccount("UserBankOne_2", 100);
    EXPECT_EQ(1010, bankOne.GetBankLiquidity());
    bankOne.OpenAccount("UserBankOne_3", 100);
    EXPECT_EQ(1015, bankOne.GetBankLiquidity());
}

TEST_F(BankTests, WhenCreateAccount_the_banks_liquidity_increases_by_5_percent_of_the_amount_deposited_when_value_is_not_ZERO) {
    // Arrange
    Bank bankOne = Bank("NuBank", 1000);

    // Act & Assert
    bankOne.OpenAccount("UserBankOne_1");
    EXPECT_EQ(1000, bankOne.GetBankLiquidity());
    bankOne.OpenAccount("UserBankOne_2", 100);
    EXPECT_EQ(1005, bankOne.GetBankLiquidity());
    bankOne.OpenAccount("UserBankOne_3");
    EXPECT_EQ(1005, bankOne.GetBankLiquidity());
}

int main(int argc, char **argv) {
    // Setup
	::testing::InitGoogleTest(&argc, argv);

    // Run
	int num = RUN_ALL_TESTS();

    // Clean
    return num;
}