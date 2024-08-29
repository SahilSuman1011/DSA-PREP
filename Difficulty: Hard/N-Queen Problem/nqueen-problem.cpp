//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> nQueen(int n) {
        vector<vector<int>> results;
        vector<int> board(n, 0);  // This will store the positions of queens.
        vector<bool> columns(n, false), diagonals1(2 * n - 1, false), diagonals2(2 * n - 1, false);
        solveNQueens(0, n, board, columns, diagonals1, diagonals2, results);
        return results;
    }

private:
    void solveNQueens(int col, int n, vector<int>& board, vector<bool>& columns, 
                      vector<bool>& diagonals1, vector<bool>& diagonals2, vector<vector<int>>& results) {
        if (col == n) {
            results.push_back(board);  // If all queens are placed, add the board to results.
            return;
        }
        
        for (int row = 0; row < n; ++row) {
            if (!columns[row] && !diagonals1[row - col + n - 1] && !diagonals2[row + col]) {
                // Place the queen
                board[col] = row + 1;  // Storing row in 1-indexed as per the problem statement
                columns[row] = diagonals1[row - col + n - 1] = diagonals2[row + col] = true;
                
                // Recur to place rest of the queens
                solveNQueens(col + 1, n, board, columns, diagonals1, diagonals2, results);
                
                // Backtrack
                columns[row] = diagonals1[row - col + n - 1] = diagonals2[row + col] = false;
            }
        }
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        
        Solution ob;
        vector<vector<int>> ans = ob.nQueen(n);
        if(ans.size() == 0)
            cout<<-1<<"\n";
        else {
            for(int i = 0;i < ans.size();i++){
                cout<<"[";
                for(int u: ans[i])
                    cout<<u<<" ";
                cout<<"] ";
            }
            cout<<endl;
        }
    }
    return 0;
}
// } Driver Code Ends