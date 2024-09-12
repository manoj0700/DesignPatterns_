#include <iostream>

/*
The Template Design Pattern, also known as the Template Method Pattern,
is a behavioral design pattern in C++ that defines the skeleton of an 
algorithm in a base class and allows subclasses to override specific steps 
of the algorithm without changing its overall structure. This pattern is used
 when you have multiple classes that follow the same basic steps, but some steps
may vary in implementation
*/
class CookingRecipeTemplate {
protected: 
    std::string recipie; 
    std::string ingredients;

public: 
  CookingRecipeTemplate(std::string recipie,std::string ingredients):recipie(recipie),ingredients(ingredients){};

  std::string boilIngredients() {
    return "Boiling ingredients for the receipie: " + recipie + "\n"; 
  }

  virtual std::string addSpecificIngredients () {
    return "Adding" +  ingredients + "to the recepie: " + recipie  + "\n"; 
  }

  std::string washIngredients () {
    return "Washing the ingredients for the recepie: " + recipie + "\n"; 
  }

  std::string startCooking () {
    return washIngredients() + boilIngredients() + addSpecificIngredients(); 
  }

};

class SaladRecipe : public CookingRecipeTemplate {

  public:  
    SaladRecipe(std::string recepieName,std::string ingredients):CookingRecipeTemplate(recepieName,ingredients){};

    std::string addSpecificIngredients() override {
       return "Adding " +  ingredients + " to the recepie \n"; 
    }
};




int main() {
  SaladRecipe russianSalad("Russian Salad","Tamatoe,Brocoli");
  std::cout << russianSalad.startCooking() << "\n\n";

  SaladRecipe caesarSalad("Caesar Salad","Jalepno,Brocoli,Tamato");
  std::cout << caesarSalad.startCooking() << "\n\n";
}

