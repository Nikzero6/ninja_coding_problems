#include <iostream>
using namespace std;

class Polynomial
{
public:
    int *degCoeff;
    int capacity;

    //default constructor
    Polynomial()
    {
        degCoeff = new int[5];
        for (int i = 0; i < 5; i++)
        {
            degCoeff[i] = 0;
        }
        capacity = 5;
    }

    // parametrized constructor
    Polynomial(int capacity)
    {
        degCoeff = new int[capacity];
        for (int i = 0; i < 5; i++)
        {
            degCoeff[i] = 0;
        }
        this->capacity = capacity;
    }

    // copy constructor
    Polynomial(Polynomial const &p)
    {
        delete[] degCoeff;
        degCoeff = new int[p.capacity];
        capacity = p.capacity;
        for (int i = 0; i < capacity; i++)
        {
            degCoeff[i] = p.degCoeff[i];
        }
    }

    // copy assignment (operator overloading)
    void operator=(Polynomial const &p)
    {
        delete[] degCoeff;
        degCoeff = new int[p.capacity];
        capacity = p.capacity;
        for (int i = 0; i < capacity; i++)
        {
            degCoeff[i] = p.degCoeff[i];
        }
    }

    // method
    void setCoefficient(int deg, int coeff)
    {
        if (deg >= capacity)
        {
            int *newDegCoeff = new int[deg + 1];
            for (int i = 0; i < capacity; i++)
            {
                newDegCoeff[i] = degCoeff[i];
            }
            delete[] degCoeff;
            degCoeff = newDegCoeff;
            capacity = deg + 1;
        }
        degCoeff[deg] = coeff;
    }

    // operator overloading
    Polynomial operator+(Polynomial const &p)
    {
        Polynomial result;

        if (capacity > p.capacity)
        {
            result = *this;
            for (int i = 0; i < p.capacity; i++)
            {
                result.degCoeff[i] += p.degCoeff[i];
            }
        }

        else
        {
            result = p;
            for (int i = 0; i < capacity; i++)
            {
                result.degCoeff[i] += degCoeff[i];
            }
        }

        return result;
    }

    // operator overloading
    Polynomial operator-(Polynomial const &p)
    {
        int maxCapacity = max(capacity, p.capacity);
        int minCapacity = min(capacity, p.capacity);
        Polynomial result(maxCapacity);

        for (int i = 0; i < minCapacity; i++)
        {
            result.degCoeff[i] = degCoeff[i] - p.degCoeff[i];
        }

        for (int i = minCapacity; i < maxCapacity; i++)
        {
            result.degCoeff[i] = 0 - p.degCoeff[i];
        }

        return result;
    }

    // operator overloading
    Polynomial operator*(Polynomial const &p)
    {
        Polynomial result(capacity + p.capacity);

        for (int i = 0; i < capacity; i++)
        {
            if (degCoeff[i] != 0)
            {
                for (int j = 0; j < p.capacity; j++)
                {
                    if (p.degCoeff[j] != 0)
                    {
                        result.degCoeff[i + j] += degCoeff[i] * p.degCoeff[j];
                    }
                }
            }
        }

        return result;
    }

    // method
    void print()
    {
        for (int i = 0; i < capacity; i++)
        {
            if (degCoeff[i] != 0)
                cout << degCoeff[i] << "x" << i << " ";
        }
        cout << endl;
    }
};

int main()
{
    int n;
    cin >> n;
    int deg1[n], coeff1[n];
    for (int i = 0; i < n; i++)
        cin >> deg1[i];

    for (int i = 0; i < n; i++)
        cin >> coeff1[i];

    Polynomial P1;
    for (int i = 0; i < n; i++)
    {
        P1.setCoefficient(deg1[i], coeff1[i]);
    }

    int m;
    cin >> m;
    int deg2[m], coeff2[m];
    for (int i = 0; i < m; i++)
        cin >> deg2[i];

    for (int i = 0; i < m; i++)
        cin >> coeff2[i];

    Polynomial P2;
    for (int i = 0; i < m; i++)
    {
        P2.setCoefficient(deg2[i], coeff2[i]);
    }

    P1.print();
    P2.print();

    Polynomial P3(P1);
    Polynomial P4, P5;
    P4 = P2;

    P3 = P3 + P2;
    P4 = P4 - P1;
    P5 = P1 * P2;

    P3.print();
    P4.print();
    P5.print();

    return 0;
}