/***************************************************************************

	Class for graph node is as follows:

	class graphNode
	{
		public:
    		int data;
    	vector<graphNode *> neighbours;
    	graphNode()
    	{
        	data = 0;
        	neighbours = vector<graphNode *>();
    	}

    	graphNode(int val)
    	{
        	data = val;
        	neighbours = vector<graphNode *>();
    	}

    	graphNode(int val, vector<graphNode *> neighbours)
    	{
        	data = val;
        	this->neighbours = neighbours;
    	}
	};

******************************************************************************/

#include <bits/stdc++.h>

graphNode *dfs(graphNode *n, unordered_map<graphNode *, graphNode *> &mp)
{

    // the given node is not checked

    mp[n] = new graphNode(n->data);

    // now iterate through its neighbours

    vector<graphNode *> v;

    for (auto i : n->neighbours)
    {
        // it is a neighbour which has been checked
        // checked means earlier it was discovered and it has all its
        // neighbour information as a vector
        if (mp.find(i) != mp.end())
            v.push_back(i);

        // the given neighbour has not been discovered earlier
        else
        {
            v.push_back(dfs(i, mp));
        }
    }

    n->neighbours = v;
    return n;
}

graphNode *cloneGraph(graphNode *node)
{

    unordered_map<graphNode *, graphNode *> mp;

    if (!node)
        return NULL;
    return dfs(node, mp);
}
