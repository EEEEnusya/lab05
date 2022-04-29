//
// Created by yana on 29.04.2022.
//

#include <gtest/gtest.h>
#include <Transaction.h>
#include <Account.h>

TEST(Account, GetBalance){
    Account Byaka(1,300);
    EXPECT_EQ(Byaka.GetBalance(), 300);
    Account Motya(3, 239);
    Byaka.Lock();
    Byaka.ChangeBalance(-89);
    Byaka.Unlock();
    EXPECT_EQ(Byaka.GetBalance(), 211);
    Motya.Lock();
    EXPECT_THROW(Motya.Lock(), std::runtime_error);


}

TEST(Account, ChangeBalance){
    Account Molly(0, 500);
    EXPECT_THROW(Molly.ChangeBalance(90), std::runtime_error);
    Molly.Lock();
    Molly.ChangeBalance(90);
    EXPECT_EQ(Molly.GetBalance(), 590);
    Molly.ChangeBalance(-30);
    EXPECT_EQ(Molly.GetBalance(), 560);

}

TEST(Account, Lock){
    Account EEEEnusya(0, 666);
    EEEEnusya.Lock();
    EXPECT_THROW(EEEEnusya.Lock(), std::runtime_error);
    EXPECT_EQ(EEEEnusya.GetBalance(), 666);
}