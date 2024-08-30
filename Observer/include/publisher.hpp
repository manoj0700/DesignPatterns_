#include<messageHandler.hpp>

class Publisher {

public:
   virtual void sendMessage(const std::string &message) = 0; 
   // Passing const refernce to the arguments helps in eliminating the memory copies that happens when we pass by value. its useful when dealing with 
   // Large strings. Also const modfier ensures that it provides only read-only access. 
   // since you are getting value here by reference, its recommended to have the const variable to avoid changes to the variable.
   Publisher(const std::string& publisher):m_publisherName(publisher){};
   std::string getPublisherName() {
      return m_publisherName;
   }

   void addSubcribertoList(Subscriber* subs) {
         subscriberList.push_back(subs);
   }

   std::vector<Subscriber*> getSubscriberList() {
      return subscriberList;
   }

   bool validateMessage(const std::string& message) {
      StringHandler stringHandler;
      EmptyStringValidator emptyStringValidator;
      NumberValidator numberValidator;

      stringHandler.SetNextHandler(&emptyStringValidator)->SetNextHandler(&numberValidator);

      if(stringHandler.Handle(message) == "success") {
         return true;
      } 

      return false;

      }


private: 
   std::vector<Subscriber*> subscriberList; 
   std::string m_publisherName; 
};