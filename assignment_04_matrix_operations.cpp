// =============================================================================
// PROGRAMMING FUNDAMENTALS — Assignment 4
// =============================================================================
//
// TASK: Matrix Operations
//
// Write a C++ program that performs three operations on matrices (2D arrays),
// each implemented in its own function.
//
// NOTE: Use a fixed maximum size of 10 for array dimensions.
//       Declare arrays as int matrix[10][10].
//
// -----------------------------------------------------------------------------
// PART A — Transpose a Matrix
// -----------------------------------------------------------------------------
// - Read an M x N matrix from the user.
// - Compute and display its transpose (rows become columns, columns become rows).
//
// Example (2 x 3 input):
//
//   Original Matrix:      Transposed Matrix:
//   1  2  3               1  4
//   4  5  6               2  5
//                         3  6
//
// -----------------------------------------------------------------------------
// PART B — Add Two Matrices
// -----------------------------------------------------------------------------
// - Read two matrices of exactly the same size (M x N).
// - Compute their element-wise sum and display the result.
//
// -----------------------------------------------------------------------------
// PART C — Multiply Two Matrices
// -----------------------------------------------------------------------------
// - Read matrix A of size M x N and matrix B of size N x P.
//   (Number of COLUMNS in A must equal number of ROWS in B.)
// - Compute and display the matrix product A x B (result is M x P).
//
// -----------------------------------------------------------------------------
// EXPECTED INPUT FORMAT
// -----------------------------------------------------------------------------
// The user enters each row's values one at a time:
//
//   Enter number of rows: 2
//   Enter number of columns: 3
//   Enter element [0][0]: 1
//   Enter element [0][1]: 2
//   ...
//
// -----------------------------------------------------------------------------
// REQUIREMENTS
// -----------------------------------------------------------------------------
// - Use nested loops for all operations (no external libraries).
// - Each operation must be in its own function (see scaffold below).
// - Display each matrix in a neat, aligned grid using setw().
// - Tip: Complete Part A first, then Parts B and C.
//

// =============================================================================
// YOUR CODE BELOW — remove the // symbols from the scaffold and fill it in
// =============================================================================

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

void readMatrix(int matrix[10][10], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << "Enter element [" << i << "][" << j << "]: ";
            cin >> matrix[i][j];
        }
    }
}

void displayMatrix(int matrix[10][10], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << setw(5) << matrix[i][j];
        }
        cout << endl;
    }
}

void transposeMatrix(int matrix[10][10], int rows, int cols, int result[10][10]) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[j][i] = matrix[i][j];
        }
    }
}

void addMatrices(int a[10][10], int b[10][10], int rows, int cols, int result[10][10]) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = a[i][j] + b[i][j];
        }
    }
}

void multiplyMatrices(int a[10][10], int b[10][10], int rowsA, int colsA, int colsB, int result[10][10]) {
    for (int i = 0; i < rowsA; i++) {
        for (int j = 0; j < colsB; j++) {
            int sum = 0;
            for (int k = 0; k < colsA; k++) {
                sum += a[i][k] * b[k][j];
            }
            result[i][j] = sum;
        }
    }
}

int main() {
    int matrixA[10][10], matrixB[10][10], resultMatrix[10][10];
    int rows, cols, rows2, cols2, colsB;

    // PART A - Transpose
    cout << "PART A: Transpose a Matrix" << endl;
    cout << "Enter number of rows: ";
    cin >> rows;
    cout << "Enter number of columns: ";
    cin >> cols;
    readMatrix(matrixA, rows, cols);

    cout << "\nOriginal Matrix:" << endl;
    displayMatrix(matrixA, rows, cols);

    transposeMatrix(matrixA, rows, cols, resultMatrix);
    cout << "\nTransposed Matrix:" << endl;
    displayMatrix(resultMatrix, cols, rows);

    // PART B - Add
    cout << "\nPART B: Add Two Matrices" << endl;
    cout << "Enter number of rows: ";
    cin >> rows2;
    cout << "Enter number of columns: ";
    cin >> cols2;

    int matrixC[10][10], matrixD[10][10], sumResult[10][10];
    cout << "Enter Matrix A:" << endl;
    readMatrix(matrixC, rows2, cols2);
    cout << "Enter Matrix B:" << endl;
    readMatrix(matrixD, rows2, cols2);

    addMatrices(matrixC, matrixD, rows2, cols2, sumResult);
    cout << "\nSum:" << endl;
    displayMatrix(sumResult, rows2, cols2);

    // PART C - Multiply
    cout << "\nPART C: Multiply Two Matrices" << endl;
    int rowsX, colsX, colsY;
    cout << "Enter rows for Matrix A: ";
    cin >> rowsX;
    cout << "Enter columns for Matrix A (rows for Matrix B): ";
    cin >> colsX;
    cout << "Enter columns for Matrix B: ";
    cin >> colsY;

    int matrixX[10][10], matrixY[10][10], productResult[10][10];
    cout << "Enter Matrix A:" << endl;
    readMatrix(matrixX, rowsX, colsX);
    cout << "Enter Matrix B:" << endl;
    readMatrix(matrixY, colsX, colsY);

    multiplyMatrices(matrixX, matrixY, rowsX, colsX, colsY, productResult);
    cout << "\nProduct:" << endl;
    displayMatrix(productResult, rowsX, colsY);

    return 0;
}