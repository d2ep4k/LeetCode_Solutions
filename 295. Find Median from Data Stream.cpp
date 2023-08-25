struct minheap{        

        int val=2e5;
        minheap*l=nullptr;
        minheap*r=nullptr;
        minheap*prev=nullptr;

        void heapifydown(){
            if(l!=nullptr&&r!=nullptr){
                if(l->val<r->val){
                    if(this->val>l->val){
                        swap(this->val,l->val);
                        l->heapifydown();
                    }
                }else{
                    if(this->val>r->val){
                        swap(this->val,r->val);
                        r->heapifydown();
                    }
                }
            }
            else if(l!=nullptr){
                if(this->val>l->val){
                    swap(this->val,l->val);
                    l->heapifydown();
                }
            }
            else if(r!=nullptr){
                if(this->val>r->val){
                    swap(this->val,r->val);
                    r->heapifydown();
                }
            }
        }

        void heapifyup(){
            if(prev!=nullptr&&prev->val>this->val){
                swap(prev->val,this->val);
                prev->heapifyup();
            }
        }

    };
    

     struct maxheap{
               
        int val=-2e5;
        maxheap*l=nullptr;
        maxheap*r=nullptr;
        maxheap*prev=nullptr;

        void heapifydown(){
            if(l!=nullptr&&r!=nullptr){
                if(l->val>r->val){
                    if(this->val<l->val){
                        swap(this->val,l->val);
                        l->heapifydown();
                    }
                }else{
                    if(this->val<r->val){
                        swap(this->val,r->val);
                        r->heapifydown();
                    }
                }
            }
            else if(l!=nullptr){
                if(this->val<l->val){
                    swap(this->val,l->val);
                    l->heapifydown();
                }
            }
            else if(r!=nullptr){
                if(this->val<r->val){
                    swap(this->val,r->val);
                    r->heapifydown();
                }
            }
        }

        void heapifyup(){
            if(prev!=nullptr&&prev->val<this->val){
                swap(prev->val,this->val);
                prev->heapifyup();
            }
        }
    };
queue<minheap*>free1;
queue<maxheap*>free2;
class MedianFinder {
    int size;
    maxheap *left_half;
    minheap *right_half;

public:
    
    MedianFinder() {

        free1=queue<minheap*>();
        free2=queue<maxheap*>();

        left_half=nullptr;
        right_half=nullptr;
        size=0;

    }
    
    void addNum(int num) {
        if(size%2){
            if(right_half==nullptr){

                right_half=new minheap;

                free1.push(right_half);
                free1.push(right_half);

                right_half->val=num;
                if(right_half->val<left_half->val){
                    swap(right_half->val,left_half->val);
                }
                size++;

                return;
            }

            if(left_half->val>num){
                swap(left_half->val,num);
                left_half->heapifydown();
            }
            minheap*ptr=free1.front();
            free1.pop();
            minheap *child=new minheap;

            free1.push(child);
            free1.push(child);

            if(ptr->l==nullptr){                
                ptr->l=child;                
            }
            else{
                ptr->r=child;
            }
            child->prev=ptr;
            child->val=num;
            child->heapifyup();

        }
        else{
            if(left_half==nullptr){
                left_half=new maxheap;
                free2.push(left_half);
                free2.push(left_half);

                left_half->val=num;
                size++;
                return;

            }

            if(right_half->val<num){
                swap(right_half->val,num);
                right_half->heapifydown();
            }
            
            maxheap*ptr=free2.front();
            free2.pop();
            maxheap *child=new maxheap;

            free2.push(child);
            free2.push(child);

            if(ptr->l==nullptr){
                
                ptr->l=child;
            }
            else{
                ptr->r=child;
            }

            child->prev=ptr;
            child->val=num;
            child->heapifyup();

        }
        size++;
    }
    
    double findMedian() {
        if(size%2==0){        
            return double((left_half->val+right_half->val)*1.0/2.0);
        }
        return double(left_half->val);
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
