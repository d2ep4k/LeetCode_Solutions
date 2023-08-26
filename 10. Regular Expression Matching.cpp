class Solution {
public:

    int memo[20][20]={};

    int dp(string s,string p,int ptr1,int ptr2){
        if(ptr1<0&&ptr2<0)return 1;
        else if(ptr2<0)return 0;
        else if(ptr1<0){
            if(p[ptr2]=='*'){
                return dp(s,p,ptr1,ptr2-2);
            }
            return 0;
        }
        if(memo[ptr1][ptr2]!=-1)
        return memo[ptr1][ptr2];
        int ans=0;
        if(p[ptr2]=='*'){
            ptr2--;            
            ans|=dp(s,p,ptr1,ptr2-1);
            if(p[ptr2]=='.'){
                while(ptr1>=0){                
                    ans|=dp(s,p,ptr1-1,ptr2-1);
                    if(ptr1==0)
                    break;
                    ptr1--;
                }
            }
            else{                
                while(ptr1>=0&&s[ptr1]==p[ptr2]){                
                    ans|=dp(s,p,ptr1-1,ptr2-1);
                    if(ptr1==0)
                    break;
                    ptr1--;
                }
            }
        }
        if(p[ptr2]=='.'){
            ans|=dp(s,p,ptr1-1,ptr2-1);
        }
        if(p[ptr2]==s[ptr1]){
            ans|=dp(s,p,ptr1-1,ptr2-1);
        }
        return memo[ptr1][ptr2]=ans;
    }

    bool isMatch(string s, string p){
        for(int i=0;i<20;i++){
            for(int j=0;j<20;j++){
                memo[i][j]=-1;
            }
        }
        return bool(dp(s,p,s.length()-1,p.length()-1));     
    }
};
