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

class CookingRecipieTemplate: public Visitor {
protected: 
    std::string recipie; 
    std::string ingredients;

public: 
  CookingRecipieTemplate(std::string recipie,std::string ingredients):recipie(recipie),ingredients(ingredients){};

  std::string boilIngredients() {
    return "Boiling ingredients for the receipie: " + recipie + "\n"; 
  }

  virtual std::string addSpecificIngredients() {
    return "Adding" +  ingredients + " to the recepie: " + recipie  + "\n\n"; 
  }

  std::string washIngredients() {
    return "Washing the ingredients for the recepie: " + recipie + "\n"; 
  }

  std::string startCooking() {
    return washIngredients() + boilIngredients() + addSpecificIngredients(); 
  }

  void handlePerson(std::string personName) override {
      std::cout << "Cooking " << recipie << " for " << personName << " with " << ingredients << std::endl;
      std::cout << startCooking();
  }

};

class SaladRecipie : public CookingRecipieTemplate {

  public:  
    SaladRecipie(std::string recepieName,std::string ingredients):CookingRecipieTemplate(recepieName,ingredients){};

    std::string addSpecificIngredients() override {
       return "Adding " +  ingredients + " to the recepie \n\n"; 
    }

    void handlePerson(std::string personName) override {
      std::cout << "Cooking " << recipie << " for " << personName << " with " << ingredients << std::endl;
      std::cout << startCooking();
  }
};
