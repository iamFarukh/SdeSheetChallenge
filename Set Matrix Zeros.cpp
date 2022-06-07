#include <bits/stdc++.h> 
void setZeros(vector<vector<int>> &matrix)
{
	// Write your code here.
    int r = matrix.size(), c = matrix[0].size();
    vector<int> temp1(r,-1), temp2(c,-1);
    
    for(int i = 0;i<r;i++){
        for(int j = 0;j<c;j++){
            if(matrix[i][j]==0){
                temp1[i] =0;
                temp2[j] =0;
            }
        }
    }
    for(int i = 0;i<r;i++){
        for(int j = 0;j<c;j++){
            if(temp1[i]==0 || temp2[j]==0){
                matrix[i][j]=0;
            }
        }     
    }
}
