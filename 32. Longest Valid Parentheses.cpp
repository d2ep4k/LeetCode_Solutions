class Solution {
public:
    int longestValidParentheses(string s) {
        int ans=0,curans=0,cont=0;
        int left=0,right=0;
        for(int i=0;i<s.length();i++){
            if(s[i]=='(')
                left++;
            else{         
                right++;
            }
            cout<<left<<" "<<right<<" ";
            if(right>left){
                cont=0;
                left=0,right=0;
                cout<<curans<<"--"<<endl;
                continue;
            }
            if(left>=right&&s[i]==')')
            {                 
                if(cont==1){
                    if(left>=right){
                    curans+=2*right;
                    ans=max(ans,curans);
                    cont=1;
                    left=left-right,right=0;
                    }
                }
                else{                    
                    curans=2*right;
                    ans=max(ans,curans);
                    cont=1;
                    left=left-right,right=0;
                }
            }
            cout<<curans<<endl;         

        }
        return ans;
    }
};
