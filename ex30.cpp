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
    int t[4];
    t[0]=1;
    t[1]=-6;
    t[2]=9;
    t[3]=-12;
    isortTab(t,4);
    for(int i=0;i<4;i++){cout<<t[i]<<" ";}
}
