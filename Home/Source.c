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