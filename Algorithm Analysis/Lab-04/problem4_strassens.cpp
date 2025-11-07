#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> add(const vector<vector<int>> &a, const vector<vector<int>> &b, int n, int sign = 1) {
    vector<vector<int>> res(n, vector<int>(n));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            res[i][j] = a[i][j] + sign * b[i][j];
    return res;
}

vector<vector<int>> strassen(const vector<vector<int>> &mat1, const vector<vector<int>> &mat2) {
    int n = mat1.size();
    vector<vector<int>> res(n, vector<int>(n, 0));
    if (n == 1) {
        res[0][0] = mat1[0][0] * mat2[0][0];
        return res;
    }
    int newSize = n / 2;
    vector<vector<int>> a11(newSize, vector<int>(newSize)), a12(newSize, vector<int>(newSize)), a21(newSize, vector<int>(newSize)), a22(newSize, vector<int>(newSize));
    vector<vector<int>> b11(newSize, vector<int>(newSize)), b12(newSize, vector<int>(newSize)), b21(newSize, vector<int>(newSize)), b22(newSize, vector<int>(newSize));
    for (int i = 0; i < newSize; i++)
        for (int j = 0; j < newSize; j++) {
            a11[i][j] = mat1[i][j]; a12[i][j] = mat1[i][j + newSize]; a21[i][j] = mat1[i + newSize][j]; a22[i][j] = mat1[i + newSize][j + newSize];
            b11[i][j] = mat2[i][j]; b12[i][j] = mat2[i][j + newSize]; b21[i][j] = mat2[i + newSize][j]; b22[i][j] = mat2[i + newSize][j + newSize];
        }
    auto m1 = strassen(add(a11, a22, newSize), add(b11, b22, newSize));
    auto m2 = strassen(add(a21, a22, newSize), b11);
    auto m3 = strassen(a11, add(b12, b22, newSize, -1));
    auto m4 = strassen(a22, add(b21, b11, newSize, -1));
    auto m5 = strassen(add(a11, a12, newSize), b22);
    auto m6 = strassen(add(a21, a11, newSize, -1), add(b11, b12, newSize));
    auto m7 = strassen(add(a12, a22, newSize, -1), add(b21, b22, newSize));
    auto c11 = add(add(m1, m4, newSize), add(m7, m5, newSize, -1), newSize);
    auto c12 = add(m3, m5, newSize);
    auto c21 = add(m2, m4, newSize);
    auto c22 = add(add(m1, m3, newSize), add(m6, m2, newSize, -1), newSize);
    for (int i = 0; i < newSize; i++)
        for (int j = 0; j < newSize; j++) {
            res[i][j] = c11[i][j]; res[i][j + newSize] = c12[i][j]; res[i + newSize][j] = c21[i][j]; res[i + newSize][j + newSize] = c22[i][j];
        }
    return res;
}

int main() {
    int n;
    cin >> n;
    vector<vector<int>> mat1(n, vector<int>(n)), mat2(n, vector<int>(n));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> mat1[i][j];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> mat2[i][j];
    vector<vector<int>> res = strassen(mat1, mat2);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            cout << res[i][j] << " ";
        cout << endl;
    }
    return 0;
}
