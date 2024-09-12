#include <NumberIterator.hpp>
#include <iostream>

int main() {

  NumberCollection num1({1,2,3,5,6,7});

  NumberIterator* forwardIt = num1.getForwardIterator();
  NumberIterator* backwardIt = num1.getBackwardIterator();

  while(!forwardIt->isFinished()) {
     std::cout << forwardIt->next();
  }

   std::cout << std::endl << std::endl;

  while(!backwardIt->isFinished()) {
     std::cout << backwardIt->next();
  }

  delete forwardIt;
  delete backwardIt;

}

