class Solution {
public:

    bool isBipartite(bool coloured, int node, vector<vector<int>>& adj, vector<bool>& visited, vector<bool>& colour){
    
        visited[node] = true;
        colour[node] = coloured;
        for(int nodes:adj[node]){
            if(!visited[nodes]){
                if(!isBipartite(1-coloured,nodes,adj,visited,colour))
                    return false;
            }
            else{
                if(colour[nodes] == coloured)
                return false;
            }
        }
        return true;

    }

    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<vector<int>> adj(n);
        for(auto &pairs:dislikes){
            adj[pairs[0]-1].push_back(pairs[1]-1);
            adj[pairs[1]-1].push_back(pairs[0]-1);
        }
        vector<bool>visited(n,false);
        vector<bool>colour(n,false);
        bool ans=true;
        for(int i=0;i<n;i++){
            if(!visited[i])
            ans&=isBipartite(false,i,adj,visited,colour);
        }
        return ans;
    }
};
