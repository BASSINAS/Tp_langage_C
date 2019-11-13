#include <stdio.h>
#include <stdlib.h>

double f(double x)
        {
            return x*x; // Cette fonction est un exemple
        }
//size_t fwrite ( const void * ptr, size_t size, size_t count, FILE * stream )
//        {
//            int i;
//            ptr = fopen("Fic.bin","wba");
//            if (ptr == NULL)
//                {
//                    printf("erreur le fichier binaire n'a pas pu etre ouvert!");
//                    exit(1);
//                }
//            else
//                {
//                    for(i = 0; i < count; i++)
//                        {
//                            fwrite(ptr,sizeof(size_t),count,stream);
//                        }
//                }
//        fclose(ptr);
//        }

int main()
        {
            int i;
            double a,b,pas,x;
            double *ptr_tableau = NULL;
            FILE *fp = NULL;
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
                        printf("x = %f\t tab[%d] = %f \n",x,i+1,ptr_tableau[i]);
                        fp = fopen("fic.bin","wb");
                        if(fp == NULL)
                            {
                                printf("erreur d'ouverture du fichier");
                                exit(1);
                            }
                        else
                            {
                                fwrite(ptr_tableau,sizeof(double),n,fp);
                            }
                    }
            fclose(fp);

    return 0;
    }
