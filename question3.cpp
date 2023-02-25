#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;

int max_hourglass_sum(vector<vector<int>>& grid) {
    int m = grid.size();
    int n = grid[0].size();
    int max_sum = INT_MIN;

    
    for (int i = 1; i < m-1; i++) {
        for (int j = 1; j < n-1; j++) {
            int sum = grid[i][j] + grid[i-1][j] + grid[i+1][j] + grid[i-1][j-1] + grid[i-1][j+1] + grid[i+1][j-1] + grid[i+1][j+1];
            if (sum > max_sum) {
                max_sum = sum;
            }
        }
    }

    return max_sum;
}

int main() {
    int m, n;
    cout << "Enter the number of rows and columns (at least 3x3): ";
    cin >> m >> n;
    vector<vector<int>> grid(m, vector<int>(n, 0));
    cout << "Enter the elements of the matrix: " << endl;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }
    int max_sum = max_hourglass_sum(grid);
    cout << "The maximum hourglass sum is: " << max_sum << endl;
    return 0;
}
