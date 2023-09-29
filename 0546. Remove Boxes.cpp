class Solution {
public:

    int getmax(vector<int>&boxes,int cur,int left,int right,vector<vector<vector<int>>>& dp){
        if(left>right)  return 0;
        if(dp[left][right][cur]!=-1)    return dp[left][right][cur];

        while(left+1<right&&boxes[left]==boxes[left+1]){            //to reduce no of calls(not mandatory)
            return dp[left][right][cur] = getmax(boxes,cur+1,left+1,right,dp);
        }

        int ans = (cur+1)*(cur+1);
        
        for(int i=left+1;i<=right;i++){
            if(boxes[i]==boxes[left]){
                ans=max(ans,getmax(boxes,0,left+1,i-1,dp)+getmax(boxes,cur+1,i,right,dp));
            }
            else{
                ans=max(ans,(cur+1)*(cur+1)+getmax(boxes,0,left+1,i-1,dp)+getmax(boxes,0,i,right,dp));
            }
        }
        return dp[left][right][cur]=ans;

    }

    int removeBoxes(vector<int>& boxes) {
        vector<vector<vector<int>>> dp(boxes.size(),vector<vector<int>>(boxes.size(),vector<int>(boxes.size()+1,-1)));
        return getmax(boxes,0,0,boxes.size()-1,dp);
    }
};
