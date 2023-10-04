#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Definir uma estrutura para armazenar informações sobre uma reserva
typedef struct
{
  int reserva_id;
  char nome_cliente[50];
  char data_checkin[11];
  char data_checkout[11];
  char tipo_quarto[20];
} Reserva;

// Função para exibir as informações de uma reserva
void exibirReserva(Reserva reserva)
{
  printf("Reserva #%d:\n", reserva.reserva_id);
  printf("Nome do cliente: %s\n", reserva.nome_cliente);
  printf("Data de check-in: %s\n", reserva.data_checkin);
  printf("Data de check-out: %s\n", reserva.data_checkout);
  printf("Tipo de quarto: %s\n", reserva.tipo_quarto);
}

int main()
{
  int opcao, num_reservas = 0;
  Reserva reservas[100];

  while (1)
  {
    printf("\nMenu de opções:\n");
    printf("1. Fazer uma nova reserva\n");
    printf("2. Visualizar reservas\n");
    printf("3. Modificar uma reserva\n");
    printf("4. Cancelar uma reserva\n");
    printf("5. Sair\n");
    printf("Escolha uma opção: ");
    scanf("%d", &opcao);

    switch (opcao)
    {
    case 1:
      if (num_reservas < 100)
      {
        system("clear");
        printf("Digite o nome do cliente: ");
        scanf(" %[^\n]", reservas[num_reservas].nome_cliente);
        printf("Digite a data de check-in (DD/MM/AAAA): ");
        scanf("%s", reservas[num_reservas].data_checkin);
        printf("Digite a data de check-out (DD/MM/AAAA): ");
        scanf("%s", reservas[num_reservas].data_checkout);
        printf("Digite o tipo de quarto: ");
        scanf(" %[^\n]", reservas[num_reservas].tipo_quarto);
        reservas[num_reservas].reserva_id = num_reservas + 1;
        printf("Reserva criada com sucesso!\n");
        num_reservas++;
      }
      else
      {
        system("clear");
        printf("Limite de reservas atingido!\n");
        sleep(2);
        system("clear");
      }
      break;

    case 2:
      system("clear");
      printf("Reservas existentes:\n");
      sleep(2);
      system("clear");
      for (int i = 0; i < num_reservas; i++)
      {
        exibirReserva(reservas[i]);
      }
      break;

    case 3:
      system("clear");
      printf("Digite o ID da reserva que deseja modificar: ");
      int id_modificar;
      scanf("%d", &id_modificar);
      if (id_modificar >= 1 && id_modificar <= num_reservas)
      {
        system("clear");
        exibirReserva(reservas[id_modificar - 1]);
        printf("Digite a nova data de check-in (DD/MM/AAAA): ");
        scanf("%s", reservas[id_modificar - 1].data_checkin);
        system("clear");
        printf("Digite a nova data de check-out (DD/MM/AAAA): ");
        scanf("%s", reservas[id_modificar - 1].data_checkout);
        system("clear");
        printf("Digite o novo tipo de quarto: ");
        scanf(" %[^\n]", reservas[id_modificar - 1].tipo_quarto);
        system("clear");
        printf("Reserva modificada com sucesso!\n");
        sleep(2);
        system("clear");
      }
      else
      {
        system("clear");
        printf("ID de reserva inválido!\n");
        sleep(2);
        system("clear");
      }
      break;

    case 4:
      system("clear");
      printf("Digite o ID da reserva que deseja cancelar: ");
      int id_cancelar;
      scanf("%d", &id_cancelar);
      if (id_cancelar >= 1 && id_cancelar <= num_reservas)
      {
        for (int i = id_cancelar - 1; i < num_reservas - 1; i++)
        {
          reservas[i] = reservas[i + 1];
        }
        num_reservas--;
        system("clear");
        printf("Como politica de cancelamento, cobraremos uma taxa de 10%% do valor pago na sua reserva\n");
        sleep(5);
        system("clear");
        printf("Reserva cancelada com sucesso!\n");
        sleep(2);
        system("clear");
      }
      else
      {
        system("clear");
        printf("ID de reserva inválido!\n");
        sleep(2);
        system("clear");
      }
      break;

    case 5:
      system("clear");
      printf("Saindo do programa. Até logo!\n");
      exit(0);

    default:
      system("clear");
      printf("Opção inválida!\n");
      sleep(2);
      system("clear");
    }
  }

  return 0;
}