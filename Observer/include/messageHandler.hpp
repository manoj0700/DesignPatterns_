
#include <iostream> 

class BaseHandler {

public:
   virtual std::string Handle(const std::string& message) {
        if(m_nextHandler) {
          m_nextHandler->Handle(message);
        }
        
        return "success";
    }

   BaseHandler* SetNextHandler(BaseHandler* nextHandler) {
          m_nextHandler = nextHandler;

          return m_nextHandler;
    }
  
   BaseHandler():m_nextHandler(nullptr){}

public: 

    BaseHandler* m_nextHandler; 
};


class StringHandler:public BaseHandler {
    public: 
      std::string Handle(const std::string& message) override {
           if(message.size() > 10) {
             std::cout << "Sorry you cannot send Message greater than 10 characters" << std::endl;
             return "StringValidation failed";
           }
\
           return BaseHandler::Handle(message);
      }

      StringHandler():BaseHandler(){};
};

class EmptyStringValidator:public BaseHandler {
  public:
        EmptyStringValidator():BaseHandler(){};

      std::string Handle(const std::string& message) override {
           if(message.empty()) {
             std::cout << "Sorry you cannot send empty messages in this group" << std::endl;
             return "EmptyStringValidator failed";
           }

          return BaseHandler::Handle(message);
          
      }

};


class NumberValidator:public BaseHandler {
  public:
        NumberValidator():BaseHandler(){};

      std::string Handle(const std::string& message) override {
           if(std::any_of(message.begin(), message.end(), ::isdigit)) {
             std::cout << "Sorry you cannot send Numbers in this group" << std::endl;
             return "NumberValidator failed";
           }

          return BaseHandler::Handle(message);
      }

};