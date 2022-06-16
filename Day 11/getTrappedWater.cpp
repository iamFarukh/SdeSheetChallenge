#include <bits/stdc++.h> 
long getTrappedWater(long *a, int n){
    // Write your code here.
    long lmax=0,rmax=0;

    int i=0,j=n-1;
    long sum=0;

    while(i<j){
        lmax=max(lmax,a[i]);
        rmax=max(rmax,a[j]);

        if(lmax<rmax){
            sum+=(lmax-a[i]);
            i++;
        }else{
            sum+=(rmax-a[j]);
            j--;
        }
    }
    return sum;
}
