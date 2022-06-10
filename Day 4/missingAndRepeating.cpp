#include <bits/stdc++.h> 
/// Multiple Approach availabe 
pair<int, int> missingAndRepeating(vector<int> &arr, int n)
{
    int Xor = 0;
    for (auto i : arr)
    {
        Xor ^= i;
    }
    for (int i = 1; i <= n; i++)
    {
        Xor ^= i;
    }
    int rsb = Xor & -Xor;
    int x = 0;
    int y = 0;
    for (auto i : arr)
    {
        if (i & rsb)
            x ^= i;
        else
            y ^= i;
    }

    for (int i = 1; i <= n; i++)
    {
        if (i & rsb)
            x ^= i;
        else
            y ^= i;
    }
    for (auto i : arr)
    {
        if (i == x)
            return {y, x};
        else if (i == y)
            return {x, y};
    }
}
