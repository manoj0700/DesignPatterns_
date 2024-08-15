#include <iostream>
#include <vector>
#include <string>
#include <BaseHandler.hpp>

using namespace std;

class StringValidation: public BaseHandler{	
public:
	StringValidation() {};
	~StringValidation() {};

	std::string Handle(std::string &email) override {

		if(email.empty() == true) {
		   return "email is empty";
		}

		std::cout<<"StringValidation completed successfully "<<std::endl;

		return BaseHandler::Handle(email);
	}

};

class NumberValidation: public BaseHandler{	

	std::string Handle(std::string &email) override{

		for (char c : email) {
			if (isdigit(c)) {
				return "Email should not contain numbers";
			}
		}

		std::cout<<"Number Validation completed successfully"<<std::endl;


		return BaseHandler::Handle(email);
	}

};

class LengthValidation: public BaseHandler{	

	std::string Handle(std::string &email) override{

		if(email.size() <= 20) {
		   return "Enter proper Email";
		}

		std::cout<<"Length Validation completed successfully"<<std::endl;


		return BaseHandler::Handle(email);
	}

};

int main(){

	StringValidation stringValidation;
	NumberValidation numberValidation;
	LengthValidation lengthVaildation;

	std::string email = "manojkumar.mr@gmail.com";

	stringValidation.SetNextHandler(&numberValidation);
	numberValidation.SetNextHandler(&lengthVaildation);

	std::cout << stringValidation.Handle(email) << std::endl;
}



