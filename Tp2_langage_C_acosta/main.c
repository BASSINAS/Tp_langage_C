#include <stdio.h>
#include <stdlib.h>

double f(double x)
        {
            return (3*x*2+2*x-7); // Cette fonction est un exemple
        }
int main()
        {
            int i;
            double a,b,pas,x,y;
            FILE *fp;
            fp=fopen("function.txt","w");
            printf("a = ");
            scanf("%lf",&a);
            printf("b = ");
            scanf("%lf",&b);
            printf("pas = ");
            scanf("%lf",&pas);
            printf("Vous avez tapé [%f, %f],pas= %f\n",a,b,pas);
            int n=(b-a)/pas;
            printf("N Echantillons %d\n",n);
            x=a;
            for (i=0;i<n; i++)
                    {
                        x+=pas;
                        y=f(x);
                        fprintf(fp,"x = %f,\t y = %f\n",x,y);
                        printf("%f\t f(%f) = %f\n",x,x,y);
                    }
            fclose(fp);
    return 0;
    }
