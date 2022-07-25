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

graphNode* dfs(graphNode* node, unordered_map<graphNode*, graphNode*>& hmap, int parent){
    hmap[node] = new graphNode(node->data);
    for(auto &adj : node->neighbours){
        if(hmap.find(adj) == hmap.end()){
            hmap[node]->neighbours.push_back( dfs(adj, hmap, node->data) );
        }else{
            hmap[node]->neighbours.push_back(hmap[adj]);
        }
    }
    return hmap[node];
}

graphNode *cloneGraph(graphNode *node)
{
    unordered_map<graphNode*, graphNode*> hmap;
    return dfs(node, hmap, -1);
}
