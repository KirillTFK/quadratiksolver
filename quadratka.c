//quadratka.c-- Принципиальная программа, которая решает квадратные уравнения, но на самом деле она решает еще и линейные 
//уравнения, но так как она принципиальная, то жалуется на это, хотя все рано решает его, потому что так сказали менторы
//(В частности Илья Рудольфович(дед)(а почему дед, вроде не такой уж и старый))
//                                                       нижний текст

#include <stdio.h>
#include <math.h>
#include <assert.h>

void reader (double a, double b, double c);
void quadratic_solver (const double a, const double b, const double c,
                        double x1, double x2);

int main (void)
{
    double a = 0, b = 0, c = 0;
    char ch = 0;

    printf ("Введите квадратное уравнение\n"
            "В виде ax^2+bx+c=0\n");
    printf ("Символ степени покажите так: ^\n"
            "а в качестве переменной используйте x\n");

    while (1)
    {
        printf ("Введите квадратное уравнение\n");
        reader (a, b, c);
        printf ("Ваши коэффициенты:\n"
               "a = %f b = %f, c = %f\n", a, b, c);

        double x1 = 0, x2 = 0;
        quadratic_solver (a, b, c, x1, x2);

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

void reader (double a, double b, double c)
{
    printf ("Введите коэффициенты\n");
    printf ("a=");
    scanf ("%lf", &a);
    
    printf ("\nb=");
    scanf ("%lf", &b);
    
    printf ("\nc=");
    scanf ("%lf", &c);

}

void quadratic_solver (const double a, const double b, const double c,
                        double x1, double x2)
{

    if (fabs (a)<0.00001)
    {
        printf ("Это уравнение, конечно, линейное, но я все-таки решу его\n");
        if (b != 0)
        {
            x1 = -b/c;
            printf ("Одно решение:%f", x1);
        }
        else if(c == 0)
            printf ("Бесконечное число решений\n");
        else 
            printf ("Решений нет\n");
    }

    int D=0;

    if (a != 0)
    {
        D = b*b-4*a*c;

        if(D < 0)
            printf("Решений нет\n");
        
        if (D == 0)
        {
            x1 = -b/(2*a);
            assert (isfinite(x1));
            printf ("Одно решение:%f\n", x1);
        }
        if (D>0)
        {
            assert(D>0);
            x1 = (-b + sqrt(D))/(2*a);
            x2 = (-b - sqrt(D)/(2*a));
            printf ("Ваше уравнение имеет два решения %f и %f\n", x1, x2);
        }
        
    }
}