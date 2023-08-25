class Solution {
public:
    string minWindow(string s, string t) {
        s+='_';
        int left=0,right=0,ind=0,ans=1000000;
        vector<int>sub(59,0);
        for(char c:t){
            sub[int(c)-65]++;
        }
        for(auto &i:sub){
            if(i==0)
                i=1000001;
        }
        int size=t.length();
        while(right<s.length()&&left<s.length()){            
            if(size==0&&sub[int(s[left])-65]<1000001){  
                if(ans>right-left){
                ind=left;
                ans=right-left;
                }              
                if(sub[int(s[left])-65]>=0)
                    size++;
                sub[int(s[left])-65]++;               
                left++;
            }
               else if(size==0)left++;
            else if(sub[int(s[right])-65]<1000001){
                if(sub[int(s[right])-65]>0)
                size--;
                sub[int(s[right])-65]--;                
                right++;
            }
         
            else
                right++;
        }
        if(ans==1000000)return "";
        return s.substr(ind,ans);
    }
};
