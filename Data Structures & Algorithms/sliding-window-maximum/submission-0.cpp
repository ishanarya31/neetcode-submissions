class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> res;
        int l = 0; int r = 0;
        multiset<int, greater<int>> maxHeap; 
        for(; r < k; r++){
            maxHeap.insert(nums[r]);
        }
        res.push_back(*maxHeap.begin());
        while(r < n){
            maxHeap.insert(nums[r]);
            r++;
            maxHeap.erase(maxHeap.find(nums[l]));
            l++;
            res.push_back(*maxHeap.begin());
        }
        return res;
    }
};