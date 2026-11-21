#include <stdio.h>
#include <math.h>

#define N 10

int main(void)
{
    float A[N];
    float rounded[N];
    float sum = 0.0f;

    // Ввод элементов массива
    for (int i = 0; i < N; i++) {
        printf("a[%d] = ", i + 1);
        scanf("%f", &A[i]);

        // Округление в большую сторону
        rounded[i] = ceilf(A[i]);
        sum += A[i];
    }

    // Вывод исходных и преобразованных значений
    printf("\n%-10s %-20s %-20s\n", "Индекс", "Исходное значение", "Новое значение");
    for (int i = 0; i < N; i++) {
        printf("%-10d %-20.2f %-20.2f\n", i + 1, A[i], rounded[i]);
    }

    printf("\nСреднее арифметическое исходных элементов: %.2f\n", sum / N);

    return 0;
}
