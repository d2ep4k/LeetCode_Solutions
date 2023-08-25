class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_map<string,bool>map1;
        unordered_map<string,bool>vis;
        unordered_map<string,int>dis;
        for(string &str:wordList){
            map1[str]=1;
        }
        if(map1[beginWord]!=1)
            map1[beginWord]=1;
        map<string,vector<string>>adj;
        for(string &str:wordList){
            vis[str]=0;
            dis[str]=0;
            for(int i=0;i<str.length();i++){
                string temp=str;
                for(char cur='a';cur<='z';cur++){
                    if(cur!=temp[i]){
                        temp[i]=cur;
                        if(map1[temp]==1){
                            adj[temp].push_back(str);
                            adj[str].push_back(temp);
                        }
                    }
                }
            }
        }
        queue<string>bfs;
        bfs.push(beginWord);
        vis[beginWord]=1;
        dis[beginWord]=1;
        while(!bfs.empty()){
            string node=bfs.front();
            bfs.pop();
            for(string str:adj[node]){
                if(vis[str]==0){
                    dis[str]=dis[node]+1;
                    vis[str]=1;
                    bfs.push(str);
                }
            }
        }
        return dis[endWord];
    }
};
