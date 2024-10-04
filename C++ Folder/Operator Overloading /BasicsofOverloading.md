# OPERATOR OVERLOADING

Operator overloading in C++ allows you to redefine or "overload" the meaning of an operator (like `+`, `-`, `*`, etc.) when it is used with user-defined types (like classes). It's a powerful feature that makes your custom objects behave more like built-in types.

> It is special type of function called operator function, We can use Operator Functoin to define how a certain opeation will work defiend in certain operator 


### Basic Example of Operator Overloading

Let's start with a simple example where we overload the `+` operator for a class `Point` that represents a point in 2D space:

```cpp
#include<iostream>
using namespace std;

class Point {
    private:
        int x, y;
    public:
        // Constructor
       // Point(int x = 0, int y = 0) : x(x), y(y) {}
        Point (int X , int Y){
            this->x = X;
            this->y = Y;
        }

        // Overload + operator
        Point operator + (Point& other) {
            Point result;
            result.x = this->x + other.x;
            result.y = this->y + other.y;
            return result;
        }

        // Function to print the point
        void display(){
            cout << "(" << x << ", " << y << ")" << endl;
        }
};

int main() {
    Point p1(3, 4), p2(1, 2);
    
    // Add two points using overloaded + operator
    Point p3 = p1 + p2;

    cout << "p1 + p2 = ";
    p3.display();  // Output: (4, 6)
    
    return 0;
}
```

### Explanation:
1. **Class Definition**: We define a class `Point` with two private members, `x` and `y`, representing the coordinates of the point.
2. **Overloading the `+` Operator**: The `+` operator is overloaded using the `operator+` function. This function takes one argument (another `Point` object), adds the `x` and `y` coordinates of both objects, and returns a new `Point` object with the result.
3. **Usage in Main**: We create two points, `p1` and `p2`, and then use the `+` operator to add them. The overloaded `+` operator is automatically called, and the result is stored in `p3`.

### Syntax of Operator Overloading:
```cpp
return_type operator symbol (argument_list) {
    // Function body
}
```
- `return_type`: The type of value returned by the overloaded operator (in this case, `Point`).
- `symbol`: The operator to be overloaded (`+`, `-`, `*`, etc.).
- `argument_list`: The list of parameters the operator will use (in this case, the other `Point` object).

### Rules:
1. **At least one operand must be a user-defined type** (like a class).
2. You cannot overload the following operators: `::`, `sizeof`, `?:`, `.` (dot), `.*`, `typeid`, `const_cast`, `dynamic_cast`, `static_cast`, `reinterpret_cast`.

You can overload many operators like `-`, `*`, `/`, `[]` (subscript), `()` (function call), and more, depending on your needs.

Would you like to explore another example or specific operator?