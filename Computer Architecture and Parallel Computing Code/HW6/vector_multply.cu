#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <assert.h>
#include <cuda.h>
#include <cuda_runtime.h>

#define N 2000000
#define MAX_ERR 1e-6

__global__ void vector_multiply(float *out, float *a, float *b, int n) {
    //TODO
	int i;
	for(i = 0; i<n; i++){
	out[i] = a[i] * b[i];
	}
}

int main(){
    float *a, *b, *out;
    float *d_a, *d_b, *d_out; 

    a   = (float*)malloc(sizeof(float) * N);
    b   = (float*)malloc(sizeof(float) * N);
    out = (float*)malloc(sizeof(float) * N);

    // Initialize host arrays
    for(int i = 0; i < N; i++){
        a[i] = 4.0f;
        b[i] = 9.0f;
    }

   
    cudaMalloc((void**)&d_a, sizeof(float) * N);
    cudaMalloc((void**)&d_b, sizeof(float) * N);
    cudaMalloc((void**)&d_out, sizeof(float) * N);

    cudaMemcpy(d_a, a, sizeof(float) * N, cudaMemcpyHostToDevice);
    cudaMemcpy(d_b, b, sizeof(float) * N, cudaMemcpyHostToDevice);

    // Executing kernel 
    //TODO: call vector_multiply<<<1,1>>> with output array (d_out), input arrays (d_a, d_b), and N
   
	vector_multiply<<<1,1>>>(d_out,d_a,d_b,N);
    
   
    cudaMemcpy(out, d_out, sizeof(float) * N, cudaMemcpyDeviceToHost);

    // Verification
    for(int i = 0; i < N; i++){
        assert(fabs(out[i] - a[i] * b[i]) < MAX_ERR);
    }
    printf("out[1999999] = %f\n", out[1999999]);
    printf("PASSED\n");

    // Deallocate device memory using cudaFree
    //TODO
cudaFree(d_a);
cudaFree(d_b);
cudaFree(d_out);

    // Deallocate host memory using free
   //TODO
free(a);
free(b);
free(out);
}
