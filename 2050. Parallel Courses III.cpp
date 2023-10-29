class Solution {
public:

    int dfs(int node, vector<int>& maxAt, vector<int>& time, vector<vector<int>>& adj){
        if(maxAt[node]) return maxAt[node];
        int curMax = 0;
        for(int i: adj[node]){
            curMax = max(curMax , dfs(i, maxAt, time, adj));
        }
        return maxAt[node] = curMax + time[node];
    }

    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
        vector<vector<int>> adj(n);
        for(int i=0 ; i<relations.size() ; i++){
            adj[relations[i][1]-1].emplace_back(relations[i][0]-1);
        }
        int maxTime = 0;
        vector<int> maxAt(n, 0);
        for(int i = 0 ; i<n ; i++){
            maxTime = max(maxTime, dfs(i,maxAt,time,adj));
        }   
        return maxTime;
    }
};
