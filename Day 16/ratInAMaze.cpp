void completeMaze(vector<vector<int>> &res, vector<int> &visited, vector<vector<int>> &maze, int row, int col, int n){
    if(row == n-1 && col == n-1){
        visited[row*n+col] = 1;
        res.push_back(visited);
        return ;
    }
    
    if(row >= n || row < 0 || col >= n || col < 0 || maze[row][col] == 0 || visited[row*n+col] == 1)
        return ;
 
    visited[row*n+col] = 1;
    //Down
    completeMaze(res, visited ,maze, row+1, col , n);
    //Up
    completeMaze(res, visited ,maze, row-1, col , n);
    //Right
    completeMaze(res, visited ,maze, row, col+1 , n);
    //Left
    completeMaze(res, visited ,maze, row, col-1 , n);
    visited[row*n+col] = 0;
}
vector<vector<int> > ratInAMaze(vector<vector<int> > &maze, int n){
  // Write your code here.
  vector<vector<int>> res;
    vector<int> visited(n*n, 0);
    completeMaze(res, visited, maze, 0,0,n);
      return res;
}
