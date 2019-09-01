#include <iostream>
#include <cmath>

using namespace std;

const int INF = 2147483647;
// merge(A,9,12,16)
// ...9   10  11  12  13  14  15  16 ...
//    2,  4,  5,  6,  1,  2,  3,  6
//    p           q               r
// L1 = {2,4,5,7,INF}
// R1 = {1,2,3,6,INF}
void merge(int A[],int p,int q, int r){
    int n1 = q-p+1;
    int n2 = r-q;
    int L[n1+1], R[n2+1];

    for(int i=0;i<n1;i++){
        L[i] = A[p+i];
    }

    for(int j=0;j<n2;j++){
        R[j] = A[q+j+1];
    }

    L[n1] = INF;
    R[n2] = INF;

    int i = 0;
    int j =0;
    for(int k=p;k<=r;k++){
        if(L[i]<= R[j]){
            A[k] = L[i];
            i=i+1;
        }else{
            A[k] = R[j];
            j=j+1;
        }

    }
}

void merge_sort(int A[],int p,int r){
    if(p<r){
        int q = (p+r)/2;
        merge_sort(A,p,q);
        merge_sort(A,q+1,r);
        merge(A,p,q,r);
    }
}

// Driver program
int main()
{
    int A[] = {-1,6,7,3,5,4,0,5};
    int N = sizeof(A) / sizeof(A[0]);
    

    merge_sort(A, 0,N-1);
    for (int i : A) {
        cout << i << ", ";
    }
}