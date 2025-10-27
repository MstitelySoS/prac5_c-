/* ----------------------------------------------------
 * ИМЯ: Абрамов А.С., ID: 23К0607
 * ДАТА: 27/10/2025
 * ФАЙЛ: vector_compare.c
 * НАЗНАЧЕНИЕ: Определение вектора с наибольшей длиной
 * ---------------------------------------------------- */
/* ФУНКЦИИ:
 * vector_length() — вычисляет длину вектора.
 * get_longer_vector() — сравнивает длины двух векторов и
 *                        возвращает указатель на более длинный вектор,
 *                        а также записывает длину через указатель.
 * main() — ввод данных, вызов функций, вывод результата.
 * ---------------------------------------------------- */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double vector_length(double *v, int n) {
    double sum = 0.0;
    for (int i = 0; i < n; i++) sum += v[i] * v[i];
    return sqrt(sum);
}

double *get_longer_vector(double *a, double *b, int n, double *length) {
    double len_a = vector_length(a, n);
    double len_b = vector_length(b, n);

    if (len_a >= len_b) {
        *length = len_a;
        return a;
    } else {
        *length = len_b;
        return b;
    }
}

int main() {
    int n;
    printf("Введите размерность векторов: ");
    scanf("%d", &n);

    double *a = (double *)malloc(n * sizeof(double));
    double *b = (double *)malloc(n * sizeof(double));

    if (!a || !b) {
        perror("Ошибка выделения памяти");
        return 1;
    }

    printf("Введите элементы первого вектора:\n");
    for (int i = 0; i < n; i++) scanf("%lf", &a[i]);

    printf("Введите элементы второго вектора:\n");
    for (int i = 0; i < n; i++) scanf("%lf", &b[i]);

    double max_length;
    double *longest = get_longer_vector(a, b, n, &max_length);

    printf("\nДлина первого вектора: %.3f\n", vector_length(a, n));
    printf("Длина второго вектора: %.3f\n", vector_length(b, n));
    printf("\nБолее длинный вектор: ");
    for (int i = 0; i < n; i++) printf("%.2f ", longest[i]);
    printf("\nЕго длина: %.3f\n", max_length);

    free(a);
    free(b);
    return 0;
}
