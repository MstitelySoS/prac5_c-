/* ----------------------------------------------------
 * ИМЯ: Абрамов А.С., ID: 23К0607
 * ДАТА: 27/10/2025
 * ФАЙЛ: two-dimension-arr.c
 * НАЗНАЧЕНИЕ: Динамический 2D массив (array-of-pointers) и анализ адресов
 * ---------------------------------------------------- */
#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int rows, cols;
    printf("Enter rows and cols: ");
    if (scanf("%d %d", &rows, &cols) != 2 || rows <= 0 || cols <= 0) {
        fprintf(stderr, "Bad sizes\n"); return 1;
    }

    int **a = (int**)malloc((size_t)rows * sizeof(int*));
    if (!a) { perror("malloc rows"); return 1; }

    for (int i = 0; i < rows; ++i) {
        a[i] = (int*)malloc((size_t)cols * sizeof(int));
        if (!a[i]) { perror("malloc row"); return 1; }
        for (int j = 0; j < cols; ++j) a[i][j] = i*100 + j;
    }

    printf("Address map (row pointers):\n");
    for (int i = 0; i < rows; ++i) {
        printf("a[%d] = %p\n", i, (void*)a[i]);
    }

    printf("\nElements (address & deltas inside row 0):\n");
    for (int j = 0; j < cols; ++j) {
        long d = (j==0)?0:(char*)&a[0][j] - (char*)&a[0][j-1];
        printf("a[0][%d]=%4d @ %p  Δ=%ld\n", j, a[0][j], (void*)&a[0][j], d);
    }

    printf("\nSample across rows (a[i][0]):\n");
    for (int i = 0; i < rows; ++i) {
        printf("a[%d][0] @ %p\n", i, (void*)&a[i][0]);
    }

    for (int i = 0; i < rows; ++i) free(a[i]);
    free(a);
    return 0;
}
