#include <stdio.h>

union anyval {
	int n;
	double d;
	char s[10];
};

struct variable {
	char name[10];
	int type;
	union anyval val;
};

int readvars (struct variable* vars);
void printvars (struct variable* vars, int n);

int main(void) {
	const int max = 100;
	struct variable vars[max];
	printf("\n");
	int n = readvars(vars);
	printvars (vars, n);
	printf("\n");
	return 0;
}

int readvars (struct variable* vars) {
	int n;
	scanf("%d", &n);
	printf("Ilosc zmiennych = %d\n", n);
	printf("\n");
	for (int i = 0; i < n; i++) {
		scanf("%s", vars[i].name);
		scanf("%d", &vars[i].type);
		switch(vars[i].type) {
		case 1:
			scanf("%d", &vars[i].val.n);
			break;
		case 2:
			scanf("%lf", &vars[i].val.d);
			break;
		case 3:
			scanf("%s", vars[i].val.s);
			break;
		default:
			printf("Wrong type %d\n", vars[i].type);
			break;
		}
	}
	return n;
}
		

void printvars (struct variable* vars, int n) {
	static const char *types[] = {"int", "double", "string"};
	for (int i = 0; i < n; i++) {
		printf("%10s", vars[i].name);
		printf("%8s", types[vars[i].type-1]);
		switch(vars[i].type) {
		case 1:
			printf("%10d", vars[i].val.n);
			break;
		case 2:
			printf("%10f", vars[i].val.d);
			break;
		case 3:
			printf("%10s", vars[i].val.s);
			break;
		default: 
			printf("Wrong type %d", vars[i].type);
			break;
		}
		printf("\n");
	}
}

