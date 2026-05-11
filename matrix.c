#include <stdio.h>

#define MAX 10

// Function prototypes
void inputMatrix(int mat[MAX][MAX], int row, int col);
void displayMatrix(int mat[MAX][MAX], int row, int col);
void addMatrices(int a[MAX][MAX], int b[MAX][MAX], int res[MAX][MAX], int r, int c);
void multiplyMatrices(int a[MAX][MAX], int b[MAX][MAX], int res[MAX][MAX], int r1, int c1, int c2);
void transposeMatrix(int mat[MAX][MAX], int trans[MAX][MAX], int r, int c);

int main() {
    int matA[MAX][MAX], matB[MAX][MAX], result[MAX][MAX];
    int r1, c1, r2, c2, choice;

    printf("Enter rows and columns for Matrix A: ");
    scanf("%d %d", &r1, &c1);
    inputMatrix(matA, r1, c1);

    printf("Enter rows and columns for Matrix B: ");
    scanf("%d %d", &r2, &c2);
    inputMatrix(matB, r2, c2);

    printf("\n--- Matrix Operations ---\n");
    printf("1. Addition\n2. Multiplication\n3. Transpose (Matrix A)\n");
    printf("Enter choice: ");
    scanf("%d", &choice);

    switch(choice) {
        case 1:
            if (r1 == r2 && c1 == c2) {
                addMatrices(matA, matB, result, r1, c1);
                printf("Resultant Matrix:\n");
                displayMatrix(result, r1, c1);
            } else {
                printf("Error: Matrices must have same dimensions for addition!\n");
            }
            break;
        case 2:
            if (c1 == r2) {
                multiplyMatrices(matA, matB, result, r1, c1, c2);
                printf("Resultant Matrix:\n");
                displayMatrix(result, r1, c2);
            } else {
                printf("Error: Columns of A must equal Rows of B!\n");
            }
            break;
        case 3:
            transposeMatrix(matA, result, r1, c1);
            printf("Transpose of Matrix A:\n");
            displayMatrix(result, c1, r1);
            break;
        default:
            printf("Invalid choice!\n");
    }

    return 0;
}

// Helper function to take input
void inputMatrix(int mat[MAX][MAX], int row, int col) {
    printf("Enter elements:\n");
    for (int i = 0; i < row; i++)
        for (int j = 0; j < col; j++)
            scanf("%d", &mat[i][j]);
}

// Helper function to print matrix
void displayMatrix(int mat[MAX][MAX], int row, int col) {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++)
            printf("%d\t", mat[i][j]);
        printf("\n");
    }
}

void addMatrices(int a[MAX][MAX], int b[MAX][MAX], int res[MAX][MAX], int r, int c) {
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
            res[i][j] = a[i][j] + b[i][j];
}

void multiplyMatrices(int a[MAX][MAX], int b[MAX][MAX], int res[MAX][MAX], int r1, int c1, int c2) {
    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c2; j++) {
            res[i][j] = 0;
            for (int k = 0; k < c1; k++) {
                res[i][j] += a[i][k] * b[k][j];
            }
        }
    }
}

void transposeMatrix(int mat[MAX][MAX], int trans[MAX][MAX], int r, int c) {
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
            trans[j][i] = mat[i][j];
}