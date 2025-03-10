class Solution {
public:

    bool allZero(vector<int>& counter)
    {
        for (int &count : counter)
        {
            if (count != 0)
            {
                return false;
            }
        }
        return true;
    }

    vector<int> findAnagrams(string s, string p) {
        vector<int> result;

        int n = s.size();
        vector<int>counter (26, 0);

        for (int i = 0; i < p.length(); i++)
        {
            char ch = p[i];
            counter[ch - 'a']++;
        }

        int i = 0, j = 0;
        int k = p.length();
        while(j < n)
        {
            counter[s[j] - 'a']--;

            if (j - i + 1 == k)
            {
                if (allZero(counter))
                {
                    result.push_back(i);
                }
                counter[s[i] - 'a']++;
                i++;
            }
            j++;
        }
        return result;

    }
};