struct node{                      //linked list acts as stack
    int val;
    node* prev=nullptr;
};

class FreqStack {
public:
    int maxFrequency;            //current maximum frequency
    vector<node*>order;          //order[i] -> store relative ordering of insertion(lifo) for i(th) occurrence of element 
    map<int,int>frequency;       //store frequency count of elements
                                   
    FreqStack() {
        maxFrequency=0;
        order=vector<node*>(2e4+1,nullptr);
    }
    
    void push(int val) {
        int curFrequency = frequency[val]++;
        maxFrequency = max(maxFrequency, curFrequency);
        node * newNode = new node;
        newNode->prev = order[curFrequency];
        order[curFrequency] = newNode;
        newNode->val = val;               
    }

    
    int pop() {
        node * poppedNode = order[maxFrequency];
        order[maxFrequency] = order[maxFrequency]->prev;
        int popped = poppedNode->val;
        delete poppedNode;
        frequency[popped]--;
        if(!order[maxFrequency])
            maxFrequency--;
        return popped;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */
