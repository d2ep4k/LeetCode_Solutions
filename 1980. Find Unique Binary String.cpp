class Solution {
public:
    struct node{
        bool flag;
        node * child[2];

        node(){
            flag = false;
            for(int i = 0; i<2; i++)
                child[i] = nullptr;
        }
    };

    void mark(int n, string & mask, node * ptr){
        for(int i = 0; i<n ;i++){
            if(!ptr->child[mask[i] - '0']){
                ptr->child[mask[i] - '0'] = new node;
            }            
            ptr = ptr->child[mask[i]-'0'];
        }
        ptr->flag = 1;
    }

    string dfs(int ind, int n, node * cur, string &ans){
        if(ind == n){
            if(!cur->flag)
                return ans;
            else return "";
        }
        if(!cur->child[0]){
            cur->child[0] = new node;
        }
        ans.push_back('0');
        if(dfs(ind+1, n, cur->child[0], ans).length()){
            return ans;
        }
        ans.pop_back();
        if(!cur->child[1]){
            cur->child[1] = new node;
        }
        ans.push_back('1');
        if(dfs(ind+1, n, cur->child[1], ans).length()){
            return ans;
        }
        ans.pop_back();
        return "";
    }

    string findDifferentBinaryString(vector<string>& nums) {
        int n = nums[0].length();
        node * head = new node();
        for(int i = 0; i<nums.size(); i++)
            mark(n, nums[i], head);
        string ans;
        return dfs(0, n, head, ans);
    }
};
