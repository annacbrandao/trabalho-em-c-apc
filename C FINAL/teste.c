#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

//int main(){

/*char cpf[15];
char n_cpf;
char CADASTRO;

n_cpf = 0;

printf("----------- Registro de pessoas com beneficio social -----------\n");
    printf("Insira o CPF a ser cadastrado e lembre-se de usar o padrao XXX.XXX.XXX-XX: \n");
    scanf(" %s", &n_cpf);


    validador_cpf = verificarCPF(CADASTRO.cpf);
    if (validador_cpf == 0)
    {
    printf("CPF INVALIDO \n");
    }
    else
    {
    printf("CPF VALIDO \n");
    }
}

int verificarCPF(char x[]){
    int num, cont, resultado, soma = 0;
    char digito12, digito13;

    // VERIFICA ESTRUTURA
    if(!(x[0] >= '0' && x[0] <= '9' && x[1] >= '0' && x[1] <= '9' && x[2] >= '0' && x[2] <= '9' && x[3] =='.' && x[4] >= '0' && x[4] <= '9' && x[5] >= '0' && x[5] <= '9' && x[6] >= '0' && x[6] <= '9' && x[7] == '.' && x[8] >= '0' && x[8] <= '9' && x[9] >= '0' && x[9] <= '9' && x[10] >= '0' && x[10] <= '9' && x[11] == '-' && x[12] >= '0' && x[12]<= '9' && x[13] >= '0' && x[13] <= '9' && strlen(x) == 14)){
        return 0; 
    }
    //TIRA NUMEROS IGUAIS
    else if(x[0] == x[1] && x[1] == x[2] && x[2] == x[4] && x[4] == x[5] && x[5] == x[6] && x[6] == x[8] && x[8] == x[9] && x[9] == x[12] && x[12] == x[13] && x[13] == x[0]){ 
        return 0;
    }
    else{
        //PRIMEIRA VALIDACAO
        for(cont = 0; cont <= 2; cont++){ 
            num = x[cont] - 48;
            soma = soma + (num * (10 - cont));
        }
        for(cont = 4; cont <= 6; cont++){
            num = x[cont] - 48;
            soma = soma + (num * (11 - cont));
        }
        for(cont = 8; cont <= 10; cont++){
            num = x[cont] - 48;
            soma = soma + (num * (12 - cont));
        }
        resultado = 11 - (soma % 11);
        if ((resultado == 10) || (resultado == 11))
        {
            digito12 = '0';
        }
        else
        {
            digito12 = resultado + 48;
        }

        // SEGUNDA VALIDACAO
        soma = 0;
        resultado = 0;

        for(cont = 0; cont <= 2; cont++){ 
            num = x[cont] - 48;
            soma = soma + (num * (11 - cont));
        }
        for(cont = 4; cont <= 6; cont ++){
            num = x[cont] - 48;
            soma = soma + (num * (12 - cont));
        }
        for(cont = 8; cont <= 10; cont++){
            num = x[cont] - 48;
            soma = soma + (num * (13 - cont));
        }
        num = x[12] - 48;
        soma = soma + (num * 2);
        resultado = 11 - (soma % 11);
        if ((resultado == 10) || (resultado == 11))
        {
            digito13 = '0';
        }
        else
        {
            digito13 = resultado + 48;
        }

        // RETORNA VALIDO = 1 OU NAO VALIDO == 0
        if ((digito12 == x[12] && digito13 == x[13])) 
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }*/

#define TAM_MAX_CPF 15
#define TAM_MAX_NOME 100
//#define TAM_MAX_NASCIMENTO 10
#define TAM_MAX_CIDADE 100
#define TAM_MAX_ESTADO 2
//#define NULL 0
//#define EOF
#define SIZE 101
/*
    struct CADASTRO
{
    char cpf[TAM_MAX_CPF];
    char nome[TAM_MAX_NOME];
    char sexo;
    int dia;
    int mes;
    int ano;
    //char cidade[TAM_MAX_CIDADE];
    //char estado[TAM_MAX_ESTADO];
};*/

/*
    int arq_cpf(char cpf[TAM_MAX_CPF])
{
    FILE *dados;
    struct CADASTRO person;
    struct CADASTRO pessoa;

    dados = fopen("cadastro.txt", "a");

    if(dados != NULL)
    {
        while(!feof(dados))
        {
            fscanf(dados, "%[^\n]\n", &pessoa.cpf);
            fscanf(dados, "%[^\n]\n", &pessoa.nome);
            fscanf(dados, "%c\n", &pessoa.sexo);
            fscanf(dados, "%d\n", &pessoa.dia);
            fscanf(dados, "%d\n", &pessoa.mes);
            fscanf(dados, "%d\n", &pessoa.ano);
            fscanf(dados, "%[^\n]\n", &pessoa.cidade);
            fscanf(dados, "%[^\n]\n", &pessoa.estado);

            if (strcmp(cpf, pessoa.cpf) == 0)
            {
                return 0;
            }
            else
            {
                return 1;
            }
            
        }
        fclose(dados);
    }
}
    FILE *dados;
    struct CADASTRO person;

    if (arq_cpf(person.cpf) == 1)
        {
            dados = fopen("cadastro.txt", "a");
            if (dados != NULL)
            {
                fprintf(dados, "%s\n", person.cpf);
                fprintf(dados, "%s\n", person.nome);
                fprintf(dados, "%c\n", person.sexo);
                fprintf(dados, "%d\n", person.dia);
                fprintf(dados, "%d\n", person.mes);
                fprintf(dados, "%d\n", person.ano);
                fprintf(dados, "%s\n", person.cidade);
                fprintf(dados, "%s\n", person.estado);

                printf("Usuario cadastrado.\n");

                fclose(dados);
            }
            else
            {
                printf("Nao foi possivel cadastrar usuario. CPF ja esta em uso.");
            }
        }
}*/
struct CADASTRO
{
    char nome[TAM_MAX_NOME];
    char cpf[TAM_MAX_CPF];
};

struct NASCIMENTO
{
    int dia;
    int mes;
    int ano;
};

int main()
{
void consultarPessoa()
{
    int cpfPesquisa;
    int i;
    struct CADASTRO usuario;
    struct NASCIMENTO data;


    printf("Digite o CPF do usuario a ser consultado: ");
    scanf("%d", &cpfPesquisa);
    for(i = 0; i < SIZE; i++){
        if(cpf[i] == cpfPesquisa)
        {
            printf("\nCPF: %s\nNome: %s\nSexo: %s\nData de nascimento: %s");
        }
    }
}
}
/*int validar_cidade(char cidade[], char estado[])
{
    FILE *arquivo;
    struct CIDADE city;
    int examinar = 0;

    arquivo = fopen("cidades.txt", "r");
    if(arquivo != NULL)
    {
       while(!feof(arquivo))
       {
        fscanf(arquivo, "%d\n", &city.codigo);
        fscanf(arquivo, "%[^\n]\n", city.estado);
        fscanf(arquivo, "%[^\n]\n", city.cidade_sem_acento);
        fscanf(arquivo, "%[^\n]\n", city.estado);

        if ((strcmp(cidade_sem_acento, city.cidade_sem_acento) == 0) && (strcmp(estado, city.estado) == 0))
        {
            examinar = 1;
            return 1;
            break;
        }
        else
        {
            examinar = 0;
        }
       } 
       fclose(arquivo);
    }
    
}*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <locale.h>
#include "biblioteca.h"

// struct = junta várias variáveis pra trasnformar em uma única
typedef struct // typedef pq não precisa declarar struct dps, apenas chamar o nome da struct diretamente
{
    char cpf[TAM_MAX_CPF];
    char nome[TAM_MAX_NOME];
    char sexo;
    int dia;
    int mes;
    int ano;
} CADASTRO;

typedef struct
{
    int codigo;
    char cidade_sem_acento[TAM_MAX_CIDADE];
    char estado[TAM_MAX_ESTADO];  
} CIDADE;


// Declarção das funções usadas
void cadastrarPessoa();
void consultarPessoa();
void listarPessoas();

int main()
{

    int opcao = 100;
    char cpf[TAM_MAX_CPF];

    do
    {
        printf("                 Sistema de Gestao de Beneficio Social          \n");
        printf("    ___________________________________________________________ \n");
        printf("   |                                                           |\n");
        printf("   |                            MENU                           |\n");
        printf("   |                                                           |\n");
        printf("   |                    1) Cadastrar pessoa                    |\n");
        printf("   |                   2) Consultar pessoa                     |\n");
        printf("   |                  3) Listar todas as pessoas               |\n");
        printf("   |                    4) Gerar relatorio                     |\n");
        printf("   |                     5) Excluir Pessoa                     |\n");
        printf("   |                    6) Encerrar Programa                   |\n");
        printf("   |___________________________________________________________|\n\n");
        printf("   >>> Insira a opcao: ");

        scanf("%d", &opcao);
        limpar_tela();
        switch (opcao)
        {
        case 1:
            cadastrarPessoa();
            break;
        case 2:
            consultarPessoa();
            break;
        case 3:
            {
                char cidade[TAM_MAX_CIDADE]; //<<< var para leitura de cidade
                limpar_tela();
                printf(">>> Informe a cidade a ser procurada: ");
                limpar_buffer();
                scanf("%[^\n]s", cidade);
                listarPessoas(cidade);

                break;
            }
        case 4:
            // gerarRelatorio();
            break;
        case 5:
            // pesquisarAssociados();
            break;
        case 6:
            // encerrarPrograma();
            system("exit");
            printf("Programa encerrado.\n\n");
            break;
        default:
            printf("Opcao invalida. Tente novamente.\n");
            break;
        }
        return 0;
    } while (opcao != 6);
}
// Função para cadastrar pessoa
void cadastrarPessoa()
{
    FILE *arquivo;
    FILE *dados;
    int validador_cpf;
    int validador_sexo;
    int validador_data;
    int validador_cidade;
    CADASTRO pessoa;
    CIDADE city;


    limpar_tela();

    printf(">>> Insira o CPF a ser cadastrado, respeitando o padrao XXX.XXX.XXX-XX: ");
    limpar_buffer();
    scanf(" %s", &pessoa.cpf);
    limpar_tela();

    validador_cpf = verificarCPF(pessoa.cpf);
    if (validador_cpf == 0)
    {
        printf("CPF invalido!\n\n");
    }
    else
    {
    printf(">>> Digite o nome da pessoa a ser cadastrada: ");
    limpar_buffer();
    scanf("%[^\n]s", pessoa.nome);
    limpar_tela();

    if (strlen(pessoa.nome) <= 3)
    {
        printf("Nome invalido!\n\n");
    }
    else
    {

    printf(">>> Informe o sexo da pessoa a ser cadastrada (M/m ou F/f): ");
    limpar_buffer();
    scanf("%c", &pessoa.sexo);
    limpar_tela();

    if (validador_sexo = validar_sexo(pessoa.sexo) == 0)
    {
        printf("Sexo incorreto!\n\n");
    }
    else
    {

    printf(">>> Insira o dia do nascimento do usuario a ser cadastrado: ");
    scanf("%d", &pessoa.dia);
    printf(">>> Insira o mes do nascimento do usuario a ser cadastrado: ");
    scanf("%d", &pessoa.mes);
    printf(">>> Insira o ano de nascimento do usuario a ser cadastrado: ");
    scanf("%d", &pessoa.ano);
    limpar_tela();

    if (validador_data = validar_data(pessoa.dia, pessoa.mes, pessoa.ano) == 0) //ou ==1
    {
        printf("Data de nascimento invalida!\n\n");
    }
    else
    {
    FILE *arquivo;

    validador_cidade = validar_cidade(city.cidade_sem_acento, city.estado);

    printf(">>> Informe a cidade do usuario a ser cadastrado: ");
    limpar_buffer();
    scanf("%[^\n]s", city.cidade_sem_acento);
    printf(">>> Informe a UF da cidade: ");
    limpar_buffer();
    scanf("%s", city.estado);
    limpar_tela();

    if (validar_cidade(city.cidade_sem_acento, city.estado) == 1)
    {
        printf("Cidade inexistente.\n");
    }

    else
    {

        if (arq_cpf(pessoa.cpf) == 1)
        {
            dados = fopen("cadastro.txt", "a");
            if (dados != NULL)
            {
                fprintf(dados, "%s\n", &pessoa.cpf);
                fprintf(dados, "%s\n", &pessoa.nome);
                fprintf(dados, "%c\n", &pessoa.sexo);
                fprintf(dados, "%d\n", &pessoa.dia);
                fprintf(dados, "%d\n", &pessoa.mes);
                fprintf(dados, "%d\n", &pessoa.ano);
                fprintf(dados, "%s\n", &city.cidade_sem_acento);
                fprintf(dados, "%s\n", &city.estado);

                printf(">>> Usuario cadastrado.\n");

                fclose(dados);
            }
            else
            {
                printf("Nao foi possivel cadastrar usuario.");
            }
        }
        
    }
        }
    }

}
    }
}

//Função de consulta de usuário com registro no sistema