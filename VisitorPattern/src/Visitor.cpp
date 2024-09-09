#include <Visitor.hpp>

int main() {
    Person person1("Apoorva");
    Person person2("Manoj");

    LandMark landMark1("Tajmahal", "India"); 

    DataBaseWriter dbw;
    TextFileWriter tw;

    person1.accept(&dbw);
    person1.accept(&tw);

    landMark1.accept(&dbw);
}