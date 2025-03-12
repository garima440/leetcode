class Solution {
public:
    int myAtoi(string s) {
        int idx = 0;
        int result = 0;
        int sign = 1;
        int len = s.length();

        // Skip whitespaces
        while (idx < len && s[idx] == ' ') {
            idx++;
        }

        // Check for sign (only once)
        if (idx < len && (s[idx] == '-' || s[idx] == '+')) {
            sign = (s[idx] == '-') ? -1 : 1;
            idx++;
        }

        // Process digits
        while (idx < len && isdigit(s[idx])) {
            int digit = s[idx] - '0';
            
            // Check for overflow
            if (result > INT_MAX/10 || (result == INT_MAX/10 && digit > INT_MAX % 10)) {
                return (sign == 1) ? INT_MAX : INT_MIN;
            }
            
            result = result * 10 + digit;
            idx++;
        }
        
        return result * sign;
    }
};