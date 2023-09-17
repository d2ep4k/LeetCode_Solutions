class Solution {
public:
    int calculate(string s) {
        stack<char>st;
        long result=0;
        long cur=0;
        long mul=1;
        for(char i:s){
            if(i==' ')continue;
            else if(i==')'){
                result=0;
                cur=0;
                mul=1;
                while(st.top()!='('){
                    char x=st.top();
                    if(x>='0'&& x<='9'){
                        cur+=mul*int(x-'0');
                        mul*=10;
                    }
                    else{
                        if(x=='+'){
                            result+=cur;
                            cur=0;mul=1;
                        }
                        else{
                            st.pop();
                            if(!st.empty()&&st.top()=='-')
                                result+=cur;
                            else{
                                st.push('-');
                                result-=cur;
                            }
                            cur=0;mul=1;
                        }
                    }
                    st.pop();                    
                }
                result+=cur;
                st.pop();
                string y="";
                if(result==0)st.push('0');
                if(result<0){
                    result*=-1;
                    st.push('-');
                }
                while(result>0){
                    y+=char('0'+result%10);
                    result/=10;
                }

                reverse(y.begin(),y.end());
                for(char i:y)
                    st.push(i);
            }
            else{
                st.push(i);
            }
        }
        result=0;
        cur=0;
        mul=1;
        while(!st.empty()){            
            char x=st.top();
            st.pop();
            if(x>='0'&& x<='9'){
                cur+=mul*int(x-'0');
                mul*=10;
            }
            else if(x=='+'){
                    result+=cur;
                    cur=0;mul=1;
                }
                else if(x=='-'){                    

                    if(!st.empty()&&st.top()=='-'){                        
                        st.pop();
                        result+=cur;
                    }
                    else{
                        result-=cur;
                    }
                    cur=0;mul=1;
                }
                             
        }
        result+=cur;
        return result;
    }
};
