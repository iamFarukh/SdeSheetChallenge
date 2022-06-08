#include <bits/stdc++.h> 
#include <vector>

bool findTargetInMatrix(vector < vector < int >> & mat, int m, int n, int target) {
    // Write your code here.
    // m= rows n = columns
    int lo = 0;
        if(!mat.size()) return false;
        int hi = (mat.size() * mat[0].size()) - 1;
        
        while(lo <= hi) {
            int mid = (lo + (hi - lo) / 2);
            if(mat[mid/mat[0].size()][mid % mat[0].size()] == target) {
                return true;
            }
            if(mat[mid/mat[0].size()][mid % mat[0].size()] < target) {
                lo = mid + 1;
            }
            else {
                hi = mid - 1;
            }
        }
        return false;
}
