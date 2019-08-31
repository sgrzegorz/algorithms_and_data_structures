#include <stdio.h>
#include <time.h>

struct date {
	int day;
	int month;
	int year;
};

struct worker {
	char lastname[20];
	char firstname[20];
	char address[100];
	double wages;
	struct date birthdate;
	struct date empdate;
};

double mean_worktime (struct worker* staff, int n, int y) {
	double mean = 0.0;
	for (int i = 0; i < n; i++) {
		int emp = y - staff[i].empdate.year;
		mean += emp;
		printf("%15s%10s%5d\n", staff[i].lastname, staff[i].firstname, emp);
	}
	return mean / n;
}

int readdata(struct worker *staff) {
	int n;
	scanf("%d", &n);
	printf("Ilosc pracownikow: %d\n", n);
	printf("\n");
	for (int i = 0; i < n; i++) {
		scanf("%s", staff[i].lastname);
		scanf("%s", staff[i].firstname);
		scanf("%s", staff[i].address);
		scanf("%lf", &staff[i].wages);
		scanf("%d", &staff[i].birthdate.year);
		scanf("%d", &staff[i].birthdate.month);
		scanf("%d", &staff[i].birthdate.day);
		scanf("%d", &staff[i].empdate.year);
		scanf("%d", &staff[i].empdate.month);
		scanf("%d", &staff[i].empdate.day);
	}
	return n;
}

int main(void) {
	const int max = 100;
	struct worker staff[max];
	double mean;
	int n;
	time_t sec;
	struct tm* dt;

	time(&sec);
	dt = localtime(&sec);
	printf("\n");
	printf("Today is %d/%d/%d\n", dt->tm_mday, dt->tm_mon+1, dt->tm_year+1900);
	printf("\n");
	n = readdata(staff);
	mean = mean_worktime(staff, n, dt->tm_year+1900);
	printf("\n");
	printf("Mean worktime = %f\n", mean);
	printf("\n");
	return 0;
}

