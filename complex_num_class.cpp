#include <iostream>
using namespace std;

class Complex
{
private:
    int a, b;

public:
    Complex(int a, int b)
    {
        this->a = a;
        this->b = b;
    }

    void add(Complex const &c2)
    {
        a = a + c2.a;
        b = b + c2.b;
    }

    void multiply(Complex const &c2)
    {
        a = a * c2.a;
        b = b * c2.b;
    }

    void print()
    {
        cout << a << " + i" << b << endl;
    }
};

int main()
{
    int a, b, c, d;
    cin >> a >> b >> c >> d;

    Complex c1(a, b);
    Complex c2(c, d);

    int choice;
    cin >> choice;

    if (choice == 1)
    {
        c1.add(c2);
        c1.print();
    }
    else if (choice == 2)
    {
        c1.multiply(c2);
        c1.print();
    }

    return 0;
}