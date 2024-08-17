
#include <BankAccountUpdate.hpp>
#include <iostream>

enum BankRequestType {
	ADD_MONEY,
	DEDUCT_MONEY,
	TRANFER_MONEY
};

// Command Interface

class UserRequestExecution {

	public:
		 virtual ~UserRequestExecution(){};
     	 virtual void executeUserRequest(){};

};

// Concrete class which implements command interface
class MoneyUpdateRequest:public UserRequestExecution {
	long m_accountNumber;
	long m_money;
	BankRequestType m_bankRequestType;
	BankAccountUpdate *m_bankAccountUpdate;
public:
    MoneyUpdateRequest(long accountNumber,long money,BankRequestType bankRequestType,BankAccountUpdate *bankAccountUpdate) {
		m_accountNumber = accountNumber;
		m_money = money;
		m_bankRequestType = bankRequestType;
		m_bankAccountUpdate = bankAccountUpdate;
	}

	void executeUserRequest() override {
		if (m_bankRequestType == ADD_MONEY) {
			m_bankAccountUpdate->addMoneytoAccount(m_accountNumber,m_money);
		}
		else { 
			std::cout << "Currently Bank Do not support the request " << std::endl;
		}
	}
};

// Invoker class that is responsibile to perform a user request and it decouples the main implemention class from the
// Client

class InitiateRequest {
	UserRequestExecution *m_UserRequestExecution;

public:
	InitiateRequest(UserRequestExecution *userRequestExecution):m_UserRequestExecution(userRequestExecution){};
	void execute() {
          m_UserRequestExecution->executeUserRequest();
	}
};


// Client which is completely decoupled from the actual implementation 
int main() {

	BankAccountUpdate *bankUpdateRequest = new BankAccountUpdate();

	MoneyUpdateRequest moneyUpdateRequest(123,123,BankRequestType::ADD_MONEY,bankUpdateRequest);

    InitiateRequest *initiateRequest = new InitiateRequest(&moneyUpdateRequest);

	initiateRequest->execute();

	return 0;
}
