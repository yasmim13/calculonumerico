#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define EX 2.7171
#define PI 3.1414
#define L 4
#define C 5
#define INTER L-1
void formar_matriz(float m[L][C],float aux[L][C]);
void imprimir_matriz(float m[L][C]);

int main (void)
{
    int i,j,k;
    float m[L][C] ={{PI,- EX, sqrt(2),- sqrt(3),sqrt(11)},
                  {PI*PI,EX,-(EX*EX),(3/7),0},
                  {sqrt(5),- sqrt(6),1,-sqrt(2),PI},
                  {PI*PI,EX*EX,- sqrt(7),0.9,sqrt(2)}};
   float mult, aux[L][C];

    for(k=0; k<INTER; k++)  /*laço dos passos*/
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
