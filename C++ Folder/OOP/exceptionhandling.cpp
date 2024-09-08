#include <iostream>

void functionB() {
    try {
        throw "An error occurred in functionB";  // Throw an exception
    }
    catch (const char* msg) {
        std::cout << "Caught in functionB: " << msg << std::endl;
        throw;  // Rethrow the same exception
    }
}

void functionA() {
    try {
        functionB();
    }
    catch (const char* msg) {
        std::cout << "Caught in functionA: " << msg << std::endl;
    }
}

int main() {
    functionA();
    return 0;
}
