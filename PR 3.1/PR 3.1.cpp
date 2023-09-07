#include <iostream>
#include <cmath>

using std::cout;
using std::cin;
using std::endl;

class Vector
{
public:
    Vector() = default;

    Vector(float x, float y, float z) :x{ x }, y{ y }, z{ z } {};

    friend Vector operator+(const Vector&, const Vector&);
    friend Vector operator-(const Vector&, const Vector&);
    friend Vector operator*(const Vector&, float);

    friend std::ostream& operator<<(std::ostream&, const Vector&);
    friend std::istream& operator>>(std::istream&, Vector&);

    operator float()
    {
        return sqrt(x * x + y * y + z * z);
    }

    friend bool operator>(const Vector&, const Vector&);

    float operator[](int i)
    {
        switch (i)
        {
        case 1: 
        {
            return x;
        }
        case 2:
        {
            return y;
        }
        case 3:
        {
            return z;
        }
        default:
            cout << "error: unknown index";
            break;
        }
    }

private:
    float x =0;
    float y=0;
    float z=0;
};



Vector operator+(const Vector& v1, const Vector& v2)
{
    return Vector(v1.x + v2.x, v1.y + v2.y, v1.z + v2.z);
}
Vector operator-(const Vector& v1, const Vector& v2)
{
    return Vector(v1.x - v2.x, v1.y - v2.y, v1.z - v2.z);
}
Vector operator*(const Vector& v, float f)
{
    return Vector(v.x * f, v.y * f, v.z * f);
}

std::istream& operator>>(std::istream& in, Vector& v)
{
    in >> v.x>> v.y>> v.z;
    return in;
}
std::ostream& operator<<(std::ostream& out, const Vector& v)
{
    out << ' ' << v.x << ' ' << v.y << ' ' << v.z;
    return out;
}

bool operator>(const Vector& v1, const Vector& v2)
{
    return false;
}

int main()
{
    Vector v1(0, 1, 2);
    Vector v2(3, 4, 5);
    Vector v3 = v1 + v2;
    cout << v3 << endl;
    Vector v4 = v1 - v2;
    cout << v4 << endl;
    Vector v5 = v1 * float(5);
    cout << v5 << endl;
    Vector v6;
    cin >> v6;
    cout << v6 << endl;
    cout << v2[1]<<endl;
    cout << float(v3)<< endl;
}

