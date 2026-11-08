#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <locale.h>
 
#define PI 3.14159265358979
 
int summa_m_n(int m, int n);
int kolvo_raz(int m, int n);
unsigned long long dvoika_v_stepeni(int k);
double f(double x);
 
int main()
{
    int kolvo, i;
    char simv, simv2;
    int m, n;
    int stepen;
    long long granica;
    unsigned long long dvoika;
    double a = 1, b = 3;
    double shag, x;
 
    setlocale(LC_ALL, "Rus");
 
    printf("=== Задание 0 ===\n");
    for (int start = 1; start <= 10; start++) putchar('*');
    printf("\n");
 
    printf("Введите количество символов: ");
    scanf("%d", &kolvo);
    printf("Введите символ: ");
    scanf(" %c", &simv);
 
    for (i = 1; i <= kolvo; i++)
        putchar(simv);
    printf("\n");
 
    putchar('+');
    for (i = 1; i <= kolvo; i++)
        putchar(simv);
    putchar('+');
    printf("\n");
 
    printf("Введите второй символ: ");
    scanf(" %c", &simv2);
    for (i = 1; i <= kolvo; i++)
    {
        if (i <= kolvo / 2)
            putchar(simv);
        else
            putchar(simv2);
    }
    printf("\n");
 
    for (i = 1; i <= kolvo; i++)
    {
        putchar(simv);
        putchar('!');
    }
    printf("\n\n");
 
    printf("=== Задание 1 ===\n");
    printf("Введите m и n: ");
    scanf("%d %d", &m, &n);
    printf("выполнено %d раз\n", kolvo_raz(m, n));
    printf("результат %d\n\n", summa_m_n(m, n));
 
    printf("=== Задание 1А ===\n");
    printf("Введите степень n (от 0 до 62): ");
    scanf("%d", &stepen);
    if (stepen < 0 || stepen > 62)
        printf("Ошибка! n должно быть от 0 до 62\n");
    else
    {
        for (i = 0; i <= stepen; i++)
            printf("2^%-2d = %20llu\n", i, dvoika_v_stepeni(i));
        printf("Результат: %lluK\n", dvoika_v_stepeni(stepen) / 1024);
    }
 
    printf("\nВведите целое число m (степени 2 до этого числа): ");
    scanf("%lld", &granica);
    if (granica < 1)
        printf("Ошибка! m должно быть больше 0\n\n");
    else
    {
        i = 0;
        dvoika = 1;
        while (dvoika_v_stepeni(i) <= (unsigned long long)granica)
        {
            dvoika = dvoika_v_stepeni(i);
            printf("2^%-2d = %20llu\n", i, dvoika);
            i++;
        }
        printf("Результат: %.1fK\n\n", dvoika / 1024.0);
    }
 
    printf("=== Задание 2 ===\n");
    printf("Функция: y = x^2 - cos^2(pi*x), x на отрезке [%g; %g]\n", a, b);
    printf("Введите шаг: ");
    scanf("%lf", &shag);
    if (shag <= 0)
        printf("Ошибка! Шаг должен быть больше 0\n");
    else
    {
        printf(" ___________________\n");
        printf("|    x    |   f(x)  |\n");
        printf("|_________|_________|\n");
        for (x = a; x <= b + shag / 1000; x += shag)
            printf("| %7.3f | %7.4f |\n", x, f(x));
        printf("|_________|_________|\n");
    }
 
    return 0;
}
 
int summa_m_n(int m, int n)
{
    int s = 0;
    int i, tmp;
    if (m < n)
    {
        tmp = m;
        m = n;
        n = tmp;
    }
    for (i = m; i >= n; i--)
        s += i;
    return s;
}
 
int kolvo_raz(int m, int n)
{
    int k;
    if (m > n)
        k = m - n + 1;
    else
        k = n - m + 1;
    return k;
}
 
unsigned long long dvoika_v_stepeni(int k)
{
    unsigned long long p = 1;
    int i;
    for (i = 1; i <= k; i++)
        p *= 2;
    return p;
}
 
double f(double x)
{
    double y;
    y = x * x - cos(PI * x) * cos(PI * x);
    return y;
}

