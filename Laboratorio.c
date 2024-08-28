#include <stdio.h> //biblioteca de comunica��o cokm o usuario 
#include <stdlib.h> //biblioteca de aloca��o de espa�o em memoria 
#include <locale.h> //biblioteca de aloca��es de texto por regi�o
#include <string.h> //biblioteca responsavel por cuidar das string

int registro() //responsavel por cadastrar 
{
	//inicio cria��o de variavel/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final da cria��o
	
	printf("Digite o CPF a ser cadastro: "); //colata de informa��o 
	scanf("%s", cpf); 
	
	strcpy(arquivo, cpf); //responsavel por copia os valores de string
	
	FILE *file; //cria o arquivo
	file = fopen(arquivo, "w"); //cria o arquivo
	fprintf(file,cpf); //salva o valor da variavel
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("digite o nome a ser cadastrado: ");
	scanf("%s",nome);
	
	file = fopen(arquivo, "a");
	fprintf(file,nome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("digite o sobrenome a ser cadastrado: ");
	scanf("%s",sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("digite o cargo a ser cadastrado: ");
	scanf("%s",cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file,cargo);
	fclose(file);

	system("pause");
	
	}

int consulta()
{
	setlocale(LC_ALL, "portuguese");  //definindo a linguaguem 
	
	char cpf[40];
	char conteudo[200];
	
	printf("digite o cpf a ser consultado: ");
    scanf ("%s",cpf);
    
    FILE *file;
    file = fopen(cpf,"r");
    
    if(file == NULL)
    {
    	printf("CPF n�o localizado!.\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\nessas s�o as informa��es do usuario: ");
		printf("%s", conteudo);
		printf("\n\n");
		}
		
		system("pause");
		
		
}

int deletar()
{
	char cpf[40];
	
	printf("digite o cpf a ser cancelado: ");
	scanf("%s",cpf);
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("O usuario n�o existe!.\n");
		system("pause");
	}
}


int main()
{
	int opcao=0; //definindo variaveis
	int laco=1;
	
	for(laco=1;laco=1;)
	{
		
		system("cls");
			
	setlocale(LC_ALL, "portuguese"); //definindo a linguaguem
	
	printf("### Cart�rio do Laboratorio ###\n\n"); //inicio do menu
	printf("Escolha a op��o desejada do menu \n\n");
	printf("\t1 - Registrar produto nomes\n");
	printf("\t2 - Consultar produto nomes\n");
	printf("\t3 - Deletar produto nomes \n"); 
	printf("Op��o: "); //fim do menu
	
	scanf("%d", &opcao); //armazenamento de scolha do usuario
	
	system("cls"); //responsavel por limpa a tela
	
	
	switch(opcao)
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
		
		
		default:
		printf("op��o n�o disponivel");
		system ("pause");
		break;
		
		
	} //fim da sele��o
	
	
	
    }

}
