#include <iostream>
#include <math.h>
using namespace std;

double multiply(double number, int n)
{
    double ans = 1.0;
    for (int i = 0; i < n; i++)
    {
        ans = ans * number;
    }
    return ans;
}

void NthrootOfM(int n, int m)
{
    double low = 1;
    double high = m;
    double eps = 1e-6;

    while ((high - low) > eps)
    {
        double mid = (low + high) / 2;
        if (multiply(mid, n) < m)
        {
            low = mid;
        }
        else
        {
            high = mid;
        }
    }

    cout << low << "  " << high << endl;
    // just to check
    cout << pow(m, (double)(1.0 / (double)n));
}

int main()
{
    int n, m;
    cin >> n >> m;
    NthrootOfM(n, m);
    return 0;
}