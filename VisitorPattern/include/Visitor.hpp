#include <iostream>

class Visitor
{
public:
    virtual void handlePerson(std::string personName) = 0;
    virtual void handlelandMark(std::string location, std::string place) = 0;
};

class DataBaseWriter : public Visitor
{
public:
   
    void handlePerson(std::string personName) override{
        std::cout << "Writing " << personName << " to Database" << std::endl;
    }

    void handlelandMark(std::string personName, std::string place) override{
        std::cout << "Writing " << personName << " " << place << " to Database" << std::endl;
    }
};

class TextFileWriter : public Visitor
{

public:
    void handlePerson(std::string personName) override{
        std::cout << "Writing " << personName << " to TextFile" << std::endl;
    }

    void handlelandMark(std::string personName, std::string place) override{
        std::cout << "Writing " << personName << " " << place << "to TextFile" << std::endl;
    }
};

class Person {
std::string personName; 
public: 
    Person(std::string personName):personName(personName){};
    void accept(Visitor* visitor){
        visitor->handlePerson(personName);
    }

};


class LandMark {
std::string location;
std::string place;

public: 
    LandMark(std::string location,std::string place):location(location),place(place){}
    void accept(Visitor* visitor){
        visitor->handlelandMark(location,place);
    }

};


