#include <iostream>
#include <omp.h>



using namespace std;

int main() {

	long long N = 15000000000;
	double sum = 0;
	double start_time = clock();

#pragma omp parallel reduction(+:sum) num_threads(4) 
	{

#pragma omp for schedule(guided, 1000) 
		for (long long n = 1; n <= N; n += 2) {
			sum += -1.0 / (n - log(n));
			sum += 1.0 / (n + 1. - log(n + 1.));
		}
	}

	double end_time = clock();

	cout << "SUM  = " << sum << "\n";
	cout << "Time = " << (end_time - start_time) / CLK_TCK << "\n\n\n";



	return 0;
}