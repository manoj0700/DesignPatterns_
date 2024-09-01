#include <iostream> 

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