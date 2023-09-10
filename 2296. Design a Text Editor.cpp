/*
*Intuition*

The task can be done by a data structure that could insert, delete, and traverse (both directions) in constant time. 
The cursor itself determines the position of insertion and deletion, so it is not arbitrary but rather identical to earlier calls.
Appropriate DS. :

Doubly linked list
Array x 2

--------------------------------------------------------------------------------------------------------------------------------------------------------------------------

*Approach*

Using doubly linked list to store text and traverse, the cursor position is stored in a pointer and is consequently referred to during updating, deleting, and traversing.

Add : Insert node(s) from cursor onwards (cursor increments leftwards).
Delete : Delete node(s) from cursor onwards (cursor increments rightwards).
Move : Traverse 'cursor' through nodes as intended.

--------------------------------------------------------------------------------------------------------------------------------------------------------------------------

*Complexity*

Time complexity:
O(k) per call

Space complexity:
O(n)

*/

//doubly linked list 

class node{
    public:
    char ch;
    node * left=nullptr;
    node * right=nullptr;
};

static string ans="";

class TextEditor {
    public:    
    node * cursor=nullptr;    //cursor's position is btw pointer 'cursor' and 'cursor->right'
    node * head=nullptr;
    node * tail=nullptr;
    

    TextEditor() {
        head=new node;
        tail=new node;
        cursor=head;
        head->right=tail;
        tail->left=head;        
    }
    
    void addText(string text) {
        for(char c:text){

            node * temp = new node;
            temp -> ch = c;    

            cursor -> right -> left = temp;         // inserting nodes in DLL
            temp -> right = cursor -> right ;
            cursor -> right = temp;
            temp -> left = cursor;

            cursor = cursor -> right;
        }
    }
    
    int deleteText(int k) {
        int charDeleted=0;
        while(k--){
            if(cursor!=head){

                cursor->left->right=cursor->right;
                cursor->right->left=cursor->left;
                                
                node * temp = cursor;      
                cursor = cursor->left;          
                delete temp; // deleting node from DLL 

                charDeleted++; // increment count
            }
        }
        return charDeleted;
    }
    
    string cursorLeft(int k) {
        ans.clear();
        while(k--){     // traverse left
            if(cursor!=head){
                cursor=cursor->left;
            }
        }
        node * temp = cursor;
        k=10;
        while(k--){     
            if(temp!=head){
                ans+=temp->ch;
                temp=temp->left;
            }
        }
        for(int i=0;i<ans.length()/2;i++)   //reversal of str
            swap(ans[i],ans[ans.length()-1-i]);
        return ans;
    }
    
    string cursorRight(int k) {
        ans.clear();
        while(k--){     //traverse right
            if(cursor->right!=tail){                
                cursor=cursor->right;
            }
        }
        node * temp = cursor ;
        k=10;
        while(k--){
            if(temp!=head){
                ans+=temp->ch;
                temp=temp->left;
            }
        }
        for(int i=0;i<ans.length()/2;i++) //reversal of str
            swap(ans[i],ans[ans.length()-1-i]);
        return ans;
    }

};

/**
 * Your TextEditor object will be instantiated and called as such:
 * TextEditor* obj = new TextEditor();
 * obj->addText(text);
 * int param_2 = obj->deleteText(k);
 * string param_3 = obj->cursorLeft(k);
 * string param_4 = obj->cursorRight(k);
 */
