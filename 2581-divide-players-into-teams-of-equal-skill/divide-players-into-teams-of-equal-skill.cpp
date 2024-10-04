class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        int n = skill.size() ;
        int teams = n/2 ;
        int totalSum = 0 ;
        for (int i=0; i<n; i++){
            totalSum += skill[i] ;
        }
        if (totalSum % teams != 0) return -1 ;
        int targetSum = totalSum / teams ;

        sort(skill.begin(), skill.end()) ;

        long long int ans = 0 ;
        for (int i=0; i<teams; i++){
            int sum = skill[i] + skill[n-1-i] ;
            if (sum != targetSum) return -1 ;
            int prod = skill[i] * skill[n-1-i] ;
            ans += prod ;
        }
        return ans ;
    }
};