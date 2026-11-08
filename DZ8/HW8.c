#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <locale.h>
 
double summa_sin(double nachalo, double konec, double shag);
 
int main()
{
    double summa;
 
    setlocale(LC_ALL, "Rus");
 
    printf("Считаем sin1 + sin1,1 + sin1,2 + ... + sin2\n");
 
    summa = summa_sin(1, 2, 0.1);
 
    printf("Ответ: %f\n", summa);
 
    return 0;
}
 
double summa_sin(double nachalo, double konec, double shag)
{
    double s = 0;
    int i, kolvo;
    kolvo = (int)((konec - nachalo) / shag + 0.5);
    for (i = 0; i <= kolvo; i++)
        s += sin(nachalo + i * shag);
    return s;
}
 
