#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    // your code goes here
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> v(n);
        map<int, int> mp;
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
            mp[v[i]]++;
        }
        int even = 0, odd = 0;
        bool flag = false;
        for (auto it : mp)

        {
            cout << it.first << "->" << it.second << endl;
            if (int(it.second) > 1)
            {
                flag = true;
            }
            // if((int(it.second))%2==0){
            //     even++;
            // }
            else
            {
                odd++;
            }
        }
        // if (!flag)
        // {
        //     cout << "YES" << endl;
        //     continue;
        // }
        if (odd > 1)
        {
            cout << "no" << endl;
        }
        else
        {
            cout << "yes" << endl;
        }
    }
    return 0;
}
