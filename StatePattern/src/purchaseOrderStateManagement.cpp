#include <purchaseOrderStateManagement.hpp>

int main() {

   OrderDeliveredState *delivered = new OrderDeliveredState(nullptr);
   OrderIntransitState *inTransit = new OrderIntransitState(delivered);
   OrderPurchasedState *purchased = new OrderPurchasedState(inTransit);


   Purchase* order = new Purchase("Shoes",purchased);

   order->m_currentState->executeStateJob();
   order->setNextState();

   order->m_currentState->executeStateJob();
   order->setNextState();

   order->m_currentState->executeStateJob();
   order->setNextState();


    return 0;
}

