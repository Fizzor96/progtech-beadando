#include "pch.h"


struct BankAccount
{
	int balance;

	BankAccount()
	{
		balance = 0;
	}

	BankAccount(const int balance)
	{
		this->balance = balance;
	}
};


TEST(TestCaseName, TestName) {
	BankAccount acc;
	EXPECT_EQ(1, acc.balance);
	//EXPECT_TRUE(true);
}

int main(int argc, char* argv[]) 
{
	testing::InitGoogleTest(&argc, argv);
	RUN_ALL_TESTS();
	system("pause");
	return 0;
}