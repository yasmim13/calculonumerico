#include <stdio.h>
#include <stdlib.h>
 void fomarmatriz(float m[3][4],float aux[3][4]);

void imprimirmatriz(float m[3][4]);

int main (void)
{
    int i,j,k;
    float m[3][4] ={{2,1,-3,-1},
                  {-1,3,2,12},
                  {3,1,-3,0}};
   float mult, aux[3][4];
   int v[4];

    for(k=0;k<2;k++)
    {
        for(i=k+1;i<3;i++)
        {
            mult=m[i][k]/m[k][k];
            for(j=0;j<4;j++)
                aux[i][j]=m[i][j]-(mult*m[k][j]);
        }
        fomarmatriz(m,aux);
        imprimirmatriz(m);
    }       
    return 0;
}

void fomarmatriz(float m[3][4],float aux[3][4])
{
    for (int i=1;i<3;i++)
    {
        for(int j=0;j<4;j++)
            m[i][j]=aux[i][j];
   }  
    return;
}

void imprimirmatriz(float m[3][4])
{

    printf("\n");
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<4;j++)
            printf("%f ",m[i][j]);
        printf("\n");
    }
    return;
}
