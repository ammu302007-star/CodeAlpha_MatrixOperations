#include <stdio.h>

#define MAX 10

// Function to input a matrix
void inputMatrix(int matrix[MAX][MAX], int rows, int cols)
{
    printf("Enter matrix elements:\n");

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            scanf("%d", &matrix[i][j]);
        }
    }
}

// Function to display a matrix
void displayMatrix(int matrix[MAX][MAX], int rows, int cols)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            printf("%d ", matrix[i][j]);
        }

        printf("\n");
    }
}

// Function for matrix addition
void addMatrices(int matrix1[MAX][MAX], int matrix2[MAX][MAX],
                 int result[MAX][MAX], int rows, int cols)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            result[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }
}

// Function for matrix multiplication
void multiplyMatrices(int matrix1[MAX][MAX], int matrix2[MAX][MAX],
                      int result[MAX][MAX],
                      int rows1, int cols1, int cols2)
{
    for (int i = 0; i < rows1; i++)
    {
        for (int j = 0; j < cols2; j++)
        {
            result[i][j] = 0;

            for (int k = 0; k < cols1; k++)
            {
                result[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }
}

// Function for matrix transpose
void transposeMatrix(int matrix[MAX][MAX], int result[MAX][MAX],
                     int rows, int cols)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            result[j][i] = matrix[i][j];
        }
    }
}

int main(void)
{
    int choice;

    printf("=== Matrix Operations ===\n");
    printf("1. Matrix Addition\n");
    printf("2. Matrix Multiplication\n");
    printf("3. Transpose\n");

    printf("\nEnter your choice: ");
    scanf("%d", &choice);

    // ================= MATRIX ADDITION =================
    if (choice == 1)
    {
        int rows1, cols1;
        int rows2, cols2;

        int matrix1[MAX][MAX];
        int matrix2[MAX][MAX];
        int result[MAX][MAX];

        printf("\nEnter rows and columns of first matrix: ");
        scanf("%d %d", &rows1, &cols1);

        printf("Enter rows and columns of second matrix: ");
        scanf("%d %d", &rows2, &cols2);

        // Check dimensions before entering elements
        if (rows1 != rows2 || cols1 != cols2)
        {
            printf("\nMatrix addition is not possible.\n");
            printf("Both matrices must have the same number of rows and columns.\n");
            return 0;
        }

        printf("\nEnter first matrix:\n");
        inputMatrix(matrix1, rows1, cols1);

        printf("\nFirst Matrix:\n");
        displayMatrix(matrix1, rows1, cols1);

        printf("\nEnter second matrix:\n");
        inputMatrix(matrix2, rows2, cols2);

        printf("\nSecond Matrix:\n");
        displayMatrix(matrix2, rows2, cols2);

        addMatrices(matrix1, matrix2, result, rows1, cols1);

        printf("\nResult of Addition:\n");
        displayMatrix(result, rows1, cols1);
    }

    // ================= MATRIX MULTIPLICATION =================
    else if (choice == 2)
    {
        int rows1, cols1;
        int rows2, cols2;

        int matrix1[MAX][MAX];
        int matrix2[MAX][MAX];
        int result[MAX][MAX];

        printf("\nEnter rows and columns of first matrix: ");
        scanf("%d %d", &rows1, &cols1);

        printf("Enter rows and columns of second matrix: ");
        scanf("%d %d", &rows2, &cols2);

        // Check dimensions before entering elements
        if (cols1 != rows2)
        {
            printf("\nMatrix multiplication is not possible.\n");
            printf("The number of columns of the first matrix must equal the number of rows of the second matrix.\n");
            return 0;
        }

        printf("\nEnter first matrix:\n");
        inputMatrix(matrix1, rows1, cols1);

        printf("\nFirst Matrix:\n");
        displayMatrix(matrix1, rows1, cols1);

        printf("\nEnter second matrix:\n");
        inputMatrix(matrix2, rows2, cols2);

        printf("\nSecond Matrix:\n");
        displayMatrix(matrix2, rows2, cols2);

        multiplyMatrices(matrix1, matrix2, result,
                         rows1, cols1, cols2);

        printf("\nResult of Multiplication:\n");
        displayMatrix(result, rows1, cols2);
    }

    // ================= TRANSPOSE =================
    else if (choice == 3)
    {
        int rows, cols;

        int matrix[MAX][MAX];
        int result[MAX][MAX];

        printf("\nEnter rows and columns of matrix: ");
        scanf("%d %d", &rows, &cols);

        printf("\nEnter matrix:\n");
        inputMatrix(matrix, rows, cols);

        printf("\nOriginal Matrix:\n");
        displayMatrix(matrix, rows, cols);

        transposeMatrix(matrix, result, rows, cols);

        printf("\nTranspose:\n");
        displayMatrix(result, cols, rows);
    }

    // ================= INVALID CHOICE =================
    else
    {
        printf("\nInvalid choice.\n");
        printf("Please select 1, 2, or 3.\n");
    }

    return 0;
}
