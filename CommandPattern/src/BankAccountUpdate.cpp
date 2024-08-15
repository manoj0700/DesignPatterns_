#include <BankAccountUpdate.hpp>
#include <string>
#include <iostream>

// Concrete class methods that performs actual implementation 
void BankAccountUpdate::addMoneytoAccount(long accountNumber,long money){
    std::cout << "Succesfully Added " << money << " to the account : " << accountNumber << std::endl;
}


void BankAccountUpdate::deductMoneyfromAccount(long accountNumber,long money){

 std::cout << "Succesfully Deducted " << money << "to the account : " << accountNumber << std::endl;
	
}


void BankAccountUpdate::transferMoneyFromAccount(long accountNumber,long money){

	    std::cout << "Succesfully Transferred " << money << "to the account : " << accountNumber << std::endl;
	
}