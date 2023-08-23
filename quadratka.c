//quadratka.c-- Принципиальная программа, которая решает квадратные уравнения, но на самом деле она решает еще и линейные 
//уравнения, но так как она принципиальная, то жалуется на это, хотя все рано решает его, потому что так сказали менторы
//(В частности Илья Рудольфович(дед)(а почему дед, вроде не такой уж и старый))
//                                                       нижний текст

#include <stdio.h>
#include <math.h>
#include <assert.h>

void read_coeffs (double* a, double* b, double* c);
void quadratic_solver (const double a, const double b, const double c,
                        double* x1, double* x2);
void check_input (double* letter);
int is_it_zer0 (const double num);

int main (void)
{
    double a = 0, b = 0, c = 0;
    char ch = 0;

    printf("Я ожидаю от Вас квадратное уравнение вида"
           "ax^2+bx+c=0");
    while (1)
    {
        
        read_coeffs (&a, &b, &c);
        printf ("Ваши коэффициенты:\n"
               "a = %f b = %f, c = %f\n", a, b, c);

        double x1 = 0, x2 = 0;
        quadratic_solver (a, b, c, &x1, &x2);

        printf ("Хотите продолжить? Если да, введите *\n"
               "Если хотите завершить программу введите #\n");
        ch = getchar ();

        while (ch != '*' || ch != '#')
        {
            printf ("Пожалуйста, введите корректный символ!\n");
            ch = getchar ();
        }

        if ('*' == ch)
            continue;
        if ('#' == ch)
            break;
        
        


    }

    return 0;
}
void read_coeffs (double* a, double* b, double* c)
{
    printf ("Введите коэффициенты\n");
    printf ("a=");
    check_input (a);
    
    printf ("\nb=");
    check_input (b);
    
    printf ("\nc=");
    check_input (c);

}

void quadratic_solver (const double a, const double b, const double c,
                        double* x1, double* x2)
{

    if (is_it_zer0(a))
    {
        printf ("Это уравнение, конечно, линейное, но я все-таки решу его\n");
        if ( !(is_it_zer0(b)) )
        {
            *x1 = -c/b;
            printf ("Одно решение:%f\n", x1);
        }
        else if ( is_it_zer0(b) && is_it_zer0(c) )
            printf ("Бесконечное число решений\n");
        else 
            printf ("Решений нет\n");
    }

    double D=0;

    if ( !(is_it_zer0(a)) )
    {
        D = b*b-4*a*c;

        if(D < 0)
            printf ("Решений нет\n");
        
        if ( is_it_zer0(D) )
        {
            *x1 = -b/(2*a);
            printf ("Ваше уравнение имеет одно решение:%f\n", x1);
        }
        if (D>0)
        {
            *x1 = (-b + sqrt(D))/(2*a);
            *x2 = (-b - sqrt(D)/(2*a));
            printf ("Ваше уравнение имеет два решения %f и %f\n", x1, x2);
        }
        
    }
}