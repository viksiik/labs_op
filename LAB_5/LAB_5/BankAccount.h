#pragma once
#pragma warning(disable: 4996)
#include<iostream>
#include<string>
#include<ctime>

using namespace std;

class BankAccount {
protected:
	string bank_name;
	string account_number;
	bool status;
	float balance;
public:
	void addCost(float sum);
	void withdrawCost(float sum);
	BankAccount(string bank_name, string account_number);
	virtual void showInfo();
	float getBalance();
	bool getStatus();
	
};


class DepositAccount : public BankAccount {
private:
	string openDate;
	int period;
	float rate;
public:
	DepositAccount(string bank_name, string account_number, int period, double interest_rate, string openDate);
	void showInfo() override;
	float addInterest();
	void closeAccount();
	bool is_matured();
	string getDate();
	int getPeriod();
	float getRate();
};

class CurrentAccount : public BankAccount {
private:
	time_t lastDate;
public:
	CurrentAccount(string bank_name, string account_number);
	void showInfo() override;
	void addCost(float sum);
	float getBalance();
};


void depositToCard(DepositAccount& depositAccount, BankAccount& card);
