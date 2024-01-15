// 0503 實習Q1.cpp : 此檔案包含 'main' 函式。程式會於該處開始執行及結束執行。
//

//#include <stdafx>
#include <iostream>
#include <cstdlib>

using namespace std;

class Vector2D
{
public:
    double getax()
    {
        return(Ax);
    }
    double getay()
    {
        return(Ay);
    }
    Vector2D(double a, double b)
    {
        Ax = a;
        Ay = b;
    }
    double operator *(const Vector2D & v2);
    void input();
private:
    double Ax, Ay;

};

double Vector2D::operator*(const Vector2D& v2)
{
    return(Ax * v2.Ax + Ay * v2.Ay);
}


int main()
{
    Vector2D v1(10,0),v2(0,10),v3(10,10),v4(5,4);
   
    cout << "\n <" << v1.getax() << "," << v1.getay() << "> * <" << v2.getax() << "," << v2.getay() << "> = " << v1 * v2 << "\n";
    cout << "\n <" << v2.getax() << "," << v2.getay() << "> * <" << v3.getax() << "," << v3.getay() << "> = " << v2 * v3 << "\n";
    cout << "\n <" << v3.getax() << "," << v3.getay() << "> * <" << v4.getax() << "," << v4.getay() << "> = " << v3 * v4 << "\n\n";
    

    system("PAUSE");
    return(0);
}

