#include <stdio.h>
#include <time.h>
#include <locale.h>

int main() {
    setlocale(LC_ALL, "Russian");

    
    struct tm* mytime; // указатель на структуру tm
    time_t t;          // переменная для системного времени

    //  Получение системного времени
    t = time(NULL);

    //  Трансформация в структуру tm
    mytime = localtime(&t);

    //  Вывод времени
    printf("Текущее время: %02d:%02d:%02d\n",
        mytime->tm_hour, mytime->tm_min, mytime->tm_sec);

    // Получение месяца (0-11, поэтому +1) и года (от 1900, поэтому +1900)
    int month = mytime->tm_mon + 1;
    int year = mytime->tm_year + 1900;

    // Массив римских цифр для месяцев (индекс 1..12)
    const char* roman[] = {
        "", "I", "II", "III", "IV", "V", "VI",
        "VII", "VIII", "IX", "X", "XI", "XII"
    };

    // Вывод месяца римской цифрой и года
    printf("Месяц: %s\n", roman[month]);
    printf("Год: %d\n", year);

    return 0;
}