#include <stdio.h>  /*printf/scanf*/
#include <stdlib.h> /*standart library*/
#include <math.h>   /*math library*/
#include <assert.h>

int Solve_square(double a, double b, double c, double* x1, double* x2);
/*the function returns number of solutions of square and solves it*/

int Solve_linear(double k, double b, double* x);
/*the function returns number of solutions of linear equation and solves it*/

int main()
{
    printf("The program solves a quadratic equation(ax^2+bx+c=0)            Version 3.0   Made by Andre Kunavin\n");

    double a = NAN, b = NAN, c = NAN; /*parameters of equation*/

    printf("Input parameters(a, b, c) of equation here:\n");
    scanf("%lg %lg %lg",&a ,&b ,&c);

    double x1 = NAN, x2 = NAN;  /*solutions of equation*/
    int ns = Solve_square(a, b, c, &x1, &x2);

    assert(x1 != x2);

    switch (ns){
    case 0:
        printf("no solutions");
        break;
    case 1:
        printf("one solution: %lg\n", x1);
        break;
    case 2:
        printf("two solutions: %lg %lg\n", x1, x2);
        break;
    case 3:
        printf("any number");
        break;
    }

    return 0;
}

int Solve_square(double a, double b, double c, double* x1, double* x2)  /*ax^2+bx+c=0*/
{
    assert(isfinite(a) == 1);
    assert(isfinite(b) == 1);
    assert(isfinite(c) == 1);

    if (a == 0)
        return Solve_linear(b, c, x1);

    else if (c == 0){
        *x1 = 0;
        return Solve_linear(a, b, x2) + 1;
        }

    else{
        double d = b * b - 4 * a * c;   /*discriminant*/

        if (d == 0){
            *x1 = -b / (2 * a);
            return 1;
            }
        else if (d > 0){
            *x1 = (-b + sqrt(d)) / (2 * a);
            *x2 = (-b - sqrt(d)) / (2 * a);
            return 2;
        }
        else
            return 0;
    }
}
int Solve_linear(double k, double b, double* x) /*kx+b=0*/
{
    if (k == 0){
            if (b == 0)
                return 3;
            else
                return 0;
        }
        else{
            if (b == 0){
                *x = 0;
                return 1;
                }
            else{
                *x = - b / k;
                return 1;
                }
        }
}


