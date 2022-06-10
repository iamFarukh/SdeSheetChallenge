#include <bits/stdc++.h> 
// In this We are using floor(N/2)
int findMajorityElement(int arr[], int n) {
	int count = 0;
    int candidate = 0;
    for(int i = 0;i<n;i++){
        if(count == 0) candidate = arr[i];
        if(candidate == arr[i]) count++;
        else count--;
    }
    count = 0;
    for(int i = 0;i<n;i++){
        if(arr[i] == candidate) count++;
    }
    if(count<=n/2) return -1;
    return candidate;
}
