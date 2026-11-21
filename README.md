# Домашняя работа
# Индивидуальный вариант 22
# Описание программы
Задание 3. 


<img width="669" height="71" alt="image" src="https://github.com/user-attachments/assets/4e92d87f-7b42-44bc-93aa-0ff87e7572ed" />
<img width="640" height="47" alt="image" src="https://github.com/user-attachments/assets/3e062402-7c8a-4e67-ab99-776965e69a11" />

# Алгоритм и блок-схема
Алгоритм
Начало.
Ввести размер массива n.
Ввести n целых чисел в массив.
Установить last = -1 — признак, что подходящий элемент пока не найден.
Установить i = 0.
Пока i < n:
проверить, меньше ли a[i] нуля и делится ли оно на 3;
если да, записать last = i + 1;
увеличить i на 1.
Если last = -1, вывести, что подходящих элементов нет. Иначе вывести last.
Конец.


# Блок-схема
<img width="616" height="625" alt="image" src="https://github.com/user-attachments/assets/6560a3ce-408d-4bb3-b15c-4cac231ea035" />




 # Реализация программы
    #include <stdio.h>
    #include <stdlib.h>

    int main(void) {
    int n;

    printf("Введите количество элементов массива: ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Некорректное количество элементов.\n");
        return 1;
    }

    int *array = malloc(n * sizeof(int));
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
    } else {
        printf("Номер последнего подходящего элемента: %d\n", lastPosition);
    }

    free(array);
    return 0;
    }  
   
# Информация о разработчике
Попова Елена, БТИИ 262



