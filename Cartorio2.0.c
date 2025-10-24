#include <stdio.h>  //blioblioteca de comunica��o com o usu�rio
#include <stdlib.h> //bliblioteca de aloca��o de mem�ria
#include <locale.h> //bliblioteca de aloca��es de texto por regi�o
#include <string.h> //biblioteca respons�vel por cuidar das string

int registro() //fun��o respons�vel por cadastrar os usu�rios no sitema
{
	//in�cio da cria��o de vari�veis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final da cria��o de vari�veis/string
	
	printf("Digite o CPF a ser cadastrado: "); //coletando informa��o do usu�rio
	scanf("%s", cpf); //%s refere-se a string
	
	strcpy(arquivo, cpf);  //Respons�vel por copiar os valores das string
	
	FILE *file;  //cria o arquivo
	file = fopen(arquivo, "w"); //cria o arquivo e o "w" significa escrever
	fprintf(file, cpf);  //salvo o valor da vari�vel
	fclose(file);  //fecha o arquivo
	
	file = fopen(arquivo, "a"); //abre o arquivo e o "a" significa atualizar o arquivo
	fprintf(file, ",");  //adiciona uma v�rgula
	fclose(file); //fecha o arquivo
	
	printf("Digite o nome a ser cadastrado: "); //coletando informa��es do usu�rio
	scanf("%s", nome); //salvando a informa��o
	
	file = fopen(arquivo, "a"); //abre e atualiza o arquivo
	fprintf(file, nome); //salva o valor da var�avel
	fclose(file);  //fecha o arquivo
	
	file = fopen(arquivo, "a"); //abre e atualiza o arquivo
	fprintf(file, ","); //adiciona uma v�rgula
	fclose(file);  //fecha o arquivo
	
	printf("Digite o sobrenome a ser cadastrado: ");  //coletando informa��es do usu�rio
	scanf("%s", sobrenome); //salvando a informa��o
	
	file = fopen(arquivo, "a");  //abre e atualiza o arquivo
	fprintf(file, sobrenome);  //salva o valor da vari�vel
	fclose(file);  //fecha o arquivo
	
	file = fopen(arquivo, "a");  //abre e atualiza o arquivo
	fprintf(file, ",");  //adiciona uma v�rgula
	fclose(file);  //fecha o arquivo
	
	printf("Digite o cargo a ser cadastrado: ");  //coletando informa��es do usu�rio
	scanf("%s", cargo);  //salvando a informa��o
	
	file = fopen(arquivo, "a");  //abre e atualiza o arquivo
	fprintf(file, cargo);  //salvando o valor da vari�vel
	fclose(file);  //fecha o arquivo
	
	system("pause"); //pausa o sistema
}

int consulta()
{
	setlocale(LC_ALL,"Portuguese");  //definindo a linguagem
	
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF a ser consultado: ");  //coletando as informa��es do usu�rio
	scanf("%s", cpf);  //salva a informa��o
	
	FILE *file;  //cria o arquivo
	file = fopen(cpf,"r"); //abre o arquivo e o "r" l� 
	
	if(file == NULL) //if = se, cria uma vari�vel
	{
		printf("N�o foi poss�vel abrir o arquivo, n�o localizado!. \n"); //informa a resposta ao usu�rio
	}
	
	while(fgets(conteudo, 200, file) != NULL) 
	{
		printf("\n Essas s�o as informa��es do usu�rio: ");
		printf("%s", conteudo);
		printf("\n\n");
	}	
	
	system("pause");
	
}

int deletar()
{
	char cpf [40];
	
	printf("Digite o CPF do usu�rio a ser deletado: ");
	scanf("%s", cpf);
	
	
	FILE *file;
	file = fopen(cpf, "r");
	fclose(file);
	
	if(file == NULL)
	{
		printf("\nO us�ario n�o se encontra no sistema!. \n");
		system("pause");
	}
	
	else
	{
	remove(cpf);
	printf("\nO CPF do usu�rio foi deletado com sucesso!\n");
	system("pause");
	}

}


int main()
{
	int opcao=0; //definindo vari�veis
	int laco=1;
	
	for(laco=1;laco=1;)
	{
	
		system("cls");
	
		setlocale(LC_ALL,"Portuguese");  //definindo a linguagem
	
		printf("### Cart�rio da EBAC ### \n\n");  //in�cio do menu
		printf("Escolha a op��o desejada do menu:\n\n");
		printf("\t 1- Registrar nomes \n");
		printf("\t 2- Consultar nomes \n");
		printf("\t 3- Deletar nomes \n");  
		printf("\t 4- Sair do sistema\n\n");
		printf("Op��o: ");  //fim do menu
		
		scanf("%d", &opcao ); //armazenando a escolha do us�ario
	
		system("cls");  //respons�vel por limpar a tela
		
		switch(opcao)  //in�cio da sele��o do menu
		{
			case 1:
			registro();  //chamada de fun��es
			break;
			
			case 2:
			consulta();
			break;
			
			case 3:
			deletar();
			break;
			
			case 4:
			printf("Obrigado por utilizar o sistema!\n");
			return 0;
			break;
			
			default:
			printf("Est� op��o n�o est� disponivel!\n");
			system("pause");
			break;
				
		} //fim da sele��o
		
	}
}


