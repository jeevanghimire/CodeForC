#include <iostream>
using namespace std;

class DivisionException {
private:
    double numerator;
    double denominator;

public:
    DivisionException(double num, double denom) : numerator(num), denominator(denom) {}

    void what() {
        cout << "Error: Division by " << denominator << " with numerator " << numerator << endl;
    }
};

class Division {
private:
    double numerator;
    double denominator;

public:
    Division(double num, double denom) : numerator(num), denominator(denom) {}

    double performDivision() {
        if (denominator == 0) {
            throw DivisionException(numerator, denominator);  // Throw an object with details
        }
        return numerator / denominator;
    }
};

int main() {
    try {
        Division div(25.0, 0.0);
        cout << "Result: " << div.performDivision() << endl;
    }
    catch (DivisionException& err) {
        err.what();  // Display detailed error message
    }

    return 0;
}
