/* ----------------------------------------------------
 * ИМЯ: Абрамов А.С., ID: 23К0607
 * ДАТА: 27/10/2025
 * ФАЙЛ: one-dimension-arr.c
 * НАЗНАЧЕНИЕ: Динамическое размещение 1D массива int и анализ адресов
 * ---------------------------------------------------- */
#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int n;
    printf("Enter N: ");
    if (scanf("%d", &n) != 1 || n <= 0) { fprintf(stderr, "Bad N\n"); return 1; }

    int *arr = (int*)malloc((size_t)n * sizeof(int));
    if (!arr) { perror("malloc"); return 1; }

    for (int i = 0; i < n; ++i) { arr[i] = i + 1; }

    printf("Index  Value  Address           Δ(bytes)\n");
    for (int i = 0; i < n; ++i) {
        long delta = (i == 0) ? 0 : (char*)&arr[i] - (char*)&arr[i-1];
        printf("%5d %6d  %p  %ld\n", i, arr[i], (void*)&arr[i], delta);
    }

    free(arr);
    return 0;
}
