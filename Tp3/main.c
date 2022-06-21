#include <stdio.h>
#include <stdlib.h>

void main()
{
  int matrice[15][15], vecteur[15],matriceFinal[15][15];

  int i, j, ligne, col;

   printf(" Entrez le nombre de lignes (maximum 15): ");
   scanf("%d",&ligne);
  printf(" Entrez le nombre de colonne (maximum 15): ");
  scanf("%d",&col);

  // ramplissage et affichage de la matrice
  printf(" Entrez les %d éléments de tableau : ",ligne*col);

  for(i = 0; i < ligne; i++)
  {
    for(j = 0; j < col; j++)
    {
      scanf("%d",&matrice[i][j]);
    }
  }
  printf(" La matrice est   = \n");
  for(i=0; i < ligne; i++)
  {
    for(j = 0; j < col; j++)
    {
      printf("%d  ",matrice[i][j]);
    }
    printf("\n");
  }
  //remplissage et affichage du vecteur
  printf(" Entrez les %d éléments du vecteur : ",ligne);
for(i = 0; i < ligne; i++){
        scanf("%d",&vecteur[i]);    }

   printf(" Le vecteur est   = \n");
for(i=0; i < ligne; i++){
  printf(" %d \n ",vecteur[i]);
    }

  // modification

  printf("modification de La matrice\n");

#pragma omp parallel for num_threads(3) private(i,j)
for(i=0; i < ligne; i++)
  {
    for(j = 1; j < col; j++)
    {
      matriceFinal[i][j] = matrice[i][j]*vecteur[i];
    }
    printf("\n");
  }
  //affichage
  printf(" La nouvelle matrice est   = \n");
  for(i=0; i < ligne; i++)
  {
    for(j = 0; j < col; j++)
    {
      printf("%d  ",matrice[i][j]);
    }
    printf("\n");
  }
}
