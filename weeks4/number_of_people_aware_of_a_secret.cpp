class Solution {
public:
    int peopleAwareOfSecret(int n, int delay, int forget) {
        const int MOD = 1000000007;
        std::deque<int> q; 
        std::deque<std::pair<int, int>> v;
        
        // On day 1, 1 person knows the secret
        q.push_back(1);
        v.push_back({1 + delay, 1 + forget - 1});
      
        for (int day = 2; day <= n; ++day) {
            int count = 0;
            
            
            while (!v.empty() && v.front().second < day) {
                q.pop_front();
                v.pop_front();
            }
            
            
            for (int j = 0; j < q.size(); ++j) {
                int l = v[j].first; // start sharing day
                int r = v[j].second; // stop sharing day
                
                if (l <= day && day <= r) {
                    count = (count + q[j]) % MOD; 
                }
            }
            
      
            if (count > 0) {
                q.push_back(count);
                v.push_back({day + delay, day + forget - 1});
            }
        }
        
        
        long long ans = 0;
        for (int ele : q) {
            ans = (ans + ele) % MOD; 
        }
        
        return ans;
    }
};