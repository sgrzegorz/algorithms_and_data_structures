#include <iostream>
using namespace std;

int partition(int A[],int p,int r){
    int x = A[r];
    int i,j;
    i = p-1;
    for(j=p;j<r;j++){
        if(A[j]<=x){
            i+=1;
            swap(A[i],A[j]);
        }
    }
    swap(A[i+1],A[r]);
    return i+1;
}

void quicksort(int A[],int p,int r){
    while(p<r){
        int q = partition(A, p, r);
        quicksort(A,p,q-1);
        p=q+1;
    }
}


int main() {
    int A[] = {1,5,-3,12,3,4,5,9};
    quicksort(A,0,sizeof(A)/sizeof(A[0]));

    for(int i: A){
        cout<<i<<", ";
    }


    return 0;
}