# Работа 8
 
## Задание 0. Напечатайте 10 символов '*' с использованием цикла for
 
## Задание 1. Разработайте программу вычисления суммы целых чисел от m до n (включительно)
 
## Задание 1А. Напечатать в столбик все значения 2 в степени n
 
## Задание 2. Напишите программу табулирования функции с произвольным шагом согласно варианту
 
Вариант 14: y = x² − cos²(πx), интервал [1; 3].
 
## Код
 
```c
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
```
 
## Результат
 
```
=== Задание 0 ===
**********
Введите количество символов: 12
Введите символ: #
############
+############+
Введите второй символ: @
######@@@@@@
#!#!#!#!#!#!#!#!#!#!#!#!
 
=== Задание 1 ===
Введите m и n: 1 5
выполнено 5 раз
результат 15
 
=== Задание 1А ===
Введите степень n (от 0 до 62): 11
2^0  =                    1
2^1  =                    2
2^2  =                    4
2^3  =                    8
2^4  =                   16
2^5  =                   32
2^6  =                   64
2^7  =                  128
2^8  =                  256
2^9  =                  512
2^10 =                 1024
2^11 =                 2048
Результат: 2K
 
Введите целое число m (степени 2 до этого числа): 1300
2^0  =                    1
2^1  =                    2
2^2  =                    4
2^3  =                    8
2^4  =                   16
2^5  =                   32
2^6  =                   64
2^7  =                  128
2^8  =                  256
2^9  =                  512
2^10 =                 1024
Результат: 1,0K
 
=== Задание 2 ===
Функция: y = x^2 - cos^2(pi*x), x на отрезке [1; 3]
Введите шаг: 0,25
 ___________________
|    x    |   f(x)  |
|_________|_________|
|   1,000 |  0,0000 |
|   1,250 |  1,0625 |
|   1,500 |  2,2500 |
|   1,750 |  2,5625 |
|   2,000 |  3,0000 |
|   2,250 |  4,5625 |
|   2,500 |  6,2500 |
|   2,750 |  7,0625 |
|   3,000 |  8,0000 |
|_________|_________|
```
 
## Выполнил
 
Кочергин Савелий бИД-261
