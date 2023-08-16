#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include "222006534.h"

// Instruções
int main()
{
    int opcao = 100;

    // Menu
    do
    {
        printf("                 Sistema de Gestao de Beneficio Social          \n");
        printf("    ___________________________________________________________ \n");
        printf("   |                                                           |\n");
        printf("   |                            MENU                           |\n");
        printf("   |                                                           |\n");
        printf("   |                    1) Cadastrar pessoa                    |\n");
        printf("   |                   2) Consultar pessoa                     |\n");
        printf("   |                3) Listar pessoas por cidade               |\n");
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
            listarPessoas();
            break;
        case 4:
            gerarRelatorio();
            break;
        case 5:
            excluirPessoa();
            break;
        case 6:
            printf(">>> Programa encerrado.");
            exit(0); // Usado pra encerrar o programa
        default:
            printf("Opcao invalida. Tente novamente.\n");
            break;
        }
    } while (opcao != 6); // Enquanto a opção de encerrar programa não for escolhia, os números de 1 a 5, quando inseridos, chamarão uma fução específoca para cada item
}