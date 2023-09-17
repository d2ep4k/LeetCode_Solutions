class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int>helper(s.length(),-1);
        unordered_map<string,int>m;
        unordered_map<int,int>p;
        int z=0;
        for(auto &i:words){
            m[i]=z++;
        }         
        for(auto &i:words){
            p[m[i]]++;
        }
        for(int i=0;i<s.length();i++){
            string x="";
            for(int j=i;j<s.length()&&x.length()<words[0].length();j++){
                x+=s[j];
            }
            if(m.find(x)!=m.end()){
                helper[i]=m[x];
            }
        }
        int left=0,right=0,win=(words.size())*words[0].length();
        vector<int>ans;
        unordered_map<int,int>curwin[words[0].length()];
        vector<int>size(words[0].length(),0);
        if(helper[right]!=-1){
            size[right%words[0].length()]++;
            curwin[right%words[0].length()][helper[right]]++;
        }
        while(right<s.length()){                    
            if(right-left+1==win){                
                if(helper[left]!=-1){
                    if(size[left%words[0].length()]==words.size()){
                        ans.push_back(left);
                    }
                    if(curwin[left%words[0].length()][helper[left]]<=p[helper[left]])
                        size[left%words[0].length()]--;
                    curwin[left%words[0].length()][helper[left]]--;
                    if(curwin[left%words[0].length()][helper[left]]==0)
                        curwin[left%words[0].length()].erase(helper[left]);
                }
                left++;
            }
            else if(right-left+1<win){
                right++;
                if(right==s.length())
                    break;
                if(helper[right]!=-1){
                    if(curwin[right%words[0].length()][helper[right]]<p[helper[right]])
                        size[right%words[0].length()]++;
                    curwin[right%words[0].length()][helper[right]]++;
                }
            }
        }
        return ans;
    }
};
