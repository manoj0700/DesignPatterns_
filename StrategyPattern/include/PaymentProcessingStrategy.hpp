#include <iostream> 

/*
The Strategy Design Pattern is a behavioral design pattern that defines a family of algorithms, encapsulates each one,
 and makes them interchangeable. The strategy pattern lets the algorithm vary independently from the clients that use 
 it. It enables selecting an algorithm's behavior at runtime.*/

class PaymentGatewayStrategy {
public: 
    virtual void initiatePayment(){};
};

class DebitCardPaymentStrategy: public PaymentGatewayStrategy {

void initiatePayment(){
    std::cout <<" Performing payment through Debit card gateway" << std::endl;
}

};

class UPIPaymentStrategy: public PaymentGatewayStrategy {

void initiatePayment(){
    std::cout <<" Performing payment through UPI gateway" << std::endl;
}
};

class Payment {
    PaymentGatewayStrategy* m_paymentGatewayStrategy;

public:
    Payment(PaymentGatewayStrategy* paymentGatewayStrategy):m_paymentGatewayStrategy(paymentGatewayStrategy){};
    void initatePayment() {
        m_paymentGatewayStrategy->initiatePayment();
    }

};