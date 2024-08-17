
#include <Collegue.hpp>

class Mediator {
	protected: 
	    std::vector<Collegue*> collegues; 
	public:
		virtual void sendMessage(std::string message, Collegue* col) = 0;
		virtual void addCollegue(Collegue* collegue) {};
};
