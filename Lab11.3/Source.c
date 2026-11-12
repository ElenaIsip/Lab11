#include <stdio.h>
#include <string.h>

#define SCREEN_WIDTH 80      // ширина экрана
#define BOX_WIDTH    10      // ширина окна (внутренняя часть)
#define BOX_TOTAL    (BOX_WIDTH + 2)  // +2 на рамки '|'

// Функция выводит строку окна, центрированного по экрану
void print_centered_box_line(const char* text) {
    char inner[128];   // содержимое окна (ровно BOX_WIDTH символов)
    char line[256];    // итоговая строка экрана
    int len = strlen(text);

    // Центрируем текст внутри окна: дополняем пробелами
    int pad_left = (BOX_WIDTH - len) / 2;
    int pad_right = BOX_WIDTH - len - pad_left;

    // Формируем содержимое окна через sprintf()
    int k = 0;
    for (int i = 0; i < pad_left; i++)  inner[k++] = ' ';
    sprintf(inner + k, "%s", text);     // копируем текст
    k += len;
    for (int i = 0; i < pad_right; i++) inner[k++] = ' ';
    inner[k] = '\0';

    // Отступ слева для центрирования окна на экране 80 символов
    int left_pad = (SCREEN_WIDTH - BOX_TOTAL) / 2;

    // Формируем строку экрана: '*' + '|' + содержимое + '|'
    int p = 0;
    for (int i = 0; i < left_pad; i++) line[p++] = '*';
    line[p++] = '|';
    for (int i = 0; i < BOX_WIDTH; i++) line[p++] = inner[i];
    line[p++] = '|';
    line[p] = '\0';

    printf("%s\n", line);
}

// Функция выводит горизонтальную границу окна
void print_centered_box_border(void) {
    char line[256];
    int left_pad = (SCREEN_WIDTH - BOX_TOTAL) / 2;

    int p = 0;
    for (int i = 0; i < left_pad; i++) line[p++] = '*';
    line[p++] = '+';
    for (int i = 0; i < BOX_WIDTH; i++) line[p++] = '-';
    line[p++] = '+';
    line[p] = '\0';

    printf("%s\n", line);
}

int main() {
    // Строки, подготовленные через sprintf()
    char msg1[32], msg2[32], msg3[32];

    sprintf(msg1, "Hello");
    sprintf(msg2, "World");
    sprintf(msg3, "C lang");

    // Вывод окна
    print_centered_box_border();
    print_centered_box_line(msg1);
    print_centered_box_line(msg2);
    print_centered_box_line(msg3);
    print_centered_box_border();

    return 0;
}