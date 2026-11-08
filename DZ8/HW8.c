#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <locale.h>
 
int main()
{
    int i;
    double x;
    double summa = 0;
 
    setlocale(LC_ALL, "Rus");
 
    printf("Считаем sin1 + sin1,1 + sin1,2 + ... + sin2\n\n");
 
    for (i = 0; i <= 10; i++)
    {
        x = 1 + i * 0.1;
        summa += sin(x);
        printf("%2d) sin(%.1f) = %f   сумма = %f\n", i + 1, x, sin(x), summa);
    }
 
    printf("\nОтвет: %f\n", summa);
 
    return 0;
}
 
