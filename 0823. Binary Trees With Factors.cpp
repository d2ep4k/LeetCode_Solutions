class Solution {
public:
    int numFactoredBinaryTrees(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        map<long long,int> dp;
        int trees = 0;
        for(int i=0; i<arr.size(); i++){
            int ans = 1; 
            for(int j = 0 ; j<i && 1ll*arr[j]*arr[j] <= 1ll*arr[i]; j++){
                if(((arr[i]%arr[j]) == 0) && (dp.find(arr[i]/arr[j]) != dp.end())){
                    ans = (ans + (1ll*dp[arr[j]]*dp[arr[i]/arr[j]])%1000000007)%1000000007;
                    if(arr[j] != arr[i]/arr[j])
                        ans = (ans + (1ll*dp[arr[j]]*dp[arr[i]/arr[j]])%1000000007)%1000000007;
                }
            }
            dp[arr[i]] = ans; 
            trees = (trees + ans)%1000000007;
        }
        return trees;
    }
};
