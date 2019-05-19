#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define  L 4
#define  C 5
#define PI 3.1414

void formar_matriz(float m[L][C],float aux[L][C]);
void imprimir_matriz(float m[L][C]);

void iteracoes(float m[L][C],float i[4], int max);

int main (void)
{
    int i,j,k;
    float s[4]={1.21,0.32,2.41,0.35};

    float m[L][C] ={{0.2345, 0.6793, 0.0145, 1.3315, 3.032},
                    {sqrt(5), 1.9861, -sqrt(PI), 2.0315, 2.135},
                    {sqrt(PI), -7.3324, 3*sqrt(3), -2*sqrt(2), 1.015},
                    {sqrt(2), sqrt(3), -3*sqrt(PI), 5.6785, 2.101}};

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
    
        iteracoes(m,s,0);
    return 0;
}

void iteracoes(float m[L][C],float i[4], int max)
{
    float v[4];

    if(max<10)
    {

    v[3] =i[3]+m[3][4]/ m[3][3];
   v[2]= i[2]+(1/m[2][2])*(m[2][4]-(m[2][3]*v[3]));
   v[1]=i[1]+(1/m[1][1])*(m[1][4]-((m[1][2]*v[2])+(m[1][3]*v[3])));
   v[0]=i[0]+(1/m[0][0])*(m[0][4]-((m[0][1]*v[1])+(m[0][2]*v[2])+(m[0][3]*v[3])));

   printf("\n S%d(",max);
 for(int i=0;i<4;i++)
     printf(" %f; ",v[i]);

 printf(")\n");

 iteracoes(m,v,max+1);
    }

 return;
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
