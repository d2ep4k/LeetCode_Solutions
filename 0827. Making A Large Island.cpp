class Solution {
public:

    class UnionFind{
        public:
        vector<int>parent;
        vector<int>size;
        int sets;
        UnionFind(int size){

            parent.resize(size);
            this->size.resize(size);

            clear();

        }

        void clear(){

            for(int i=0;i<parent.size();i++)parent[i]=i;
            for(int i=0;i<this->size.size();i++)size[i]=0;
            sets=parent.size();

        }

        void Union(int node1,int node2){
            node1=find(node1);
            node2=find(node2);
            if(node1==node2){
                return;
            }
            if(size[node1]<size[node2]){
                swap(node1,node2);
            }
            parent[node2]=node1;
            size[node1]+=size[node2];
        }

        int find(int node1){
            if(parent[node1]==node1)
                return node1;
            return parent[node1]=find(parent[node1]);
        }

    };

    int largestIsland(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
        UnionFind uf(n*m);
        pair<int,int> moves[]={{0,1},{0,-1},{-1,0},{1,0}};
        int zeros=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='1'){
                    for(int k=0;k<4;k++){
                        int x=i+moves[k].first;
                        int y=j+moves[k].second;
                        if(x>=0&&y>=0&&x<grid.size()&&y<grid[0].size()&&grid[x][y]=='1'){
                            uf.Union(i*m+j,x*m+y);
                        }
                    }
                }else{
                    zeros++;
                }
            }

        }
        int ans=0;
        for(int i=0;i<n*m;i++){
            if(grid[i/m][i%m]=='0'){
                set<int>sets;
                for
            }
        }
        return ans-zeros;
    }
};
