#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <windows.h>



// registros

typedef struct Contato
{
    char telefone[10];
} Contato;

typedef struct Login
{
    char login[10], senha[10];
} Login;

typedef struct Especialidade
{
    char nome[15], codigo[10];

} Especialidade;

typedef struct Medico
{
    char nome[15], CRM[10], espec[10];
    Especialidade especialidade[10];
    Login login[20];

} Medico;

typedef struct Funcionario
{
    char nome[15], matricula[10];
    Login login[20];

} Funcionario;

typedef struct Paciente
{
    char nome[15], CPF[15];
    Login login[20];
    Contato contato[20];

} Paciente;

//assinaturas funçoes/procedimentos

/*------- TELAS DE MENUS-------*/
void LimparTela();
void TelaMenuFuncionario(Paciente paciente[], int *contadorPaciente);
void TelaMenuAdm(Funcionario funcionario[], int *contadorFuncionario, Especialidade especialidade[], int *contadorEspecialidade,
                 Medico medico[], int *contadorMedico, Paciente paciente[], int *contadorPaciente);
void MenuCadastros(Funcionario funcionarios[], int *contadorFuncionarios, Especialidade especialidade[], int *contadorEspecialidade, Medico medico[],
                   int *contadorMedico, Paciente paciente[], int *contadorPaciente);
void MenuAlteracao(Paciente paciente[], int *contadorPaciente, Funcionario funcionario[], int *contadorFuncionario, Especialidade especialidade[], int *contadorEspecialidade,
                   Medico medico[], int *contadorMedico);
void MenuExclusao(Paciente paciente[], int *contadorPaciente, Funcionario funcionario[], int *contadorFuncionario, Especialidade especialidade[], int *contadorEspecialidade,
                  Medico medico[], int *contadorMedico);
void TelaMenuPesquisaAdm(Funcionario funcionario[], int *contadorFuncionario, Especialidade especialidade[], int *contadorEspecialidade,
                         Medico medico[], int *contadorMedico, Paciente paciente[], int *contadorPaciente);
void TelaMenuPesquisaFuncionario(Paciente paciente[], int *contadorPaciente);

void MenuCadastroFuncionario(Paciente paciente[], int *contadorPaciente);
void MenuExclusaoFuncionario(Paciente paciente[], int *contadorPaciente);
void MenuAlteracaoFuncionario(Paciente paciente[], int *contadorPaciente);

/*------- CADASTRO-------*/

void CadastrarEspecialidade(Especialidade especialidade[], int *contadorEspecialidade);
void CadastrarMedico(Medico medico[], int *contadorMedico, Especialidade especialidade[], int *contadorEspecialidade);
void CadastrarFuncionario(Funcionario funcionario[], int *contadorFuncionario);
void CadastrarPaciente(Paciente paciente[], int *contadorPaciente);

/*------- ALTERACÃO-------*/
void AlterarPaciente(Paciente paciente[], int *contadorPaciente);
void AlterarFuncionario(Funcionario funcionario[], int *contadorFuncionario);
void AlterarEspecialidade(Especialidade especialidade[], int *contadorEspecialidade);
void AlterarMedico(Medico medico[], int *contadorMedico);

/*------- EXCLUSÃO-------*/
void ExcluirPaciente(Paciente paciente[], int *contadorPaciente);
void ExcluirFuncionario(Funcionario funcionario[], int *contadorFuncionario);
void ExcluirMedico(Medico medico[], int *contadorMedico);
void ExcluirEspecialidade(Especialidade especialidade[], int *contadorEspecialidade);

/*------- LISTAR/EXIBIR-------*/
void TesteListaEspeci(Especialidade espec[], int *contadorEspecialidade);
void ListarFuncionario(Funcionario funcionario[], int *contadorFuncionario);
void ListarMedicos(Medico medico[], int *contadorMedico);
void ListarPaciente(Paciente paciente[], int *contadorPaciente);

/*------- PESQUISAR-------*/
void PesquisarEspecialidade(Especialidade especialidade[], int *contadorEspecialidade);
void PesquisarMedico(Medico medico[], int *contadorMedico);
void PesquisarPaciente(Paciente paciente[], int *contadorPaciente);
void PesquisarFuncionario(Funcionario funcionario[], int *contadorFuncionario);

//function
int main()
{

    setlocale(LC_ALL, "portuguese");

    int i = 0, contador = 0, contadorFuncionario = 0, contadorEspecialidade = 0,
        contadorMedico = 0, contadorPaciente = 0, achou = 0;
    char user[10], pass[10];
    Funcionario funcionario[10];
    Especialidade especialidade[10];
    Medico medico[10];
    Paciente paciente[10];

    do
    {
        printf("\n ---  LOGIN ---- \n ");
        printf("_________________ \n ");
        printf(" *** Usuário *** \n ");
        fflush(stdin);
        gets(user);
        printf(" *** Informe a Senha *** \n ");
        fflush(stdin);
        gets(pass);
        /*
        do
        {
            pass[i] = getch();
            if (pass[i] == 8 && i > 0) //Backspace
            {
                printf("\b \b");
                pass[i] = 0;
                i--;
            }
            else if (pass[i] == 13) // Enter
            {
                pass[i] = 0;
                i = 0;
                break;
            }
            else if (pass[i] != 8)
            {
                putchar('-');
                i++;
            }

        } while (i < 10); // TROCA DE CARACTERES, sTRINGS PARA UM MASCARA NAS SENHAS. CASO A SENHA PASSE DE 10 CARACTERES ELA EXECUTA O EVENTO.

        system("cls");
        
    */
        if (strcmp(user, "adm") == 0 && strcmp(pass, "123") == 0)
        {
            achou = 1;
            TelaMenuAdm(funcionario, &contadorFuncionario, especialidade, &contadorEspecialidade, medico, &contadorMedico, paciente, &contadorPaciente);
        }

        for (int i = 0; i < contadorFuncionario; i++)
        {
            if (strcmp(funcionario[i].login->login, user) == 0 && strcmp(funcionario[i].login->senha, pass) == 0)
            {
                achou = 1;

                TelaMenuFuncionario(paciente, &contadorPaciente);
            }
        }

        if (achou == 0)
        {
            printf("\n ---- DADOS NÃO ENCONTRADO ---- \n");
        }

        /*
        contador++;
        if (contador >= 2)
        {
            printf("\n --- Muitas tentativas --- ");
            Sleep(2000);
            LimparTela();
            printf("** saindo do sistema ** ");
            Sleep(2000);
            exit(0);
        }
        */

    } while (1); // login para adm ou funcionario entrar no menu correspondente.

    return 0;
}

void TelaMenuAdm(Funcionario funcionario[], int *contadorFuncionario, Especialidade especialidade[], int *contadorEspecialidade,
                 Medico medico[], int *contadorMedico, Paciente paciente[], int *contadorPaciente)
{
    int opcao, op;

    do
    {
        LimparTela();

        printf("\n ---- MENU PRINCIPAL ---- \n");
        printf("\n [1] CADASTRAR DADOS");
        printf("\n [2] ALTERAR DADOS");
        printf("\n [3] PESQUISAR DADOS");
        printf("\n [4] EXCLUIR DADOS");
        printf("\n [5] LOGOFF");
        printf("\n [0] EXIT ");
        printf("\n Informe uma opção: ");

        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:
            MenuCadastros(funcionario, contadorFuncionario, especialidade, contadorEspecialidade, medico, contadorMedico, paciente, contadorPaciente);
            break;

        case 2:
            MenuAlteracao(paciente, contadorPaciente, funcionario, contadorFuncionario, especialidade, contadorEspecialidade, medico, contadorMedico);
            // TesteListaEspeci(especialidade, contadorEspecialidade);
            //ListarMedicos(medico, contadorMedico);
            // ListarPaciente(paciente, contadorPaciente);
            break;

        case 3:
            TelaMenuPesquisaAdm(funcionario, contadorFuncionario, especialidade, contadorEspecialidade, medico, contadorMedico, paciente, contadorPaciente);
            break;

        case 0:
            printf("\n *** EXIT ***");
            Sleep(1500);
            system("cls");
            exit(0);

            break;
        case 4:
            MenuExclusao(paciente, contadorPaciente, funcionario, contadorFuncionario, especialidade, contadorEspecialidade, medico, contadorMedico);
            break;
        case 5:
            op = 5;
            break;

        default:
            printf("Digite uma opção válida\n");
        }
    } while (op != 5);
}

void TelaMenuFuncionario(Paciente paciente[], int *contadorPaciente)
{
    int opcao, op;

    do
    {
        LimparTela();

        printf("\n ---- MENU PRINCIPAL FUNCIONÁRIO---- \n");
        printf("\n [1] CADASTRAR DADOS");
        printf("\n [2] ALTERAR DADOS");
        printf("\n [3] PESQUISAR DADOS");
        printf("\n [4] EXCLUIR DADOS");
        printf("\n [5] VOLTAR MENU DE OPÇÃO");
        printf("\n [0] EXIT ");
        printf("\n Informe uma opção: ");

        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:
            MenuCadastroFuncionario(paciente, contadorPaciente);
            break;

        case 2:
            MenuAlteracaoFuncionario(paciente, contadorPaciente);
            break;

        case 3:
            TelaMenuPesquisaFuncionario(paciente, contadorPaciente);
            break;

        case 0:
            printf("\n *** EXIT ***");
            Sleep(1500);
            system("cls");
            exit(0);

            break;
        case 4:
            MenuExclusaoFuncionario(paciente, contadorPaciente);
            break;
        case 5:
            op = 5;
            break;

        default:
            printf("Digite uma opção válida\n");
        }
    } while (op != 5);
}

void TelaMenuPesquisaAdm(Funcionario funcionario[], int *contadorFuncionario, Especialidade especialidade[], int *contadorEspecialidade,
                         Medico medico[], int *contadorMedico, Paciente paciente[], int *contadorPaciente)
{
    int opcao, op;

    do
    {
        printf("\n ---- MENU PESQUISA ADM---- \n");
        printf("\n [1] - Especialidade: ");
        printf("\n [2] - Médico: ");
        printf("\n [3] - Paciente: ");
        printf("\n [4] - Funcionário: ");
        printf("\n [0] - Menu ADM: ");
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 0:

            op = 0;
            break;
        case 1:
            PesquisarEspecialidade(especialidade, contadorEspecialidade);
            break;
        case 2:
            PesquisarMedico(medico, contadorMedico);
            break;
        case 3:
            PesquisarPaciente(paciente, contadorPaciente);
            break;
        case 4:
            PesquisarFuncionario(funcionario, contadorFuncionario);
            break;

        default:
            printf("\n **** Verifique a opção digitada **** ");
            LimparTela();
            break;
        }

    } while (op != 0);
}

void PesquisarEspecialidade(Especialidade especialidade[], int *contadorEspecialidade)
{
    int cont = *contadorEspecialidade, achou = 0, opcao;
    char dadosPesquisa[20];

    do
    {
        printf("\n ---- PESQUISAR ESPECIALIDADE ---- \n");
        printf("\n Informe o Código: ");
        fflush(stdin);
        gets(dadosPesquisa);
        for (int i = 0; i < cont; i++)
        {
            if (strcmp(especialidade[i].codigo, dadosPesquisa) == 0)
            {
                achou = 1;
                printf("\n ----- Dados Encontrados! -----");
                Sleep(2000);
                LimparTela();
                printf("\n ========================");
                printf("\n CÓDIGO: %s", especialidade[i].codigo);
                printf("\n NOME: %s", especialidade[i].nome);
                printf("\n ========================");
            }
        }
        if (achou == 0)
        {
            printf("\n ----- Dados não Encontrados! -----");
            Sleep(2000);
            LimparTela();
        }

        printf("\n [1] Pesquisar novamente ou [0] para sair. ");
        scanf("%d", &opcao);
        achou = 0;

    } while (opcao != 0);
}

void PesquisarMedico(Medico medico[], int *contadorMedico)
{
    int cont = *contadorMedico, achou = 0, opcao;
    char dadosPesquisa[20];

    do
    {
        printf("\n ---- PESQUISAR MÉDICO ---- \n");
        printf("\n Informe o CRM: ");
        fflush(stdin);
        gets(dadosPesquisa);
        for (int i = 0; i < cont; i++)
        {
            if (strcmp(medico[i].CRM, dadosPesquisa) == 0)
            {
                achou = 1;
                printf("\n ----- Dados Encontrados! -----");
                Sleep(2000);
                LimparTela();
                printf("\n ========================");
                printf("\n NOME: %s ", medico[i].nome);
                printf("\n CRM: %s ", medico[i].CRM);
                printf("\n ESPECIALIDADE: %s ", medico[i].espec); // falta fazer de forma correta
                printf("\n LOGIN: %s ", medico[i].login->login);
                printf("\n SENHA: ***** ");
                printf("\n ========================");
            }
        }
        if (achou == 0)
        {
            printf("\n ----- Dados não Encontrados! -----");
            Sleep(2000);
            LimparTela();
        }

        printf("\n [1] Pesquisar novamente ou [0] para sair. ");
        scanf("%d", &opcao);
        achou = 0;

    } while (opcao != 0);
}

void PesquisarPaciente(Paciente paciente[], int *contadorPaciente)
{
    int cont = *contadorPaciente, achou = 0, opcao;
    char dadosPesquisa[20];

    do
    {
        printf("\n ---- PESQUISAR PACIENTE ---- \n");
        printf("\n Informe o CPF: ");
        fflush(stdin);
        gets(dadosPesquisa);
        for (int i = 0; i < cont; i++)
        {
            if (strcmp(paciente[i].CPF, dadosPesquisa) == 0)
            {
                achou = 1;
                printf("\n ----- Dados Encontrados! -----");
                Sleep(2000);
                LimparTela();
                printf("\n ========================");
                printf("\n NOME: %s ", paciente[i].nome);
                printf("\n CPF: %s ", paciente[i].CPF);
                printf("\n TELEFONE: %s ", paciente[i].contato->telefone);
                printf("\n LOGIN: %s ", paciente[i].login->login);
                printf("\n SENHA: ***** ");
                printf("\n ========================");
            }
        }
        if (achou == 0)
        {
            printf("\n ----- Dados não Encontrados! -----");
            Sleep(2000);
            LimparTela();
        }

        printf("\n [1] Pesquisar novamente ou [0] para sair. ");
        scanf("%d", &opcao);
        achou = 0;

    } while (opcao != 0);
}

void PesquisarFuncionario(Funcionario funcionario[], int *contadorFuncionario)
{
    int cont = *contadorFuncionario, achou = 0, opcao;
    char dadosPesquisa[20];

    do
    {
        printf("\n ---- PESQUISAR FUNCIONÁRIO ---- \n");
        printf("\n Informe a Matrícula: ");
        fflush(stdin);
        gets(dadosPesquisa);
        for (int i = 0; i < cont; i++)
        {
            if (strcmp(funcionario[i].matricula, dadosPesquisa) == 0)
            {
                achou = 1;
                printf("\n ----- Dados Encontrados! -----");
                Sleep(2000);
                LimparTela();
                printf("\n ========================");
                printf("\n NOME: %s ", funcionario[i].nome);
                printf("\n MATRÍCULA: %s ", funcionario[i].matricula);
                printf("\n LOGIN: %s ", funcionario[i].login->login);
                printf("\n SENHA: ***** ");
                printf("\n ========================");
            }
        }
        if (achou == 0)
        {
            printf("\n ----- Dados não Encontrados! -----");
            Sleep(2000);
            LimparTela();
        }

        printf("\n [1] Pesquisar novamente ou [0] para sair. ");
        scanf("%d", &opcao);
        achou = 0;

    } while (opcao != 0);
}

void TelaMenuPesquisaFuncionario(Paciente paciente[], int *contadorPaciente)
{
    int opcao, op;
    do
    {
        printf("\n ---- MENU PESQUISA FUNCIONÁRIO---- \n");
        printf("\n [1] - Paciente: ");
        printf("\n [0] - Menu anterior: ");
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 0:
            op = 0;
            break;
        case 1:
            PesquisarPaciente(paciente, contadorPaciente);
            break;
        default:
            printf("\n **** Verifique a opção digitada **** ");
            LimparTela();
            break;
        }

    } while (op != 0);

}
void MenuAlteracaoFuncionario(Paciente paciente[], int *contadorPaciente)
{
    int opcao;

    do
    {
        printf("\n ----- OPÇÕES PARA ALTERAÇÃO ----- \n ");
        printf("\n [1] - Paciente: ");
        printf("\n [0] - Menu Anterior: ");
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 0:
            opcao = 0;
            break;
        case 1:
            AlterarPaciente(paciente, contadorPaciente);

            break;
        default:
            printf("\n **** Verifique a opção digitada **** ");
            Sleep(1500);
            LimparTela();
            break;
        }

    } while (opcao != 0);
}

void MenuCadastroFuncionario(Paciente paciente[], int *contadorPaciente)
{
    int opcao, op;

    printf("\n ----- OPÇÕES PARA CADASTRO ----- \n ");

    do
    {
        printf("\n [1] - Paciente:: ");
        printf("\n [0] - Menu ADM: ");
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 0:
            // TelaMenuAdm(funcionario, &contadorFuncionarios);
            op = 0;
            break;
        case 1:
            CadastrarPaciente(paciente, contadorPaciente);
            break;

        default:
            printf("\n **** Verifique a opção digitada **** ");

            LimparTela();
            break;
        }

    } while (op != 0);
}

void MenuExclusaoFuncionario(Paciente paciente[], int *contadorPaciente)
{
    int opcao;

    do
    {
        printf("\n ----- OPÇÕES PARA EXCLUSÃO ----- \n ");
        printf("\n [1] -  Paciente: ");
        printf("\n [0] - Menu anterior: ");
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 0:
            opcao = 0;
            break;
        case 1:
            ExcluirPaciente(paciente, contadorPaciente);
            break;
        default:
            printf("\n **** Verifique a opção digitada **** ");
            Sleep(1500);
            LimparTela();
            break;
        }

    } while (opcao != 0);
}

void LimparTela()
{
    system("cls");
}

void MenuCadastros(Funcionario funcionarios[], int *contadorFuncionarios, Especialidade especialidade[], int *contadorEspecialidade, Medico medico[],
                   int *contadorMedico, Paciente paciente[], int *contadorPaciente)
{
    int opcao, op;

    printf("\n ----- OPÇÕES PARA CADASTRO ----- \n ");

    do
    {
        printf("\n [1] - Especialidade: ");
        printf("\n [2] - Médico: ");
        printf("\n [3] - Paciente: ");
        printf("\n [4] - Funcionário: ");
        printf("\n [0] - Menu ADM: ");
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 0:
            // TelaMenuAdm(funcionario, &contadorFuncionarios);
            op = 0;
            break;
        case 1:
            CadastrarEspecialidade(especialidade, contadorEspecialidade);
            break;
        case 2:
            CadastrarMedico(medico, contadorMedico, especialidade, contadorEspecialidade);
            //TesteListaEspeci (especialidade, contador);
            break;
        case 3:
            CadastrarPaciente(paciente, contadorPaciente);
            //ListarMedicos(medico, contadorMedico);
            break;
        case 4:
            CadastrarFuncionario(funcionarios, contadorFuncionarios);
            break;

        default:
            printf("\n **** Verifique a opção digitada **** ");

            LimparTela();
            break;
        }

    } while (op != 0);
}

void CadastrarEspecialidade(Especialidade especialidade[], int *contadorEspecialidade)
{
    int i = *contadorEspecialidade, opcao;
    do
    {
        printf("\n ---- MENU CADASTRO ---- \n");

        printf("\n Informe o nome da Especialidade: ");
        fflush(stdin);
        gets(especialidade[i].nome);
        printf("\n Informe o Código: ");
        fflush(stdin);
        gets(especialidade[i].codigo);
        i++;
        printf("\n **** Cadastrado com Sucesso! **** \n");
        Sleep(1500);
        system("cls");
        printf("\n [1] Cadastrar novamente ou [0] para sair. ");
        scanf("%d", &opcao);

    } while (opcao != 0);

    *contadorEspecialidade = i;
}

void TesteListaEspeci(Especialidade espec[], int *contadorEspecialidade)
{
    int cont = *contadorEspecialidade;
    printf("\n ___ LISTA ESPECIALIDADE ___ \n ");

    for (int i = 0; i < cont; i++)
    {
        printf("\n NOME: %s ", espec[i].nome);
        printf("\n CÓDIGO: %s ", espec[i].codigo);
    }
}

// PROCEDIMENTO EM ANDAMENTO
void CadastrarMedico(Medico medico[], int *contadorMedico, Especialidade especialidade[], int *contadorEspecialidade)
{
    int i = *contadorMedico, contEspe = *contadorEspecialidade, opcao, indice = 0, achou = 0;
    char dadosPesquisa[10];

    do
    {
        printf("\n ---- MENU CADASTRO ---- \n");

        printf("\n Informe o nome do Médico: ");
        fflush(stdin);
        gets(medico[i].nome);
        printf("\n Escolha a especialidade: ");
        TesteListaEspeci(especialidade, contadorEspecialidade); //listar as especialidades
        printf("\n Informe o código da especialidade: ");
        fflush(stdin);
        gets(dadosPesquisa);
        for (int c = 0; c < contEspe; c++)
        {
            if (strcmp(dadosPesquisa, especialidade[c].nome) == 0)
            {
                achou = 1;
                strcpy(medico[c].espec, dadosPesquisa); //FALTA IMPLEMENTAR DE FORMA CORRETA ;-(

                printf("\n Infome o CRM: ");
                fflush(stdin);
                gets(medico[i].CRM);
                printf("\n Infome o login: ");
                fflush(stdin);
                gets(medico[i].login->login);
                printf("\n Infome a Senha: ");
                fflush(stdin);
                gets(medico[i].login->senha);
                printf("\n **** Cadastrado com Sucesso! **** \n");
                Sleep(1500);
                system("cls");
                i++;
            }
        }

        if (achou == 0)
        {
            printf("\n Erro!!\n");
        }
        printf("\n [1] Cadastrar novamente ou [0] para sair. ");
        scanf("%d", &opcao);
    } while (opcao != 0);

    *contadorMedico = i;
} //verificar essa funçao

void ListarMedicos(Medico medico[], int *contadorMedico)
{
    int cont = *contadorMedico;

    printf("\n ___ LISTA MÉDICOS ___ \n ");

    for (int i = 0; i < cont; i++)
    {
        printf("\n NOME: %s ", medico[i].nome);
        printf("\n CRM: %s ", medico[i].CRM);
        printf("\n ESPECIALIDADE: %s ", medico[i].espec); // falta fazer de forma correta
        printf("\n LOGIN: %s ", medico[i].login->login);
        printf("\n SENHA: ***** ");
    }
}

void CadastrarPaciente(Paciente paciente[], int *contadorPaciente)
{

    int i = *contadorPaciente, opcao;

    do
    {
        printf("\n ---- MENU CADASTRO ---- \n");

        printf("\n Informe o nome do Paciente: ");
        fflush(stdin);
        gets(paciente[i].nome);
        printf("\n Informe o telefone: ");
        fflush(stdin);
        gets(paciente[i].contato->telefone);
        printf("\n Informe o CPF: ");
        fflush(stdin);
        gets(paciente[i].CPF);
        printf("\n Informe o Login: ");
        fflush(stdin);
        gets(paciente[i].login->login);
        printf("\n Informe a Senha: ");
        fflush(stdin);
        gets(paciente[i].login->senha);
        printf("\n **** Cadastrado com Sucesso! **** \n");
        Sleep(1500);
        system("cls");
        i++;

        printf("\n [1] Cadastrar novamente ou [0] para sair. ");
        scanf("%d", &opcao);
    } while (opcao != 0);

    *contadorPaciente = i;
}

void ListarPaciente(Paciente paciente[], int *contadorPaciente)
{
    int cont = *contadorPaciente;
    void MenuAlteracao();

    printf("\n ___ LISTA PACIENTES ___ \n ");

    for (int i = 0; i < cont; i++)
    {
        printf("\n NOME: %s ", paciente[i].nome);
        printf("\n CPF: %s ", paciente[i].CPF);
        printf("\n TELEFONE: %s ", paciente[i].contato->telefone);
        printf("\n LOGIN: %s ", paciente[i].login->login);
        printf("\n SENHA: ***** ");
    }
}

void CadastrarFuncionario(Funcionario funcionario[], int *contadorFuncionario)
{
    int i = *contadorFuncionario, opcao;

    do
    {
        printf("\n ---- MENU CADASTRO ---- \n");

        printf("\n Informe o nome do funcionário: ");
        fflush(stdin);
        gets(funcionario[i].nome);
        printf("\n Informe a matrícula: ");
        fflush(stdin);
        gets(funcionario[i].matricula);
        printf("\n Informe o Login: ");
        fflush(stdin);
        gets(funcionario[i].login->login);
        printf("\n Informe a Senha: ");
        fflush(stdin);
        gets(funcionario[i].login->senha);
        printf("\n **** Cadastrado com Sucesso! **** \n");
        Sleep(1500);
        system("cls");
        i++;

        printf("\n [1] Cadastrar novamente ou [0] para sair. ");
        scanf("%d", &opcao);
    } while (opcao != 0);

    *contadorFuncionario = i;
}

void ListarFuncionario(Funcionario funcionario[], int *contadorFuncionario)
{
    int cont = *contadorFuncionario;

    printf("\n ___ LISTA FUNCIONÁRIO ___ \n ");

    for (int i = 0; i < cont; i++)
    {
        printf("\n NOME: %s ", funcionario[i].nome);
        printf("\n MATRÍCULA: %s ", funcionario[i].matricula);
        printf("\n LOGIN: %s ", funcionario[i].login->login);
        printf("\n SENHA: ***** ");
    }
}

void MenuAlteracao(Paciente paciente[], int *contadorPaciente, Funcionario funcionario[], int *contadorFuncionario, Especialidade especialidade[], int *contadorEspecialidade,
                   Medico medico[], int *contadorMedico)
{
    int opcao;

    do
    {
        printf("\n ----- OPÇÕES PARA ALTERAÇÃO ----- \n ");
        printf("\n [1] - Especialidade: ");
        printf("\n [2] - Médico: ");
        printf("\n [3] - Paciente: ");
        printf("\n [4] - Funcionário: ");
        printf("\n [0] - Menu ADM: ");
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 0:
            opcao = 0;
            break;
        case 1:
            AlterarEspecialidade(especialidade, contadorEspecialidade);
            break;
        case 2:
            AlterarMedico(medico, contadorMedico);
            break;
        case 3:
            AlterarPaciente(paciente, contadorPaciente);
            break;
        case 4:
            AlterarFuncionario(funcionario, contadorFuncionario);
            break;

        default:
            printf("\n **** Verifique a opção digitada **** ");
            Sleep(1500);
            LimparTela();
            break;
        }

    } while (opcao != 0);
}

void MenuExclusao(Paciente paciente[], int *contadorPaciente, Funcionario funcionario[], int *contadorFuncionario, Especialidade especialidade[], int *contadorEspecialidade,
                  Medico medico[], int *contadorMedico)
{
    int opcao;

    do
    {
        printf("\n ----- OPÇÕES PARA EXCLUSÃO ----- \n ");
        printf("\n [1] - Especialidade: ");
        printf("\n [2] - Médico: ");
        printf("\n [3] - Paciente: ");
        printf("\n [4] - Funcionário: ");
        printf("\n [0] - Menu ADM: ");
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 0:
            opcao = 0;
            break;
        case 1:
            ExcluirEspecialidade(especialidade, contadorEspecialidade);
            break;
        case 2:
            ExcluirMedico(medico, contadorMedico);
            break;
        case 3:
            ExcluirPaciente(paciente, contadorPaciente);
            break;
        case 4:
            ExcluirFuncionario(funcionario, contadorFuncionario);
            break;

        default:
            printf("\n **** Verifique a opção digitada **** ");
            Sleep(1500);
            LimparTela();
            break;
        }

    } while (opcao != 0);
}

void AlterarPaciente(Paciente paciente[], int *contadorPaciente)
{
    int cont = *contadorPaciente, achou = 0, op, opcao;
    char dadosPesquisa[15];

    printf("\n ---- ALTERAR DADOS PACIENTE---- \n");
    printf("\n Informe o CPF: ");
    fflush(stdin);
    gets(dadosPesquisa);
    for (int i = 0; i < cont; i++)
    {
        if (strcmp(paciente[i].CPF, dadosPesquisa) == 0)
        {
            achou = 1;
            do
            {
                printf("\n ** DADOS CONFEREM ** \n");
                system("cls");
                printf("\n ---- DADOS ----\n ");
                printf(" \n ============================ \n ");
                printf("\n Nome: %s", paciente[i].nome);
                printf("\n Telefone: %s", paciente[i].contato->telefone);
                printf("\n CPF: %s", paciente[i].CPF);
                printf("\n Login: %s", paciente[i].login->login);
                printf("\n Senha: ******* ");
                printf(" \n ============================ \n ");

                printf("\n Escolha a opção para alterar dados \n ");
                printf("\n [1] Nome: ");
                printf("\n [2] Telefone: ");
                printf("\n [3] CPF: ");
                printf("\n [4] Login: ");
                printf("\n [5] Senha: ");
                printf("\n [0] Encerrar: ");
                scanf("%d", &opcao);
                switch (opcao)
                {
                case 1:
                    printf("\n Informe o novo nome: ");
                    fflush(stdin);
                    gets(&paciente[i].nome);
                    break;
                case 2:
                    printf("\n Informe o novo Telefone: ");
                    fflush(stdin);
                    gets(&paciente[i].contato->telefone);
                    break;
                case 3:
                    printf("\n Informe o novo CPF: ");
                    fflush(stdin);
                    gets(&paciente[i].CPF);
                    break;
                case 4:
                    printf("\n Informe o novo Login: ");
                    fflush(stdin);
                    gets(&paciente[i].login->login);
                    break;
                case 5:
                    printf("\n Informe a nova Senha: ");
                    fflush(stdin);
                    gets(&paciente[i].login->senha);
                    break;
                case 0:
                    opcao = 0;
                    // MenuAlteracao(paciente, contadorPaciente);

                    Sleep(1500);
                    break;

                default:
                    printf("\n ---- OPÇÃO INVÁLIDA ---- \n ");
                    break;
                }

                //printf("\n **** Atualizado com Sucesso! **** \n");
                printf("\n **** [1] ALTERAR NOVAMENTE [0] MENU PRINCIPAL**** \n ");
                scanf("%d", &op);
            } while (op != 0);
        }
    }
    if (achou == 0)
    {
        printf("\n ---- NÃO ENCONTRADO! ---- \n ");
    }
}

void AlterarFuncionario(Funcionario funcionario[], int *contadorFuncionario)
{
    int cont = *contadorFuncionario, achou = 0, op, opcao;
    char dadosPesquisa[15];

    printf("\n ---- ALTERAR DADOS FUNCIONÁRIO---- \n");
    printf("\n Informe a Matrícula: ");
    fflush(stdin);
    gets(dadosPesquisa);
    for (int i = 0; i < cont; i++)
    {
        if (strcmp(funcionario[i].matricula, dadosPesquisa) == 0)
        {
            achou = 1;
            do
            {
                printf("\n ** DADOS CONFEREM ** \n");
                system("cls");
                printf("\n ---- DADOS ----\n ");
                printf(" \n ============================ \n ");
                printf("\n Nome: %s", funcionario[i].nome);
                printf("\n Matrícula: %s", funcionario[i].matricula);
                printf("\n Login: %s", funcionario[i].login->login);
                printf("\n Senha: ******* ");
                printf(" \n ============================ \n ");

                printf("\n Escolha a opção para alterar dados \n ");
                printf("\n [1] Nome: ");
                printf("\n [2] Matrícula: ");
                printf("\n [3] Login: ");
                printf("\n [4] Senha: ");
                printf("\n [0] Encerrar: ");
                scanf("%d", &opcao);
                switch (opcao)
                {
                case 1:
                    printf("\n Informe o novo nome: ");
                    fflush(stdin);
                    gets(&funcionario[i].nome);
                    break;
                case 2:
                    printf("\n Informe a nova Matrícula: ");
                    fflush(stdin);
                    gets(&funcionario[i].matricula);
                    break;
                case 3:
                    printf("\n Informe o novo Login: ");
                    fflush(stdin);
                    gets(&funcionario[i].login->login);
                    break;
                case 4:
                    printf("\n Informe a nova Senha: ");
                    fflush(stdin);
                    gets(&funcionario[i].login->senha);
                    break;
                case 0:
                    opcao = 0;
                    // MenuAlteracao(paciente, contadorPaciente);
                    Sleep(1500);
                    break;

                default:
                    printf("\n ---- OPÇÃO INVÁLIDA ---- \n ");
                    break;
                }

                //printf("\n **** Atualizado com Sucesso! **** \n");
                printf("\n **** [1] ALTERAR NOVAMENTE [0] MENU PRINCIPAL**** \n ");
                scanf("%d", &op);
            } while (op != 0);
        }
    }
    if (achou == 0)
    {
        printf("\n ---- NÃO ENCONTRADO! ---- \n ");
    }
}

void AlterarEspecialidade(Especialidade especialidade[], int *contadorEspecialidade)
{
    int cont = *contadorEspecialidade, achou = 0, op, opcao;
    char dadosPesquisa[15];

    printf("\n ---- ALTERAR DADOS ESPECIALIDADE---- \n");
    printf("\n Informe o código: ");
    fflush(stdin);
    gets(dadosPesquisa);
    for (int i = 0; i < cont; i++)
    {
        if (strcmp(especialidade[i].codigo, dadosPesquisa) == 0)
        {
            achou = 1;
            do
            {
                printf("\n ** DADOS CONFEREM ** \n");
                system("cls");
                printf("\n ---- DADOS ----\n ");
                printf(" \n ============================ \n ");
                printf("\n Nome: %s", especialidade[i].nome);
                printf("\n Código: %s", especialidade[i].codigo);
                printf(" \n ============================ \n ");

                printf("\n Escolha a opção para alterar dados \n ");
                printf("\n [1] Nome: ");
                printf("\n [2] Código: ");
                printf("\n [0] Encerrar: ");
                scanf("%d", &opcao);
                switch (opcao)
                {
                case 1:
                    printf("\n Informe o novo nome: ");
                    fflush(stdin);
                    gets(&especialidade[i].nome);
                    break;
                case 2:
                    printf("\n Informe a nova Matrícula: ");
                    fflush(stdin);
                    gets(&especialidade[i].codigo);
                    break;
                case 0:
                    opcao = 0;
                    // MenuAlteracao(paciente, contadorPaciente);
                    Sleep(1500);
                    break;

                default:
                    printf("\n ---- OPÇÃO INVÁLIDA ---- \n ");
                    break;
                }

                //printf("\n **** Atualizado com Sucesso! **** \n");
                printf("\n **** [1] ALTERAR NOVAMENTE [0] MENU PRINCIPAL**** \n ");
                scanf("%d", &op);
            } while (op != 0);
        }
    }
    if (achou == 0)
    {
        printf("\n ---- NÃO ENCONTRADO! ---- \n ");
    }
}

void AlterarMedico(Medico medico[], int *contadorMedico)
{
    int cont = *contadorMedico, achou = 0, op, opcao;
    char dadosPesquisa[15];

    printf("\n ---- ALTERAR DADOS MÉDICOS---- \n");
    printf("\n Informe o CRM: ");
    fflush(stdin);
    gets(dadosPesquisa);
    for (int i = 0; i < cont; i++)
    {
        if (strcmp(medico[i].CRM, dadosPesquisa) == 0)
        {
            achou = 1;
            do
            {
                printf("\n ** DADOS CONFEREM ** \n");
                system("cls");
                printf("\n ---- DADOS ----\n ");
                printf(" \n ============================ \n ");
                printf("\n Nome: %s", medico[i].nome);
                printf("\n CRM: %s", medico[i].CRM);
                printf("\n Login: %s", medico[i].login->login);
                printf("\n Senha: ******* ");
                printf(" \n ============================ \n ");

                printf("\n Escolha a opção para alterar dados \n ");
                printf("\n [1] Nome: ");
                printf("\n [2] CRM: ");
                printf("\n [3] Login: ");
                printf("\n [4] Senha: ");
                printf("\n [0] Encerrar: ");
                scanf("%d", &opcao);
                switch (opcao)
                {
                case 1:
                    printf("\n Informe o novo nome: ");
                    fflush(stdin);
                    gets(&medico[i].nome);
                    break;
                case 2:
                    printf("\n Informe o novo CRM: ");
                    fflush(stdin);
                    gets(&medico[i].CRM);
                    break;
                case 3:
                    printf("\n Informe o novo Login: ");
                    fflush(stdin);
                    gets(&medico[i].login->login);
                    break;
                case 4:
                    printf("\n Informe a nova Senha: ");
                    fflush(stdin);
                    gets(&medico[i].login->senha);
                    break;
                case 0:
                    opcao = 0;
                    // MenuAlteracao(paciente, contadorPaciente);
                    Sleep(1500);
                    break;
                default:
                    printf("\n ---- OPÇÃO INVÁLIDA ---- \n ");
                    break;
                }

                //printf("\n **** Atualizado com Sucesso! **** \n");
                printf("\n **** [1] ALTERAR NOVAMENTE [0] MENU PRINCIPAL**** \n ");
                scanf("%d", &op);
            } while (op != 0);
        }
    }
    if (achou == 0)
    {
        printf("\n ---- NÃO ENCONTRADO! ---- \n ");
    }
}

void ExcluirPaciente(Paciente paciente[], int *contadorPaciente)
{
    int cont = *contadorPaciente, achou = 0, op, opcao;
    char dadosPesquisa[15];

    printf("\n ---- EXCLUIR DADOS PACIENTE---- \n");
    printf("\n Informe o CPF: ");
    fflush(stdin);
    gets(dadosPesquisa);
    for (int i = 0; i < cont; i++)
    {
        if (strcmp(paciente[i].CPF, dadosPesquisa) == 0)
        {
            achou = 1;

            printf("\n ** DADOS CONFEREM ** \n");
            Sleep(2000);
            system("cls");
            strcpy(paciente[i].nome, "");
            strcpy(paciente[i].CPF, "");
            strcpy(paciente[i].login->login, "");
            strcpy(paciente[i].login->senha, "");
            printf("\n **** Excluído com Sucesso! **** \n");
        }
    }

    if (achou == 0)
    {
        printf("\n ---- NÃO ENCONTRADO! ---- \n ");
    }
}

void ExcluirFuncionario(Funcionario funcionario[], int *contadorFuncionario)
{
    int cont = *contadorFuncionario, achou = 0, op, opcao;
    char dadosPesquisa[15];

    printf("\n ---- EXCLUIR DADOS FUNCIONÁRIO---- \n");
    printf("\n Informe a Matrícula: ");
    fflush(stdin);
    gets(dadosPesquisa);
    for (int i = 0; i < cont; i++)
    {
        if (strcmp(funcionario[i].matricula, dadosPesquisa) == 0)
        {
            achou = 1;

            printf("\n ** DADOS CONFEREM ** \n");
            Sleep(2000);
            system("cls");
            strcpy(funcionario[i].nome, "");
            strcpy(funcionario[i].login->login, "");
            strcpy(funcionario[i].login->senha, "");
            strcpy(funcionario[i].matricula, "");
            printf("\n **** Excluído com Sucesso! **** \n");
        }
    }

    if (achou == 0)
    {
        printf("\n ---- NÃO ENCONTRADO! ---- \n ");
    }
}

void ExcluirMedico(Medico medico[], int *contadorMedico)
{
    int cont = *contadorMedico, achou = 0, op, opcao;
    char dadosPesquisa[15];

    printf("\n ---- EXCLUIR DADOS MÉDICO---- \n");
    printf("\n Informe o CRM: ");
    fflush(stdin);
    gets(dadosPesquisa);
    for (int i = 0; i < cont; i++)
    {
        if (strcmp(medico[i].CRM, dadosPesquisa) == 0)
        {
            achou = 1;

            printf("\n ** DADOS CONFEREM ** \n");
            Sleep(2000);
            system("cls");
            strcpy(medico[i].nome, "");
            strcpy(medico[i].CRM, "");
            strcpy(medico[i].espec, "");
            strcpy(medico[i].login->login, "");
            strcpy(medico[i].login->senha, "");
            printf("\n **** Excluído com Sucesso! **** \n");
        }
    }
    if (achou == 0)
    {
        printf("\n ---- NÃO ENCONTRADO! ---- \n ");
    }
}

void ExcluirEspecialidade(Especialidade especialidade[], int *contadorEspecialidade)
{
    int cont = *contadorEspecialidade, achou = 0, op, opcao;
    char dadosPesquisa[15];

    printf("\n ---- EXCLUIR DADOS ESPECIALIDADE---- \n");
    printf("\n Informe o código: ");
    fflush(stdin);
    gets(dadosPesquisa);
    for (int i = 0; i < cont; i++)
    {
        if (strcmp(especialidade[i].codigo, dadosPesquisa) == 0)
        {
            achou = 1;

            printf("\n ** DADOS CONFEREM ** \n");
            Sleep(2000);
            system("cls");
            strcpy(especialidade[i].codigo, "");
            strcpy(especialidade[i].nome, "");
            printf("\n **** Excluído com Sucesso! **** \n");
        }
    }
    if (achou == 0)
    {
        printf("\n ---- NÃO ENCONTRADO! ---- \n ");
    }
}