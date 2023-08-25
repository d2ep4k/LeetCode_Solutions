class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        k*=2;
        int dp[prices.size()][k];
        int n=prices.size();
        for(int i=0;i<n;i++){
            for(int j=0;j<k;j++){
                dp[i][j]=-1000000;
            }
        }
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<k&&j<=i;j++){
                if(i>0){
                    dp[i][j]=dp[i-1][j];
                }
                if(j%2==0){
                    if(j==0){
                        dp[i][j]=max(dp[i][j],-prices[i]);
                    }
                    else{
                        dp[i][j]=max(dp[i][j],dp[i-1][j-1]-prices[i]);
                    }
                }
                else{
                    dp[i][j]=max(dp[i][j],dp[i-1][j-1]+prices[i]);
                }
            }
        }

        for(int i=0;i<k;i++){
            ans=max(ans,dp[n-1][i]);
        }
        return ans;
    }   
};
