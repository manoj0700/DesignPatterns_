#include <iostream>

/*
   Subscriber need to subscribe to a publisher
   a publisher needs to notify the subscriber 
*/

class Publisher; 

class Subscriber { 

public:
     virtual void notify(Publisher* publisher, const std::string& message) = 0;
     virtual void subscribe(Publisher* publisher) = 0;  // Ensure that we do not instantiate any objects of this class
     std::string getSubcriberName() {
      return m_subcriberName;
     }
     Subscriber(const std::string& subscriberName):m_subcriberName(subscriberName){};
     ~Subscriber(){};

private: 
   std::string m_subcriberName;
};