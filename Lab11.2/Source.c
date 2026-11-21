#include <stdio.h>
#include <math.h>

#define N 100

/* ==== Собственная функция из варианта 10 ====
   y = x^2 + 2*pi*cos(pi*x) */
double func(double x)
{
    return x * x + 2.0 * M_PI * cos(M_PI * x);
}

int main(void)
{
    double a = 0.1;   /* начало интервала */
    double b = 2.5;   /* конец интервала   */
    double h;

  
    printf("Табулирование функции: y = x^2 + 2*pi*cos(pi*x)\n");
    printf("Интервал: [%.1f; %.1f]\n", a, b);

  
    printf("Введите шаг табуляции h: ");
    if (scanf("%lf", &h) != 1 || h <= 0.0) {
        printf("Ошибка: шаг должен быть положительным числом.\n");
        return 1;
    }

   
    printf("\n-------------------\n");
    printf("|   x   |  f(x)   |\n");
    printf("-------------------\n");

    for (double x = a; x <= b + 1e-9; x += h) {
        printf("| %5.2f | %7.4f |\n", x, func(x));
    }
    printf("-------------------\n");

    
    double arr[N];
    double step = (b - a) / (N - 1);   /* шаг для 100 точек */

    for (int i = 0; i < N; i++)
        arr[i] = func(a + i * step);

    double sum_pos = 0.0, sum_neg = 0.0;
    int cnt_pos = 0, cnt_neg = 0;

    for (int i = 0; i < N; i++) {
        if (arr[i] > 0.0)      { sum_pos += arr[i]; cnt_pos++; }
        else if (arr[i] < 0.0) { sum_neg += arr[i]; cnt_neg++; }
    }

    double avg_pos = (cnt_pos > 0) ? sum_pos / cnt_pos : 0.0;

    printf("\nМассив: arr[%d]  (x от %.1f до %.1f)\n", N, a, b);
    printf("Накопленная сумма положительных: %.6f\n", sum_pos);
    printf("Накопленная сумма отрицательных: %.6f\n", sum_neg);
    printf("Количество положительных:        %d\n", cnt_pos);
    printf("Количество отрицательных:        %d\n", cnt_neg);
    printf("Среднее значение положительных:  %.6f\n", avg_pos);

    return 0;
}
