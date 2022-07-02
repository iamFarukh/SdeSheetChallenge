#include <bits/stdc++.h>

vector<int> findSpans (vector<int> &v) {

    stack<int>stk;

    vector<int>ans(v.size(),1);

    

    for(int i=0;i<v.size();i++)

    {

        int cnt = 1;

        if(!stk.empty() and v[i] >= v[stk.top()])

        {

          while(!stk.empty() and v[i] >= v[stk.top()])

            {

                cnt += ans[stk.top()];

              stk.pop();

            }

        }

            stk.push(i);  

        ans[i] = cnt;

    }

    return ans;

}
