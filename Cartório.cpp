#include <stdio.h> //biblioteca de comunicação
#include <stdlib.h> //biblioteca de alocação de espaço em memória
#include <locale.h> //biblioteca de alocaçõa de texto de região
#include <string.h> //biblioteca responsavel por cuidar das string

int registro() //Função responsável por cadastrar os usuários no sistema
{
	//inicio criação de variáveis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final da criação de variáveis/string
	
	printf("Digite o CPF a ser cadastrado: "); //coletando informação de usuário
	scanf("%s", cpf); //armazenando o valr na string, %s refere-se a string
	
	strcpy(arquivo, cpf); //responsável por criar os valores das string
	
	FILE *file; //cria o arquivo
	file = fopen(arquivo, "w"); //cria o arquivo, "W" significa escrever
	fprintf(file,cpf); //salva o valor da variavel
	fclose(file); //fecha o arqivo
	
	file = fopen(arquivo, "a"); //abre um arquivo criado, o "A" significa atualizar a informação
	fprintf(file,","); // salvar uma informação, a "," foi o que incluiu
	fclose(file); //fechar arquivo
	
	printf("Digite o nome a ser cadastrado: "); //coletando informação de usuário
	scanf("%s",nome); //armazenando o valor na string, %s refere-se a string
	
	file = fopen(arquivo, "a"); //abrir e atualizar um arquivo
	fprintf(file,nome); // salvando a variavel nome dentro do arquivo
	fclose(file); //fechar arquivo
	
	file = fopen(arquivo, "a"); //abrir e atualizar um arquivo
	fprintf(file,","); // salvar uma informação, a "," foi o que incluiu
	fclose(file); //fecha arquivo
	
	printf("Digite o sobrenome a ser cadastrado: "); //coletando informação de usuário
	scanf("%s",sobrenome); //armazenando o valor na string, %s refere-se a string
	
	file = fopen(arquivo, "a"); //abrir e atualizar um arquivo
	fprintf(file,sobrenome); // salvando a variavel nome dentro do arquivo
	fclose(file); //fechar arquivo
	
	file = fopen(arquivo, "a"); //abrir e atualizar um arquivo
	fprintf(file,","); // salvar uma informação, a "," foi o que incluiu
	fclose(file); //fechar arquivo
	
	printf("Digite o cargo a ser cadastrado: "); //coletando informação de usuário
	scanf("%s",cargo); //armazenando o valor na string, %s refere-se a string
	
	file = fopen(arquivo, "a"); //abrir e atualizar um arquivo
	fprintf(file,cargo);  // salvando a variavel nome dentro do arquivo
	fclose(file); //fecha o arquivo
	
	system("pause");
	
	


}

int consulta()
{
	setlocale(LC_ALL, "Portuguese"); //Definindo linguagem
	
	//inicio criação de variáveis/string
	char cpf[40]; 
	char conteudo [200];
	//final da criação de variáveis/string
	
	printf("Digite o CPF a ser consultado: "); //coletando informação de usuário
	scanf("%s",cpf); //armazenando o valor na string, %s refere-se a string
	
	FILE *file; //cria o arquivo
	file = fopen(cpf,"r"); //abrir o arquivo, "R" significa ler o arquivo
	
	if(file == NULL) //validação do arquivo
	{
		printf("Não foi possivel abrir o arquivo, não localizado!.\n"); //informação para o usuário
	}
	
	while(fgets(conteudo, 200, file) != NULL)  //validação do arquivo
	{
		printf("\nEssas são as informações do usuário: "); //informação para o usuário
		printf("%s", conteudo); //salvar o conteudo dentro da string
		printf("\n\n"); //pular linha, "\n" significa pular linha
	}
	
	system("pause");
	
	
}

int deletar()
{
	//inicio criação de variáveis/string
	char cpf[40];
	//final da criação de variáveis/string
	
	printf("Digite o CPF do usuário a ser deletado: ");//coletando informação de usuário
	scanf("%s",cpf); //armazenando o valor na string, %s refere-se a string
	
	remove(cpf); //remover arquivo
	
	FILE *file; //criando arquivo
	file = fopen(cpf,"r"); //abrir o arquivo, "R" significa ler o arquivo
	
	if(file == NULL) //validação do arquivo
	{
		printf("O usuário não se encontra no sistema!.\n"); //informação para o usuário
		system("pause");
	}
	
}


int main()
{
	int opcao=0; //Definindo variáveis
	int laco=1;
	
	for(laco=1;laco=1;)
	{
		
		system("cls"); //responsável por limpar a tela
		
		setlocale(LC_ALL, "Portuguese"); //Definindo linguagem
	
		printf("## cartório da EBAC ##\n\n"); //Inicio do menu
		printf("Escolha opção desejada do menu:\n\n");
		printf("\t1 - registrar nomes\n");
		printf("\t2 - consutar nomes\n");
		printf("\t3 - deletar nomes\n\n"); 
		printf("Opção: "); //Fim do menu
	
		scanf("%d", &opcao); //armazenando a escolha do usuário
	
		system("cls"); //responsável por limpar a tela
		
		
		switch(opcao)  //inicio da seleção do menu
		{
			case 1:
			registro(); //chamada de funções
			break;
			
			case 2:
			consulta();
			break;
			
			case 3:
			deletar();
			break;
			

			
			default:
			printf("Essa opção não está disponivel!\n");
			system("pause");
			break;
		}
	
	}
}
