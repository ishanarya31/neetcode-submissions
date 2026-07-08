class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        for (int i = 0; i < n; i++) {
            if (i > 0 && nums[i] == nums[i-1]) continue;  // skip duplicate i

            int trgt = -nums[i];
            int l = i + 1;
            int r = n - 1;

            while (l < r) {
                int sum = nums[l] + nums[r];
                if (sum == trgt) {
                    res.push_back({nums[i], nums[l], nums[r]});
                    l++;
                    r--;
                    while (l < r && nums[l] == nums[l-1]) l++;
                    while (l < r && nums[r] == nums[r+1]) r--;
                }
                else if (sum > trgt) {
                    r--;
                }
                else {
                    l++;
                }
            }
        }
        return res;
    }
};
