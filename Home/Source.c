#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int n;

    printf("Введите количество элементов массива: ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Некорректное количество элементов.\n");
        return 1;
    }

    int* array = malloc(n * sizeof(int));
    if (array == NULL) {
        printf("Не удалось выделить память.\n");
        return 1;
    }

    printf("Введите %d целых чисел:\n", n);
    for (int i = 0; i < n; i++) {
        if (scanf("%d", &array[i]) != 1) {
            printf("Некорректный ввод.\n");
            free(array);
            return 1;
        }
    }

    int lastPosition = -1;

    for (int i = 0; i < n; i++) {
        if (array[i] < 0 && array[i] % 3 == 0) {
            lastPosition = i + 1;
        }
    }

    if (lastPosition == -1) {
        printf("В массиве нет отрицательных элементов, делящихся на 3.\n");
    }
    else {
        printf("Номер последнего подходящего элемента: %d\n", lastPosition);
    }

    free(array);
    return 0;
}
