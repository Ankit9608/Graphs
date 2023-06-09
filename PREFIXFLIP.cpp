#include <bits/stdc++.h>
#define ll long long
#define llinf LLONG_MAX
#define llminf LLONG_MIN
#define inf INT_MAX
#define minf INT_MIN
const long long mod = 1e9 + 7;

using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        string s;
        cin >> s;
        int pref[n];
        pref[0] = 0;
        for (int i = 1; i < n; i++)
        {
            pref[i] = pref[i - 1];
            if (s[i] != s[i - 1])
                pref[i]++;
        }
        for (int i = 0; i < n; i++)
        {

            cout << pref[i] << " ";
        }
        cout << endl;
        int mn = inf;

        for (int i = 0; i <= n - k; i++)
        {
            if (s[i + k - 1] == '1')
            {
                mn = min(mn, pref[i + k - 1] - pref[i]);
                cout << "[i+k-1]=='1'"
                     << " " << mn << endl;
            }
            else
            {
                mn = min(mn, pref[i + k - 1] - pref[i] + 1);
                cout << "[i+k-1]!='1'"
                     << " " << mn << endl;
            }
        }
        cout << mn << endl;
    }
}

// Let's break the string into contiguous ‘blocks’ of zeros and ones. Notice, that for some substring,
// that starts at position L and ends at position R, the number of flips required to make it all ones is
//  almost the number of 'blocks' in it. The idea is greedily flip the blocks from the end of the string.
//   Let's say that some substring A consists of X 'blocks'. Then, there are 2 cases:

// 1)A ends with '1'. Then we don't need to flip the last block and the answer is X-1.
// 2)A ends with '0'. Then we need to flip the last block and the answer is X.
// Let's return to our initial problem. We need to make a substring of length K all 1's. First,
// let's create a Prefix sum array of the number of blocks at index i. Then, let's make a sliding widnow of
// length K and iterate through the string S. For each window, we check the number of blocks in this window
// and if it ends with 1, subtract 1. Find the minumum of all such substrings and that's the answer.

// Code implementation
// From Line 19 to 24
// Here pref[i] - number of blocks-1 by index i, inclusive.

// Code implementation
// From Line 27 to 28
// Thus, I don't subtract 1 where it ends with '1'. Instead, I add 1 when it ends with '0'.