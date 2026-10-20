// Лабораторна робота № 5.3

#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

double j(const double x);   // прототип

int main()
{
    double kp, kk, z;
    int n;
    cout << "kp = "; cin >> kp;
    cout << "kk = "; cin >> kk;
    cout << "n = "; cin >> n;

    cout << fixed;
    cout << "------------------" << endl;
    cout << "|" << setw(5) << "k" << " |"
        << setw(8) << "z" << " |" << endl;
    cout << "------------------" << endl;

    double dk = (kk - kp) / n;
    double k = kp;
    while (k <= kk)
    {
        z = j(k) + j(k - 1) * j(k - 1) + 2 * j(1);
        cout << "|" << setw(5) << setprecision(2) << k
            << " |" << setw(8) << setprecision(3) << z
            << " |" << endl;
        k += dk;
    }
    cout << "------------------" << endl;

    return 0;
}

double j(const double x)   // визначення
{
    if (abs(x) >= 1)
        return (sin(x) + 1) / (cos(x) * cos(x) + exp(x));
    else
    {
        double S = 0;
        int k = 0;
        double a = 1;
        S = a;
        do
        {
            k++;
            double R = (4 * x * x) / (2 * k * (2 * k - 1));
            a *= R;
            S += a;
        } while (k < 7);
        return S / cos(2 * x);
    }
}