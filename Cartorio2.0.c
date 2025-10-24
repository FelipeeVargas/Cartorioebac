#include <stdio.h>  //blioblioteca de comunicação com o usuário
#include <stdlib.h> //bliblioteca de alocação de memõria
#include <locale.h> //bliblioteca de alocações de texto por região
#include <string.h> //biblioteca responsável por cuidar das string

int registro() //função responsável por cadastrar os usuários no sitema
{
	//início da criação de variáveis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final da criação de variáveis/string
	
	printf("Digite o CPF a ser cadastrado: "); //coletando informação do usuário
	scanf("%s", cpf); //%s refere-se a string
	
	strcpy(arquivo, cpf);  //Responsável por copiar os valores das string
	
	FILE *file;  //cria o arquivo
	file = fopen(arquivo, "w"); //cria o arquivo e o "w" significa escrever
	fprintf(file, cpf);  //salvo o valor da variável
	fclose(file);  //fecha o arquivo
	
	file = fopen(arquivo, "a"); //abre o arquivo e o "a" significa atualizar o arquivo
	fprintf(file, ",");  //adiciona uma vírgula
	fclose(file); //fecha o arquivo
	
	printf("Digite o nome a ser cadastrado: "); //coletando informações do usuário
	scanf("%s", nome); //salvando a informação
	
	file = fopen(arquivo, "a"); //abre e atualiza o arquivo
	fprintf(file, nome); //salva o valor da varíavel
	fclose(file);  //fecha o arquivo
	
	file = fopen(arquivo, "a"); //abre e atualiza o arquivo
	fprintf(file, ","); //adiciona uma vírgula
	fclose(file);  //fecha o arquivo
	
	printf("Digite o sobrenome a ser cadastrado: ");  //coletando informações do usuário
	scanf("%s", sobrenome); //salvando a informação
	
	file = fopen(arquivo, "a");  //abre e atualiza o arquivo
	fprintf(file, sobrenome);  //salva o valor da variável
	fclose(file);  //fecha o arquivo
	
	file = fopen(arquivo, "a");  //abre e atualiza o arquivo
	fprintf(file, ",");  //adiciona uma vírgula
	fclose(file);  //fecha o arquivo
	
	printf("Digite o cargo a ser cadastrado: ");  //coletando informações do usuário
	scanf("%s", cargo);  //salvando a informação
	
	file = fopen(arquivo, "a");  //abre e atualiza o arquivo
	fprintf(file, cargo);  //salvando o valor da variável
	fclose(file);  //fecha o arquivo
	
	system("pause"); //pausa o sistema
}

int consulta()
{
	setlocale(LC_ALL,"Portuguese");  //definindo a linguagem
	
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF a ser consultado: ");  //coletando as informações do usuário
	scanf("%s", cpf);  //salva a informação
	
	FILE *file;  //cria o arquivo
	file = fopen(cpf,"r"); //abre o arquivo e o "r" lê 
	
	if(file == NULL) //if = se, cria uma variável
	{
		printf("Não foi possível abrir o arquivo, não localizado!. \n"); //informa a resposta ao usuário
	}
	
	while(fgets(conteudo, 200, file) != NULL) 
	{
		printf("\n Essas são as informações do usuário: ");
		printf("%s", conteudo);
		printf("\n\n");
	}	
	
	system("pause");
	
}

int deletar()
{
	char cpf [40];
	
	printf("Digite o CPF do usuário a ser deletado: ");
	scanf("%s", cpf);
	
	
	FILE *file;
	file = fopen(cpf, "r");
	fclose(file);
	
	if(file == NULL)
	{
		printf("\nO usúario não se encontra no sistema!. \n");
		system("pause");
	}
	
	else
	{
	remove(cpf);
	printf("\nO CPF do usuário foi deletado com sucesso!\n");
	system("pause");
	}

}


int main()
{
	int opcao=0; //definindo variáveis
	int laco=1;
	
	for(laco=1;laco=1;)
	{
	
		system("cls");
	
		setlocale(LC_ALL,"Portuguese");  //definindo a linguagem
	
		printf("### Cartório da EBAC ### \n\n");  //início do menu
		printf("Escolha a opção desejada do menu:\n\n");
		printf("\t 1- Registrar nomes \n");
		printf("\t 2- Consultar nomes \n");
		printf("\t 3- Deletar nomes \n");  
		printf("\t 4- Sair do sistema\n\n");
		printf("Opção: ");  //fim do menu
		
		scanf("%d", &opcao ); //armazenando a escolha do usúario
	
		system("cls");  //responsável por limpar a tela
		
		switch(opcao)  //início da seleção do menu
		{
			case 1:
			registro();  //chamada de funções
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
			printf("Está opção não está disponivel!\n");
			system("pause");
			break;
				
		} //fim da seleção
		
	}
}


