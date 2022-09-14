class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        vector<int> ans{-1, -1};
        if (right == -1) {
            return ans;
        }
        
        while (left < right) {
            int mid = (left + right) / 2;
            
            if (nums[mid] < target) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        if (nums[left] == target) {
            ans[0] = left;
        }
        
        left = 0, right = nums.size() - 1;
        while (left < right) {
            int mid = (left + right + 1) / 2;
            
            if (nums[mid] > target) {
                right = mid - 1;
            } else {
                left = mid;
            }
        }
        if (nums[left] == target) {
            ans[1] = left;
        }
        
        return ans;
    }
};