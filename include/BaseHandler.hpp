
// StandardFormat check 
// Length Validation
// Special Character Vvalidation
#include <iostream>
using namespace std;

class BaseHandler {
	public: 
		BaseHandler() : nextHandler(nullptr) {}	
		virtual ~BaseHandler() {};

		virtual std::string Handle(std::string &email) {
			if (nextHandler) {
				return nextHandler->Handle(email);
			}
			return "Success";
		}

		void SetNextHandler(BaseHandler* nextHandler) {
			this->nextHandler = nextHandler;
		}

	private: 
		BaseHandler* nextHandler; 	    
};