/* ----------------------------------------------------*/
/* ИМЯ: Абрамов А.С., ID пользователя: 23К0607         */
/* ДАТА: 27/10/2025                                    */
/* НАЗНАЧЕНИЕ ПРОГРАММЫ:                               */
/* Функция принимает два вектора и вычисляет их         */
/* скалярное произведение и косинус угла между ними.    */
/* ИМЯ ФАЙЛА: vector_calc.c                             */
/* ----------------------------------------------------*/
/* ФУНКЦИИ:                                            */
/* dot_product() – вычисляет скалярное произведение.    */
/* cosine_between() – возвращает косинус угла между     */
/*                   двумя векторами.                   */
/* main() – вводит данные, вызывает функции и выводит   */
/*          результат.                                 */
/* ----------------------------------------------------*/

#include <stdio.h>
#include <math.h>
#include <stdlib.h>

double dot_product(double *a, double *b, int n) {
    double sum = 0.0;
    for (int i = 0; i < n; i++) {
        sum += a[i] * b[i];
    }
    return sum;
}

double cosine_between(double *a, double *b, int n) {
    double dot = dot_product(a, b, n);
    double len_a = 0.0, len_b = 0.0;
    for (int i = 0; i < n; i++) {
        len_a += a[i] * a[i];
        len_b += b[i] * b[i];
    }
    len_a = sqrt(len_a);
    len_b = sqrt(len_b);
    return dot / (len_a * len_b);
}

int main() {
    int n;
    printf("Введите размерность векторов: ");
    scanf("%d", &n);

    double *a = (double *)malloc(n * sizeof(double));
    double *b = (double *)malloc(n * sizeof(double));

    if (a == NULL || b == NULL) {
        perror("Ошибка выделения памяти");
        return 1;
    }

    printf("Введите элементы первого вектора:\n");
    for (int i = 0; i < n; i++) scanf("%lf", &a[i]);

    printf("Введите элементы второго вектора:\n");
    for (int i = 0; i < n; i++) scanf("%lf", &b[i]);

    double dot = dot_product(a, b, n);
    double cos_val = cosine_between(a, b, n);

    printf("\nСкалярное произведение: %.3f\n", dot);
    printf("Косинус угла между векторами: %.3f\n", cos_val);

    free(a);
    free(b);
    return 0;
}
