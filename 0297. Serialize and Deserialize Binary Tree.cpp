/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
class Codec {
public:

    

    void intToString(string &str,int val){                         //converts integer to string inplace.

        if(val<0){                                                 //-ve value accomodation
            str+='-';
            val*=-1;
        }
        while(val>0){
            str+=char(val%10+'0');
            val/=10;
        }
        return;

    }

    void stringToInt(string &str,int &ind,TreeNode * node){       //converts string to integere untill next delimiter

        node->val=0;
        int offset=1;
        bool flag=false;

        if(str[ind]=='-'){                                        //-ve value flag
            ind++;
            flag=1;
        }

        while(str[ind]>='0'&&str[ind]<='9'){
            node->val+=int(str[ind]-'0')*offset;
            offset*=10;
            ind++;
        }
        
        node->val=flag?-node->val:node->val;                        

    }

    void helperCode(TreeNode* root,string&str){

        if(root==nullptr)return;

        intToString(str,root->val);

        if(root->left){
            str+='<';                                             //left-child delimeter   
            str+=serialize(root->left);
        }
      
        if(root->right){                
            str+='>';                                             //right-child delimeter       
            str+=serialize(root->right);
        }
      
        str+='^';                                                 //node-traversed(backtrack) delimeter
        return;

    }

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {

        string str;                                              //stores serialised data
        helperCode(root,str);                                    //dfs+data extraction
        return str;

    }

    TreeNode * helperDecode(string &data,int &ind){
        TreeNode * node = new TreeNode;

        stringToInt(data,ind,node);
        
        if(data[ind]=='<'){
            ind++;
            node->left=helperDecode(data,ind);
        }

        if(data[ind]=='>'){
            ind++;
            node->right=helperDecode(data,ind);            
        }

        ind++;
        return node;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {

        int ind=0;                                              
        if(data.empty())return nullptr;
        return helperDecode(data,ind);

    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
