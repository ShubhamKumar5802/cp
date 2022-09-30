#include <iostream>
#include<bits\stdc++.h>
#include<algorithm>
#define int long
using namespace std;
const int N = 1e6;
int a[N], f[N], b[N];

int gcd(int a, int b)
{
    if (b == 0)
        return a;
    else
        return gcd(b, a % b);
}
void gcdc(int n)
{
    f[1] = a[1];
    b[n] = a[n];
    for (int i = n - 1; i > 0; i--)
    {
        b[i] = gcd(b[i + 1], a[i]);
    }
    for (int i = 2; i < n + 1; i++)
    {
        f[i] = gcd(f[i - 1], a[i]);
    }
}

int main()
{

    int n1;
    cin >> n1;
    for (int x = 0; x < n1; x++)
    {
        int n;
        cin >> n;
        int sum = 0, notes = 0;
        for (int i = 1; i < n + 1; i++)
            cin >> a[i];
        int temp=n+1;
        sort(a,a+temp);
        gcdc(n);
        for (int i = 1; i < n + 1; i++)
            sum += a[i];
        long long money = 1000000000000000;
        for (int i = 1; i < n + 1; i++)
        {
            notes = (sum - a[i] + gcd(f[i - 1], b[i + 1])) / gcd(f[i - 1], b[i + 1]);
            if (notes < money)
                money = notes;
        }
        cout << money << endl;
    }
    return 0;
}
