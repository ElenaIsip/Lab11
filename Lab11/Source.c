#include <stdio.h>
#include <math.h>
#include <locale.h>

struct point {
    float x;
    float y;
    char name;
};

typedef struct point Point;


void put_point(Point z) {
    printf("point %c (%.1f, %.1f)", z.name, z.x, z.y);
}


float dist(Point z, Point w) {
 
    return sqrt(pow(w.x - z.x, 2) + pow(w.y - z.y, 2));
}


Point midpoint(Point z, Point w) {
    Point mid;
    mid.x = (z.x + w.x) / 2.0f;
    mid.y = (z.y + w.y) / 2.0f;
    mid.name = 'M';
    return mid;
}


int get_quadrant(Point p) {
    if (p.x > 0 && p.y > 0) return 1;
    if (p.x < 0 && p.y > 0) return 2;
    if (p.x < 0 && p.y < 0) return 3;
    if (p.x > 0 && p.y < 0) return 4;
    return 0; 
}

int main() {
    setlocale(LC_ALL, "Russian"); 

    Point a, b, m;

    printf("Введите координаты первой точки (x y): ");
    scanf("%f %f", &a.x, &a.y);
    a.name = 'A';

    printf("Введите координаты второй точки (x y): ");
    scanf("%f %f", &b.x, &b.y);
    b.name = 'B';

    printf("\nВведенные точки:\n");
    put_point(a);
    printf("\n");
    put_point(b);
    printf("\n");

   
    float d = dist(a, b);
    printf("\nРасстояние между точками: %.2f\n", d);

   
    m = midpoint(a, b);
    printf("Середина отрезка: ");
    put_point(m);
    printf("\n");

    
    printf("\nОпределение координатных четвертей:\n");

    int qa = get_quadrant(a);
    if (qa != 0) printf("Точка %c находится в %d-й четверти.\n", a.name, qa);
    else printf("Точка %c лежит на оси или в начале координат.\n", a.name);

    int qb = get_quadrant(b);
    if (qb != 0) printf("Точка %c находится в %d-й четверти.\n", b.name, qb);
    else printf("Точка %c лежит на оси или в начале координат.\n", b.name);

   
    return 0;
}