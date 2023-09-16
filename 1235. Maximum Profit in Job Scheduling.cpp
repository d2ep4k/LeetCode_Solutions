//  0/1 knap-sack dp --> dp[i] denotes the maximum profit possible till endTime[i] given the jobs (0 to i). 

struct job{
    int start,end,profit;
};

bool cmp(job& a,job& b){
    return a.end<b.end;
}

class Solution {
public:

    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {

        vector<job>jobs(profit.size());
        for(int i=0;i<profit.size();i++){
            jobs[i].start = startTime[i];
            jobs[i].profit = profit[i];
            jobs[i].end = endTime[i];
        }
        sort(jobs.begin(),jobs.end(),cmp);
        
        vector<int>dp(profit.size(),0);

        for(int i=0;i<profit.size();i++){

            if(i==0){                               //base cond.
                dp[i]=jobs[i].profit;
                continue;
            }

            dp[i]=dp[i-1];                          //don't take

            int low=0,high=i-1;                     //take 
            while(low<high){                  
                int mid=(low+high+1)>>1;
                if(jobs[mid].end<=jobs[i].start){
                    low=mid;
                }
                else{
                    high=mid-1;
                }
            }
            
            if(jobs[low].end<=jobs[i].start){      //optimal profit before current job
                dp[i]=max(dp[i],jobs[i].profit+dp[low]);
            }
            else{
                dp[i]=max(jobs[i].profit,dp[i]);
            }           

        }
        return dp.back();

    }
};
