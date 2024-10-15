class Solution {
public:
    long long minimumSteps(string s) {
        int n = s.length();
        int r = n - 1;
        long long cnt = 0;
        long long ans = 0;
        while (r >= 0) {
            if (s[r] == '0') {
                cnt++;
            } else {
                ans += cnt;
            }
            r--;
        }
        return ans;
    }
};