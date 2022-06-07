#include <bits/stdc++.h> 
void sort012(int *arr, int n)
{
   //   Write your code here
   int l=0,h=n-1,mid = 0;
    
    while(mid<=h){
        switch(arr[mid]){
            case 0:
                swap(arr[l++],arr[mid++]);
                break;
            case 1:
                mid++;
                break;
            case 2:
                swap(arr[mid],arr[h--]);
                break;
        }
    }
}
