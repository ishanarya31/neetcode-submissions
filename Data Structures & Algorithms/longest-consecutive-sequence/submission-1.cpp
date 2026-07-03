class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        if(n == 0) return 0;
        set<int> numbs;
        for(int i =0; i< n; i++){
            numbs.insert(nums[i]);
        }
        int res = 1;
        int prev = INT_MIN;
        int cnt = 1;
        for(auto & it : numbs){
            int curr = it;
            if(curr == prev + 1){
                cnt++;
                res = max(res ,cnt);
                prev = curr;
            }
            else{
                cnt = 1;
                prev = curr;
            }
        }
        return res;
    }
};
