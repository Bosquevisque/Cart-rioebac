#include <stdio.h> //biblioteca de comunica��o
#include <stdlib.h> //biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> //biblioteca de aloca��a de texto de regi�o
#include <string.h> //biblioteca responsavel por cuidar das string

int registro() //Fun��o respons�vel por cadastrar os usu�rios no sistema
{
	//inicio cria��o de vari�veis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final da cria��o de vari�veis/string
	
	printf("Digite o CPF a ser cadastrado: "); //coletando informa��o de usu�rio
	scanf("%s", cpf); //armazenando o valr na string, %s refere-se a string
	
	strcpy(arquivo, cpf); //respons�vel por criar os valores das string
	
	FILE *file; //cria o arquivo
	file = fopen(arquivo, "w"); //cria o arquivo, "W" significa escrever
	fprintf(file,cpf); //salva o valor da variavel
	fclose(file); //fecha o arqivo
	
	file = fopen(arquivo, "a"); //abre um arquivo criado, o "A" significa atualizar a informa��o
	fprintf(file,","); // salvar uma informa��o, a "," foi o que incluiu
	fclose(file); //fechar arquivo
	
	printf("Digite o nome a ser cadastrado: "); //coletando informa��o de usu�rio
	scanf("%s",nome); //armazenando o valor na string, %s refere-se a string
	
	file = fopen(arquivo, "a"); //abrir e atualizar um arquivo
	fprintf(file,nome); // salvando a variavel nome dentro do arquivo
	fclose(file); //fechar arquivo
	
	file = fopen(arquivo, "a"); //abrir e atualizar um arquivo
	fprintf(file,","); // salvar uma informa��o, a "," foi o que incluiu
	fclose(file); //fecha arquivo
	
	printf("Digite o sobrenome a ser cadastrado: "); //coletando informa��o de usu�rio
	scanf("%s",sobrenome); //armazenando o valor na string, %s refere-se a string
	
	file = fopen(arquivo, "a"); //abrir e atualizar um arquivo
	fprintf(file,sobrenome); // salvando a variavel nome dentro do arquivo
	fclose(file); //fechar arquivo
	
	file = fopen(arquivo, "a"); //abrir e atualizar um arquivo
	fprintf(file,","); // salvar uma informa��o, a "," foi o que incluiu
	fclose(file); //fechar arquivo
	
	printf("Digite o cargo a ser cadastrado: "); //coletando informa��o de usu�rio
	scanf("%s",cargo); //armazenando o valor na string, %s refere-se a string
	
	file = fopen(arquivo, "a"); //abrir e atualizar um arquivo
	fprintf(file,cargo);  // salvando a variavel nome dentro do arquivo
	fclose(file); //fecha o arquivo
	
	system("pause");
	
	


}

int consulta()
{
	setlocale(LC_ALL, "Portuguese"); //Definindo linguagem
	
	//inicio cria��o de vari�veis/string
	char cpf[40]; 
	char conteudo [200];
	//final da cria��o de vari�veis/string
	
	printf("Digite o CPF a ser consultado: "); //coletando informa��o de usu�rio
	scanf("%s",cpf); //armazenando o valor na string, %s refere-se a string
	
	FILE *file; //cria o arquivo
	file = fopen(cpf,"r"); //abrir o arquivo, "R" significa ler o arquivo
	
	if(file == NULL) //valida��o do arquivo
	{
		printf("N�o foi possivel abrir o arquivo, n�o localizado!.\n"); //informa��o para o usu�rio
	}
	
	while(fgets(conteudo, 200, file) != NULL)  //valida��o do arquivo
	{
		printf("\nEssas s�o as informa��es do usu�rio: "); //informa��o para o usu�rio
		printf("%s", conteudo); //salvar o conteudo dentro da string
		printf("\n\n"); //pular linha, "\n" significa pular linha
	}
	
	system("pause");
	
	
}

int deletar()
{
	//inicio cria��o de vari�veis/string
	char cpf[40];
	//final da cria��o de vari�veis/string
	
	printf("Digite o CPF do usu�rio a ser deletado: ");//coletando informa��o de usu�rio
	scanf("%s",cpf); //armazenando o valor na string, %s refere-se a string
	
	remove(cpf); //remover arquivo
	
	FILE *file; //criando arquivo
	file = fopen(cpf,"r"); //abrir o arquivo, "R" significa ler o arquivo
	
	if(file == NULL) //valida��o do arquivo
	{
		printf("O usu�rio n�o se encontra no sistema!.\n"); //informa��o para o usu�rio
		system("pause");
	}
	
}


int main()
{
	int opcao=0; //Definindo vari�veis
	int laco=1;
	
	for(laco=1;laco=1;)
	{
		
		system("cls"); //respons�vel por limpar a tela
		
		setlocale(LC_ALL, "Portuguese"); //Definindo linguagem
	
		printf("## cart�rio da EBAC ##\n\n"); //Inicio do menu
		printf("Escolha op��o desejada do menu:\n\n");
		printf("\t1 - registrar nomes\n");
		printf("\t2 - consutar nomes\n");
		printf("\t3 - deletar nomes\n\n"); 
		printf("Op��o: "); //Fim do menu
		printf("\t4 - Sair do sistema\n\n");
		
		
		scanf("%d", &opcao); //armazenando a escolha do usu�rio
	
		system("cls"); //respons�vel por limpar a tela
		
		
		switch(opcao)  //inicio da sele��o do menu
		{
			case 1:
			registro(); //chamada de fun��es
			break;
			
			case 2:
			consulta();
			break;
			
			case 3:
			deletar();
			break;
			
			case 4:
			printf("Obrigado por utilizar o sistema\n");
			return 0;
			break;

			
			default:
			printf("Essa op��o n�o est� disponivel!\n");
			system("pause");
			break;
		}
	
	}
}
