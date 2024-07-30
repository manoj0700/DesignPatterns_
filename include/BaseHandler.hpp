
// StandardFormat check 
// Length Validatoin 
// Special Character Vvalidation
#include <iostream>
using namespace std;

class BaseHandler {
	public: 
	     
		 BaseHandler() {};
		 virtual ~BaseHandler() {};

	     virtual void Handle(std::string &email) {};
		 virtual BaseHandler* nextHander() {};

	private: 
	   std::string email;	 	    
};