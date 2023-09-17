struct node{
    int val=-1;
    node *prev=nullptr;
    node *next=nullptr;
};

class LFUCache {
public:
    int min,cap;
    const int head=-1,tail=100001;
    
    unordered_map<int,pair<int,int>>freq;
    unordered_map<int,unordered_map<int,node*>>dll;
    LFUCache(int capacity) {
        cap=capacity;
        min=-1;
    }

    int getmin(){
        return dll[min][tail]->prev->val;
    }
    
    void remove(int key,int freq){     

        dll[freq][key]->next->prev=dll[freq][key]->prev;
        dll[freq][key]->prev->next=dll[freq][key]->next;

        delete dll[freq][key];

        dll[freq].erase(key);
    }

    void insert(int key,int freq){      
        
        if(dll.find(freq)==dll.end()){
            dll[freq][head]=new node;
            dll[freq][tail]=new node;
            dll[freq][tail]->val=tail;
            dll[freq][head]->val=head;
            dll[freq][head]->next=dll[freq][tail];
            dll[freq][tail]->prev=dll[freq][head];
        }

        dll[freq][key]=new node;
        dll[freq][key]->val=key;

        dll[freq][key]->next=dll[freq][head]->next;
        dll[freq][head]->next->prev=dll[freq][key];        

        dll[freq][head]->next=dll[freq][key];
        dll[freq][key]->prev=dll[freq][head];

    }

    int get(int key) {
        if(freq.find(key)==freq.end())
            return -1;
        else{
            remove(key,freq[key].second);
            if(dll[freq[key].second].size()==2){
                if(min==freq[key].second)
                    min++;
            }
            insert(key,++freq[key].second);            
            return freq[key].first;
        }
    }
    
    void put(int key, int value) { 
        if(freq.find(key)!=freq.end()){            
            remove(key,freq[key].second);
            freq[key].first=value;
            if(dll[freq[key].second].size()==2){
                if(min==freq[key].second)
                    min++;
            }
            insert(key,++freq[key].second);
            return;
        } 
        if(cap==0){
            freq.erase(getmin());
            remove(getmin(),min);
        }
        else{
            cap--;
        }
        min=1;
        freq[key]={value,1};
        insert(key,1);
    }
};
/*
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
