class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<pair<int,int> > adj[n];
        for(int i=0;i<flights.size();i++){
            int u = flights[i][0];
            int v = flights[i][1];
            int d = flights[i][2];
            adj[u].push_back({v,d});
            
        }
        queue<pair<int,pair<int,int>>> q;
        vector<int> dis(n,INT_MAX);
        q.push({0,{src,0}});
        dis[src] = 0;
        while(!q.empty()){
            auto it = q.front();
            int stops = it.first;
            int node = it.second.first;
            int cost = it.second.second;
            q.pop();
            if(stops > k ) continue;
            for(auto iter : adj[node]){
                int newNode = iter.first;
                int edgeWt = iter.second;
                if(dis[newNode] > cost + edgeWt && stops <= k){
                    dis[newNode] = cost+edgeWt;
                    q.push({stops+1,{newNode,dis[newNode]}});
                }
            }
        }
        if(dis[dst] == INT_MAX) return -1;
        return dis[dst];
    }
};