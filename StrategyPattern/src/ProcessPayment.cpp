#include <PaymentProcessingStrategy.hpp>

int main() {

Payment debitCardPayment(new DebitCardPaymentStrategy());
debitCardPayment.initatePayment();

Payment upiPayment(new UPIPaymentStrategy());
upiPayment.initatePayment();

return 0;
}