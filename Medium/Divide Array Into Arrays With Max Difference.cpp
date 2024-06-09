

#include <bits/stdc++.h>
using namespace std;
void solve()
{
    int n, a, c = 0;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    for (int i = 0; i < n; i++)
    {
        if (v[i] > 1 && i % 2 == 0)
        {
            cout << "First\n";
            return;
        }
        if (v[i] > 1 && i % 2)
        {
            cout << "Second\n";
            return;
        }
    }
    if (n % 2)
        cout << "First\n";
    else
        cout << "Second\n";
}
int main()
{
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}
