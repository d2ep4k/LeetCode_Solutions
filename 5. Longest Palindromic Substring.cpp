class Solution {
public:

    string manacher(string &str){
  
        string tweakedStr;
        vector<int>maxPalindrome((2*str.length())+1,0);

        tweakedStr+='*'; 
        for(int i=0;i<str.length();i++){
            tweakedStr+=str[i];
            tweakedStr+='*'; 
        }

        int ans = 0, mid = 1, right = 1;

        for(int i=0;i<tweakedStr.length();i++)
        {     
            maxPalindrome[i]=max(0,min(maxPalindrome[2*mid-i],right-i));
            int ind = maxPalindrome[i];
            while(i-ind-1>=0&&i+ind+1<tweakedStr.length()&&tweakedStr[i-ind-1]==tweakedStr[i+ind+1]){
                ind++;
            }
            maxPalindrome[i] = ind;
            if(maxPalindrome[i]>maxPalindrome[ans]){
                ans=i;
            }            
            if( i+ind >= right ){
                right = i+ind;
                mid = i;
            }
        }

        string maxPalin;
        for(int i=ans-maxPalindrome[ans];i<=ans+maxPalindrome[ans];i++)
            if(tweakedStr[i]!='*')
                maxPalin+=tweakedStr[i];
        return maxPalin;
    }

    string longestPalindrome(string s) {
        return manacher(s);
    }
};
