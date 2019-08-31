#include <stdio.h>
#include <stdlib.h>

int N;

void inic(float **t)
{
    printf("\nWprowadz tablice A:\n");
    for(int y = 0; y < N; y++)
    {
        for( int x = 0;  x < N ; x++ ){ scanf("%f",&t[x][y]);}
    }
    printf("\nWprowadz kolumne wyrazow wolnych: \n");
    for(int y=0;y<N;y++)
    {
        scanf("%f",&t[N][y]);
    }
}

void print(float **t)
{
    for( int y = 0; y < N; y++ )
    {
        for( int x = 0; x < N+1 ; x++)
        {
            printf("%f ",t[x][y]);
        }
        printf("\n");
    }
}


void sub(float **t,int y1, int y ,float czynnik)
{
    for(int x=0;x<N+1;x++)
    {
        t[x][y1]*=czynnik;
        t[x][y1]-=t[x][y];
    }
}

int main()
{
    // |------------|--> x
    // |            |
    // |            |
    // | -----------
    // V
    // y
    printf("Podaj N: ");
    scanf("%i",&N);

    float **t=malloc((N+1)*sizeof(float*));
    for(int i=0;i<N+1;i++)
    {
        t[i]=malloc(N *sizeof(float));
    }

    inic(t);
    print(t);
    printf("\n");

    for(int x=0;x<N;x++)
    {
        int y=-1;
        for(int i=0;i<N;i++) // znajdz w kolumnie x wiersz i taki ze t[x][i]!=0
        {
            if(t[x][i]!=0)
            {
                int czy=1;
                for(int j=0;j<x;j++) // sprawdz czy od poczatku wiersza i wystepuja jakas niezerowa wartosc
                {
                    if(t[j][i]!=0)czy = 0;
                }
                if(czy)
                {
                    y=i;            // jesli wszyskto poszlo ok to znaleziony y jest naszym szukanym numerem wiersza
                    break;
                }
            }
        }
        if(y==-1) continue;       // zaden wiersz nie spelnia warunkow, zwieksz x o jeden.

        for(int y1=0;y1<N;y1++)
        {
            if(y1!=y && t[x][y1]!=0)
            {
                float czynnik=t[x][y]/t[x][y1];
                sub(t,y1,y,czynnik);
            }
        }
/*
        printf("\n");
        printf("%i",y);
        printf("\n");
        print(t);
        */

    }

    for(int y=0;y<N;y++)
    {

        int x=-1;
        for(int k=0;k<N;k++)
        {
            if(t[k][y]!=0)
            {
                x=k;
                break;
            }
        }
        if(x!=-1)
        {
            double czynnik=1/t[x][y];
            for(int i=0;i<N+1;i++)
            {
                t[i][y]*=czynnik;
            }
        }

    }



    int rA=0; //rzad A
    int rAB=0;
    for(int y=0;y<N;y++)
    {
        for(int x=0;x<N;x++)
        {
            if(t[x][y]!=0)
            {
                rA++;
                break;
            }
        }
        for(int x=0;x<N+1;x++)
        {
            if(t[x][y]!=0)
            {
                rAB++;
                break;
            }
        }
    }

    if(rA!=rAB)
    {
        printf("\nSPRZECZNY");
    }else if(rA<N){
        printf("\nNIEOZNACZONY");
    }else{
        printf("\n");
        print(t);
    }

}
