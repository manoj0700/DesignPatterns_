#include<string>
#include <vector>

class Mediator; 

class Collegue {
	protected: 
	Mediator* m_mediator;
	public:
	Collegue(Mediator* mediator):m_mediator(mediator){};
	virtual void receiveMessage(std::string message){};
};