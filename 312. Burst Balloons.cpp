class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int n=nums.size();
        int dp[n][n];
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                dp[i][j]=0;
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j+i<n;j++){
                for(int k=j;k<=i+j;k++){
                    int temp=nums[k];
                    if(j-1>=0)
                        temp*=nums[j-1];
                    if(j+i+1<nums.size())
                        temp*=nums[j+i+1];
                    if(k!=j)
                        temp+=dp[j][k-1];
                    if(k!=j+i)
                        temp+=dp[k+1][j+i];
                    dp[j][i+j]=max(dp[j][i+j],temp);    
                }
            }
        }
        return dp[0][n-1];
    }
};
