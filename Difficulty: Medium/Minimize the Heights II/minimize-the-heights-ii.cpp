//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
public:
    int getMinDiff(vector<int> &arr, int k) {
        // Sort the array first
        sort(arr.begin(), arr.end());
        int n = arr.size();
        
        // Initialize the difference between the largest and the smallest values
        int ans = arr[n - 1] - arr[0];
        
        // Traverse through the array and calculate new possible values
        for (int i = 1; i < n; i++) {
            // Ensure that subtracting k doesn't result in a negative value
            if (arr[i] - k < 0) {
                continue;
            }
            
            // Compute the maximum and minimum heights after adding/subtracting k
            int longest = max(arr[n - 1] - k, arr[i - 1] + k);
            int shortest = min(arr[0] + k, arr[i] - k);
            
            // Update the answer with the minimized difference
            ans = min(ans, longest - shortest);
        }
        return ans;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        int n, k;
        cin >> k;
        cin.ignore();
        vector<int> a, b, c, d;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int num;
        while (ss >> num)
            a.push_back(num);

        Solution ob;
        auto ans = ob.getMinDiff(a, k);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends