class Solution {
public:

    int getFact(int num){
        if(num <= 1) return 1;
        return getFact(num-1) * num;
    }

    string getPermutation(int n, int k) {
        set<char> nums;
        for(int i = 1; i<=n; i++){
            nums.insert(char('0'+i));
        }
        k--;
        string ans;
        while(!nums.empty()){
            int fact = getFact(nums.size()-1);
            char inPlace;
            int orderOfCur = k/fact;
            for(char i: nums){
                if(orderOfCur == 0){
                    inPlace = i;
                }
                orderOfCur--;
            }
            ans += inPlace;
            nums.erase(inPlace);
            k -= (k/fact)*fact;
        }
        return ans;
    }
};
