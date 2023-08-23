//quadratka.c-- Принципиальная программа, которая решает квадратные уравнения, но на самом деле она решает еще и линейные 
//уравнения, но так как она принципиальная, то жалуется на это, хотя все рано решает его, потому что так сказали менторы
//(В частности Илья Рудольфович(дед)(а почему дед, вроде не такой уж и старый))
//                                                       нижний текст

#include <assert.h>
#include <math.h>
#include <stdio.h>

void read_coeffs (double* input_a, double* input_b, double* input_c);
int quadratic_solver (const double a, const double b, const double c,
                        double* x1, double* x2);
void check_input (double* check_coeff);
int is_it_zer0 (const double num, const char operation);
void clear_buf (void);
void restart (char* ch);
void output (int nRoots, double* x1, double* x2);

void read_coeffs_asserts (double* input_a, double* input_b, double* input_c);
void quadratic_slover_asserts (const double a, const double b, const double c,
                        double* x1, double* x2);
void check_input_asserts (void);
void is_it_zer0_asserts (void);
void output_asserts (void);






int main (void)
{
    printf("Я ожидаю от Вас квадратное уравнение вида"
           " ax^2+bx+c=0");
    while (true)
    {
        double a = 0, b = 0, c = 0;
        char ch = 0;
        int nRoots = 0;

        read_coeffs (&a, &b, &c);
        printf ("Ваши коэффициенты:\n"
               "a = %f b = %f, c = %f\n", a, b, c);

        double x1 = 0, x2 = 0;
        nRoots = quadratic_solver (a, b, c, &x1, &x2);
        output (nRoots, &x1, &x2);

        restart(&ch);

        if ('*' == ch)
            continue;
        if ('#' == ch)
            break;
    }

    return 0;
}

void read_coeffs (double* input_a, double* input_b, double* input_c)
{   
    assert ( !isnan (*input_a) );
    assert ( !isnan (*input_b) );
    assert ( !isnan (*input_c) );
    assert (isfinite (*input_a));
    assert (isfinite (*input_b));
    assert (isfinite (*input_c));

    printf ("Введите коэффициенты\n");
    printf ("a=");
    check_input (input_a);
    
    printf ("\nb=");
    check_input (input_b);
    
    printf ("\nc=");
    check_input (input_c);

}

void check_input (double* check_coeff)
{
    assert ( !isnan (*check_coeff) );
    assert (isfinite (*check_coeff));

    while(scanf ("%lf", check_coeff) == 0)
    {
        printf ("Введите только числовое значение");
        clear_buf();
    }
    clear_buf();
}

int quadratic_solver (const double a, const double b, const double c,
                        double* x1, double* x2)
{
    assert ( !isnan(a) );
    assert ( !isnan(b) );
    assert ( !isnan(c) );
    assert (isfinite(a));
    assert (isfinite(b));
    assert (isfinite(c));
    assert ( !isnan(*x1) );
    assert ( !isnan(*x2) );
    assert (isfinite(*x1));
    assert (isfinite(*x2));
    

    int nRoots = 0;
    if (is_it_zer0(a, '='))
    {
        printf ("Это уравнение, конечно, линейное, но я все-таки решу его\n");
        if ( !(is_it_zer0(b, '=')) )
        {
            *x1 = -c/b;
            nRoots = 1;
        }
        else if ( is_it_zer0(b, '=') && is_it_zer0(c, '=') )
               return nRoots = 8;
        else 
               return nRoots = 0;
        
    }

    double D = 0;

    
        D = b*b-4*a*c;

        if( is_it_zer0(D, '<'))
            return nRoots = 0;
        
        if ( is_it_zer0(D, '=') )
        {
            *x1 = -b/(2*a);
            return nRoots = 1;
        }
        if ( is_it_zer0(D, '>'))
        {   double sqrt_D = sqrt(D);
            *x1 = (-b + sqrt_D)/(2*a);
            *x2 = (-b - sqrt_D)/(2*a);
            return nRoots = 2;
        }
        return 0;
}


int is_it_zer0(const double num, const char operation)
{
     assert ( !(isnan(num)) );
     assert (isfinite(num));

    const double EPSILON = 0.000001;

    if (operation == '=')
        return ((fabs(num) < EPSILON) ? 1:0);

    if (operation == '<')
    {
        if(num > 0 || fabs(num) < EPSILON)
        return 0;
    }   
    else 
    return 1;

    if (operation == '>')
    {
        if(num < 0 || fabs(num) < EPSILON)
        return 0;
    }
    else 
        return 1;  
    return 0;
}

void clear_buf (void)
{
    char ch = 0;
    while( (ch = (char) getchar()) != '\n')
        continue;
}

void output (int nRoots, double* x1, double* x2)
{
    assert ( !isnan(*x1) );
    assert ( !isnan(*x2) );
    assert (isfinite(*x1));
    assert (isfinite(*x2));

    switch(nRoots)
    {
        case 0:
            printf("Корней нет!\n");
            break;

        case 1:
            printf("Уравнение имеет один корень равный %lf\n", *x1);
            break;

        case 2:
            printf("Уравнение имеет два корня равные %lf %lf\n", *x1, *x2);
            break;

        case 8:
            printf("Уравнение имеет бесконечное число корней\n");
            break;

        default:
           ;


    }
}

void restart (char* ch)
{
    
    printf ("Хотите продолжить? Если да, введите *\n"
            "Если хотите завершить программу введите #\n");
    
        while ( (*ch = (char) getchar()) != '*' && *ch != '#')
        {
            printf ("Пожалуйста, введите корректный символ!\n");
            printf("Вывожу символ %d\n", *ch);
        }
}

void read_coeffs_asserts (void)
{

}
void quadratic_slover_asserts (void);
void check_input_asserts (void);
void is_it_zer0_asserts (void);
void output_asserts (void);