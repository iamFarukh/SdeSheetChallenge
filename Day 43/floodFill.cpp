#include<bits/stdc++.h>
vector<int> dx = {0,0,1,-1};
vector<int> dy = {1,-1,0,0};

vector<vector<int>> floodFill(vector<vector<int>> &image, int x, int y, int newColor)
{
    // Write your code here.
    int val = image[x][y], n= image.size(), m = image[0].size();
    if(val == newColor) return image;
    queue<pair<int,int>> pq;
    image[x][y] =  newColor;
    pq.push({x,y});
    
    while(!pq.empty()){
        int p = pq.front().first, q = pq.front().second,x1,y1;
        pq.pop();
        for(int i=0;i<4;i++){
         x1 = p+dx[i], y1 = q + dy[i];
         if(x1 <n and x1>=0 and y1<m and y1 >=0 and image[x1][y1] == val){
           image[x1][y1] =  newColor;
           pq.push({x1,y1});  
         } 
      }   
    }
   return image; 
}
