#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "Transaction.h"
#include "Account.h"

using ::testing::_;
using ::testing::AtLeast;

class MockAccount : public Account {
public:
    MockAccount(int id, int balance) : Account(id, balance) {
        Lock(); 
    }

    MOCK_METHOD(void, ChangeBalance, (int), (override));
    MOCK_METHOD(int, GetBalance, (), (const, override));
    MOCK_METHOD(void, Lock, (), (override));
    MOCK_METHOD(void, Unlock, (), (override));
};

class MockTransaction : public Transaction {
public:
    MOCK_METHOD(void, SaveToDataBase, (Account&, Account&, int), (override));
};

TEST(TransactionTest, ThrowsOnSameAccount) {
    Account acc(1, 1000);
    Transaction tx;
    EXPECT_THROW(tx.Make(acc, acc, 100), std::logic_error);
}

TEST(TransactionTest, FailsIfTooSmallSum) {
    Account a(1, 500), b(2, 500);
    a.Lock(); b.Lock();
    Transaction tx;
    EXPECT_THROW(tx.Make(a, b, 50), std::logic_error);
}

TEST(TransactionTest, CreditAndDebitCalled) {
    Account from(1, 1000);
    Account to(2, 1000);

    MockTransaction tx;

    EXPECT_CALL(tx, SaveToDataBase(_, _, _)).Times(1);
    bool result = tx.Make(from, to, 200);
    EXPECT_TRUE(result);
}

