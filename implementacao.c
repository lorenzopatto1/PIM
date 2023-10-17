#include <stdio.h>;

#define TRUE 1
#define FALSE 0

int main()
{
  int linhas = 3, colunas = 3, i, j;

  int matriz[linhas][colunas];

  for (i = 0; i < 3; i++)
  {
    for (j = 0; j < 3; j++)
    {
      matriz[i][j] = TRUE;
      printf("%i", matriz[i][j]);
    }
  }
}