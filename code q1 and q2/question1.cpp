#include <iostream>
#include <vector>
#include <cmath>

using namespace std;
void getCofactor(vector<vector<int>>& matrix, vector<vector<int>>& temp, int p, int q, int n) {
    int i = 0, j = 0;
    for (int row = 0; row < n; row++) {
        for (int col = 0; col < n; col++) {
            if (row != p && col != q) {
                temp[i][j++] = matrix[row][col];
                if (j == n - 1) {
                    j = 0;
                    i++;
                }
            }
        }
    }
}

int determinantOfMatrix(vector<vector<int>>& matrix, int n) {
    if (n == 1)
        return matrix[0][0];

    vector<vector<int>> temp(n, vector<int>(n));
    int det = 0;
    int sign = 1;

    for (int f = 0; f < n; f++) {
        getCofactor(matrix, temp, 0, f, n);
        det += sign * matrix[0][f] * determinantOfMatrix(temp, n - 1);
        sign = -sign;
    }

    return det;
}

int main() {
    int n;
    cout << "Enter the size of the matrix: ";
    cin >> n;

    vector<vector<int>> matrix(n, vector<int>(n));
    cout << "Enter the elements of the matrix:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> matrix[i][j];
        }
    }

    cout << "Determinant of the matrix is " << determinantOfMatrix(matrix, n) << endl;

    return 0;
}

