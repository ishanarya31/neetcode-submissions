class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        unordered_map<int, int> map;
        vector<int> res;
        for(int i = 0 ; i< n; i++){
            int diff = target - nums[i];
            if(map.count(diff)){
                res.push_back(map[diff]);
                res.push_back(i);                
                break;
            }
            else{
                map[nums[i]] = i;
            }
        }
        return res;
    }
};
