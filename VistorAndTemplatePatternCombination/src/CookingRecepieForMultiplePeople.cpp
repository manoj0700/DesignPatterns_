#include <CookingRecepieForMultiplePeople.hpp>

int main() {
    Person person1("Apoorva");
    Person person2("Manoj");

    person1.accept(new SaladRecipie("Russian Salad", "Brocoli,tamato,cauliflower"));
    person2.accept(new SaladRecipie("Russian Salad", "Brocoli,tamato,cauliflower"));
}