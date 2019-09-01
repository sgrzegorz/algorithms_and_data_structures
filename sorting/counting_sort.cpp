// C++ program for implementation of Heap Sort
#include <iostream>
#include <algorithm>


using namespace std;

// A - tablica indeksowana od 0
// n -dlugosc tablicy A
// k - ilość liczb w przedziale [0,największa_liczba_w_A], UWAGA k = max_element(A)+1
void counting_sort(int A[],int n,int k){
    int B[n], C[k];
    for(int i=0;i<k;i++) C[i]=0;
    for(int i=0;i<n;i++) C[A[i]]++;
    for(int i=1;i<k;i++) C[i] = C[i]+C[i-1];
    for(int i=n-1;i>=0;i--){ //musi byc od tyłu zeby bylo stabilne
        B[C[A[i]]-1] = A[i]; // to -1 jest poniewaz tablica A indeksowana jest od 0.
        C[A[i]]--;
    }

    for(int i=0;i<n;i++) A[i]=B[i];
}


int main()
{
    int A[]={2,5,3,0,2,3,0,3,6,0};
    int n=sizeof(A)/sizeof(A[0]);
    int k = (*max_element(A,A+n))+1;

    counting_sort(A,n,k);

    for (int i : A) {
        cout << i << ", ";
    }


}