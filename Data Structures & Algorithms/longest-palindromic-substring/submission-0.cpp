class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        int resLen = 0 ; string res = "";
        for(int i = 0 ; i< n; i++){
            //odd length palindromes
            int l = i; int r = i;
            while(l >= 0 && r < n && s[r] == s[l]){
                if(r-l+1 > resLen){
                    resLen = r-l+1;
                    res = s.substr(l, r-l+1);
                }
                r++;
                l--;
            }
            //even case
            l = i; r = i+1;
            while(l >= 0 && r < n && s[r] == s[l]){
                if(r-l+1 > resLen){
                    resLen = r-l+1;
                    res = s.substr(l, r-l+1);
                }
                r++;
                l--;
            }
        }
        return res;
    }
};
