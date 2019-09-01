#include <iostream>

using namespace std;

int left(int i) {
    return 2 * i + 1;
}

int right(int i) {
    return 2 * i + 2;
}

int parent(int i) {
    return (i - 1) / 2;
}

//usun blad z kopca o korzeniu i, jesli jedno z dzieci korzenia jest od niego wieksze
void max_heapify(int A[], int heap_size, int i) {
    int max = i;
    int l = left(i);
    int r = right(i);

    if (l < heap_size and A[l] > A[max]) {
        max = l;
    }
    if (r < heap_size and A[r] > A[max]) {
        max = r;
    }
    if (max != i) {
        swap(A[i], A[max]);
        max_heapify(A, heap_size, max);
    }
}

void heapsort(int A[], int N) {
    //build max heap zbuduj drzewo binarne z właściwością ze rodzic jest wiekszy od kazdego z dwojga jego dzieci.
    int heap_size = N;
    for (int i = N / 2 - 1; i >= 0; i--) {
        max_heapify(A, heap_size, i);
    }

    for (int i = N - 1; i >= 0; i--) {
        //wez najwiekszy element kopca - korzen i wyrzuc go poza kopiec
        swap(A[0], A[i]);
        heap_size = heap_size -1;
        //napraw kopiec bo korzen teraz nie jest najwiekszym elementem kopca
        max_heapify(A, heap_size, 0);
    }
}


int main() {
    int A[] = {12, 0, 11, 13, 5, 6, 7};
    int N = sizeof(A) / sizeof(A[0]);

    heapsort(A, N);
    for (int i : A) {
        cout << i << ", ";
    }
    return 0;
}