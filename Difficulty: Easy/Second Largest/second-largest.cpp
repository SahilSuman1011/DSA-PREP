//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
public:
    // Function returns the second
    // largest elements
    int print2largest(vector<int> &arr)
    {
        sort(arr.begin(), arr.end(), greater<int>());
        int n=arr.size();
        // start from second element as first
        // element is the largest
        for (int i = 1; i < n; i++) {
            // if the element is not equal to largest
            // element
            if (arr[i] != arr[0]) {
                return arr[i];
            }
        }
        return -1;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution ob;
        int ans = ob.print2largest(arr);
        cout << ans << endl;
    }
    return 0;
}

// } Driver Code Ends