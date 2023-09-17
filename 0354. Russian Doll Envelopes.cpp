class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        int n=envelopes.size();
        vector<int> dp(n,100001);
        int ind=0;
        vector<int>v;
        sort(envelopes.begin(),envelopes.end());
        for(int i=0;i<n;){
            int low=0,high=ind;
            while(low<high){
                int mid=(low+high)/2;
                if(dp[mid]<envelopes[i][1])
                    low=mid+1;
                else
                    high=mid;
            }
            if(low==ind&&dp[low]<envelopes[i][1]){
                low++;
            }
            dp[low]=envelopes[i][1];
            ind=max(ind,low);            
            i++;
        }
        return ind+1;
    }
};
