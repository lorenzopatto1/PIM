#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// Função para validar o formato da data
bool validarData(const char *data)
{
  if (strlen(data) != 10)
    return false;

  if (data[2] != '/' || data[5] != '/')
    return false;

  int dia, mes, ano;
  if (sscanf(data, "%d/%d/%d", &dia, &mes, &ano) != 3)
    return false;

  if (dia < 1 || dia > 31 || mes == 1 && dia > 31 || mes == 2 && dia > 28 || mes == 3 && dia > 31 || mes == 4 && dia > 30 || mes == 5 && dia > 31 || mes == 6 && dia > 30 || mes == 7 && dia > 31 || mes == 8 && dia > 31 || mes == 9 && dia > 30 || mes == 10 && dia > 31 || mes == 11 && dia > 30 || mes == 12 && dia > 31 || mes < 1 || mes > 12 || ano < 2023)
    return false;

  // Você também pode adicionar verificações mais específicas, como verificar se o mês não excede 31 dias, se é um ano bissexto, etc.

  return true;
}

int main()
{
  char data[11];

  do
  {
    printf("Digite a data utilizando o formato a seguir (dd/mm/aaaa): ");
    scanf(" %10[^\n]", data);

    if (!validarData(data))
    {
      printf("Formato de data inválido. Tente novamente.\n");
    }
  } while (!validarData(data));

  printf("Data válida: %s\n", data);

  return 0;
}
