#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> prefix_sum(vector<vector<int>> arr) {
    int m = arr.size();
    int n = arr[0].size();
    vector<vector<int>> prefix(m, vector<int>(n, 0));
    prefix[0][0] = arr[0][0];

    for (int j = 1; j < n; j++) {
        prefix[0][j] = prefix[0][j-1] + arr[0][j];
    }
    for (int i = 1; i < m; i++) {
        prefix[i][0] = prefix[i-1][0] + arr[i][0];
    }

    for (int i = 1; i < m; i++) {
        for (int j = 1; j < n; j++) {
            prefix[i][j] = prefix[i-1][j] + prefix[i][j-1] - prefix[i-1][j-1] + arr[i][j];
        }
    }

    return prefix;
}

int main() {
    int m, n;
    cout << "Enter the number of rows and columns: ";
    cin >> m >> n;
    vector<vector<int>> arr(m, vector<int>(n, 0));
    cout << "Enter the elements of the matrix: " << endl;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> arr[i][j];
        }
    }
    vector<vector<int>> prefix = prefix_sum(arr);
    cout << "The prefix sum matrix is: " << endl;
    for (int i = 0; i < prefix.size(); i++) {
        for (int j = 0; j < prefix[0].size(); j++) {
            cout << prefix[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
