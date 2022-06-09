#include <bits/stdc++.h> 

void rotateMatrix(vector<vector<int>> &mat, int n, int m)
{
    // Write your code here
    int r = 0, c = 0;
    int prev, cr;
    while (r < n && c < m)
    {
        if (r + 1 == n || c + 1 == m)
            break;
        prev = mat[r + 1][c];
        for (int i = c; i < m; i++)
        {
            cr = mat[r][i];
            mat[r][i] = prev;
            prev = cr;
        }
        r++;
        for (int i = r; i < n; i++)
        {
            cr = mat[i][m - 1];
            mat[i][m - 1] = prev;
            prev = cr;
        }
        m--;
        if (r < n)
        {
            for (int i = m - 1; i >= c; i--)
            {
                cr = mat[n - 1][i];
                mat[n - 1][i] = prev;
                prev = cr;
            }
        }
        n--;
        if (c < m)
        {
            for (int i = n - 1; i >= r; i--)
            {
                cr = mat[i][c];
                mat[i][c] = prev;
                prev = cr;
            }
        }
        c++;
    }
}
