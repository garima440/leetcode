class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();

        vector <int> result(n);
        result[0] = 1;

        // populate left
        for (int i = 1; i < n; i++)
        {
            result[i] = result[i - 1] * nums[i - 1];
        }

        int right = 1;
        // populate right
        for (int i = n - 1; i >= 0; i--)
        {
            result[i] = result[i] * right;
            right *= nums[i];
        }
        return result;
    }
};