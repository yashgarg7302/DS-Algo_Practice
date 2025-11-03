class Solution {
public:
    bool isValid(int i, int j, int m, int n){ 
        if(i>=0 && i<m && j>=0 && j<n) return true;
        return false;
    }
    void dfs(vector<vector<int>> grid, int m, int n, vector<vector<int>>& visited, int i, int j, int &currArea){
        visited[i][j] = 1; 
		
		
        if(isValid(i-1, j, m, n) && !visited[i-1][j] && grid[i-1][j] == 1){ 
            currArea++;
            dfs(grid, m, n, visited, i-1, j, currArea);
        }
        if(isValid(i, j+1, m, n) && !visited[i][j+1] && grid[i][j+1] == 1){ 
            currArea++;
            dfs(grid, m, n, visited, i, j+1, currArea);
        }
        if(isValid(i+1, j, m, n) && !visited[i+1][j] && grid[i+1][j] == 1){
            currArea++;
            dfs(grid, m, n, visited, i+1, j, currArea);
        }
        if(isValid(i, j-1, m, n) && !visited[i][j-1] && grid[i][j-1] == 1){
            currArea++;
            dfs(grid, m, n, visited, i, j-1, currArea);
        }
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> visited(m, vector<int>(n,0));
        int res = INT_MIN;
        
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                int currArea = 0; 
                if(!visited[i][j] && grid[i][j] == 1){
                    currArea = 1;
                    dfs(grid, m, n, visited, i, j, currArea); 
                }
                res = max(res, currArea);
            }
        }
        return res;
    }
};