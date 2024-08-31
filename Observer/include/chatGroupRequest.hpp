#include <iostream>


enum AdminRequestType {
	PUBLISH_MESSAGE,
	GET_SUBSCRIBER_LIST,
	REMOVE_USER
};


class ChatGroupRequest {
    public: 
    virtual void executeChatGroupRequest(){};
};

class AdminRequest : public ChatGroupRequest {

    AdminRequestType m_requestType;
    Publisher *m_chatGroup;
    std::string m_message; 
    std::string m_userName;

    public: 
    AdminRequest(AdminRequestType adminRequestType,const std::string& message,Publisher* chatGroup):m_requestType(adminRequestType),m_message(message),m_chatGroup(chatGroup){

         if(adminRequestType != AdminRequestType::PUBLISH_MESSAGE) {
            throw std::invalid_argument("Invalid action for the constructor");
         }
    };

    AdminRequest(AdminRequestType adminRequestType,Publisher* chatGroup):m_requestType(adminRequestType),m_chatGroup(chatGroup){

        if(adminRequestType != AdminRequestType::GET_SUBSCRIBER_LIST) {

        throw std::invalid_argument("Invalid action for the constructor");
    
        }
    };

    // AdminRequest(AdminRequestType adminRequestType = AdminRequestType::REMOVE_USER,const std::string& userName,Publisher* chatGroup):m_requestType(adminRequestType),m_userName(userName),m_chatGroup(chatGroup){

    //     if(adminRequestType != AdminRequestType::REMOVE_USER) {

    //     throw std::invalid_argument("Invalid action for the constructor");

    //     }
    // };

    void executeChatGroupRequest() {

        if(m_requestType == AdminRequestType::PUBLISH_MESSAGE) {
            m_chatGroup->sendMessage(m_message);
        }

        if(m_requestType == AdminRequestType::GET_SUBSCRIBER_LIST) {
           std::vector<Subscriber*> subscriberList =  m_chatGroup->getSubscriberList();
           std::cout << std::endl << std::endl << "Below is the list of Subscribers :" << std::endl;
           for (auto subscriber: subscriberList) {
               std::cout << subscriber->getSubcriberName() << std::endl;
           }

        }

    }
};


class InvokeRequest {
    ChatGroupRequest* m_chatGroupRequest;
    public: 
      InvokeRequest(ChatGroupRequest* chatGroupRequest):m_chatGroupRequest(chatGroupRequest){}
      void execute(){
          m_chatGroupRequest->executeChatGroupRequest();
      }
};
