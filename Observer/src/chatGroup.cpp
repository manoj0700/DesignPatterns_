#include <iostream> 
#include <subscriber.hpp>
#include <publisher.hpp>

class GroupMember: public Subscriber {

public: 
   void subscribe(Publisher &publisher) override {
         std::cout << this->getSubcriberName() << " Successfully Subscribed to the Group: " << publisher.getPublisherName() << std::endl;
         publisher.addSubcribertoList(this);
   }

   void notify(Publisher* publisher, const std::string & message) override {
      std::cout << "Message received from "<< publisher->getPublisherName() <<" to " << this->getSubcriberName() << ": " << message << std::endl;
   }

   // Explicitly call the Parent constructor 
   GroupMember(const std::string& subscriberName):Subscriber(subscriberName){};

};


class GroupAdmin: public Subscriber {

};


class FriendsGroup: public Publisher {

public:

      void sendMessage(const std::string& message) override {

            if(validateMessage(message)){
             for(auto subscriber: getSubscriberList()) {
                  subscriber->notify(this,message);
             }
            } else {
                  std::cout << "Please send message again .. " << std::endl;
            }
      }

      FriendsGroup(const std::string& groupName):Publisher(groupName){};

};

int main () {

      GroupMember member1("Apoorva");
      GroupMember member2("Aradhya");

      FriendsGroup group1("Masti Group");

     // Member1 & member 2 subscribes to the Group1 i.e Masti Group
      member1.subscribe(group1);
      member2.subscribe(group1);

      group1.sendMessage("Hey Budyy");

}