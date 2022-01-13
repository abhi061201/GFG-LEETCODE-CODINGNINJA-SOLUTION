#include <iostream>
#include <bits/stdc++.h>
#define ll long long
using namespace std;

void solve()
{
    ll n;
    cin >> n;
    ll arr[n];
    ll max = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        if (max < arr[i])
        {
            max = arr[i];
        }
    }
    ll max_diff = 0;
    for (int i = 0; i < n; i++)
    {
        if (max_diff < abs(max - arr[i]))
        {
            max_diff = abs(max - arr[i]);
        }
        
    }cout << max_diff;
}
int main()
{

    ll t;
    cin >> t;
    while (t-- > 0)
    {
        solve();
    }

    return 0;
}
