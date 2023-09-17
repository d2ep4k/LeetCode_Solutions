class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        set<string>words;
        for(string str:wordList){
            words.insert(str);
        }    
        vector<vector<string>>ans;
        queue<vector<string>>bfs;
        bfs.push({beginWord});
        set<string>vis;
        while(!bfs.empty()){
            vector<string>seq=bfs.front();
            bfs.pop();
            string cur=seq.back();        
            cout<<cur<<" ";    
            if(cur==endWord){
                ans.emplace_back(seq);
                int anslen=seq.size();
                while(!bfs.empty()){
                    vector<string>restseq=bfs.front();
                    bfs.pop();
                    if(restseq.size()>anslen)break;
                    if(endWord==restseq.back())
                        ans.push_back(restseq);
                }
                return ans;
            }  
            string temp=cur;words.erase(temp);
            for(int i=0;i<cur.length();i++){
                char j=cur[i];
                for(char x='a';x<='z';x++){
                    cur[i]=x;
                    if(words.find(cur)!=words.end()&&vis.find(cur)==vis.end()&&cur!=temp){
                        seq.push_back(cur);
                        bfs.push(seq);
                        seq.pop_back();
                    }
                }
                cur[i]=j;
            }  
            
            
        }
        return ans;
    }
};
