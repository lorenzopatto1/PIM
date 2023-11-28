#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <unistd.h>
#include <time.h>
#include <stdbool.h>

typedef struct
{
  int dia;
  int mes;
  int ano;
} DATEC;

typedef struct
{
  int reserva_id;
  char hotel;
  char nome_cliente[50];
  char identificacao_cliente[50];
  DATEC nascimento;
  DATEC data_checkin;
  DATEC data_checkout;
  int quarto_escolhido;
  float valor;
} Reserva;

// Fun��o para exibir as informa��es de uma reserva
void exibirReserva(Reserva reserva)
{
  printf("\nReserva #%d:\n", reserva.reserva_id);
  if (reserva.hotel == 1)
  {
    printf("Hotel: A\n");
  }
  else
  {
    printf("Hotel: B\n");
  }
  printf("Nome do cliente: %s\n", reserva.nome_cliente);

  printf("Data de nascimento do cliente: %02d/%02d/%04d\n", reserva.nascimento.dia, reserva.nascimento.mes, reserva.nascimento.ano);

  printf("Documento do cliente: %s\n", reserva.identificacao_cliente);

  printf("Data de check-in: %02d/%02d/%04d\n", reserva.data_checkin.dia, reserva.data_checkin.mes, reserva.data_checkin.ano);

  printf("Data de check-out: %02d/%02d/%04d\n", reserva.data_checkout.dia, reserva.data_checkout.mes, reserva.data_checkout.ano);

  if (reserva.quarto_escolhido == 1)
  {
    printf("Tipo de quarto: Suite Master\n");
  }
  else if (reserva.quarto_escolhido == 2)
  {
    printf("Tipo de quarto: Quarto Standard\n");
  }
  else
  {
    printf("Tipo de quarto: Quarto de Luxo\n");
  }
  printf("Valor da reserva: %.2f", reserva.valor);
}
int escolha;

void escolha_hotel()
{
  do
  {
    printf("Escolha o hotel de sua prefer�ncia:\n");
    printf("1. Hotel A\n");
    printf("2. Hotel B\n");
    printf("Digite o numero correspondete a sua escolha:\n");
    scanf("%d", &escolha);

    if (escolha == 1)
    {
      system("cls");
      printf("Voc� escolheu o Hotel A.\n Tenha uma �tima estadia!\n");
    }
    else if (escolha == 2)
    {
      system("cls");
      printf("Voc� escolheu o Hotel B.\n Tenha uma �tima estadia!\n");
    }
    else
    {
      system("cls");
      printf("Escolha invalida. Por gentileza, escolha 1 para Hotel A ou 2 para o Hotel B.\n");
    }
  } while (escolha != 1 && escolha != 2);
}

int main()
{
  setlocale(LC_ALL, "Portuguese");
  int tipo_quarto, opcao, num_reservas = 0, suite_Standard = 0, suite_Master = 0, suite_Deluxo = 0;

  bool disponibilidade_suite_master[30];    // Um array de 30 booleanos para representar a disponibilidade dos dias
  bool disponibilidade_quarto_luxo[30];     // Um array de 30 booleanos para representar a disponibilidade dos dias
  bool disponibilidade_quarto_standard[30]; // Um array de 30 booleanos para representar a disponibilidade dos dias
  int i, quantidade_dias, data_reserva;
  int valor_suite_master = 120, valor_quarto_luxo = 160, valor_quarto_standard = 200;

  // Realizar login
  login();

  // Inicialize todos os dias como disponiveis (true)
  for (i = 0; i < 30; i++)
  {
    disponibilidade_suite_master[i] = true;
    disponibilidade_quarto_luxo[i] = true;
    disponibilidade_quarto_standard[i] = true;
  }

  Reserva reservas[100];

  time_t t;
  struct tm *tm_info;
  char buffer[20];

  time(&t);
  tm_info = localtime(&t);

  strftime(buffer, 20, "%d/%m/%Y %H:%M:%S", tm_info);

  printf("Seja bem vindo!\n");
  printf("Horario Atual: \n");
  printf("%s \n", buffer);
  system("cls");

  while (1)
  {

    printf("\nMenu de op��es:\n");
    printf("1. Fazer uma nova reserva\n");
    printf("2. Visualizar reservas\n");
    printf("3. Modificar uma reserva\n");
    printf("4. Cancelar uma reserva\n");
    printf("5. Sair\n");
    printf("Escolha uma das op��es: ");
    scanf("%d", &opcao);
    fflush(stdin);

    switch (opcao)
    {
    case 1:
      if (num_reservas < 100)
      {
        system("cls");
        escolha_hotel();
        system("cls");
        printf("Digite o nome do cliente: ");
        scanf(" %[^\n]", &reservas[num_reservas].nome_cliente);
        fflush(stdin);

        printf("Digite o RG ou CPF do cliente: ");
        scanf(" %[^\n]", &reservas[num_reservas].identificacao_cliente);
        fflush(stdin);

        printf("Digite sua data de nascimento (DD/MM/AAAA): ");
        scanf("%d/%d/%d", &reservas[num_reservas].nascimento.dia, &reservas[num_reservas].nascimento.mes, &reservas[num_reservas].nascimento.ano);
        fflush(stdin);

        printf("Quantos dias de estadia voc� deseja? ");
        scanf("%i", &quantidade_dias);
        fflush(stdin);

        printf("Digite a data de check-in (DD/MM/AAAA): ");
        scanf("%d/%d/%d", &reservas[num_reservas].data_checkin.dia, &reservas[num_reservas].data_checkin.mes, &reservas[num_reservas].data_checkin.ano);
        fflush(stdin);

        if (reservas[num_reservas].data_checkin.dia + quantidade_dias >= 31)
        {
          reservas[num_reservas].data_checkout.dia = reservas[num_reservas].data_checkin.dia;
          reservas[num_reservas].data_checkout.mes = reservas->data_checkin.mes + 1;

          while (reservas[num_reservas].data_checkout.dia != 30)
          {
            reservas[num_reservas].data_checkout.dia++;
            quantidade_dias--;
          }
          reservas[num_reservas].data_checkout.dia = 1 + quantidade_dias - 1;
        }
        else
        {
          reservas[num_reservas].data_checkout.dia = reservas[num_reservas].data_checkin.dia + quantidade_dias;
          reservas[num_reservas].data_checkout.mes = reservas[num_reservas].data_checkin.mes;
        }

        if (reservas[num_reservas].data_checkout.mes > 12)
        {
          reservas[num_reservas].data_checkout.mes = 1;
          reservas[num_reservas].data_checkout.ano = reservas[num_reservas].data_checkin.ano + 1;
        }
        else
        {
          reservas[num_reservas].data_checkout.ano = reservas[num_reservas].data_checkin.ano;
        }

        fflush(stdin);
        system("cls");

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
        reservas[num_reservas].hotel = escolha;

        switch (tipo_quarto)
        {
        case 1:

          for (i = reservas[num_reservas].data_checkin.dia; i < reservas[num_reservas].data_checkin.dia + quantidade_dias; i++)
          {
            if (reservas[num_reservas].data_checkin.dia + quantidade_dias <= 30)
            {
              disponibilidade_suite_master[i - 1] = false;
            }
            else
              disponibilidade_suite_master[i - 1] = true;
          }

          reservas[num_reservas].valor = quantidade_dias * valor_suite_master;
          reservas[num_reservas].reserva_id = num_reservas + 1;

          printf("Reserva criada com sucesso!\n");
          num_reservas++;
          break;

        case 2:

          reservas[num_reservas].valor = quantidade_dias * valor_quarto_luxo;
          for (i = reservas[num_reservas].data_checkin.dia; i < reservas[num_reservas].data_checkin.dia + quantidade_dias; i++)
          {
            if (reservas[num_reservas].data_checkin.dia + quantidade_dias <= 30)
            {
              disponibilidade_quarto_luxo[i - 1] = false;
            }
            else
              disponibilidade_quarto_luxo[i - 1] = true;
          }

          suite_Deluxo = suite_Deluxo + 1;
          reservas[num_reservas].reserva_id = num_reservas + 1;
          printf("Reserva criada com sucesso!\n");
          num_reservas++;
          break;

        case 3:

          reservas[num_reservas].valor = quantidade_dias * valor_quarto_standard;
          for (i = reservas[num_reservas].data_checkin.dia; i < reservas[num_reservas].data_checkin.dia + quantidade_dias; i++)
          {
            if (reservas[num_reservas].data_checkin.dia + quantidade_dias <= 30)
            {
              disponibilidade_quarto_standard[i - 1] = false;
            }
            else
              disponibilidade_quarto_standard[i - 1] = true;
          }

          suite_Standard = suite_Standard + 1;
          reservas[num_reservas].reserva_id = num_reservas + 1;

          printf("Reserva criada com sucesso!\n");
          num_reservas++;
          break;
        default:
          system("cls");
          printf("Op��es invalida");
        }
      }
      else
      {
        system("cls");
        printf("Limite de reservas atingido!\n");

        sleep(2);
        system("cls");
      }
      break;

    case 2:
      system("cls");
      printf("Reservas existentes:\n");

      for (int i = 0; i < num_reservas; i++)
      {
        exibirReserva(reservas[i]);
      }
      printf("\n");

      break;

    case 3:
      system("cls");
      printf("Digite o ID da reserva que deseja modificar: ");

      int id_modificar;
      scanf("%d", &id_modificar);

      if (id_modificar >= 1 && id_modificar <= num_reservas)
      {
        system("cls");
        exibirReserva(reservas[id_modificar - 1]);
        printf("\nDigite a nova data de check-in (DD/MM/AAAA): ");
        scanf("%d/%d/%d", &reservas[id_modificar - 1].data_checkin.dia, &reservas[id_modificar - 1].data_checkin.mes, &reservas[id_modificar - 1].data_checkin.ano);

        system("cls");

        printf("Quantos dias para estadia voc� deseja?");
        scanf("%i", &quantidade_dias);

        fflush(stdin);
        if (reservas[id_modificar - 1].data_checkin.dia + quantidade_dias >= 31)
        {
          reservas[id_modificar - 1].data_checkout.dia = reservas[id_modificar - 1].data_checkin.dia;
          reservas[id_modificar - 1].data_checkout.mes = reservas->data_checkin.mes + 1;

          while (reservas[id_modificar - 1].data_checkout.dia != 30)
          {
            reservas[id_modificar - 1].data_checkout.dia++;
            quantidade_dias--;
          }
          reservas[id_modificar - 1].data_checkout.dia = 1 + quantidade_dias - 1;
        }
        else
        {
          reservas[id_modificar - 1].data_checkout.dia = reservas[id_modificar - 1].data_checkin.dia + quantidade_dias;
          reservas[id_modificar - 1].data_checkout.mes = reservas[id_modificar - 1].data_checkin.mes;
        }

        if (reservas[id_modificar - 1].data_checkout.mes > 12)
        {
          reservas[id_modificar - 1].data_checkout.mes = 1;
          reservas[id_modificar - 1].data_checkout.ano = reservas[id_modificar - 1].data_checkin.ano + 1;
        }
        else
        {
          reservas[id_modificar - 1].data_checkout.ano = reservas[id_modificar - 1].data_checkin.ano;
        }

        printf("Digite o novo tipo de quarto: ");
        scanf(" %i", &reservas[id_modificar - 1].quarto_escolhido);

        system("cls");

        printf("Reserva modificada com sucesso!\n");
        sleep(2);
        system("cls");
      }
      else
      {
        system("cls");
        printf("ID de reserva invalido!\n");
        sleep(2);
        system("cls");
      }
      break;

    case 4:
      system("cls");
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
        system("cls");

        printf("Como politica de cancelamento, cobraremos uma taxa de 10%% do valor pago na sua reserva\n");
        sleep(5);
        system("cls");

        printf("Reserva cancelada com sucesso!\n");
        sleep(2);
        system("cls");
      }
      else
      {
        system("cls");
        printf("ID de reserva invalido!\n");
        sleep(2);
        system("cls");
      }
      break;

    case 5:
      system("cls");
      printf("Saindo do programa. At� logo!\n");
      exit(0);

    default:
      system("cls");
      printf("Op��o invalida!\n");
      sleep(2);
      system("cls");
    }
  }

  return 0;
}

void login()
{
  int a = 0, i = 0;
  char nomeUsuario[10], c = ' ';
  char senha[10], codigo[10];
  char usuario[10] = "admin";
  char senhaCorreta[10] = "admin";

  // inicia uma contagem de tentativas de login (variavel 'a') e um contador (variavel 'i').
  // Tambem declara variaveis para armazenar o nome de usuario, senha e valores corretos para compara��es.

  do
  {
    strcpy(nomeUsuario, "");
    strcpy(senha, "");
    a = 0;

    printf(".##.....##..#######..########.########.##..........###....########..####....###............######...#######..##.....##\n");
    printf(".##.....##.##.....##....##....##.......##.........##.##...##.....##..##....##.##..........##....##.##.....##.###...###\n");
    printf(".##.....##.##.....##....##....##.......##........##...##..##.....##..##...##...##.........##.......##.....##.####.####\n");
    printf(".#########.##.....##....##....######...##.......##.....##.########...##..##.....##........##.......##.....##.##.###.##\n");
    printf(".##.....##.##.....##....##....##.......##.......#########.##...##....##..#########........##.......##.....##.##.....##\n");
    printf(".##.....##.##.....##....##....##.......##.......##.....##.##....##...##..##.....##....###.##....##.##.....##.##.....##\n");
    printf(".##.....##..#######.....##....########.########.##.....##.##.....##.####.##.....##....###..######...#######..##.....##\n");

    printf("\n*********  FORMULARIO DE LOGIN  *********  \n");
    printf(" \n      INSIRA O NOME DE USUARIO:-");
    fflush(stdin);
    scanf("%s", &nomeUsuario);
    fflush(stdin);
    printf(" \n      INSIRA A SENHA: ");
    do
    {
      c = getch();
      if (isprint(c))
      {
        senha[a] = c;
        a++;
        printf("*");
      }
      else if (c == 8 && a)
      {
        senha[a] = '\0';
        a--;
        printf("\b \b");
      }
    } while (c != 13);

    senha[a] = '\0';
    if (strcmp(nomeUsuario, usuario) == 0 && strcmp(senha, senhaCorreta) == 0)
    {
      printf("  \n\n\n       BEM-VINDO !!!! LOGIN REALIZADO COM SUCESSO\n");
      system("PAUSE");
      system("cls");
      break;
    }
    else
    {
      printf("\n        DESCULPE !!!! O LOGIN N�O FOI BEM-SUCEDIDO!\n");
      i++;

      getchar();
      system("cls");
    }
  } while (i <= 3);
  if (i > 2)
  {
    printf("\nDesculpe, voc� inseriu o nome de usuario e senha incorretamente quatro vezes!!!\n");

    system("PAUSE");
    exit(0);
  }
}
