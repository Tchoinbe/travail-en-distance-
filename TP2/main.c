#include<stdio.h>
#include<stdlib.h>
#include<omp.h>

int main (int argc, char const *argv[]){

int n=65636;
float *X =(float*)malloc(sizeof(float)*n); //allocation dynamique du tablau X
int i;
double sum;
for(i=0;i<n;i++){
    X[i]= i+1;

}


    #pragma omp parallel  num_threads(5)  // CREATION DE 5 thread pour la paralelisation du programme.

for(i=0;i<n;i++){
    sum  +=  X[i];

}

    printf("LA SOMMME EST: %f\n", sum);

    return 0;
}
