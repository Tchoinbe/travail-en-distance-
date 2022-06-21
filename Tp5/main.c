#include <stdio.h>
#include <stdlib.h>

void main()
{
  int matrice[10][10];
  int i, j, row, col;

   printf(" Entrez le nombre de lignes (maximum 10): ");
   scanf("%d",&row);
  printf(" Entrez le nombre de colonne (maximum 10): ");
  scanf("%d",&col);
  printf(" Entrez les %d éléments de tableau : ",row*col);

  for(i = 0; i < row; i++)
  {
    for(j = 0; j < col; j++)
    {
      scanf("%d",&matrice[i][j]);
    }
  }
  printf(" La matrice est   = \n");
  for(i=0; i < row; i++)
  {
    for(j = 0; j < col; j++)
    {
      printf("%d  ",matrice[i][j]);
    }
    printf("\n");
  }

  // modification

  printf("modification de La matrice\n");

      #pragma omp parallel for num_threads(3)
  for(i=0; i < row; i++)
  {
    for(j = 1; j < col; j++)
    {
      matrice[i][j] += matrice[i][j-1];;
    }
    printf("\n");
  }
  //affichage
  printf(" La nouvelle matrice est   = \n");
  for(i=0; i < row; i++)
  {
    for(j = 0; j < col; j++)
    {
      printf("%d  ",matrice[i][j]);
    }
    printf("\n");
  }
}

