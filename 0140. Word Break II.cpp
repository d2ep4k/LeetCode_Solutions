class Solution {
public:
    vector<string>ans;
    string temp="";
    unordered_map<string,bool>map1;

    void recur(string &s,int ind){
        cout<<ind<<" "<<temp<<endl;
        int n=s.length();
        if(ind==n){
            temp.pop_back();
            ans.push_back(temp);
            temp+=' ';
            return;
        }
        string cur="";
        for(int i=ind;i<n;i++){
            cur+=s[i];
            if(map1[cur]){
                temp+=cur;
                temp+=' ';
                recur(s,i+1);
                temp.pop_back();
                for(int i=0;i<cur.length();i++)
                    temp.pop_back();
            }
        }
        return;
    }

    vector<string> wordBreak(string s, vector<string>& wordDict) {
        for(string &str:wordDict)
            map1[str]=1;
        recur(s,0);
        return ans;
    }
};
