int dx[]={0,-1,0,1};
int dy[]={1,0,-1,0};

class Solution {    
public:    
    struct trie{
        bool weight=0;
        trie * child[26];
        trie(){
            for(int i=0;i<26;i++)
                child[i]=nullptr;
        }
    };

    void dfs(int i,int j,trie * ptr, string &cur, vector<string>&ans,vector<vector<bool>>&path,vector<vector<char>>& board){   
        if(ptr->weight){
            ans.push_back(cur);
            ptr->weight=0;
        }
        for(int k=0;k<4;k++){
            int x=i+dx[k],y=j+dy[k];
            if(x>=0&&x<path.size()&&y>=0&&y<path[0].size()&&ptr->child[board[x][y]-'a']!=nullptr&&path[x][y]==0){
                cur+=board[x][y];
                path[x][y]=1;
                dfs(x,y,ptr->child[board[x][y]-'a'],cur,ans,path,board);
                path[x][y]=0;
                cur.pop_back();
            }
        }
    }

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        trie * head = new trie ;
        trie * ptr = nullptr ;
        for(string &str : words){
            ptr = head;
            for(char &c : str){
                if(ptr->child[int(c-'a')] == nullptr){
                    ptr->child[int(c-'a')] = new trie;
                }
                ptr=ptr->child[int(c-'a')];
            }
            ptr->weight=1;
        }
        int n=board.size();
        int m=board[0].size();
        vector<string> ans;
        string cur="";
        vector<vector<bool>>path(n,vector<bool>(m,0));
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                ptr=head;
                if(ptr->child[board[i][j]-'a']!=nullptr){
                    cur+=board[i][j];
                    path[i][j]=1;                    
                    dfs(i,j,ptr->child[board[i][j]-'a'],cur,ans,path,board);
                    path[i][j]=0;
                    cur.pop_back();
                }
            }
        }
        return ans;
    }
};
