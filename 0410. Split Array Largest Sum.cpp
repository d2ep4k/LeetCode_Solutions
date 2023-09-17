class Solution {
public:

    //method 1: binary search

    int splitArray(vector<int>& nums, int k) {
        int low=0,high=0;
        for(int i=0;i<nums.size();i++){
            low=max(low,nums[i]);
            high+=nums[i];
        }
        int temp=0,kdash=0,mid;
        while(low<high){
            mid=low+(high-low)/2;
            temp=0,kdash=0;
            for(int i=0;i<nums.size();i++){
                temp+=nums[i];
                if(temp>mid){
                    kdash++;
                    temp=nums[i];
                }
            }
            if(kdash+1<=k)
                high=mid;
            else
                low=mid+1;
        }
        return high;
    }


    // method 2 : dynamic programming 
    
    // int splitArray(vector<int>& nums, int k) {
    //     int dp[nums.size()][k];
    //     int temp=0;
    //     for(int i=0;i<nums.size();i++){
    //         dp[i][0]=temp=max(0,nums[i]+temp);
    //     }        
    //     for(int j=1;j<k;j++){
    //         for(int i=nums.size()-1;i>=j;i--){
    //             dp[i][j]=1111111111;
    //             int temp=max(nums[i],0);
    //             for(int l=i-1;l>=j-1;l--){                   
    //                 dp[i][j]=min(dp[i][j],max(temp,dp[l][j-1]));
    //                 temp=max(0,nums[l]+temp);
    //             }
    //         }
    //     }
    //     return dp[nums.size()-1][k-1];
    // }

};
