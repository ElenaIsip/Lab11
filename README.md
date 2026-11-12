# Домашняя работа
# Индивидуальный вариант 22
# Описание программы
Задание 3. Реализуйте создание структуры, заполнение полей и вывод на экран. (Создание массива структур в след. работе)

<img width="646" height="249" alt="{A5F89B00-F948-4109-9DD8-0C35365DF878}" src="https://github.com/user-attachments/assets/94804b8a-b5a0-470c-a928-af8764fcc990" />


# Алгоритм и блок-схема

Начало.

Подключить библиотеки stdio.h (для ввода-вывода) и locale.h (для русского языка).

Установить русскую локаль с помощью setlocale(LC_ALL, "Russian").

Объявить структуру Flight, содержащую поля:

flight_number — целое число (номер рейса);

departure_time — строка (время вылета);

arrival_time — строка (время прилёта);

destination — строка (направление);

plane_model — строка (марка самолёта);

distance — вещественное число (расстояние).

Объявить переменную my_flight типа Flight.

Вывести на экран заголовок «Ввод данных об авиарейсе».

Запросить и ввести номер авиарейса в поле flight_number.

Запросить и ввести время вылета в поле departure_time.

Запросить и ввести время прилёта в поле arrival_time.

Запросить и ввести направление в поле destination.

Запросить и ввести марку самолёта в поле plane_model.

Запросить и ввести расстояние в поле distance.

Вывести на экран заголовок «Информация о рейсе».

Вывести на экран значения всех полей структуры my_flight.

Вернуть 0 (успешное завершение программы).

Конец.

# Блок-схема

<img width="358" height="854" alt="{F43A973F-7AD3-433D-BC0D-588BF0F77FFB}" src="https://github.com/user-attachments/assets/bc3285a5-28a5-48f9-9253-9ccc2bf327cd" />


 # Реализация программы
    #include <stdio.h>
    #include <locale.h>

     // 1. Создание структуры для хранения записи
    struct Flight {
    int flight_number;       
    char departure_time[10]; 
    char arrival_time[10];   
    char destination[50];    
    char plane_model[30];    
    float distance;          
    };

    int main() {
   
    setlocale(LC_ALL, "Russian");

   
    struct Flight my_flight;

    printf("--- Ввод данных об авиарейсе ---\n");

    printf("Введите номер авиарейса: ");
    scanf("%d", &my_flight.flight_number);

    printf("Введите время вылета (ЧЧ:ММ): ");
    scanf("%9s", my_flight.departure_time);

    printf("Введите время прилета (ЧЧ:ММ): ");
    scanf("%9s", my_flight.arrival_time);

    printf("Введите направление (город): ");
    scanf("%49s", my_flight.destination);

    printf("Введите марку самолета: ");
    scanf("%29s", my_flight.plane_model);

    printf("Введите расстояние (км): ");
    scanf("%f", &my_flight.distance);

  
    printf("\n--- Информация о рейсе ---\n");
    printf("№ Авиарейса:      %d\n", my_flight.flight_number);
    printf("Время вылета:     %s\n", my_flight.departure_time);
    printf("Время прилета:    %s\n", my_flight.arrival_time);
    printf("Направление:      %s\n", my_flight.destination);
    printf("Марка самолета:   %s\n", my_flight.plane_model);
    printf("Расстояние:       %.1f км\n", my_flight.distance);

    return 0;
     }

   
# Информация о разработчике
Попова Елена, БТИИ 262



