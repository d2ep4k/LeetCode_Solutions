class Solution {
public:

    vector<pair<int,int>>moves={{0,1},{1,0},{-1,0},{0,-1}};
    vector<vector<int>>dp;

    int getLIS(vector<vector<int>>&matrix,int i ,int j){
        if(dp[i][j]!=-1)return dp[i][j];
        int ans=1;
        int n=matrix.size();
        int m=matrix[0].size();   
        for(auto k:moves){
            if(i+k.first>=0&&i+k.first<n&&j+k.second>=0&&j+k.second<m){
                if(matrix[i][j]<matrix[i+k.first][j+k.second])
                    ans=max(ans,1+getLIS(matrix,i+k.first,j+k.second));
            }
        }
        return dp[i][j]=ans;
    }

    int longestIncreasingPath(vector<vector<int>>& matrix) {
        //maybe dfs + dp -> limiting at greatest(>=) among neighbours
        int n=matrix.size();
        int m=matrix[0].size();                      
        dp=vector<vector<int>>(n,vector<int>(m,-1));
        int ans=1;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                ans=max(ans,getLIS(matrix,i,j));
            }
        }
        return ans;
    }
};
