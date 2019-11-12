#include <stdio.h>
#include <stdlib.h>

double f(double x)
        {
            return x*x; // Cette fonction est un exemple
        }
int main()
        {
            int i =0;
            double a,b,pas,x;
            double *ptr_tableau = NULL;
            printf("a = ");
            scanf("%lf",&a);
            printf("b = ");
            scanf("%lf",&b);
            printf("pas = ");
            scanf("%lf",&pas);
            printf("Vous avez tapé [%f, %f],pas= %f\n",a,b,pas);
            int n=(b-a)/pas;
            ptr_tableau = malloc(sizeof(double)*n);
            printf("N Echantillons %d\n",n);
            x=a;
            for (i=0;i<n; i++)
                    {
                        x+=pas;
                        ptr_tableau[i] = f(x);
                        printf("x = %f\t tab[%d] = %f\n",x,i+1,ptr_tableau[i]);
                    }
    return 0;
    }
