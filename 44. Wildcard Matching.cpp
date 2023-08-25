class Solution {
public:
    bool isMatch(string text, string pattern) {
        bool dp[pattern.length()+1][text.length()+1];
      memset(dp,0,sizeof(dp));
      dp[0][0]=1;
      int ind=0;
      while(ind<pattern.length()&&pattern[ind]=='*'){dp[ind+1][0]=1;ind++;}
      for(int i=0;i<pattern.length();i++){
      for(int j=0;j<text.length();j++){
         if(pattern[i]==text[j])
            dp[i+1][j+1]=dp[i][j];
         else if(pattern[i]=='?')
            dp[i+1][j+1]|=dp[i][j];
         else if(pattern[i]=='*'){
            dp[i+1][j+1]|=dp[i+1][j];
            dp[i+1][j+1]|=dp[i][j+1];
            dp[i+1][j+1]|=dp[i][j];
         }
      }
   }
   return dp[pattern.length()][text.length()];
    }
};
