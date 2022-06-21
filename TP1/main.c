#include<stdio.h>
#include<stdlib.h>
#include<omp.h>
int main (int argc, char const *argv[]){

int n=(50);

float *A =(float*)malloc(sizeof(float)*n); //allocation dynamique des tablaus AB et C
float *B =(float*)malloc(sizeof(float)*n);
float *C =(float*)malloc(sizeof(float)*n);
int i;

 for(i=0;i<n;i++){
    A[i]=i+1;
    B[i]=i+2;
 }
    #pragma omp parallel for num_threads(10)  // CREATION DE 5 thread pour la paralelisation du programme.
for(i=0;i<n;i++){

    C[i]= A[i]+B[i];
    printf("A[%d] =  %f ....B[%d] =  %f ....C[%d] =  %f\n ",i,A[i],i,B[i],i,C[i]); // affichage du resultat.
 }



return EXIT_SUCCESS;
}

