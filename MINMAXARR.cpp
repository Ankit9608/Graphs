#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n, maxi = INT_MIN;
    cin >> n;
    // vector<int> v(n);
    int v[n];
    for (int i = 0; i < n; i++)
    {

        cin >> v[i];
        maxi = max(maxi, v[i]);
    }
    int ans = 0;
    if (maxi == v[0])
    {
        cout << v[0] << endl;
        return;
    }
    for (int i = n - 1; i > 0; i--)
    {
        if (v[i] < v[i - 1] && v[i] == v[i - 1])
        {
            continue;
        }
        else
        {
            int temp = ((v[i] - v[i - 1]) / 2);
            v[i] -= temp;
            v[i - 1] += temp;
            ans = max(ans, v[i]);
        }
    }
    cout << ans << endl;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
