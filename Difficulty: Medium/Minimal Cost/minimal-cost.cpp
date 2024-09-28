//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  
      public:
    int minimizeCost(int k, vector<int>& arr) {
        int n = arr.size();
        vector<int> dp(n, INT_MAX);  // Initialize DP array with INT_MAX
        dp[0] = 0;  // No cost to stay at the first stone
        
        // Outer loop: iterate over each stone from 1 to n-1
        for (int i = 1; i < n; ++i) {
            // Inner loop: check all previous stones within the range of k
            for (int j = 1; j <= k; ++j) {
                // Check if the previous stone exists
                if (i - j >= 0) {
                    dp[i] = min(dp[i], dp[i - j] + abs(arr[i] - arr[i - j]));
                }
            }
        }
        
        return dp[n - 1];  // Return the minimum cost to reach the last stone
    }

};

//{ Driver Code Starts.

int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);
    while (t--) {
        string ks;
        getline(cin, ks);
        int k = stoi(ks);
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution obj;
        int res = obj.minimizeCost(k, arr);
        cout << res << endl;
        // string tl;
        // getline(cin, tl);
    }
    return 0;
}

// } Driver Code Ends