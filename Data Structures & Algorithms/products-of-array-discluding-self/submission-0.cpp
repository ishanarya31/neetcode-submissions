class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        int count_zero = 0;
        vector<int > res(n,0);
        vector<int> pre(n,1); 
        vector<int> suff(n,1);
        pre[0] = 1;
        suff[n-1] = 1;
        for(int i =1; i< n; i++){
            pre[i] = nums[i-1] * pre[i-1];
            suff[n-i-1] = nums[n-i] * suff[n-i];
        }

        for(int i = 0 ; i< n; i++){
            res[i] = pre[i] * suff[i];
        }
        return res;
    }
};
