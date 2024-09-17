//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int maxLength(string& str) {
        // corrected variable names to avoid conflict with std::max
        int mx=0, op=0, cl=0, mx2=0;
        
        // Forward iteration
        for(int i=0; i < str.length(); i++) {
            if(str[i] == '(') op++;
            else cl++;
            
            if(cl > op) cl = op = 0;  // Reset if more closing brackets
            if(cl == op) mx = std::max(mx, op * 2);
        }
        
        op = cl = 0;
        
        // Backward iteration
        for(int i = str.length() - 1; i >= 0; i--) {
            if(str[i] == '(') op++;
            else cl++;
            
            if(op > cl) op = cl = 0;  // Reset if more opening brackets
            if(op == cl) mx2 = std::max(mx2, op * 2);
        }
        
        return std::max(mx, mx2);  // Return the maximum of both directions
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin >> S;

        Solution ob;
        cout << ob.maxLength(S) << "\n";
    }
    return 0;
}
// } Driver Code Ends