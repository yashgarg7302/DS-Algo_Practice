class Solution {
private:
    void dfs( int r, int c, vector<vector<int>>& vis){
        vis[r][c] = 0;

        int dx[] = {-1,0,1,0};
        int dy[] = {0,1,0,-1};

        for ( int i=0; i<4; i++ ){
            int nr = r+dx[i];
            int nc = c+dy[i];

            if ( nr>=0 && nc>=0 && nr<vis.size() && nc<vis[0].size() && vis[nr][nc] == 1 ){
                dfs(nr,nc,vis);
            }
        }
    }

public:
    int numEnclaves(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        vector<vector<int>> vis = grid;

        for ( int i=0; i<cols; i++ ){
            if ( vis[0][i] == 1 ){
                dfs(0,i,vis);
            }
            if ( vis[rows-1][i] == 1 ){
                dfs(rows-1,i,vis);
            }
        }

        for ( int i=0; i<rows; i++ ){
            if ( vis[i][0] == 1 ){
                dfs(i,0,vis);
            }
            if ( vis[i][cols-1] == 1 ){
                dfs(i,cols-1,vis);
            }
        }

        int ans = 0;
        for ( int i=0; i<rows; i++){
            for ( int j=0; j<cols; j++ ){
                if ( vis[i][j] == 1 ){
                    ans++;
                }
            }
        }
        return ans;
    }
};