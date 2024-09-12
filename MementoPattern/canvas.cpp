#include <iostream>

class CanvasMemento{

    friend class Canvas;
    std::vector<std::string> shapes;
public:
    CanvasMemento(std::vector<std::string> shapes) : shapes(shapes) {};
};

class Canvas{
    std::vector<std::string> shapes;
    std::vector<CanvasMemento*> oldShapes;
public:
   ~Canvas() {
    for(auto ptr: oldShapes){
        delete ptr;
    }
    oldShapes.clear();
   }
    void addShape(std::string shape){
        oldShapes.push_back(new CanvasMemento(shapes));
        shapes.push_back(shape);
    }

    void clearAll(){
        shapes.clear();
    }

    void undo() {
        CanvasMemento *previousState = oldShapes.back();
        shapes = previousState->shapes;
        oldShapes.pop_back();
        delete previousState;
    }

    std::vector<std::string> getShapes() {
        return shapes;
    }
};

int main() {

    Canvas canvas; 

    canvas.addShape("Triangle");
    canvas.addShape("Rectangle");
    canvas.addShape("Circle");

    canvas.undo();

    for(std::string shape : canvas.getShapes()) {
      std::cout << shape << std::endl;
    }

    canvas.clearAll();

    for(std::string shape : canvas.getShapes()) {
      std::cout << shape << std::endl;
    }
}
