class Solution {
public:
    int sieve[20002];
    int maxPoints(vector<vector<int>>& points) {
        memset(sieve,-1,sizeof(sieve));
        for(int i=2;i<2e4+2;i++){
            if(sieve[i]==-1){
                for(int j=i;j<2e4+2;j+=i){
                    if(sieve[j]==-1)
                        sieve[j]=i;
                }
            }
        }
        map<pair<pair<int,int>,int>,int>h;
        for(int i=0;i<points.size()-1;i++){
            for(int j=i+1;j<points.size();j++){

                int num=points[i][0]-points[j][0];
                int den=points[i][1]-points[j][1];
                
                int temp=abs(min(num,den));

                while(temp>1){
                    if(num%sieve[temp]==0&&den%sieve[temp]==0){
                        num/=sieve[temp];
                        den/=sieve[temp];
                    }
                    temp/=sieve[temp];
                }
                if(num<0&&den<0){
                    den*=-1;num*=-1;
                }
                else if(den<0){
                    den*=-1;num*=-1;
                }
                
                int intercept=den*points[i][0]-num*points[i][1];

                if(num==0){den=points[i][0];intercept=0;}
                else if(den==0){num=points[i][1];intercept=0;}

                
                h[{{den,num},intercept}]++;
            }
        }
        
        int ans=0;
        for(auto it:h){            
            ans=max(it.second,ans);
        }  
        
        return int((sqrt(4*(ans*2)+1)+1)/2);
    }
};
