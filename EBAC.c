#include <stdio.h> 								//biblioteca de comunicação com o usuário
#include <stdlib.h>								//biblioteca de alocação de espaço em memória
#include <locale.h> 							//biblioteca de alocações de texto por região

int registro() 									//Função responsável por cadastrar os usuarios no sistema
{
	setlocale(LC_ALL, "portuguese"); 			//Definindo linguagem
												//inicio criação de variáveis/strings
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	
	printf("Digite o CPF a ser cadastrado: ");  //coleta informação do usuário para o sistema
	scanf("%39s", cpf); 							//%s refere-se a string
	
	strcpy(arquivo, cpf); 						//Responsável por copiar os valores das strings
	
	FILE *file; 								//cria arquivo
	file = fopen(arquivo, "w"); 				//cria o arquivo
	fprintf(file,cpf); 							//salva o valor da variavel
	fclose(file); 								//fecha o arquivo
	
	file = fopen(arquivo, "a");					//acessa o arquivo
	fprintf(file, ", ");						//atualiza o arquivo com dados adicionais
	fclose(file);								//fecha arquivo
	
	printf("Digite o nome a ser cadastrado: "); //coleta informação do usuário para o sistema
	scanf("%39s",nome);							//%s refere-se a string
	
	file = fopen(arquivo, "a");					//acessa o arquivo
	fprintf(file,nome);							//atualiza o arquivo com dados adicionais
	fclose(file);								//fecha o arquivo
	
	file = fopen(arquivo, "a");					//acessa o arquivo
	fprintf(file, ", ");						//atualiza o arquivo com dados adicionais
	fclose(file);								//fecha o arquivo
	
	printf("Digite o sobrenome a ser cadastrado: ");//coleta informação do usuário para o sistema
	scanf("%39s",sobrenome);						//%s refere-se a string
	
	file = fopen(arquivo, "a");					//acessa o arquivo
	fprintf(file,sobrenome);					//atualiza o arquivo com dados adicionais
	fclose(file);								//fecha o arquivo
	
	file = fopen(arquivo, "a");					//acessa o arquivo
	fprintf(file, ", ");						//atualiza o arquivo com dados adicionais
	fclose(file);								//fecha o arquivo
	
	printf("Digite o cargo a ser cadastrado: ");//coleta informação do usuário para o sistema
	scanf("%39s",cargo);							//%s refere-se a string
	
	file = fopen(arquivo, "a");					//acessa o arquivo
	fprintf(file,cargo);						//atualiza o arquivo com dados adicionais
	fclose(file);								//fecha o arquivo
	
	system("pause");							//pausa para o usuario
		
}

int consulta()									//Função responsável por consultar dados de usuarios no sistema
{
	setlocale(LC_ALL, "portuguese");			//Definindo linguagem
												//definindo variaveis/strings utilizadas
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF a ser consultado: ");	//coleta informação do usuário para a consulta no sistema
	scanf("%39s", cpf);							//%s refere-se a string
	system("cls");								//limpa tela anterior para o usuário
	
	FILE *file;									//acessa arquivo
	file = fopen(cpf,"r");						//abre e lê o arquivo
	
	if(file == NULL)							//Definindo parâmetros quando o arquivo não for encontrado 
	{
		printf("\nDados não foram localizados, usuário não existe!\n");//mensagem de retorno para usuario, quando dados não são encontrados
	}
	
	while(fgets(conteudo, 200, file) != NULL)	//Definindo para exibir ao usuário os dados encontrados
	{
		printf("\nEssas são as informações do usuário:");//mensagem exibida ao usuário
		printf("\n%199s", conteudo);			//dados buscados pelo usuario sendo exibido
		printf("\n\n");							//meramente estético
	}

	system("pause");							//pausa no sistema para o usuario
}

int deletar()									//Função responsável por deletar as informações de usuários no sistema
{
	setlocale(LC_ALL, "portuguese");			//Definindo linguagem
												//definindo variaveis/strings utilizadas
	char cpf[40];
	
	printf("Digite o CPF do usuário a ser deletado: ");//Coletando dados do usuário a ser deletado
	scanf("%39s",cpf);							//%s refere-se a string

	remove(cpf);								//remove usuário digitado do sistema
	
	FILE *file;									//acessa o arquivo
	file = fopen(cpf,"r");						//abre e lê o arquivo
	
	if(file == NULL);							//Definindo mensagem ao usuário, quando dados não são encontrados
	{
		printf("\nDados não foram localizados, usuário não existe!\nUsuário deletado com sucesso!\n");//mensagem exibida ao usuário
		system("pause");						//pausa no sistema
	}
}

int main()										//Função principal
{
	int opcao=0; 								//definindo variável
	int laco=1;
	
	for(laco = 1; laco <= 10; laco++)
	{
	
		system("cls");
	
		setlocale(LC_ALL, "portuguese"); 		//Definindo linguagem
	
		printf("\n ### Cartório da EBAC ###\n\n");//inicio do menu
		printf("Escolha a opção desejada do menu:\n\n");
		printf("\t1 - Registrar nomes\n");
		printf("\t2 - Consultar nomes\n");
		printf("\t3 - Excluir nomes\n");
		printf("\n\n Opção:  "); 				//fim do menu
	
		scanf("%d", &opcao); 					//armazenando a escolha do usuario
	
		system("cls");
	
	 	switch(opcao)							//definindo os parametros e as opções do menu
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
	 		printf("Você escolheu uma opção invalida, por favor escolha uma opção do menu.\n");//mensagem exibida ao usuário, caso escolha uma opção invalida
			system("pause");
			break;	
		}
	}
 }
