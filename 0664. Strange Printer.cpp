class Solution {
public:
    int strangePrinter(string s) {
        vector<vector<int>> dp(s.length(),vector<int>(s.length(),0));
        for(int i=0;i<s.length();i++){
            for(int j=0;i+j<s.length();j++){
                dp[j][j+i]=s.length();
                if(i==0)dp[j][j+i]=1;
                else{
                    for(int k=j+1;k<=j+i;k++){
                        if(s[k]==s[j]){
                            dp[j][j+i]=min(dp[j][j+i],dp[j+1][k-1]+dp[k][j+i]);
                        }
                        else{
                            dp[j][j+i]=min(dp[j][j+i],dp[j][k-1]+dp[k][j+i]);
                        }
                    }
                }
            }
        }
        return dp[0][s.length()-1];    
    }
};
