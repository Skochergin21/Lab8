#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <locale.h>

#define PI 3.14159265358979

int main()
{
    int kolvo, i;
    char simv, simv2;
    int m, n, tmp;
    int s, k;
    int stepen;
    long long granica;
    unsigned long long dvoika;
    double a = 1, b = 3; /* интервал варианта 14 (по кругу это 2 вариант) */
    double shag, x, y;

    setlocale(LC_ALL, "Rus");

    /* Задание 0. Печать символов циклом for */
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

    /* Задание 1. Сумма целых чисел от m до n */
    printf("=== Задание 1 ===\n");
    printf("Введите m и n: ");
    scanf("%d %d", &m, &n);
    if (m < n)
    {
        tmp = m;
        m = n;
        n = tmp;
    }
    s = 0;
    k = 1;
    for (i = m; i >= n; i--)
    {
        s += i;
        printf("выполнено %d раз\n", k++);
    }
    printf("результат %d\n\n", s);

    /* Задание 1А. Степени двойки в столбик */
    printf("=== Задание 1А ===\n");
    printf("Введите степень n (от 0 до 62): ");
    scanf("%d", &stepen);
    if (stepen < 0 || stepen > 62)
        printf("Ошибка! n должно быть от 0 до 62\n");
    else
    {
        dvoika = 1;
        for (i = 0; i <= stepen; i++)
        {
            if (i > 0)
                dvoika *= 2;
            printf("2^%-2d = %20llu\n", i, dvoika);
        }
        printf("Результат: %lluK\n", dvoika / 1024);
    }

    printf("\nВведите целое число m (степени 2 до этого числа): ");
    scanf("%lld", &granica);
    if (granica < 1)
        printf("Ошибка! m должно быть больше 0\n\n");
    else
    {
        i = 0;
        for (dvoika = 1; dvoika <= (unsigned long long)granica; dvoika *= 2)
        {
            printf("2^%-2d = %20llu\n", i, dvoika);
            i++;
        }
        printf("Результат: %.1fK\n\n", (dvoika / 2) / 1024.0);
    }

    /* Задание 2. Табулирование функции (вариант 14 -> 2) */
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
        {
            y = x * x - cos(PI * x) * cos(PI * x);
            printf("| %7.3f | %7.4f |\n", x, y);
        }
        printf("|_________|_________|\n");
    }

    return 0;
}
