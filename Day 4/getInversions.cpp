#include<bits/stdc++.h>

long long modifiedMerge(long long arr[], int l, int mid, int r){
    int i = l, j = mid, str=0;
    long long cnt=0;
    
    int arr2[(r-l+1)]; 
    while(i<mid || j<=r){
        if(i<mid && j<=r){
            if(arr[i] > arr[j]){ 
                cnt+=(mid-i); arr2[str++] = arr[j++]; 
            }
            else arr2[str++] = arr[i++];   
        }
        else if(i<mid){ 
            arr2[str++] = arr[i++];   
        }
        else{ 
            arr2[str++] = arr[j++]; 
        }
    }
    
    j = 0;
    for(int i=l;i<=r;i++) arr[i] = arr2[j++];
    
    return cnt;
}

long long mergeSort(long long arr[], int l, int r){
    long long ans=0;
    
    if(l<r){
        int mid = l + (r-l) / 2;
        
        ans = mergeSort(arr, l, mid); 
        ans += mergeSort(arr, mid+1, r);
        ans += modifiedMerge(arr, l, mid+1, r);
    }
    return ans;
}

long long getInversions(long long *arr, int n){
    return mergeSort(arr, 0, n-1);
}
