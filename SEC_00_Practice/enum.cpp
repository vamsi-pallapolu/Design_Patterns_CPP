#include <iostream>

enum Color{ // Unscoped enums
    RED,
    GREEN,
    BLUE
};

enum Traffic{
    // GREEN, // Names are injected into surrounding scope
    YELLOW = 2
};

// Scoped enums
enum class State{
    START,
    STOP,
    PAUSE
};

void paint(Color c){
    // Pain logic
}

int main(){
    Color c;
    // c=GREEN; // 1. Name space collision
    if(c==RED)
        std::cout << "Color is:" << c << std::endl;
    else
        std::cout << "Color is:" << c << std::endl; // 1 // 2. Implicit conversion to int

    State s = State::START; // Scoped
    if(s == State::STOP) // No implicit conversion
        std::cout << "STOP" << std::endl;
    else
        std::cout << "START" << std::endl;


    // Type Safety Example
    // paint(YELLOW);
    return 0;
}