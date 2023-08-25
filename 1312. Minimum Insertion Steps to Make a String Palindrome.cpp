class Solution {
public:
    int minInsertions(string s) {
        vector<vector<int>>dp(s.length(),vector<int>(s.length(),0));
        for(int i=0;i<s.length();i++){
            for(int j=0;j+i<s.length();j++){
                dp[j][j+i]=500;
                if(j+i<=j)dp[j][j+i]=0;
                else{
                    if(s[j]==s[j+i]&&j+1<s.length()&&j+i-1>=0){
                        dp[j][j+i]=dp[j+1][j+i-1];
                    }
                    else{
                        if(j+i-1>=0)
                            dp[j][j+i]=min(dp[j][j+i],1+dp[j][j+i-1]);
                        if(j+1<s.length())
                            dp[j][j+i]=min(dp[j][j+i],1+dp[j+1][j+i]);
                    }
                }
            }
        }
        return dp[0][s.length()-1];
    }
};
