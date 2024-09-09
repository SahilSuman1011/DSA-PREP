class Solution {
public:
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        vector<vector<int>> matrix(m, vector<int>(n, -1));

        int id = 0; // Direction: 0 -> left to right, 1 -> top to bottom, 2 -> right to left, 3 -> bottom to top
        int top = 0, down = m - 1, left = 0, right = n - 1;

        while (top <= down && left <= right) {
            if (id == 0) { // left to right
                for (int i = left; head != nullptr && i <= right; i++) {
                    matrix[top][i] = head->val;
                    head = head->next;
                }
                top++;
            } 
            else if (id == 1) { // top to bottom
                for (int i = top; head != nullptr && i <= down; i++) {
                    matrix[i][right] = head->val;
                    head = head->next;
                }
                right--;
            } 
            else if (id == 2) { // right to left
                for (int i = right; head != nullptr && i >= left; i--) {
                    matrix[down][i] = head->val;
                    head = head->next;
                }
                down--;
            } 
            else if (id == 3) { // bottom to top
                for (int i = down; head != nullptr && i >= top; i--) {
                    matrix[i][left] = head->val;
                    head = head->next;
                }
                left++;
            }

            // Update the direction (0 -> 1 -> 2 -> 3 -> back to 0)
            id = (id + 1) % 4;
        }

        return matrix;
    }
};

