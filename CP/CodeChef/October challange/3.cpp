#include <iostream>

#define rep(i, x, y) for (int i = x; i < y; i++)
#define f first
#define s second
#define pb push_back
#define eb emplace_back
#define PRES(c, x) ((c).find(x) != (c).end())



using namespace std;


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n96;
    cin >> n96;
    for (int x101 = 0; x101 < n96; x101++)
    {
        int n;
        cin >> n;
        long long lower = 1;
        while (lower <= n)
            lower << 1;
        lower >> 1;
        long long ans = n - lower + 1;
        ans = max(ans, lower);
        
        cout << ans << endl;
    }
    return 0;
}