#include <PaymentProcessingStrategy.hpp>

enum PaymentMethod {
    UPI,
    DebitCard,
    CashOnDelivery
};

int main() {

Payment debitCardPayment(new DebitCardPaymentStrategy());
debitCardPayment.initatePayment();

Payment upiPayment(new UPIPaymentStrategy());
upiPayment.initatePayment();

return 0;
}