#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <unistd.h>

typedef struct
{
  int reserva_id;
  char nome_cliente[50];
  char identificacao_cliente[50];
  char nascimento[10];
  char data_checkin[10];
  char data_checkout[10];
  int quarto_escolhido;
  float valor;
} Reserva;

// Definir uma estrutura para armazenar informações das suites
typedef struct
{
  int suite_id;
  int suite_Standard;
  int suite_Master;
  int suite_Deluxo;
} Quarto;

// Função para exibir as informações de uma reserva
void exibirReserva(Reserva reserva)
{
  setlocale(LC_ALL, "Portuguese");

  printf("\nReserva #%d:\n", reserva.reserva_id);

  printf("Nome do cliente: %s\n", reserva.nome_cliente);

  printf("Data de nascimento do cliente: %s\n", reserva.nascimento);

  printf("Documento do cliente: %s\n", reserva.identificacao_cliente);

  printf("Data de check-in: %s\n", reserva.data_checkin);

  printf("Data de check-out: %s\n", reserva.data_checkout);

  if (reserva.quarto_escolhido == 1)
  {
    printf("Tipo de quarto: Suite Master");
  }
  else if (reserva.quarto_escolhido == 2)
  {
    printf("Tipo de quarto: Quarto Standard");
  }
  else
    printf("Tipo de quarto: Quarto de Luxo");
};

Reserva reservas[100];

int main()
{
  int tipo_quarto, escolha, opcao, num_reservas, suite_Standard = 0, suite_Master = 0, suite_Deluxo = 0;

  printf("Seja bem vindo!\n");
  printf("Escolha o hotel de sua preferencia:\n");
  printf("1. Hotel A\n");
  printf("2. Hotel B\n");
  printf("Digite o número correspondete a sua escolha:\n");
  scanf("%d", &escolha);
  fflush(stdin);

  if (escolha == 1)
  {
    system("clear");
    printf("Voce escolheu o Hotel A.\n Tenha uma otima estadia!\n");
  }
  else if (escolha == 2)
  {
    system("clear");
    printf("Voce escolheu o Hotel B.\n Tenha uma otima estadia!\n");
  }
  else
  {
    system("clear");
    printf("Escolha inválida. Por gentileza, escolha 1 para Hotel A ou 2 para o Hotel B.\n");
  }

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
    fflush(stdin);

    switch (opcao)
    {
    case 1:
      if (num_reservas < 100)
      {
        system("clear");
        printf("Digite o nome do cliente: ");
        scanf(" %[^\n]", reservas[num_reservas].nome_cliente);
        fflush(stdin);

        printf("Digite o seu RG ou CPF: ");
        scanf(" %[^\n]", reservas[num_reservas].identificacao_cliente);
        fflush(stdin);

        printf("Digite sua data de nascimento: ");
        scanf(" %[^\n]", reservas[num_reservas].nascimento);
        fflush(stdin);

        printf("Digite a data de check-in (DD/MM/AAAA): ");
        scanf("%s", reservas[num_reservas].data_checkin);
        fflush(stdin);

        printf("Digite a data de check-out (DD/MM/AAAA): ");
        scanf("%s", reservas[num_reservas].data_checkout);
        fflush(stdin);
        system("clear");

        printf("Escolha o tipo de quarto: \n");
        printf("1 Suite Master\n");
        printf("  R$ 120,00\n");
        printf("2 Quarto Standard\n");
        printf("  R$ 180,00\n");
        printf("3 Quarto de Luxo\n");
        printf("  R$ 240,00\n");
        scanf(" %i", &tipo_quarto);
        fflush(stdin);
        reservas[num_reservas].quarto_escolhido = tipo_quarto;

        switch (tipo_quarto)
        {
        case 1:
          if (suite_Master == 3)
          {
            printf("Numero maximo de reservas atingido\n");
            sleep(2);
            system("clear");
            break;
          };
          suite_Master = suite_Master + 1;
          reservas[num_reservas].reserva_id = num_reservas + 1;
          printf("Reserva criada com sucesso!\n");
          num_reservas++;
          break;

        case 2:
          if (suite_Deluxo == 3)
          {
            system("clear");
            printf("Numero maximo de reservas atingido\n");
            sleep(2);
            system("clear");
            break;
          }

          suite_Deluxo = suite_Deluxo + 1;
          reservas[num_reservas].reserva_id = num_reservas + 1;
          printf("Reserva criada com sucesso!\n");
          num_reservas++;
          break;

        case 3:
          if (suite_Standard == 3)
          {
            printf("Numero maximo de reservas atingido\n");
            sleep(2);
            system("clear");
            break;
          }

          suite_Standard = suite_Standard + 1;
          reservas[num_reservas].reserva_id = num_reservas + 1;

          printf("Reserva criada com sucesso!\n");
          num_reservas++;
          break;
        default:
          system("clear");
          printf("Opcao invalida");
        }
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
      // system("clear");
      for (int i = 0; i < num_reservas; i++)
      {
        exibirReserva(reservas[i]);
      }
      printf("\n");
      // system("pause");
      // system("clear");
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
        scanf(" %[^\n]", reservas[id_modificar - 1].quarto_escolhido);
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