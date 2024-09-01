#include<iostream>

class State {
 State* m_nextState = nullptr;
public: 
  virtual void executeStateJob() = 0; 
  virtual void getStateDescription() = 0;
  void setNextState(State* nextState){
      m_nextState = nextState;
  }
  virtual State* getNextState() {
    return m_nextState;
  }
};

class OrderPurchasedState : public State { 

 State* m_nextState = nullptr;

public:

   OrderPurchasedState(State* nextState):m_nextState(nextState){};

    void executeStateJob() { 
        std::cout<< "Order has been placed "<< std::endl;
    }

    void getStateDescription() { 
        std::cout<< "Order currently is in Purchased state "<< std::endl;
    }

    State* getNextState() {
        return m_nextState;
    }


};

class OrderIntransitState: public State {
    State* m_nextState = nullptr;

public: 

    OrderIntransitState(State* nextState):m_nextState(nextState){};

    void executeStateJob() { 
        std::cout<< "Order is in-transit state "<< std::endl;
    }

    void getStateDescription() { 
        std::cout<< "Order currently is in Intransit state "<< std::endl;
    }

     State* getNextState() {
        return m_nextState;
    }

};

class OrderDeliveredState: public State {

    State* m_nextState = nullptr;

public: 

    OrderDeliveredState(State* nextState):m_nextState(nextState){};

    void executeStateJob() { 
        std::cout<< "Your Order is Delivered!! "<< std::endl;
    }

    void getStateDescription() { 
        std::cout<< "Order currently is in Delivered state "<< std::endl;
    }

    State* getNextState() {
        return m_nextState;
    }

};


class Purchase {

    public:
    State* m_currentState;
    std::string m_orderName; 
    Purchase(std::string orderName,State* currentState):m_currentState(currentState),m_orderName(orderName){};
    void setNextState(){
        m_currentState = m_currentState->getNextState();
    }

};