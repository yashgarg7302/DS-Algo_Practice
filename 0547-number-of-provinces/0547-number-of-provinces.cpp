class Solution {
public:
   void DFS(vector<vector<int>>& isConnected, vector<bool>& visited, int s) 
    {
        visited[s] = true;
        for(int f = 0 ; f < isConnected.size() ; f++)
        {
            if(isConnected[s][f] == 1 && !visited[f])
            {
                DFS(isConnected, visited, f);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        int cnt = 0;
        vector<bool> visited(n, false);
        for(int i = 0 ; i < n ; i++)
        {
            if(!visited[i]){
                DFS(isConnected, visited, i);
                cnt++;
            }         
        }
        return cnt;

    }
};