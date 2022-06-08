int removeDuplicates(vector<int> &arr, int n) {
	// Write your code here.
    
    if(arr.size() == 0)
        return 0;
    int i = 0;
    for(int j =1 ; j < arr.size() ; ++j){
        if(arr[j] != arr[i]){
            i++;
            arr[i] = arr[j];
        }
    }
    return i+1;
}
