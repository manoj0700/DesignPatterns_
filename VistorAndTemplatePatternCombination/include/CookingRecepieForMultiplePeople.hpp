#include <iostream>

class Visitor {
public:
    virtual void handlePerson(std::string personName) = 0;
};

class Person {
std::string personName; 
public: 
    Person(std::string personName):personName(personName){};
    void accept(Visitor* visitor){
        visitor->handlePerson(personName);
    }

};

class CookingRecipeTemplate: public Visitor {
protected: 
    std::string recipe; 
    std::string ingredients;

public: 
  CookingRecipeTemplate(std::string recipie,std::string ingredients):recipe(recipe),ingredients(ingredients){};

  std::string boilIngredients() {
    return "Boiling ingredients for the receipie: " + recipe + "\n"; 
  }

  virtual std::string addSpecificIngredients() {
    return "Adding" +  ingredients + " to the recepie: " + recipe  + "\n\n"; 
  }

  std::string washIngredients() {
    return "Washing the ingredients for the recepie: " + recipe + "\n"; 
  }

  std::string startCooking() {
    return washIngredients() + boilIngredients() + addSpecificIngredients(); 
  }

  void handlePerson(std::string personName) override {
      std::cout << "Cooking " << recipe << " for " << personName << " with " << ingredients << std::endl;
      std::cout << startCooking();
  }

};

class SaladRecipe : public CookingRecipeTemplate {

  public:  
    SaladRecipe(std::string recepieName,std::string ingredients):CookingRecipeTemplate(recepieName,ingredients){};

    std::string addSpecificIngredients() override {
       return "Adding " +  ingredients + " to the recepie \n\n"; 
    }

    void handlePerson(std::string personName) override {
      std::cout << "Cooking " << recipe << " for " << personName << " with " << ingredients << std::endl;
      std::cout << startCooking();
  }
};
