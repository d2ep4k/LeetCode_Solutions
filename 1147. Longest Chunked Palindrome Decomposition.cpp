class Solution {
public:
    int longestDecomposition(string text) {
        int left = 0, right = 0, ans = 0;
        while(right < text.length()/2){
            int leftc = text.length() - 1 - right;
            bool ispalin = true;
            for(int i = left, j = leftc; i <= right; i++,j++){
                if(text[i] != text[j]){
                    ispalin = false;
                }
            }
            if(ispalin){
                ans+=2;
                left = right + 1; 
            }
            right++;
        }
        if(left != right || text.length()%2){
            ans++;
        }
        return ans;
    }
};
