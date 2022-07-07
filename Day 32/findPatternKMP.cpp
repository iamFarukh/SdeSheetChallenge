void find_lps(vector<int> &lps, string p)
{
    lps[0] = 0;
    int len = 0;
    for (int i=1;i<lps.size();i++)
    {
        while (len>0 && p[i] != p[len])
            len = lps[len-1];
        if (p[i] == p[len])
            len++;
        lps[i] = len;
    }
}

bool findPattern(string p, string s)
{
    int m = p.length();
    int n = s.length();
    vector<int>lps(m,0);
    find_lps(lps,p);
    int len=0;
    for (int i=0;i<n;i++)
    {
        while (len>0 && p[len] != s[i])
            len = lps[len-1];
        if (p[len] == s[i])
            len++;
        if (len==m)
            return true;
    }
    return false;
}
