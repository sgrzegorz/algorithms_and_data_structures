#include <stdio.h>
#include <stdlib.h>
#include <cstdlib>
#include <cmath>
#include <time.h>

using namespace std;

//STRUKTURY
struct Student{
    int wydzial;
    int album;
    char nazwisko[20];
};

//FUNKCJE
int mod(Student l){
    return (l.wydzial);
}

void drukuj (Student lista[], int n){
    printf("\n");
    for (int i=0; i<n; i++){
        printf("%d ",lista[i].wydzial);
    }
    printf("\n");
}

int compare(const void * mod1, const void * mod2){
    struct Student * w1=(struct Student *)mod1;
    struct Student * w2=(struct Student *)mod2;

    if (mod(*w1)==mod(*w2)) return 0;
        else if (mod(*w1)<mod(*w2)) return -1;
            else return 1;
}




int main(){

    int n;
    Student *lista;
    srand(time(0));

    printf("Liczba studentów: ");
    scanf("%d", &n);
    printf("<Kazdorazowo potwierdz klawiszem enter>\n");




    lista=(Student*)malloc(n*sizeof(Student));

    for(int i=0;i<n;i++)
    {
        printf("wydzial: ");
        scanf("%d",&lista[i].wydzial);
        printf("album: ");
        scanf("%d",&lista[i].album);
        printf("nazwisko: ");
        scanf("%s",&lista[i].nazwisko);
    }



    Student *array_2[n];
    /*
    for (int i=0; i<n; i++){
        lista[i].wydzial=rand()%4;

    }
*/

    //printf("TABLICY lista PRZED SORTOWANIEM:");
    //drukuj(lista,n);
    qsort(lista, n, sizeof(struct Student), compare);
    //printf("TABLICY lista PO POSOROTOWANIU:");
    //drukuj(lista,n);

    int lw=1;
    int aktualny=lista[0].wydzial;
    for(int i=0;i<n;i++)
    {
        if(lista[i].wydzial!=aktualny)
        {
            aktualny=lista[i].wydzial;
            lw++;
        }
    }
    //printf("%d|",lw);
    struct Student * Array[lw];
    int lenw[lw];
    for(int i=0;i<lw;i++){lenw[i]=0;}
    aktualny=lista[0].wydzial;
    Array[0]=&lista[0];
    int nr=0;
    for(int i=0;i<n;i++)
    {

        if(lista[i].wydzial!=aktualny)
        {
            nr++;
            aktualny=lista[i].wydzial;
            Array[nr]=&lista[i];
        }
        lenw[nr]++;
    }
    /*
    for(int i=0;i<lw;i++)
    {
        printf("(%d ",Array[i]->wydzial);
        printf(",%d) ",lenw[i]);
    }*/

    int nrWydzialuDoWydrukowania;
    printf("\nNumer wydzia³u do wydrukowania: ");
    scanf("%d",&nrWydzialuDoWydrukowania);
    struct Student * q;
    int dlugosc;
    for(int i=0;i<lw;i++)
    {
        if(Array[i]->wydzial==nrWydzialuDoWydrukowania)
        {
            q=Array[i];
            dlugosc=lenw[i];
            break;
        }
    }
    for(int i=0;i<dlugosc;i++)
    {
        printf("wydzial: %d,",q->wydzial);
        printf("album: %d, ",q->album);
        printf("nazwisko: %s\n",q->nazwisko);
        q++;
    }

    //printf("%d",q->wydzial);
    return 0;
}
