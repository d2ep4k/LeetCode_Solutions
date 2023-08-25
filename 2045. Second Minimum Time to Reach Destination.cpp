class Solution {
public:
    int secondMinimum(int n, vector<vector<int>>& edges, int time, int change) {
        vector<vector<int>>adj(n+1);
        vector<pair<int,int>>time_to_reach(n+1,{1e9,1e9});

        for(auto &it:edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }

        queue<pair<int,int>>bfs;
        
        bfs.push({1,0});
        time_to_reach[1]={0,1e9};

        int node,clearance,curtime;

        while(!bfs.empty()){
            node=bfs.front().first;
            curtime=bfs.front().second;
            clearance=curtime;
            if((curtime/change)%2!=0){
                clearance+=(change-curtime%change);
            }
            bfs.pop();
            for(auto &it:adj[node]){
                if(time_to_reach[it].second==1e9&&time_to_reach[it].first==1e9){
                    time_to_reach[it].first=clearance+time;
                    bfs.push({it,clearance+time});

                }else if(time_to_reach[it].second==1e9&&clearance+time>time_to_reach[it].first){
                    time_to_reach[it].second=clearance+time;
                    bfs.push({it,clearance+time});
                }
            }
        }
        return time_to_reach[n].second;
    }
};
