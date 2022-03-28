// Day 06(02) Name: Vivek Khandelwal
#include <bits/stdc++.h>
using namespace std;
typedef vector<vector<int>> M;
// Date:23-03-2022
// Learnt => How To Calculate Transpose
void printMatrix(M &matrix)
{
    int n = matrix.size();
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}
/*
 * clockwise rotate
 * first reverse up to down, then swap the symmetry
 * 1 2 3     7 8 9     7 4 1
 * 4 5 6  => 4 5 6  => 8 5 2
 * 7 8 9     1 2 3     9 6 3
 */

void clockWiseRotate(M matrix)
{
    int n = matrix.size();
    reverse(matrix.begin(), matrix.end());
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            swap(matrix[i][j], matrix[j][i]);
        }
    }
    printMatrix(matrix);
}

/*
 * Anti-clockwise rotate
 * first reverse left to right, then swap the symmetry
 * 1 2 3     3 2 1     3 6 9
 * 4 5 6  => 6 5 4  => 2 5 6
 * 7 8 9     9 8 7     1 4 7
 */

void antiClockWiseRotate(M matrix)
{
    int n = matrix.size();
    for (auto vi : matrix)
        reverse(vi.begin(), vi.end());
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            swap(matrix[i][j], matrix[j][i]);
        }
    }
    printMatrix(matrix);
}

void transposeMatrix(M &matrix)
{
    int n = matrix[0].size();
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            swap(matrix[i][j], matrix[j][i]);
        }
    }
}
//* ROTATE by 90*
/*
 * Anti-clockwise rotate
 * first Transpose Matrix ,then reverse rows
 * 1 2 3     3 2 1     3 6 9
 * 4 5 6  => 6 5 4  => 2 5 6
 * 7 8 9     9 8 7     1 4 7
 */
void rotateImage(M matrix)
{
    //?STEP 1: Calculate Transpose
    int n = matrix[0].size();
    transposeMatrix(matrix);
    //?STEP 2: Reverse Rows in Matrix
    for (int i = 0; i < n; i++)
    {
        reverse(matrix[i].begin(), matrix[i].end());
    }
    printMatrix(matrix);
}

int main()
{
    M matrix = {{5, 1, 9, 11}, {2, 4, 8, 10}, {13, 3, 6, 7}, {15, 14, 12, 16}};
    clockWiseRotate(matrix);
}