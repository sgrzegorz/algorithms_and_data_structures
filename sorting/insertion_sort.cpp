#include <iostream>

using namespace std;

void isortTab(int A[], int n) {
	for (int j = 1; j < n; j++) {
		int key = A[j];
		int i = j - 1;
		while (i >= 0 && A[i]>key) {
			A[i + 1] = A[i];
			i--;
		}
		A[i + 1] = key;
	}
}

int main()
{
    int t[] = {5,3,6,7,7,1,0,0};
    int n =sizeof(t)/sizeof(t[0]);
    isortTab(t,n);
    for(int i=0;i<n;i++){cout<<t[i]<<" ";}
}
