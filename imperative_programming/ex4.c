void reverse(int*, int);

int main(void) {
	int* pt = (int*)calloc(1, sizeof(int));	//	allocate space for an int
	*pt = 1001;	//	store a value there
	printf("\n");
	printf("int value = %d: location = %p\n", *pt, (void*)pt);
	double* pd = (double*)calloc(1, sizeof(double));	//	allocate space for a double
	*pd = 10000001.0;	//	store a double there
	printf("double value = %f: location = %p\n", *pd, (void*)pd);
	printf("\n");
	printf("size of pt = %zu: size of *pt = %zu\n", sizeof(pt), sizeof(*pt));
	printf("size of pd = %zu: size of *pd = %zu\n", sizeof(pd), sizeof(*pd));
	printf("\n");
	int *arrp, dim;
	printf("\n");
	printf("Podaj rozmiar tablicy: ");
	scanf("%d", &dim);
	arrp = (int*)calloc(dim, sizeof(int));
	if (!arrp) {
		printf("Brak PAO\n");
		exit(1);
	}
	printf("\n");
	for (int i = 0; i < dim; i++) arrp[i] = i + 3;
	for (int i = 0; i < dim; i++)
		printf("arr[%d] = %d\n", i, arrp[i]);
	printf("\n");
	reverse(arrp, dim);
	for (int i = 0; i < dim; i++)
		printf("arr[%d] = %d\n", i, arrp[i]);
	printf("\n");
	free(pt);
	free(pd);
	free(arrp);
	return 0;
}

void reverse (int* pa, int n) {
	int i, j, t;
	for (i = 0, j = n-1; i < j; i++, j--) {
		t = pa[i];
		pa[i] = pa[j];
		pa[j] = t;
	}
}
