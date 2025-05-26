#include <gtest/gtest.h>
#include "Account.h"

TEST(AccountTest, BalanceChangeThrowsIfUnlocked) {
    Account acc(1, 100);
    EXPECT_THROW(acc.ChangeBalance(50), std::runtime_error);
}

TEST(AccountTest, LockUnlockBehavior) {
    Account acc(2, 200);
    acc.Lock();
    EXPECT_THROW(acc.Lock(), std::runtime_error);
    acc.Unlock();
    acc.Lock();  
}

TEST(AccountTest, ChangeBalanceCorrectly) {
    Account acc(3, 300);
    acc.Lock();
    acc.ChangeBalance(100);
    EXPECT_EQ(acc.GetBalance(), 400);
}
