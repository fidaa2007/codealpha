#include <stdio.h>
#include <stdlib.h>

// Function to dynamically allocate memory for a 2D matrix
int** create_matrix(int rows, int cols) {
    int** matrix = (int**)malloc(rows * sizeof(int*));
    for (int i = 0; i < rows; i++) {
        matrix[i] = (int*)malloc(cols * sizeof(int));
    }
    return matrix;
}

// Function to free allocated memory of a 2D matrix
void free_matrix(int** matrix, int rows) {
    for (int i = 0; i < rows; i++) {
        free(matrix[i]);
    }
    free(matrix);
}

// Function to read matrix values from the user
int** read_matrix(int* rows, int* cols, const char* name) {
    printf("\n--- Input for %s ---\n", name);
    printf("Enter number of rows: ");
    scanf("%d", rows);
    printf("Enter number of columns: ");
    scanf("%d", cols);

    int** matrix = create_matrix(*rows, *cols);

    printf("Enter matrix elements:\n");
    for (int i = 0; i < *rows; i++) {
        for (int j = 0; j < *cols; j++) {
            printf("Element [%d][%d]: ", i + 1, j + 1);
            scanf("%d", &matrix[i][j]);
        }
    }
    return matrix;
}

// Function to display a 2D matrix
void display_matrix(int** matrix, int rows, int cols, const char* name) {
    printf("\n%s (%dx%d):\n", name, rows, cols);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%7d", matrix[i][j]);
        }
        printf("\n");
    }
}

// 1. Matrix Addition
int** add_matrices(int** A, int rA, int cA, int** B, int rB, int cB) {
    if (rA != rB || cA != cB) {
        printf("\n[Error] Addition failed: Dimensions must match (%dx%d vs %dx%d).\n", rA, cA, rB, cB);
        return NULL;
    }

    int** result = create_matrix(rA, cA);
    for (int i = 0; i < rA; i++) {
        for (int j = 0; j < cA; j++) {
            result[i][j] = A[i][j] + B[i][j];
        }
    }
    return result;
}

// 2. Matrix Subtraction
int** subtract_matrices(int** A, int rA, int cA, int** B, int rB, int cB) {
    if (rA != rB || cA != cB) {
        printf("\n[Error] Subtraction failed: Dimensions must match (%dx%d vs %dx%d).\n", rA, cA, rB, cB);
        return NULL;
    }

    int** result = create_matrix(rA, cA);
    for (int i = 0; i < rA; i++) {
        for (int j = 0; j < cA; j++) {
            result[i][j] = A[i][j] - B[i][j];
        }
    }
    return result;
}

// 3. Matrix Multiplication
int** multiply_matrices(int** A, int rA, int cA, int** B, int rB, int cB) {
    if (cA != rB) {
        printf("\n[Error] Multiplication failed: Columns of A (%d) must equal Rows of B (%d).\n", cA, rB);
        return NULL;
    }

    int** result = create_matrix(rA, cB);
    for (int i = 0; i < rA; i++) {
        for (int j = 0; j < cB; j++) {
            result[i][j] = 0;
            for (int k = 0; k < cA; k++) {
                result[i][j] += A[i][k] * B[k][j];
            }
        }
    }
    return result;
}

// 4. Matrix Transpose
int** transpose_matrix(int** matrix, int rows, int cols) {
    int** result = create_matrix(cols, rows);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[j][i] = matrix[i][j];
        }
    }
    return result;
}

int main() {
    int rA, cA;
    int choice;

    printf("=============================================\n");
    printf("             MATRIX OPERATIONS               \n");
    printf("=============================================\n");

    int** matrix_A = read_matrix(&rA, &cA, "Matrix A");
    display_matrix(matrix_A, rA, cA, "Matrix A");

    while (1) {
        printf("\n-----------------------------------\n");
        printf("Choose an operation:\n");
        printf("1. Addition (Matrix A + Matrix B)\n");
        printf("2. Subtraction (Matrix A - Matrix B)\n");
        printf("3. Multiplication (Matrix A * Matrix B)\n");
        printf("4. Transpose of Matrix A\n");
        printf("5. Input New Matrix A\n");
        printf("6. Exit\n");
        printf("Enter choice (1-6): ");
        scanf("%d", &choice);

        if (choice == 1) {
            int rB, cB;
            int** matrix_B = read_matrix(&rB, &cB, "Matrix B");
            display_matrix(matrix_B, rB, cB, "Matrix B");

            int** result = add_matrices(matrix_A, rA, cA, matrix_B, rB, cB);
            if (result != NULL) {
                display_matrix(result, rA, cA, "Addition Result (A + B)");
                free_matrix(result, rA);
            }
            free_matrix(matrix_B, rB);

        } else if (choice == 2) {
            int rB, cB;
            int** matrix_B = read_matrix(&rB, &cB, "Matrix B");
            display_matrix(matrix_B, rB, cB, "Matrix B");

            int** result = subtract_matrices(matrix_A, rA, cA, matrix_B, rB, cB);
            if (result != NULL) {
                display_matrix(result, rA, cA, "Subtraction Result (A - B)");
                free_matrix(result, rA);
            }
            free_matrix(matrix_B, rB);

        } else if (choice == 3) {
            int rB, cB;
            int** matrix_B = read_matrix(&rB, &cB, "Matrix B");
            display_matrix(matrix_B, rB, cB, "Matrix B");

            int** result = multiply_matrices(matrix_A, rA, cA, matrix_B, rB, cB);
            if (result != NULL) {
                display_matrix(result, rA, cB, "Multiplication Result (A * B)");
                free_matrix(result, rA);
            }
            free_matrix(matrix_B, rB);

        } else if (choice == 4) {
            int** result = transpose_matrix(matrix_A, rA, cA);
            display_matrix(result, cA, rA, "Transpose Result (A^T)");
            free_matrix(result, cA);

        } else if (choice == 5) {
            free_matrix(matrix_A, rA);
            matrix_A = read_matrix(&rA, &cA, "Matrix A");
            display_matrix(matrix_A, rA, cA, "Matrix A");

        } else if (choice == 6) {
            printf("\nExiting program.\n");
            free_matrix(matrix_A, rA);
            break;

        } else {
            printf("Invalid selection! Enter a number between 1 and 6.\n");
        }
    }

    return 0;
}