#include <stdio.h> 								//biblioteca de comunica��o com o usu�rio
#include <stdlib.h>								//biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> 							//biblioteca de aloca��es de texto por regi�o

int registro() 									//Fun��o respons�vel por cadastrar os usuarios no sistema
{
	setlocale(LC_ALL, "portuguese"); 			//Definindo linguagem
												//inicio cria��o de vari�veis/strings
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	
	printf("Digite o CPF a ser cadastrado: ");  //coleta informa��o do usu�rio para o sistema
	scanf("%39s", cpf); 							//%s refere-se a string
	
	strcpy(arquivo, cpf); 						//Respons�vel por copiar os valores das strings
	
	FILE *file; 								//cria arquivo
	file = fopen(arquivo, "w"); 				//cria o arquivo
	fprintf(file,cpf); 							//salva o valor da variavel
	fclose(file); 								//fecha o arquivo
	
	file = fopen(arquivo, "a");					//acessa o arquivo
	fprintf(file, ", ");						//atualiza o arquivo com dados adicionais
	fclose(file);								//fecha arquivo
	
	printf("Digite o nome a ser cadastrado: "); //coleta informa��o do usu�rio para o sistema
	scanf("%39s",nome);							//%s refere-se a string
	
	file = fopen(arquivo, "a");					//acessa o arquivo
	fprintf(file,nome);							//atualiza o arquivo com dados adicionais
	fclose(file);								//fecha o arquivo
	
	file = fopen(arquivo, "a");					//acessa o arquivo
	fprintf(file, ", ");						//atualiza o arquivo com dados adicionais
	fclose(file);								//fecha o arquivo
	
	printf("Digite o sobrenome a ser cadastrado: ");//coleta informa��o do usu�rio para o sistema
	scanf("%39s",sobrenome);						//%s refere-se a string
	
	file = fopen(arquivo, "a");					//acessa o arquivo
	fprintf(file,sobrenome);					//atualiza o arquivo com dados adicionais
	fclose(file);								//fecha o arquivo
	
	file = fopen(arquivo, "a");					//acessa o arquivo
	fprintf(file, ", ");						//atualiza o arquivo com dados adicionais
	fclose(file);								//fecha o arquivo
	
	printf("Digite o cargo a ser cadastrado: ");//coleta informa��o do usu�rio para o sistema
	scanf("%39s",cargo);							//%s refere-se a string
	
	file = fopen(arquivo, "a");					//acessa o arquivo
	fprintf(file,cargo);						//atualiza o arquivo com dados adicionais
	fclose(file);								//fecha o arquivo
	
	system("pause");							//pausa para o usuario
		
}

int consulta()									//Fun��o respons�vel por consultar dados de usuarios no sistema
{
	setlocale(LC_ALL, "portuguese");			//Definindo linguagem
												//definindo variaveis/strings utilizadas
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF a ser consultado: ");	//coleta informa��o do usu�rio para a consulta no sistema
	scanf("%39s", cpf);							//%s refere-se a string
	system("cls");								//limpa tela anterior para o usu�rio
	
	FILE *file;									//acessa arquivo
	file = fopen(cpf,"r");						//abre e l� o arquivo
	
	if(file == NULL)							//Definindo par�metros quando o arquivo n�o for encontrado 
	{
		printf("\nDados n�o foram localizados, usu�rio n�o existe!\n");//mensagem de retorno para usuario, quando dados n�o s�o encontrados
	}
	
	while(fgets(conteudo, 200, file) != NULL)	//Definindo para exibir ao usu�rio os dados encontrados
	{
		printf("\nEssas s�o as informa��es do usu�rio:");//mensagem exibida ao usu�rio
		printf("\n%199s", conteudo);			//dados buscados pelo usuario sendo exibido
		printf("\n\n");							//meramente est�tico
	}

	system("pause");							//pausa no sistema para o usuario
}

int deletar()									//Fun��o respons�vel por deletar as informa��es de usu�rios no sistema
{
	setlocale(LC_ALL, "portuguese");			//Definindo linguagem
												//definindo variaveis/strings utilizadas
	char cpf[40];
	
	printf("Digite o CPF do usu�rio a ser deletado: ");//Coletando dados do usu�rio a ser deletado
	scanf("%39s",cpf);							//%s refere-se a string

	remove(cpf);								//remove usu�rio digitado do sistema
	
	FILE *file;									//acessa o arquivo
	file = fopen(cpf,"r");						//abre e l� o arquivo
	
	if(file == NULL);							//Definindo mensagem ao usu�rio, quando dados n�o s�o encontrados
	{
		printf("\nDados n�o foram localizados, usu�rio n�o existe!\nUsu�rio deletado com sucesso!\n");//mensagem exibida ao usu�rio
		system("pause");						//pausa no sistema
	}
}

int main()										//Fun��o principal
{
	int opcao=0; 								//definindo vari�vel
	int laco=1;
	
	for(laco = 1; laco <= 10; laco++)
	{
	
		system("cls");
	
		setlocale(LC_ALL, "portuguese"); 		//Definindo linguagem
	
		printf("\n ### Cart�rio da EBAC ###\n\n");//inicio do menu
		printf("Escolha a op��o desejada do menu:\n\n");
		printf("\t1 - Registrar nomes\n");
		printf("\t2 - Consultar nomes\n");
		printf("\t3 - Excluir nomes\n");
		printf("\n\n Op��o:  "); 				//fim do menu
	
		scanf("%d", &opcao); 					//armazenando a escolha do usuario
	
		system("cls");
	
	 	switch(opcao)							//definindo os parametros e as op��es do menu
	 	{
	 		case 1:
	 		registro();
			break;
			
			case 2:
	 		consulta();
			break;
			
			case 3:
	 		deletar();
			break;
			
			default:
	 		printf("Voc� escolheu uma op��o invalida, por favor escolha uma op��o do menu.\n");//mensagem exibida ao usu�rio, caso escolha uma op��o invalida
			system("pause");
			break;	
		}
	}
 }
