vector<int> ninjaAndSortedArrays(vector<int>& nums1, vector<int>& nums2, int m, int n) {
    int i = m - 1, j = n - 1, k = m + n - 1;
    while(j >= 0){
        if(i>=0 && nums1[i]>nums2[j]){
            nums1[k] = nums1[i];
            i--,k--;
        }
        else{
            nums1[k] = nums2[j];
            j--,k--;
        }
    }
    return nums1;
}
