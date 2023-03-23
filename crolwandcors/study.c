#include <stdio.h>
#include <stdlib.h>
void matrix_transpose(int A[3][3], int B[3][3],int num)
{
    for (int r = 0; r < num; r++)
        for (int c = 0; c < num; c++)
            B[c][r] = A[r][c];
}
int main() {
    int rows, cols;

    printf("arr에 들어갈 행과열의 크기를 입력: ");
    scanf("%d %d", &rows, &cols);

    int** arr = (int**)malloc(rows * sizeof(int*));
    for (int i = 0; i < rows; i++) {
        arr[i] = (int*)malloc(cols * sizeof(int));
    }

    int** arr2 = (int**)malloc(rows * sizeof(int*));
    for (int i = 0; i < rows; i++) {
        arr2[i] = (int*)malloc(cols * sizeof(int));
    }

    // 2차원 배열에 값 입력
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("arr[%d][%d]에 들어갈 수를 초기화 하시오: ", i, j);
            scanf("%d", &arr[i][j]);
        }
    }

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            arr[i][j] = 0;
        }
    }
    matrix_transpose(arr, arr2, cols);




    // 2차원 배열 출력
    printf("Array 1:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
    printf("Array 2:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", arr2[i][j]);
        }
        printf("\n");
    }

    // 메모리 해제
    for (int i = 0; i < rows; i++) {
        free(arr[i]);
    }
    free(arr);
    for (int i = 0; i < rows; i++) {
        free(arr2[i]);
    }
    free(arr2);

    return 0;
}