class Solution {
public:
    int longestCommonSubsequence(string t1, string t2) {
        int n1 = t1.size();
        int n2 = t2.size();

        vector<int> prev(n2+1);
        
        for(int i = n1-1; i >= 0; i--){
            vector<int> curr(n2+1, 0);
            for(int j = n2-1; j >= 0; j--){
                if(t1[i] == t2[j]){
                    curr[j] = 1 + prev[j+1];
                }
                else{
                    curr[j] = max(prev[j] , curr[j+1]);
                }
            }
            prev = curr;
        }

        return prev[0];
    }
};