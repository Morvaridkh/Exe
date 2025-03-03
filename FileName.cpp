 #include <iostream>
#include <vector>
#include<string>
using namespace std;
class BankAccount {
private:
	string AccountNumber;
	double balance;
	string owner;
	vector<string>transactionHistory;

public:
	BankAccount(string account, double b, string own) :AccountNumber(account), balance(b), owner(own) {}
	void deposit(double y)
	{
		balance += y;
		transactionHistory.push_back(to_string(y));
	}
	void withdraw(double x)
	{
		if (x > balance)
		{
			cout << "It's more than what you have!";
		}
		else
		{
			balance -= x;
		}
		transactionHistory.push_back(to_string(x));
	}
	double getBalance()const
	{
		return balance;
	}
	string getAccountNumber()
	{
		return AccountNumber;
	}
	string getOwner()
	{
		return owner;
	}
	void getHistory()
	{
		for (const auto& transaction:transactionHistory)
		{
			cout << transaction << endl;
		}
	}
	void transferFunds(BankAccount& from, BankAccount& to, double money)
	{
		from.withdraw(money);
		to.deposit(money);
	}
	friend ostream& operator<<(ostream& COUT, const BankAccount& obj)
	{
		COUT<<"\nACCOUNT NUMBER:"<< obj.AccountNumber << endl;
		COUT << "ACCOUNT OWNER:" << obj.owner << endl;
		COUT << "ACCOUNT BALANCE:" << obj.balance << endl;
		return COUT;
	}
	BankAccount& operator+=(double amount)
	{
		deposit(amount);
		return *this;
	}
	BankAccount& operator-=(double amount)
	{
		withdraw(amount);
		return *this;
	}
};
int main()
{
	BankAccount acc1("5203456210104742", 20000.0, "Jack");
	BankAccount acc2("5206859351133537", 10000.0, "Tom");
	BankAccount acc3("2523910442357280", 60000.0, "Jason");
	BankAccount acc4("5022291087233241", 9000.0, "Me");
	cout << acc1 << acc2 << acc3 << acc4;
	acc1.deposit(100.0);
	acc1.withdraw(500.0);
	cout << "\nTransaction History 1:";
	acc1.getHistory();

	acc2.deposit(600.0);
	acc2.withdraw(700.0);
	cout << "Transaction History 2:";
	acc2.getHistory();

	acc4.transferFunds(acc4, acc3, 1000.0);
	cout << "Transaction History 4:";
	acc4.getHistory();
	cout << "Transaction History 3:";
	acc3.getHistory();

	return 0;
}