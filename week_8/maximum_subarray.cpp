class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int currSubSum = nums[0];
        int maxSubSum = nums[0];

        for (int i = 1; i < nums.size(); i++)
        {
            currSubSum = max(nums[i], currSubSum + nums[i]);
            maxSubSum = max(maxSubSum, currSubSum);
        }

        return maxSubSum;
    }
};