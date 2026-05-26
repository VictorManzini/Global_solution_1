#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#define RED "\033[1;31m"
#define GREEN "\033[1;32m"
#define YELLOW "\033[1;33m"
#define BLUE "\033[1;34m"
#define RESET "\033[0m"

char ID[50];
char nome[50];
int dadosInseridos = 0;
float temperatura = 0;
float energia = 0;
int comunicacao;
int opcao;

void login(){
    int confirm_id;
    printf("\nBem vindo\n");
    printf("Por favor digite o seu nome: ");
    fgets(nome, sizeof(nome), stdin);
    nome[strlen(nome) - 1] = '\0';
    printf("\n");
    printf("Digite o seu ID de tripulante da nave (digite um ID alfanumerico ex: 1A34V54S para simular um ID): ");
    fgets(ID,sizeof(ID), stdin);
    ID[strlen(ID) - 1] = '\0';
    printf("\n");
    printf("Bem vindo tripulante "GREEN"%s " RESET"ID: " GREEN"%s\n"RESET, nome, ID);
}

void Status(float temperature, float energy, int comunication){
    if (!dadosInseridos){
        printf(RED"Dados ainda nao foram inseridos...\n"RESET);
        printf("Insira os dados para prosseguir\n");
    }
    else{
    sleep(1);
    printf("\nStatus\n");
    if(temperature >= 80){
        printf("Temperatura da capsula: "RED"%.1f"RESET"ºC\n", temperature);
    }
    else if(temperature < 80 && temperature >= 71){
        printf("Temperatura da capsula: "YELLOW"%.1f"RESET"ºC\n", temperature);
    }
    else{
    printf("Temperatura: %.1fºC\n", temperature);}
    if(energy <= 20){
        printf("Energia da capsula: "RED"%.1f\n"RESET, energy);
    }
    else if(energy > 20 && energy < 30){
        printf("Energia da capsula: "YELLOW"%.1f\n", energy);
    }
    else{
    printf("Energia da capsula: %.1f\n", energy);}
    if(comunication == 1){printf("Comunicacao: "GREEN"OK\n"RESET);}
    else{printf("Comunicacao: "RED"desconectada\n"RESET);}
    }
    sleep(1);

}

void Temperatura(float temperature){
    if(temperature > 80){
        printf(RED"SUPERAQUECIMENTO DETECTADO!\n"RESET);
        printf("Temperatura da capsula: "YELLOW"%.1f"RESET"ºC\n", temperature);
    }
    else if(temperature < 80 && temperature >= 71){
        printf(YELLOW"TEMPERATURA QUASE EM NIVEL DE SUPERAQUECIMENTO\n"RESET);
        printf("Temperatura da capsula: "YELLOW"%.1f"RESET"ºC\n", temperature);
    }
    else{
        printf(GREEN"TEMPERATURA NORMAL\n"RESET);
        printf("Temperatura da capsula: "GREEN"%.1f"RESET"ºC\n", temperature);
    }
}

void Energia(float energy){
    if(energy < 20){
        printf(RED"BAIXA ENERGIA DETECTADA\n"RESET);
        printf("Energia da capsula: "YELLOW"%.1f\n"RESET, energy);
    }
    else if(energy > 20 && energy <= 30){
        printf(YELLOW"ENERGIA PERTO DA RESERVA\n"RESET);
        printf("Energia da capsula: "YELLOW"%.1f\n"RESET, energy);
    }
    else{
        printf("ENERGIA OK\n");
        printf("Energia da capsula: "GREEN"%.1f\n"RESET, energy);
    }
}

void Comunicacao(int comunication){
    if(comunication == 0){
        printf(RED"FALHA NA COMUNICACAO COM HOUSTON\n"RESET);
    }
    else{printf("Comunicacao com Houston "GREEN"confirmada\n"RESET);}
}

int main(){
    system("clear");
    login();
    printf("\n");

    do{
    printf(BLUE"\nopcoes\n");
    printf("1 - inserir dados\n");
    printf("2 - vizualisar status\n");
    printf("3 - executar analise\n");
    printf("4 - encerrar sistema\n"RESET);
    printf("\n");
    printf("Selecione uma das opcoes acima: ");
    scanf("%d", &opcao);
    while(getchar() != '\n');
    switch(opcao){
        case 1:
            printf("Insira os seguintes dados:\n");
            printf("\nTemperatura da capsula em ºC: ");
            scanf("%f", &temperatura);
            while(getchar() != '\n');
            printf("\n");
            if(temperatura > 80){
                printf(RED"ALETA DE SUPERAQUECIMENTO!\n"RESET);
                printf("Temperatura em: "RED"%.1f"RESET"ºC\n", temperatura);
            }
            else if(temperatura < 80 && temperatura >= 71){
                printf(YELLOW"ATENCAO!"RESET" TEMPERATURA ACIMA DO ESPERADO\n");
                printf("Temperatura em: "YELLOW"%.1f"RESET"ºC\n", temperatura);
            }
            printf("\n");
            printf("Porcentagem de energia da capsula: ");
            scanf("%f", &energia);
            while(getchar() != '\n');
            printf("\n");
            if(energia <= 20){
                printf(RED"ALERTA! BAIXA ENERGIA\n"RESET);
                printf("Energia em: "RED"%.1f\n"RESET, energia);
            }
            else if(energia > 20 && energia <= 30){
                printf(YELLOW"ATENCAO!"RESET"ENERGIA PERTO DA RESERVA\n");
                printf("Energia em: "YELLOW"%.1f\n"RESET, energia);
            }
            do{
            printf("Confirme se ha comunicacao com Houston (1 para sim | 0 para nao): ");
            scanf("%d", &comunicacao);
            while(getchar() != '\n');
            printf("\n");
            if (comunicacao > 2 || comunicacao < 0){
                printf("Confirmacao invalida... tente novamente\n");
                comunicacao = 2;
            }
            else if(comunicacao == 0){
                printf(RED"ALERTA! SEM COMUNICACAO COM HOUSTON\n"RESET);
            }
            }while(comunicacao >= 2);
        dadosInseridos = 1;
        sleep(1);
        break;

        case 2:
            Status(temperatura, energia, comunicacao);
            break;
        
        case 3:
            printf("\nAnalise\n");
            printf("\n");
            if(!dadosInseridos){
                printf(RED"Dados ainda nao foram inseridos...\n"RESET);
                printf(RED"Insira os dados para prosseguir\n"RESET);
                break;
            }
            if(temperatura > 80 && energia < 20 && comunicacao == 0){
                Temperatura(temperatura);
                Energia(energia);
                Comunicacao(comunicacao);
            }
            else if(temperatura <= 80 && energia < 20 && comunicacao == 0){
                Energia(energia);
                Comunicacao(comunicacao);
                Temperatura(temperatura);
            }
            else if(temperatura <= 80 && energia > 20 && comunicacao == 0){
                Comunicacao(comunicacao);
                Temperatura(temperatura);
                Energia(energia);
            }
            else{
                Temperatura(temperatura);
                Energia(energia);
                Comunicacao(comunicacao);
            }
            sleep(2);
            break;

        case 4:
        printf("Encerrando programa...\n");
        sleep(1);
        return 0;

        default:
        printf("Opcao invalida... tente novamente\n");
    }

    }while(opcao != 4);
    return 0;
}