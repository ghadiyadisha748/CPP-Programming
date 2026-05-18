#include <iostream>
#include <cmath>
using namespace std;

class Point
{
    int x, y;

public:
    // Constructor
    Point(int a = 0, int b = 0)
    {
        x = a;
        y = b;
    }

    // Move function (chainable)
    Point &move(int dx, int dy)
    {
        x += dx;
        y += dy;
        return *this; // enables chaining
    }

    // Display
    void show()
    {
        cout << "Point (" << x << ", " << y << ")" << endl;
    }

    // Distance from origin
    double distance()
    {
        return sqrt(x * x + y * y);
    }

    // Reset to origin using pointer
    void reset()
    {
        x = 0;
        y = 0;
    }

    // Friend function using pointer (pass-by-reference)
    friend void updatePoint(Point *p, int dx, int dy);
};

// Function using pointer
void updatePoint(Point *p, int dx, int dy)
{
    p->move(dx, dy); // pointer dereferencing
}

int main()
{
    Point p(1, 2);

    cout << "Initial: ";
    p.show();

    // Chainable moves
    p.move(2, 3).move(-1, 4).move(5, -2);

    cout << "After chaining: ";
    p.show();

    // Pass-by-reference using pointer
    updatePoint(&p, 3, 3);

    cout << "After pointer update: ";
    p.show();

    // Distance
    cout << "Distance from origin: " << p.distance() << endl;

    // Reset
    p.reset();

    cout << "After reset: ";
    p.show();

    return 0;
}
