#include <string>
#include <vector>
#include <iostream>
#include <Mediator.hpp>

class ConcreteMediator: public Mediator {

	public: 
	ConcreteMediator(){};

	void sendMessage(std::string message, Collegue* sender) {
        for ( auto collegue : collegues) {
			if(collegue != sender) {
                collegue->receiveMessage(message);
			}
		}
	};
	virtual void addCollegue(Collegue* collegue) {
		collegues.push_back(collegue);
	};

};

class CollegueA : public Collegue {
	public: 
	  CollegueA(Mediator* mediator):Collegue(mediator){};

	  void sendMessage(std::string message) { 
		m_mediator->sendMessage(message, this);
	  }

	void receiveMessage (std::string message) override {
         std::cout << "Received Message in CollegueA : " << message << std::endl;;
	}

};


class CollegueB : public Collegue {
	public: 
	  CollegueB(Mediator* mediator):Collegue(mediator){};

	  void sendMessage(std::string message) { 
		 m_mediator->sendMessage(message,this);
	  }

	  void receiveMessage (std::string message) override {
       std::cout << "Received Message in CollegueB : " << message << std::endl;;
	}
};

class CollegueC : public Collegue {
	public: 
	  CollegueC(Mediator* mediator):Collegue(mediator){};

	  void sendMessage(std::string message) { 
		 m_mediator->sendMessage(message,this);
	  }

	  void receiveMessage (std::string message) override {
       std::cout << "Received Message in CollegueC : " << message << std::endl;;
	}
};

int main() {

       ConcreteMediator* mediator = new ConcreteMediator();

	   CollegueA* colA = new CollegueA(mediator);
	   CollegueB* colB = new CollegueB(mediator);
	   CollegueC* colC = new CollegueC(mediator);


	   mediator->addCollegue(colA);
	   mediator->addCollegue(colB);
	   mediator->addCollegue(colC);


	   colA->sendMessage("Hello there from CollegueA");
	   colB->sendMessage("Hello there from ColleugueB");
	   colB->sendMessage("Hello there from ColleugueC");

}


