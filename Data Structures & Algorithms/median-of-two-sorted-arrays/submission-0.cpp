class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();

        vector<int> merged;
        int i = 0; int j = 0;
        while(i < m || j < n){
            if(i == m){
                merged.push_back(nums2[j]);
                j++;
                continue;
            }
            if(j == n){
                merged.push_back(nums1[i]);
                i++;
                continue;
            }
            if(nums1[i] < nums2[j]){
                merged.push_back(nums1[i]);
                i++;
            }
            else{
                merged.push_back(nums2[j]);
                j++;
            }
        }
        if((m+n)%2 == 0){
            return (double)(merged[(m+n)/2] + merged[(m+n-2)/2])/2; 
        }
        else return merged[(m+n)/2];
    }
};