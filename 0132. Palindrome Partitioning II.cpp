class Solution {
public:
    string p="";
    vector<int>dp;
    void build_manacher(string s){
        for(int i=0;i<s.length();i++){
            p+='$';
            p+=s[i];
        }
        p+='$';
        dp=vector<int>(p.length());
        dp[0]=1;
        int left=1,right=1;
        for(int i=1;i<p.length();i++){
            if(left+right-i>=0)
            dp[i]=min(right-i+1,dp[left+right-i]);
            dp[i]=max(dp[i],1);
            while(i-dp[i]>=0&&i+dp[i]<p.length()&&p[i-dp[i]]==p[i+dp[i]]){
                dp[i]++;
            }
            if(i+dp[i]-1>right){
                right=i+dp[i]-1;
                left=i-dp[i]+1;
            }           
        }
    }

    bool ispal(int left,int right){
        if(right-left+1<=dp[left+right+1]-1)
            return 1;
        return 0;
    }

    int minCut(string s) {
        build_manacher(s);
        int dp[s.length()];
        dp[0]=0;
        for(int i=1;i<s.length();i++){
            dp[i]=1000000;
            for(int j=0;j<=i;j++){
                if(ispal(j,i)){
                    if(j==0)
                        dp[i]=0;
                    else{
                        dp[i]=min(dp[i],dp[j-1]+1);
                    }
                }
            }
        }
        return dp[s.length()-1];
    }
};
