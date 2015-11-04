#include <thrust/host_vector.h>
#include <thrust/device_vector.h>
#include <thrust/reduce.h>
#include <thrust/functional.h>

int Factorial(int N){
	
	thrust::host_vector<int> H(N);
	
	for (int i=0; i < N; i++){
		H[i] = i + 1;
	}

	thrust::device_vector<int> D = H;
	
	int factoral = thrust::reduce(D.begin(), D.end(), (int) 0, thrust::multiplies<int>());
	return factoral;
}

