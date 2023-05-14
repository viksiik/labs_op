#include "BankAccount.h"


/*Створити клас "Банківський рахунок", 
який містить назву банку, номер рахунку статус(діє, закінчився) та методи додавання/зняття коштів.

На основі цього класу створити класи-нащадки "Депозитний рахунок", який додатково містить
дату його відкриття, період, ставку, суму коштів, та

"Розрахунковий рахунок", кий додатково містить дату останньої операції, залишок коштів на рахунку.

Створити n пар депозитних та розрахункових рахунків. 

В межах вказаного періоду передбачити щомісячне перерахування процентів по депозиту на відповідний
розрахунковий рахунок. 

У випадку закінчення терміну діїї депозиту, перерахувати на відповідний розрахунковий рахунок усі кошти
(разом з процентами) та закрити відповідний депозитний рахунок.*/

int main() {

	DepositAccount deposit1("My Bank", "123456", 12, 5.0, "12.12.2021");
	CurrentAccount current1("My Bank", "654321");
	deposit1.addCost(1000);
	current1.addCost(5000);
	deposit1.showInfo();
	current1.showInfo();

	depositToCard(deposit1, current1);
	deposit1.showInfo();
	current1.showInfo();


	DepositAccount deposit2("MonoBank", "363362", 11, 7.0, "23.04.2022");
	CurrentAccount current2("MonoBank", "647282");
	deposit2.addCost(2000);
	current2.addCost(3000);
	deposit2.showInfo();
	current2.showInfo();

	depositToCard(deposit2, current2);
	deposit2.showInfo();
	current2.showInfo();


	DepositAccount deposit3("PrivatBank", "647392", 9, 3.0, "05.06.2022");
	CurrentAccount current3("PrivatBank", "936637");
	deposit3.addCost(645);
	current3.addCost(1983);
	deposit3.showInfo();
	current3.showInfo();

	depositToCard(deposit3, current3);
	deposit3.showInfo();
	current3.showInfo();

	return 0;
}

