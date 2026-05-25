#include <stdio.h>
#include <string.h>
#include <unistd.h>
char ID[50];
char nome[50];
int dadosInseridos = 0;
float temperatura = 0;
float energia = 0;
int comunicacao;

void login(){
    int confirm_id;
    printf("\nBem vindo\n");
    printf("Por favor digite o seu nome: ");
    fgets(nome, sizeof(nome), stdin);
    nome[strlen(nome) - 1] = '\0';
    printf("\n");
    printf("Digite o seu ID de tripulante da nave (digite um ID alfanumerico ex: 1A35V54S para simular um ID): ");
    fgets(ID,sizeof(ID), stdin);
    ID[strlen(ID) - 1] = '\0';
    printf("\n");
    printf("Bem vindo %s ID: %s\n", nome, ID);
}

int main(){
    login();
    printf("\n");
    printf("Para continuar preciso que você insira alguns dados\n");
    int opcao;
    do{
    printf("\nopcoes\n");
    printf("1 - inserir dados\n");
    printf("2 - vizualisar status\n");
    printf("3 - executar analise\n");
    printf("4 - encerrar sistema\n");
    printf("Selecione uma das opcoes acima: ");
    scanf("%d", &opcao);
    switch(opcao){
        case 1:
            printf("Insira os seguintes dados:\n");
            printf("Temperatura da capsula em ºC: ");
            scanf("%f", &temperatura);
            printf("\n");
            printf("Porcentagem de energia da capsula: ");
            scanf("%f", &energia);
            do{
            printf("Confirme se ha comunicacao com Huston (1 para sim | 0 para nao): ");
            scanf("%d", &comunicacao);
            printf("\n");
            if (comunicacao > 2 || comunicacao < 0){printf("Confirmacao invalida... tente novamente\n");}
            comunicacao = 2;
            }while(comunicacao >= 2);
        dadosInseridos = 1;
        break;
        case 2:
            if (!dadosInseridos){
                printf("Dados ainda nao foram inseridos...\n");
                printf("Insira os dados para prosseguir\n");
                break;
            }
            printf("\nStatus\n");
            printf("Temperatura: %fºC\n", temperatura);
            printf("Energia da capsula: %f", energia);  
            if(comunicacao == 1){printf("Comunicacao: OK\n");}
            else{printf("Comunicacao: desconectada\n");}
            break;
        
        case 3:
            printf("\nAnalise\n");
            if(temperatura > 80 && energia < 20 && comunicacao == 0){
                printf("\nALERTA\n");
                printf("SUPERAQUECIMENTO DETECTADO!\n");
                printf("Temperatura da capsula: %fºC\n", temperatura);
                printf("BAIXA ENERGIA\n");
                printf("Energia da capsula: %f\n", energia);
                printf("SEM COMUNICACAO COM HUSTON\n");
            }
    }

    }while(opcao == 5);
    return 0;
}