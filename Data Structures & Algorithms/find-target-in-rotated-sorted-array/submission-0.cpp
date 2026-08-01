class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int l = 0 ; int r = n-1;
        int mid = 0;
        while(l <= r){
            mid = (r-l)/2 + l;
            if(nums[mid] > nums[r]){
                l = mid+1;
            }
            else if(nums[mid] < nums[r]){
                r = mid;
            }
            else{
                mid = r;
                break;
            }
        }

        if(mid != 0){
            int nl = 0;
            int nr = mid-1;
            int ml = mid;
            int mr = n-1;

            while(nl <= nr){
                int nmid = (nr-nl)/2 + nl;
                if(nums[nmid] > target){
                    nr = nmid-1;
                }
                else if(nums[nmid] < target){
                    nl = nmid+1;
                }
                else return nmid;
            }
            while(ml <= mr){
                int mmid = (mr-ml)/2 + ml;
                if(nums[mmid] > target){
                    mr = mmid-1;
                }
                else if(nums[mmid] < target){
                    ml = mmid+1;
                }
                else return mmid;
            }
        }
        else{
            l = 0; r = n-1;
            while(l <= r){
                mid = (r-l)/2 + l;
                if(nums[mid] > target){
                    r = mid-1;
                }
                else if(nums[mid] < target){
                    l = mid+1;
                }
                else return mid;
            }
        }
        return -1;
    }
};