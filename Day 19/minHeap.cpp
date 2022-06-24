void heapify_down(vector<int>& heap,int i)
{
    int left = 2*i+1;
    int right = 2*i+2;
    int smallest = i;

    if (left < heap.size() && heap[left] < heap[i]) {
        smallest = left;
    }

    if (right < heap.size() && heap[right] < heap[smallest]) {
        smallest = right;
    }

    if (smallest != i)
    {
        swap(heap[i], heap[smallest]);
        heapify_down(heap,smallest);
    }
}

// Recursive heapify-up algorithm
void heapify_up(vector<int> &heap,int i)
{
    if (i && heap[(i-1)/2] > heap[i])
    {
        swap(heap[i], heap[(i-1)/2]);
        heapify_up(heap,(i-1)/2);
    }
}

// insert key into the heap
void push(vector<int> &heap,int key)
{
    heap.push_back(key);

    int index = heap.size() - 1;
    heapify_up(heap,index);
}
 
// Function to remove an element with the lowest priority (present at the root)
void pop(vector<int> &heap)
{
    heap[0] = heap.back();
    heap.pop_back();

    heapify_down(heap,0);
}

vector<int> minHeap(int n, vector<vector<int>>& q) {
    // Write your code here.
    vector<int> heap,ans;
    for(int i=0;i<q.size();i++)
    {
        if(q[i][0])
        {
            ans.push_back(heap[0]);
            pop(heap);
        }
        else
        {
            push(heap,q[i][1]);
        }
    }
    return ans;
}
