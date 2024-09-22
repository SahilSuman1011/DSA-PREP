//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function template for C++

class Solution {
  public:
    // Function to calculate the length of the longest proper prefix which is also a suffix
    int lps(string str) {
        int n = str.length();
        
        // Create an LPS array of the same length as the string
        vector<int> lpsArr(n, 0);
        
        int length = 0;  // Length of the previous longest prefix suffix
        int i = 1;       // LPS array calculation starts from the second character
        
        // Build the LPS array
        while (i < n) {
            if (str[i] == str[length]) {
                length++;
                lpsArr[i] = length;
                i++;
            } else {
                if (length != 0) {
                    // If mismatch after some matches, fallback to previous LPS value
                    length = lpsArr[length - 1];
                } else {
                    // If no matches, set LPS value to 0 and move forward
                    lpsArr[i] = 0;
                    i++;
                }
            }
        }
        
        // The value at the last index of LPS array gives the longest proper prefix-suffix length
        return lpsArr[n - 1];
    }
};


//{ Driver Code Starts.

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        string str;
        cin >> str;

        Solution ob;

        cout << ob.lps(str) << "\n";
    }

    return 0;
}

// } Driver Code Ends