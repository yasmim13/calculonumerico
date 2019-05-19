#include <stdio.h>
#include <stdlib.h>
#define  L 4
#define  C 5

void formar_matriz(float m[L][C],float aux[L][C]);
void imprimir_matriz(float m[L][C]);

int main (void)
{
    int i,j,k;
    float m[L][C] ={{0.2345, 0.6793, 0.0145, 1.3315, 3.032},
                  {2.2360, 1.9861, 1.7723, 2.0315, 2.135},
                  {1.7723, -7.3324, 5.1961, -2.8284, 1.015},
                  {2.4142, 1.7320, -5.3171, 5.6785, 2.101}};
   float mult, aux[L][C];

    for(k=0; k<3; k++)  /*laço dos passos*/
    {
        for(i=k+1; i<L; i++)  /*laço das linhas*/
        {
            mult = m[i][k]/m[k][k];
            for(j=0; j<C ; j++)   /*laço das colunas*/
                aux[i][j] = m[i][j]-(mult*m[k][j]);
        }

        formar_matriz(m,aux);
        imprimir_matriz(m);
    }       
    return 0;
}


/*coloca as linhas novas na matriz original*/
void formar_matriz(float m[L][C],float aux[L][C])
{
    for (int i=1;i<L;i++)
    {
        for(int j=0;j<C;j++)
            m[i][j]=aux[i][j];
    }  
    return;
}

void imprimir_matriz(float m[L][C])
{

    printf("\n");
    for(int i=0;i<L;i++)
    {
        for(int j=0;j<C;j++)
            printf("%f ",m[i][j]);
        printf("\n");
    }
    return;
}
