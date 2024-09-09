//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
   void sort012(vector<int>& arr) {
        // code here
        int n = arr.size(), zero = 0, two = n-1, i = 0;
        while(i<=two){
            if(arr[i]==0){
                swap(arr[zero],arr[i]);
                zero++;
            }
            else if(arr[i]==2){
                swap(arr[i],arr[two]);
                two--;
                i--;
            }
            i++;
        }
    }

};

//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {

        vector<int> a;
        string input;
        int num;

        getline(cin, input);
        stringstream s2(input);
        while (s2 >> num) {
            a.push_back(num);
        }
        Solution ob;
        ob.sort012(a);

        int n = a.size();
        for (int i = 0; i < n; i++) {
            cout << a[i] << " ";
        }

        cout << endl;
    }
    return 0;
}

// } Driver Code Ends