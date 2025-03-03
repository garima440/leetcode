class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int>result;

        int i = 0;
        int j = numbers.size() - 1;

        while(i < j)
        {
            if (numbers[i] + numbers[j] < target)
            {
                i++;
            }
            else if (numbers[i] + numbers[j] > target)
            {
                j--;
            }
            else
            {
                i++;
                j++;
                result.push_back(i);
                result.push_back(j);
                break;
            }
        }
        return result;
    }
};