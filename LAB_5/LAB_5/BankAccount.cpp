#include "BankAccount.h"

BankAccount::BankAccount(string bank_name, string account_number)
	: bank_name(bank_name), account_number(account_number), status("active"), balance(0.0) {}


void BankAccount::addCost(float sum) {
	balance += sum;
}

void BankAccount::withdrawCost(float sum) {
	balance -= sum;
}

bool BankAccount::getStatus() {
	return status;
}

float BankAccount::getBalance() {
	return balance;
}

void BankAccount::showInfo() {
	cout << "Bank name: " << bank_name << endl;
	cout << "Account number: " << account_number << endl;
	cout << "Balance: " << balance << endl;
	cout << "Status of card: " << status << endl;
}




DepositAccount::DepositAccount(string bank_name, string account_number, int period, double rate, string openDate)
	: BankAccount(bank_name, account_number), period(period), rate(rate), openDate(openDate) {}

void DepositAccount::closeAccount() {
	status = false;
	double total_amount = balance + addInterest();
	balance = 0.0;
	cout << "Account closed.\n";
}

void DepositAccount::showInfo() {
	cout << "---DEPOSIT ACCOUNT---" << endl;
	cout << "Open date:             " << openDate << endl;
	cout << "Period:                " << period << "  months\n";
	cout << "Rate:                  " << rate << " %\n";
	if (status){
    cout << "Status:                active" << endl;
		}
	else {
		cout << "Status:                inactive" << endl;
	}
}

bool DepositAccount::is_matured() {
	time_t now;
	time(&now);

	struct tm timeInfo = { 0 };
	int year, month, day;
	sscanf(openDate.c_str(), "%d.%d.%d", &day, &month, &year);
	timeInfo.tm_year = year - 1900;
	timeInfo.tm_mon = month - 1;
	timeInfo.tm_year = year - 1900;
	time_t openTime = mktime(&timeInfo);

	if (openTime > now) {
		return false;
	}
	else {
		return true;
	}
}

float DepositAccount::addInterest() {
	return balance * rate / 100;
}

string DepositAccount::getDate() {
	return openDate;
}

int DepositAccount::getPeriod() {
	return period;
}

float DepositAccount::getRate() {
	return rate;
}




CurrentAccount::CurrentAccount(string bank_name, string account_number)
	: BankAccount(bank_name, account_number) {
	time(&lastDate);
}

void CurrentAccount::showInfo() {
	cout << "---CURRENT ACCOUNT---" << endl;
	cout << "Last operation`s date: " << ctime(&lastDate);
	cout << "Balance:               " << balance << "  grn\n\n\n";
}

void CurrentAccount::addCost(float sum) {
	this->balance += sum;
	time(&lastDate);
}

float CurrentAccount::getBalance() {
	return this->balance;
}


void depositToCard(DepositAccount& depositAccount, BankAccount& card) {
	if (!depositAccount.is_matured()) {
		cout << "Deposit has not matured yet. Cannot deposit to card." << endl;
		return;
	}

	float interest = depositAccount.addInterest();
	float total_amount = depositAccount.getBalance() + interest;

	if (total_amount > card.getBalance()) {
		cout << "Card balance is not enough to receive the deposit." << endl;
		return;
	}

	depositAccount.withdrawCost(total_amount);
	card.addCost(total_amount);

	depositAccount.closeAccount();

	cout << "Deposit successfully transferred to card." << endl;
}
