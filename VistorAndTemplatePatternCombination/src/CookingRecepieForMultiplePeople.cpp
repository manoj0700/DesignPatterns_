#include <CookingRecepieForMultiplePeople.hpp>

// This pattern is helping to create different implementations for the person class. Its combination of the 
// Visitor pattern and the template pattern. Recepie related classes are made following the template 
// pattern, and the Person class accepts the visitor and uses the implementation without creating 
// any specific methods within the person class. This is ensuring that person class is not
// loaded with unecessary functions which are not related. 

int main() {
    Person person1("Apoorva");
    Person person2("Manoj");

    person1.accept(new SaladRecipe("Russian Salad", "Brocoli,tamato,cauliflower"));
    person2.accept(new SaladRecipe("Russian Salad", "Brocoli,tamato,cauliflower"));
}