#include <iostream>
using namespace std;

int maxSumRow(int arr[][100], int m, int n) {
    int maxSum = -1, maxRow = -1;
    
    for (int i = 0; i < m; i++) {
        int sum = 0;
        for (int j = 0; j < n; j++) {
            sum += arr[i][j];
        }
        if (sum > maxSum) {
            maxSum = sum;
            maxRow = i + 1;
        }
    }
    
    return maxRow;
}

int main() {
    int m, n;
    cout << "Enter the number of rows and columns: ";
    cin >> m >> n;
    
    int arr[100][100];
    cout << "Enter the elements of the matrix: " << endl;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> arr[i][j];
        }
    }
    
    int maxRow = maxSumRow(arr, m, n);
    cout << "Row with maximum sum: " << maxRow << endl;
    
    return 0;
}
