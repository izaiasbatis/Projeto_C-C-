#include <stdio.h> // biblioteca padr�o para usar printf, scanf etc...
#include <stdlib.h> // biblioteca padr�o
#include <string.h> // biblioteca que permite acesso a manipula��o de strings e uso de structs
#include <locale.h> // biblioteca para permitir suporte a l�ngua portuguesa
#include <windows.h> // biblioteca
#include <iostream> // biblioteca manipula�� de arquivo
#include <fstream> // biblioteca manipula�� de arquivo ler/escrever
#include <string> // biblioteca manipula�� de strings
using namespace std;

/* -------------------- Estruturas: -------------------- */

typedef struct{ // Estrutura dos clientes:

    char nome[50]; // nome[limite de caracteres]
    char cpf[11];
    char telefone[11];
    char rua[50];
    char numero[20];
    char bairro[50];
    char cidade[50];
    char estado[50];
    char cep[11];
    char ano_de_nascimento[15];
    char ano_atual[15];
    char e_mail[50];
    char data_do_diagnostico[15];
    char qual_comorbidade_do_paciente[15];
} paciente; paciente p[20]; // nome da estrutura paciente atribuida a "p" e limite de clientes atribuido a [].


typedef struct { // Estrutura do gerente:

    char nome[30];
    char login[30];
    char senha[30];
    char msg_profissional[250];
} profissional; profissional f[2]; // nome da estrutura gerente atribuida a "f" e limite de clientes atribuido a [].



/* -------------------- Vari�veis globais e fun��es definidas: -------------------- */

// vari�vel com valor quantidade de paciente que ser� mudado pelo paciente em breve
int quantidade = 0;

// definindo fun��es que foram criadas abaixo do main:
void menu_profissional();
void menu_paciente();
void login_profissional();
void cadastro_paciente();

/* ---------------- fun��es: -------------------- */

int main() // fun��o main | fun��o principal
{
	setlocale(LC_ALL, "Portuguese"); // permitindo caracteres especiais do teclado PT-BR.
    system("cls"); // fun��o do prompt de comando usado para limpar cmd // serve para limpar terminal no linux

	char op; // vari�vel op��o.
	printf("------------------ Sistema de Sa�de 1.0 ------------------\n");
	printf("\n1 - Cadastro do Paciente\n");
	printf("\n2 - Login do profissional de Sa�de\n");
	printf("\n3 - fechar\n\n: ");
	scanf("%c", &op);

	switch(op){ // examinando vari�vel op��o que cont�m valor inserido pelo usu�rio. // analisando a op��o inserida pelo usu�rio.
		case '1':
            system("cls"); // fun��o do prompt de comando usado para limpar cmd // limpar prompt
		    menu_paciente(); // < volta para a fun��o
		    break;
		case '2':
		    system("cls"); // fun��o do prompt de comando usado para limpar cmd
		    login_profissional(); // < volta para a fun��o // executando fun��o do profissional
		    break;
		case '3':
		    system("cls"); // fun��o do prompt de comando usado para limpar cmd // serve para limpar terminal no linux
		    printf("\nVoc� fechou o sistema.");
		    exit(0);
		    break;
		default:
		    printf("Op��o n�o v�lida.");
            Sleep(500);
            return main(); // < volta para a fun��o
		    break;
	}
	return 0;
}
void arquivar(){ //Fun��o para arquivar

    ofstream MyReadFile("pacientes.txt", ios::app);
    for (int i=0; i < quantidade; i++){
        MyReadFile << "nome=" << p[i].nome << "&" << "CPF=" << p[i].cpf << "&" << "Telefone=" << p[i].telefone << "&" << "Rua=" << p[i].rua << "&" << "Numero=" << p[i].numero << "&" << "Bairro=" << p[i].bairro << "&" << "Cidade=" << p[i].cidade << "&" << "Estado=" << p[i].estado << "&" << "CEP=" << p[i].cep << "&" << "Ano_de_Nascimento=" << p[i].ano_de_nascimento << "&" << "Ano_Atual=" << p[i].ano_atual << "&" << "Email=" << p[i].e_mail << "&" << "Data_do_diagnostico=" << p[i].data_do_diagnostico << "&" <<"Comorbidade=" << p[i].qual_comorbidade_do_paciente << "\n" << endl;
    }
    // fechar o arquivo
    printf("\t\t\t\t\t\tPaciente arquivado!");
    MyReadFile.close();


	return;
}
void verifica_comorbidade(){

    ofstream MyReadFile("pacientes_com_comorbidade.txt", ios::app);
    for (int i=0; i < quantidade; i++){
        int idade = stoi(p[i].ano_atual)  - stoi(p[i].ano_de_nascimento);
        if (idade >= 65
            && ( 0 == strcmp(p[i].qual_comorbidade_do_paciente , "diabetes")
                || 0 == strcmp(p[i].qual_comorbidade_do_paciente , "obesidade")
                || 0 == strcmp(p[i].qual_comorbidade_do_paciente , "hipertens�o")
                || 0 == strcmp(p[i].qual_comorbidade_do_paciente , "tuberculose")
                || 0 == strcmp(p[i].qual_comorbidade_do_paciente , "outros"))) {

            MyReadFile << "CEP=" << p[i].cep << "&" << "Idade=" << idade <<"\n" << endl;
            printf("\n\t\t\t\t\t\t\tAlerta!!!\n\t\t\t\t\t\tPaciente no grupo de risco!");
        }
    }

    // Close the file
    MyReadFile.close();


	return;
}
void menu_paciente(){

    int op = 0;
    system("cls"); // fun��o do prompt de comando usado para limpar cmd // limpar prompt
    printf("------------------ Sistema de Sa�de ------------------\n");
    printf("\n1 - Cadastro de Pacientes\n");
    printf("\n2 - Voltar\n\n:");
    scanf("%d", &op);

    switch(op){ // examinando vari�vel op��o que cont�m valor inserido pelo usu�rio.
        case 1:
            cadastro_paciente();// < volta para a fun��o
            break;
        case 2:
            main(); // < volta para a fun��o
            break;
        default:
            return menu_paciente(); // < volta para a fun��o
            break;
    }
}
void idade(){
    for (int i=0; i < sizeof(p); i++){
        int idade = p[i].ano_atual - p[i].ano_de_nascimento;
    }
}
void cadastro_paciente(){
    system("cls"); // fun��o do prompt de comando usado para limpar cmd
    char op;
    printf("------------------ teste sa�de - �rea do cadastro ------------------\n");
    printf("\nQuantas pessoas quer cadastrar?: ");
    scanf("%i", &quantidade);
    system("cls"); // fun��o do prompt de comando usado para limpar cmd

    for(int i = 0; i < quantidade; i++){ // criando um contador "i" e criando uma condi��o, se "i" for maior que a vari�vel quantidade, loop mais uma vez.

        printf("------------------ Teste saude - �rea do cadastro ------------------\n");
        printf("Quantidade de cadastros: %i\n", quantidade);
        // dependendo da quantidade de cadastros fornecida pelo usu�rio, o loop s� fechar� o la�o for quando o contador for maior que a quantidade.

        printf("\n nome: ");
        scanf(" %s", p[i].nome);

        printf("\n CPF: ");
        scanf(" %s", p[i].cpf);

        printf("\n Telefone: ");
        scanf(" %s", p[i].telefone);

        printf("\n Rua: ");
        scanf(" %s", p[i].rua);

        printf("\n Numero: ");
        scanf(" %s", p[i].numero);

        printf("\n Bairro: ");
        scanf(" %s", p[i].bairro);

        printf("\n Cidade: ");
        scanf(" %s", p[i].cidade);

        printf("\n Estado: ");
        scanf(" %s", p[i].estado);

        printf("\n CEP: ");
        scanf(" %s", p[i].cep);

        printf("\n Ano de Nascimento: ");
        scanf(" %s", p[i].ano_de_nascimento);

        printf("\n Ano Atual: ");
        scanf(" %s", p[i].ano_atual);

        printf("\n Email: ");
        scanf(" %s", p[i].e_mail);

        printf("\n Data do diagnostico: ");
        scanf(" %s", p[i].data_do_diagnostico);

        printf("\n Qual a Comorbidade do paciente: ");
        scanf(" %s", p[i].qual_comorbidade_do_paciente);
        system("cls"); // fun��o do prompt de comando usado para limpar cmd

    }
    arquivar();
    verifica_comorbidade();
    printf("\nCadastro concluido com sucesso!\n");
    printf("\nTrocar usu�rio? S/N : ");
    scanf("%s", &op);
    switch(op){ // examinando vari�vel op��o que cont�m valor inserido pelo usu�rio.
        case 's':
        case 'S':
            system("cls"); // fun��o do prompt de comando usado para limpar cmd
            login_profissional(); // < volta para a fun��o
            break;
        case 'n':
        case 'N':
            system("cls"); // fun��o do prompt de comando usado para limpar cmd
            menu_paciente(); // < volta para a fun��o
            break;
        default:
            system("cls"); // fun��o do prompt de comando usado para limpar cmd
            menu_paciente(); // < volta para a fun��o
            break;

            scanf("%s", &op);
    }

}

void login_profissional(){

    setlocale(LC_ALL,"Portuguese");

	strcpy(f[0].nome, "Ketryn");
	strcpy(f[1].nome, "Izaias"); // armazenando strings na variavel da struct
	strcpy(f[0].login, "admin"); // esse � o login armazenado na struct
	strcpy(f[0].senha, "admin"); // esse � a senha armazenada na struct

	char login[10], senha[10], nome[10], cpf[11]; // criando vari�vel com [limite de tamanho]

    system("cls"); // fun��o do prompt de comando usado para limpar cmd // limpar prompt

	printf("\n\tLogin: ");
	scanf(" %s", login); // scanf para escanear e atribuir valor inserido pelo usu�rio para a vari�vel login
	printf("\n\tSenha: ");
	scanf(" %s", senha); // scanf para escanear e atribuir valor inserido pelo usu�rio para a vari�vel senha

	if ((strcmp(login,f[0].login)==0) || (strcmp(senha,f[0].senha)==0)){ // se as variaveis senha e login forem iguais a g.login e g.senha ir� logar.

		system("cls"); // fun��o do prompt de comando usado para limpar cmd

		printf("\n\tProfissional: ");
		scanf(" %s", nome);

		if(strcmp(nome,f[0].nome)==0){ // se o nome do gerente coincidir com o nome inserido, logar�. caso contr�rio fechar� o sistema por motivos de seguran�a.
            system("cls"); // fun��o do prompt de comando usado para limpar cmd
            printf("\t\tLogin efetuado com sucesso.\tBem vindo %s.\n",f[0].nome);
            menu_profissional(); // < volta para a fun��o
		}
        else if(strcmp(nome,f[1].nome)==0){ // se o nome do gerente coincidir com o nome inserido, logar�. caso contr�rio fechar� o sistema por motivos de seguran�a.
            system("cls"); // fun��o do prompt de comando usado para limpar cmd
            printf("\t\t\tLogin efetuado com sucesso.\tBem vindo %s.\n",f[1].nome);
            menu_profissional(); // < volta para a fun��o
        }
        else{ // se o nome inserido pelo usu�rio n�o for igual ao nome do gerente do sistema, fechar� o sistema por motivos de seguran�a.
            printf("\t\tNome inv�lido ou incorreto\n\t\tPor motivos de seguran�a, o sistema ser� fechado...\n\n");
            exit(1);
        }
    }
}

void menu_profissional(){

    system("cls"); // fun��o do prompt de comando usado para limpar cmd // limpar prompt
    int op = 0;
    char cpf[50];
    char zero[50];
    char op2;
    strcpy(zero, "0");
    printf("------------------ - �rea do Profissional  ------------------\n");
    printf("\n1 - Consultar paciente");
    printf("\n2 - Voltar\n\n :");
    scanf("%d", &op);


    switch(op){ // examinando vari�vel op��o que cont�m valor inserido pelo usu�rio.
        case 1:
            system("cls"); // fun��o do prompt de comando usado para limpar cmd
            printf("------------------ �rea de Profissional  ------------------\n");
            printf("\nEnviar mensagem ao cliente: ");
            scanf(" %[^\n]s", f[0].msg_profissional);
            Sleep(500);
            printf("Mensagem enviada...");
            Sleep(200);
            menu_profissional(); // < volta para a fun��o
            break;
        case 2:
            system("cls"); // fun��o do prompt de comando usado para limpar cmd
            printf("\n\t\t\tSaindo...");
            Sleep(500); // serve para dar um delay de milisegundos
            main();

        default:
            system("cls"); // fun��o do prompt de comando usado para limpar cmd
            printf("\nErro, digite uma op��o v�lida...");
            Sleep(200); // serve para dar um delay de milisegundos
            menu_profissional(); // < volta para a fun��o
            break;
    }
}
