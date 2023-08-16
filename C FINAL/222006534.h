// Ações disponíveis no menu principal

// Definindo vetores fixos
#ifndef BIBLIOTECA_H
#define BIBLIOTECA_H
#define TAM_MAX_CPF 15
#define TAM_MAX_NOME 100
#define TAM_MAX_NASCIMENTO 10
#define TAM_MAX_CIDADE 100
#define TAM_MAX_ESTADO 3
#define TAM_SEXO 2
#define NULL 0
#define TAM_LINHA 100

// Structs funcionam como um conjunto de variáveis reunidas em uma variável só
struct CADASTRO
{
    char cpf[TAM_MAX_CPF];
    char nome[TAM_MAX_NOME];
    char sexo;
    int dia;
    int mes;
    int ano;
};

struct CIDADE
{
    int codigo;
    char estado[TAM_MAX_ESTADO];
    char cidade_sem_acento[TAM_MAX_CIDADE];
    char cidade_com_acento[TAM_MAX_CIDADE];
};

// Limpa a tela toda vez que acionada
void limpar_tela()
{
#if defined(linux) || defined(unix) || defined(APPLE)
    system("clear");
#endif

#if defined(_WIN32) || defined(_WIN64)
    system("cls");
#endif
}

// Deve ser usada antes de strings e serve para limpar o "lixo" que resta do teclado e mouse
void limpar_buffer()
{
    char ch;
    while ((ch = getchar()) != '\n' && ch != EOF);
}

// Função para validar CPF
int verificarCPF(char x[])
{
    // Variáveis
    int numero, contador, resultado, soma = 0;
    char digito12, digito13;

    // Verifica a estrutura
    if (!(x[0] >= '0' && x[0] <= '9' && x[1] >= '0' && x[1] <= '9' && x[2] >= '0' && x[2] <= '9' && x[3] == '.' && x[4] >= '0' && x[4] <= '9' && x[5] >= '0' && x[5] <= '9' && x[6] >= '0' && x[6] <= '9' && x[7] == '.' && x[8] >= '0' && x[8] <= '9' && x[9] >= '0' && x[9] <= '9' && x[10] >= '0' && x[10] <= '9' && x[11] == '-' && x[12] >= '0' && x[12] <= '9' && x[13] >= '0' && x[13] <= '9' && strlen(x) == 14))
    {
        return 0;
    }
    // Impede que números iguais sejam cadastrados
    else if (x[0] == x[1] && x[1] == x[2] && x[2] == x[4] && x[4] == x[5] && x[5] == x[6] && x[6] == x[8] && x[8] == x[9] && x[9] == x[12] && x[12] == x[13] && x[13] == x[0])
    {
        return 0;
    }
    else
    {
        // Primeira validação
        for (contador = 0; contador <= 2; contador++)
        {
            numero = x[contador] - 48;
            soma = soma + (numero * (10 - contador));
        }
        for (contador = 4; contador <= 6; contador++)
        {
            numero = x[contador] - 48;
            soma = soma + (numero * (11 - contador));
        }
        for (contador = 8; contador <= 10; contador++)
        {
            numero = x[contador] - 48;
            soma = soma + (numero * (12 - contador));
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

        // Segunda validação
        soma = 0;
        resultado = 0;

        for (contador = 0; contador <= 2; contador++)
        {
            numero = x[contador] - 48;
            soma = soma + (numero * (11 - contador));
        }
        for (contador = 4; contador <= 6; contador++)
        {
            numero = x[contador] - 48;
            soma = soma + (numero * (12 - contador));
        }
        for (contador = 8; contador <= 10; contador++)
        {
            numero = x[contador] - 48;
            soma = soma + (numero * (13 - contador));
        }
        numero = x[12] - 48;
        soma = soma + (numero * 2);
        resultado = 11 - (soma % 11);
        if ((resultado == 10) || (resultado == 11))
        {
            digito13 = '0';
        }
        else
        {
            digito13 = resultado + 48;
        }

        // Se o cpf for válido retorna 1, se não for, retorna 0
        if ((digito12 == x[12] && digito13 == x[13]))
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
}

// Função para validar sexo
int validar_sexo(char sexo[TAM_SEXO])
{
    if (sexo == 'm' || sexo == 'f')
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

// Função para validar a data de nascimento do usuário
int validar_data(int dia, int mes, int ano)
{
    struct tm *structempo; // da biblioteca inserida <time.h>
    time_t date;
    time(&date);
    structempo = localtime(&date);
    int nascim = 0;
    int day = structempo->tm_mday;
    int month = structempo->tm_mon + 1;    // + 1 pois começa a contar a partir do número 1
    int year = structempo->tm_year + 1908; // + 1908 pelo mesmo motivo citado acima

    // Valida se o dia, mês e ano são coerentes com a realidade
    if (!((dia > 0 && dia < 32) || (mes > 0 && mes < 13) || (ano > 1907 && ano <= year)))
    {
        return 0;
    }
    else
    {
        // Serve para verificar se o ano é bissexto
        if (((ano % 4 == 0 && ano % 100 != 0) || ano % 400 == 0) && ano > 0 && dia <= 29 && mes == 2)
        {
            return 1;
        }
        else
        {
            // Valida meses com 31 dias
            if (((mes == 1) || (mes == 3) || (mes == 5) || (mes == 7) || (mes == 8) || (mes == 10) || (mes == 12)) && ((dia <= 31) && (dia >= 1)))
            {
                return 1;
            }
            else
            {
                // Valida meses com 30 dias
                if (((mes == 4) || (mes == 6) || (mes == 9) || (mes == 11)) && ((dia <= 30) && (dia >= 1)))
                {
                    return 1;
                }
                else
                {
                    return 0;
                }
            }
        }
    }
}
//}

// Função para validar a cidade digitada (comparando com as listadas no arquivo)
int validar_cidade(char cidade[], char estado[])
{
    // Variáveis
    FILE *arquivo;
    struct CIDADE cidad;
    int validador = 0;

    // Abre o arquivo para leitura
    arquivo = fopen("cidades.txt", "r");
    if (arquivo != NULL)
    {
        // Lê linha por linha do arquivo aberto
        while (!feof(arquivo))
        {
            fscanf(arquivo, "%d\n", &cidad.codigo);
            fscanf(arquivo, "%[^\n]\n", cidad.estado);
            fscanf(arquivo, "%[^\n]\n", cidad.cidade_com_acento);
            fscanf(arquivo, "%[^\n]\n", cidad.cidade_sem_acento);

            // Se cidade e uf comparadas as listadas no "arquivo" condizerem, a função valida
            if ((strcmp(cidade, cidad.cidade_sem_acento) == 0) && (strcmp(estado, cidad.estado) == 0))
            {
                validador = 1;
                return 1;
                break;
            }
            else
            {
                validador = 0;
            }
        }
        fclose(arquivo);
    }
}

// Função para validar se o cpf já foi registrado
int arq_cpf(char n[])
{
    // Declaração de Variáveis
    FILE *dados;
    struct CADASTRO pessoa;
    struct CIDADE cidade;
    int validar = 0;

    dados = fopen("cadastro.txt", "r");

    if (dados != NULL)
    {
        // Ler os dados do arquivo "dados" para comparação com a entrada digitada
        while (!feof(dados))
        {
            fscanf(dados, "%[^\n]\n", pessoa.cpf);
            fscanf(dados, "%[^\n]\n", pessoa.nome);
            fscanf(dados, "%c\n", &pessoa.sexo);
            fscanf(dados, "%d\n", &pessoa.dia);
            fscanf(dados, "%d\n", &pessoa.mes);
            fscanf(dados, "%d\n", &pessoa.ano);
            fscanf(dados, "%[^\n]\n", cidade.cidade_sem_acento);
            fscanf(dados, "\n%[^\n]", cidade.estado);

            if (strcmp(n, pessoa.cpf) == 0)
            {
                // return 0;
                validar = 0;
                break;
            }
            else
            {
                // return 1;
                validar++;
            }
        }
        if (validar == 0)
        {
            return 0;
        }
        else
        {
            return 1;
        }

        fclose(dados);
    }
}

// Função para cadastrar pessoa
void cadastrarPessoa()
{
    // Variáveis
    FILE *arquivo;
    FILE *dados;
    int validador_sexo;
    int validador_data;
    int validador_cidade;
    struct CADASTRO pessoa;
    struct CIDADE city;

    limpar_tela();
    printf("    ___________________________________________________________________ \n");
    printf("   |                                                                   |\n");
    printf("   |                             CADASTRO                              |\n");
    printf("   |___________________________________________________________________|\n\n");
    printf(">>> Insira o CPF a ser cadastrado, respeitando o padrao XXX.XXX.XXX-XX: ");
    limpar_buffer();
    scanf("%s", &pessoa.cpf);
    limpar_tela();

    if (verificarCPF(pessoa.cpf) == 0)
    {
        printf("CPF invalido!\n\n");
    }
    else
    {
        printf("    ___________________________________________________________________ \n");
        printf("   |                                                                   |\n");
        printf("   |                             CADASTRO                              |\n");
        printf("   |___________________________________________________________________|\n\n");
        printf(">>> Digite o nome da pessoa a ser cadastrada (sem acentos): ");
        limpar_buffer();
        scanf("%[^\n]s", pessoa.nome);
        limpar_tela();

        // strlen calcula o tamanho da string
        if (strlen(pessoa.nome) < 2)
        {
            printf("Nome invalido!\n\n");
        }
        else
        {
            printf("    ___________________________________________________________________ \n");
            printf("   |                                                                   |\n");
            printf("   |                             CADASTRO                              |\n");
            printf("   |___________________________________________________________________|\n\n");
            printf(">>> Informe o sexo da pessoa a ser cadastrada (m para masculino ou f para feminino): ");
            limpar_buffer();
            scanf("%c", &pessoa.sexo);
            limpar_tela();

            if (validar_sexo(pessoa.sexo) == 0)
            {
                printf("Sexo invalido!\n\n");
            }
            else
            {
                printf("    ___________________________________________________________________ \n");
                printf("   |                                                                   |\n");
                printf("   |                             CADASTRO                              |\n");
                printf("   |___________________________________________________________________|\n\n");
                printf(">>> Insira o dia do nascimento do usuario a ser cadastrado: ");
                scanf("%d", &pessoa.dia);
                printf(">>> Insira o mes do nascimento do usuario a ser cadastrado: ");
                scanf("%d", &pessoa.mes);
                printf(">>> Insira o ano de nascimento do usuario a ser cadastrado: ");
                scanf("%d", &pessoa.ano);
                limpar_tela();

                if (validador_data = validar_data(pessoa.dia, pessoa.mes, pessoa.ano) == 0)
                {
                    printf("Data de nascimento invalida!\n\n");
                }
                else
                {
                    printf("    ___________________________________________________________________ \n");
                    printf("   |                                                                   |\n");
                    printf("   |                             CADASTRO                              |\n");
                    printf("   |___________________________________________________________________|\n\n");
                    printf(">>> Informe a cidade do usuario a ser cadastrado (sem acentos e com a primeira letra maiuscula): ");
                    limpar_buffer();
                    scanf("%[^\n]s", city.cidade_sem_acento);
                    printf(">>> Informe a UF da cidade (tudo maiusculo): ");
                    limpar_buffer();
                    scanf("%[^\n]s", city.estado);
                    limpar_tela();

                    if (validar_cidade(city.cidade_sem_acento, city.estado) == 0)
                    {
                        printf("Cidade e/ou UF inexistentes.\n");
                    }

                    else
                    {
                        if (arq_cpf(pessoa.cpf) == 1)
                        {
                            // Abre o arquivo e o "a" tem função de acrescentar dados a esse arquvo criado
                            dados = fopen("cadastro.txt", "a");
                            limpar_buffer();
                            if (dados != NULL)
                            {
                                // fprintf printa no arquivo
                                fprintf(dados, "%s\n", pessoa.cpf);
                                fprintf(dados, "%s\n", pessoa.nome);
                                fprintf(dados, "%c\n", pessoa.sexo);
                                fprintf(dados, "%.02d\n", pessoa.dia);
                                fprintf(dados, "%.02d\n", pessoa.mes);
                                fprintf(dados, "%.04d\n", pessoa.ano);
                                fprintf(dados, "%s\n", city.cidade_sem_acento);
                                fprintf(dados, "%s\n", city.estado);

                                printf(">>> Usuario cadastrado <<<\n");

                                // Fecha os dados
                                fclose(dados);
                            }
                            else
                            {
                                printf("Nao foi possivel cadastrar usuario. Tente novamente.");
                            }
                        }
                    }
                }
            }
        }
    }
}

// Função de consulta de usuário com registro no sistema
void consultarPessoa()
{
    // Variáveis
    FILE *consulta;
    struct CADASTRO ler_usuario;
    struct CIDADE city_consultada;
    int encontrado;
    char cpf_digitado[15];
    encontrado = 0;

    limpar_tela();
    printf("    ___________________________________________________________________ \n");
    printf("   |                                                                   |\n");
    printf("   |                             CONSULTA                              |\n");
    printf("   |___________________________________________________________________|\n\n");
    printf(">>> Informe o CPF da pessoa a ser consultada: ");
    limpar_buffer();
    scanf("%[^\n]", cpf_digitado); // Lê o cpf digitado

    consulta = fopen("cadastro.txt", "r"); // Abre o arquivo para procurar
    if (consulta != NULL)                  // Se o arquivo for encontrado acontece o while
    {
        while (!feof(consulta)) // "!feof" lê linha por linha do arquivo "consulta" que está sendo aberto
        {
            fscanf(consulta, "%[^\n]\n", ler_usuario.cpf);
            fscanf(consulta, "%[^\n]\n", ler_usuario.nome);
            fscanf(consulta, "%c\n", &ler_usuario.sexo);
            fscanf(consulta, "%d\n", &ler_usuario.dia);
            fscanf(consulta, "%d\n", &ler_usuario.mes);
            fscanf(consulta, "%d\n", &ler_usuario.ano);
            fscanf(consulta, "%[^\n]\n", city_consultada.cidade_sem_acento);
            fscanf(consulta, "%[^\n]\n", city_consultada.estado);

            // Se o cpf que foi digitado for igual ao cpf guardado no arquivo (== 0), vai printar os dados do usuário consultado
            if (strcmp(cpf_digitado, ler_usuario.cpf) == 0)
            {
                encontrado = 1;
                printf("\n> CPF: %s\n", ler_usuario.cpf);
                printf("> Nome: %s\n", ler_usuario.nome);
                printf("> Sexo: %c\n", ler_usuario.sexo);
                printf("> Data de nascimento: %d/%d/%d\n", ler_usuario.dia, ler_usuario.mes, ler_usuario.ano);
                printf("> Cidade e UF: %s - %s\n\n", city_consultada.cidade_sem_acento, city_consultada.estado);
                break;
            }
        }
        if (!encontrado) // Se nada for encontrado, o sistema vai avisar que o usuário não foi localizado
        {
            printf("Usuario nao localizado!\n");
        }
        fclose(consulta); // Fecha o arquivo que foi aberto
    }
}

// Função para listar pessoas em ordem alfabética por cidade
void listarPessoas()
{
    // Variáveis
    FILE *consulta;
    struct CIDADE city_consultada;
    struct CADASTRO user_inf;
    char nomes[100][100], aux[100];
    char cidade[TAM_MAX_CIDADE];
    char estado[TAM_MAX_ESTADO];
    int nomes_found, i, j, x;
    nomes_found = 0;

    // Para ler a cidade digitada
    limpar_tela();
    printf("    ___________________________________________________________________ \n");
    printf("   |                                                                   |\n");
    printf("   |                    LISTA DE PESSOAS POR CIDADE                    |\n");
    printf("   |___________________________________________________________________|\n\n");
    printf(">>> Informe a cidade a ser procurada (sem acentos): ");
    limpar_buffer();
    scanf("%s", cidade);

    // Para ler a uf da cidade digitada
    printf(">>> Informe a UF da cidade a ser procurada: ");
    scanf("%s", estado);

    // Para abrir o arquivo com os dados registrados dos usuários
    consulta = fopen("cadastro.txt", "r");
    if (consulta != NULL)
    {
        // Lendo linha por linha para verificação
        while (!feof(consulta))
        {
            fscanf(consulta, "%[^\n]\n", user_inf.cpf);
            fscanf(consulta, "%[^\n]\n", user_inf.nome);
            fscanf(consulta, "%c\n", &user_inf.sexo);
            fscanf(consulta, "%d\n", &user_inf.dia);
            fscanf(consulta, "%d\n", &user_inf.mes);
            fscanf(consulta, "%d\n", &user_inf.ano);
            fscanf(consulta, "%[^\n]\n", city_consultada.cidade_sem_acento);
            fscanf(consulta, "%[^\n]\n", city_consultada.estado);

            // Compara se a cidade e uf são válidos em relação as listadas no arquivo
            if ((strcmp(cidade, city_consultada.cidade_sem_acento) == 0) && (strcmp(estado, city_consultada.estado) == 0))
            {
                printf("\n- %s", user_inf.nome);
                nomes_found++;
            }
            else
            {
                printf(">>> Cidade e/ou UF invalidos. Tente novamente.");
                break;
            }
        }

        for (i = 0; i <= nomes_found; i++)
        {
            for (j = i + 1; j <= nomes_found; j++)
            {
                x = strcmp(nomes[i], nomes[j]);
                if (x > 0)
                {
                    strcpy(aux, nomes[i]);
                    strcpy(nomes[i], nomes[j]);
                    strcpy(nomes[j], aux);
                }
            }
        }
        for (i = 0; i <= nomes_found; i++)
        {
            printf("%s\n", nomes[i]);
        }
    }
    fclose(consulta);
}

// Função para gerar um relatório relacionado ao percentual de pessoas por faixa etária e um percentual de pessoas por sexo
void gerarRelatorio()
{
    // Variáveis
    FILE *relatorio;
    struct CADASTRO usuario;
    struct CIDADE ciudad;
    float homem = 0;
    float mulher = 0;
    float idade = 0;
    float idade0 = 0;
    float idade16 = 0;
    float idade30 = 0;
    float idade50 = 0;
    float idade60 = 0;
    float media0 = 0;
    float media16 = 0;
    float media30 = 0;
    float media50 = 0;
    float media60 = 0;
    float media_h = 0;
    float media_m = 0;
    float people = 0;

    limpar_tela();
    printf("    ___________________________________________________________________ \n");
    printf("   |                                                                   |\n");
    printf("   |                              RELATORIO                            |\n");
    printf("   |___________________________________________________________________|\n\n");

    relatorio = fopen("cadastro.txt", "r");
    if (relatorio != NULL)
    {
        while (!feof(relatorio)) // "!feof" lê linha por linha do arquivo "relatorio" que está sendo aberto
        {
            fscanf(relatorio, "%[^\n]\n", usuario.cpf);
            fscanf(relatorio, "%[^\n]\n", usuario.nome);
            fscanf(relatorio, "%c\n", &usuario.sexo);
            fscanf(relatorio, "%d\n", &usuario.dia);
            fscanf(relatorio, "%d\n", &usuario.mes);
            fscanf(relatorio, "%d\n", &usuario.ano);
            fscanf(relatorio, "%[^\n]\n", ciudad.cidade_sem_acento);
            fscanf(relatorio, "%[^\n]\n", ciudad.estado);

            people++;

            if (usuario.sexo == 'm')
            {
                homem++;
            }
            else
            {
                mulher++;
            }

            idade = 2022 - usuario.ano;

            if (idade >= 0 && idade <= 15)
            {
                idade0++;
            }
            else
            {
                if (idade >= 16 && idade <= 29)
                {
                    idade16++;
                }
                else
                {
                    if (idade >= 30 && idade <= 49)
                    {
                        idade30++;
                    }
                    else
                    {
                        if (idade >= 50 && idade <= 60)
                        {
                            idade50++;
                        }
                        else
                        {
                            if (idade > 60)
                            {
                                idade60++;
                            }
                        }
                    }
                }
            }
        }

        // Calcula a média das idades e a média da quantidade de homens e mulheres
        media0 = ((idade0 / people) * 100);
        media16 = ((idade16 / people) * 100);
        media30 = ((idade30 / people) * 100);
        media50 = ((idade50 / people) * 100);
        media60 = ((idade60 / people) * 100);

        media_m = ((mulher / people) * 100);
        media_h = ((homem / people) * 100);

        limpar_tela();
        printf("    ___________________________________________________________________ \n");
        printf("   |                                                                   |\n");
        printf("   |                              RELATORIO                            |\n");
        printf("   |___________________________________________________________________|\n\n");
        printf(">>> Percentual de pessoas por faixa etaria: \n");
        printf("0 a 15 anos: %0.2f %% \n", media0);
        printf("16 a 29 anos: %0.2f %% \n", media16);
        printf("30 a 49 anos: %0.2f %% \n", media30);
        printf("50 a 60 anos: %0.2f %% \n", media50);
        printf("Acima de 60 anos: %0.2f %% \n\n", media60);

        printf(">>> Percentual de pessoas por sexo: \n");
        printf("Masculino: %0.2f %%\n", media_h);
        printf("Feminino: %0.2f %%\n", media_m);
    }
    fclose(relatorio);
}

// Função para excluir o cadastro de um usuário
void excluirPessoa()
{
    // Variáveis
    FILE *excluir1;
    FILE *excluir2;
    struct CADASTRO exc, arq;
    struct CIDADE cidade_arq;
    int confirmacao;

    limpar_tela();
    printf("    ___________________________________________________________________ \n");
    printf("   |                                                                   |\n");
    printf("   |                         EXCLUSAO DE CADASTRO                      |\n");
    printf("   |___________________________________________________________________|\n\n");
    printf(">>> Insira o CPF do usuario a ser excluido: ");
    limpar_buffer();
    scanf("%[^\n]s", exc.cpf);

    // Abre o arquivo que guarda os cadastros e abre um arquivo "temporário"
    excluir1 = fopen("cadastro.txt", "r");
    excluir2 = fopen("exclusao.txt", "w");

    // Lê linha a linha dos dados cadastrais
    while (!feof(excluir1))
    {
        fscanf(excluir1, "%[^\n]\n", arq.cpf);
        fscanf(excluir1, "%[^\n]\n", arq.nome);
        fscanf(excluir1, "%c\n", &arq.sexo);
        fscanf(excluir1, "%d\n", &arq.dia);
        fscanf(excluir1, "%d\n", &arq.mes);
        fscanf(excluir1, "%d\n", &arq.ano);
        fscanf(excluir1, "%[^\n]\n", cidade_arq.cidade_sem_acento);
        fscanf(excluir1, "%[^\n]\n", cidade_arq.estado);
    }

    // Se o cpf digitado for coerente com algum já cadastrado, ele printa os dados do usuário que foi pesquisado
    if (strcmp(exc.cpf, arq.cpf) == 0)
    {
        printf("\n> CPF: %s\n", arq.cpf);
        printf("> Nome: %s\n", arq.nome);
        printf("> Sexo: %c\n", arq.sexo);
        printf("> Data de nascimento: %d/%d/%d\n", arq.dia, arq.mes, arq.ano);
        printf("> Cidade e UF: %s - %s\n\n", cidade_arq.cidade_sem_acento, cidade_arq.estado);
    }
    else
    {
        if (exc.cpf != arq.cpf)
        {
            printf(">>> Usuario nao encontrado! Tente novamente.\n\n");
            return 0;
        }
        else
        {
            return 1;
        }
    }

    printf("Digite '1' para confirmar a exclusao: \n");
    limpar_buffer();
    scanf("%d", &confirmacao);

    // Se a confirmação com o número 1 for digitada, começa o processo de exclusão
    if (confirmacao == 1)
    {
        if (excluir1 != NULL)
        {
            // Rewind faz retornar ao começo do arquivo, para posteriormente os dados serem lidos de novo
            rewind(excluir1);
            while (!feof(excluir1))
            {
                fscanf(excluir1, "%[^\n]\n", arq.cpf);
                fscanf(excluir1, "%[^\n]\n", arq.nome);
                fscanf(excluir1, "%c\n", &arq.sexo);
                fscanf(excluir1, "%d\n", &arq.dia);
                fscanf(excluir1, "%d\n", &arq.mes);
                fscanf(excluir1, "%d\n", &arq.ano);
                fscanf(excluir1, "%[^\n]\n", cidade_arq.cidade_sem_acento);
                fscanf(excluir1, "%[^\n]\n", cidade_arq.estado);

                if (strcmp(exc.cpf, arq.cpf) != 0)
                {
                    fprintf(excluir2, "%s\n", arq.cpf);
                    fprintf(excluir2, "%s\n", arq.nome);
                    fprintf(excluir2, "%c\n", arq.sexo);
                    fprintf(excluir2, "%d\n", arq.dia);
                    fprintf(excluir2, "%d\n", arq.mes);
                    fprintf(excluir2, "%d\n", arq.ano);
                    fprintf(excluir2, "%s\n", cidade_arq.cidade_sem_acento);
                    fprintf(excluir2, "%s\n", cidade_arq.estado);
                }
            }
            fclose(excluir1);
            fclose(excluir2);

            // Remove o arquivo dos dados cadastrais do usuário
            remove("cadastro.txt");

            // Renomeia o arquivo que antes era "temporário" para o dos dados cadastrais
            rename("exclusao.txt", "cadastro.txt");

            limpar_tela();
            printf(">>> Usuario excluido <<< \n");
        }
    }
    else
    {
        printf(">>> Exclusao invalida. \n");
    }
}

#endif