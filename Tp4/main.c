
        #include<stdio.h>
	#include<stdlib.h>
	#include<omp.h>
	int main (int argc, char const *argv[]){
	int n=5;
	float *A =(float*)malloc(sizeof(float)*n); //allocation dynamique du tablau A
	int i;

	for(i=0;i<n;i++){
	    A[i]=i+1;
	}
	    #pragma omp parallel for num_threads(5)  // CREATION DE 5 thread pour la   paralelisation du programme.
	for(i=0;i<n;i++){

	    A[i]= (A[i]+A[i-1])/2;
	    printf("A[%d] = %f..... execute par le thread Nr: %d\n", i, A[i],omp_get_thread_num());
	}
	    return 0;
	}
