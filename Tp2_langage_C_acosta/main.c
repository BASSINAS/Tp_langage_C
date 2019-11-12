#include <stdio.h>
#include <stdlib.h>

double f(double x)
        {
            return x*x; // Cette fonction est un exemple
        }
void writeToAFile (double *tab, int taille)
        {
            int j;
            FILE *ptr_fichier_Ascii = NULL;
            ptr_fichier_Ascii = fopen("fichier.Ascii","w");
            if (ptr_fichier_Ascii == NULL)
                {
                    printf(" le fichier n'a pas pu etre ouvert");
                    exit(1);
                }
            else
                {
                    for (j = 0; j < taille; j++)
                        {
                            fprintf(ptr_fichier_Ascii,"tab[%d] = %lf\n",j+1,tab[j]);
                        }
                    fclose(ptr_fichier_Ascii);
                }

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
                        writeToAFile(ptr_tableau,n);
                        printf("x = %f\t tab[%d] = %f\n",x,i+1,ptr_tableau[i]);
                    }
    return 0;
    }
