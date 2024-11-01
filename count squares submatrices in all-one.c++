#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0));
        
        int totalSquares = 0;
        
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (matrix[i][j] == 1) {
                    if (i == 0 || j == 0) {
                        // On the first row or first column
                        dp[i][j] = 1;
                    } else {
                        // Use the minimum of the top, left, and top-left neighbors
                        dp[i][j] = min({dp[i-1][j], dp[i][j-1], dp[i-1][j-1]}) + 1;
                    }
                    // Add the size of the square ending at (i, j) to total count
                    totalSquares += dp[i][j];
                }
            }
        }
        
        return totalSquares;
    }
};

        
    
