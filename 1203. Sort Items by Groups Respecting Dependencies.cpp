// problem-> https://leetcode.com/problems/sort-items-by-groups-respecting-dependencies/
// sol-> https://leetcode.com/problems/sort-items-by-groups-respecting-dependencies/solutions/3940307/cpp-topological-sorting-with-detailed-approach-beats-100-99/
class Solution {
public:
    void dfsOnGroup(int m,vector<vector<int>>&groupAdj,vector<vector<int>>&nodeAdj,vector<vector<int>>&groupMember,
        vector<bool>&groupVisited,vector<bool>&nodeVisited,vector<bool>&groupPathVisited,
        vector<bool>&nodePathVisited,vector<int>&sortedNodes,bool &cyclicDependency)    {

        if(groupVisited[m])return;
        if(groupPathVisited[m]){ //cycle exists
            cyclicDependency=1;
            return;
        }

        for(auto &Group:groupAdj[m]){//checking for inter-group dependency
            groupPathVisited[m]=1;            
            dfsOnGroup(Group,groupAdj,nodeAdj,groupMember,groupVisited,nodeVisited,               
            groupPathVisited,nodePathVisited,sortedNodes,cyclicDependency);
            groupPathVisited[m]=0;
        }

        for(auto &node:groupMember[m]){ //traversing group elements
            dfsOnNode(node,groupAdj,nodeAdj,groupMember,groupVisited,nodeVisited,groupPathVisited,
            nodePathVisited,sortedNodes,cyclicDependency); 
        }    

        groupVisited[m]=1;
        return ;

    }

    void dfsOnNode(int m,vector<vector<int>>&groupAdj,vector<vector<int>>&nodeAdj,vector<vector<int>>&groupMember,
        vector<bool>&groupVisited,vector<bool>&nodeVisited,vector<bool>&groupPathVisited,vector<bool>&nodePathVisited,
        vector<int>&sortedNodes,bool &cyclicDependency)    {

        if(nodeVisited[m])return;
        if(nodePathVisited[m]){ //cycle exists
            cyclicDependency=1;
            return;
        }

        for(auto &node:nodeAdj[m]){ //checking for inter-node dependency
            nodePathVisited[m]=1;            
            dfsOnNode(node,groupAdj,nodeAdj,groupMember,groupVisited,nodeVisited,groupPathVisited,
            nodePathVisited,sortedNodes,cyclicDependency);
            nodePathVisited[m]=0;
        }

        sortedNodes.emplace_back(m); 

        nodeVisited[m]=1;
        return ;

    }

    vector<int> sortItems(int n, int m, vector<int>& group, vector<vector<int>>& beforeItems) {
        
        //dag + topo(dfs)        

        for(int i=0;i<n;i++){
            if(group[i]==-1){ //assigning groups to unassigned ones to reduce complexity within groupless nodes
                group[i]=m++;
            }
        }

        vector<vector<int>>groupAdj(m); //group to group dependency
        vector<vector<int>>nodeAdj(n); //node to node dependecy
        vector<vector<int>>groupMember(m); //for tracking nodes belonging to particular group

        for(int i=0;i<n;i++){ //dag creation -> group/node directs to group/node to be traversed bofore it. 

            groupMember[group[i]].push_back(i);   

            for(int j=0;j<beforeItems[i].size();j++){
                if(group[beforeItems[i][j]]==group[i]) //similar group -> inter-node dependency
                    nodeAdj[i].push_back(beforeItems[i][j]);
                else //else inter-group dependency
                    groupAdj[group[i]].push_back(group[beforeItems[i][j]]);                
            }

        }
        
        vector<bool>groupVisited(m,0); 
        vector<bool>nodeVisited(n,0);
        vector<bool>groupPathVisited(m,0); //keeps track of groups visited in current path
        vector<bool>nodePathVisited(n,0); //keeps track of nodes visited in current path

        vector<int>sortedNodes; //stores ans
        bool cyclicDependency=0; //flag to tackle cyclic dependency.

        for(int i=0;i<m;i++){    //traversing groups
            if(groupVisited[i])continue;
            dfsOnGroup(i,groupAdj,nodeAdj,groupMember,groupVisited,nodeVisited,groupPathVisited,
            nodePathVisited,sortedNodes,cyclicDependency);
            if(cyclicDependency)return {};
        }

        return sortedNodes;

    }
};
