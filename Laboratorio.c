#include <stdio.h> //biblioteca de comunicação cokm o usuario 
#include <stdlib.h> //biblioteca de alocação de espaço em memoria 
#include <locale.h> //biblioteca de alocações de texto por região
#include <string.h> //biblioteca responsavel por cuidar das string

int registro() //responsavel por cadastrar 
{
	//inicio criação de variavel/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final da criação
	
	printf("Digite o CPF a ser cadastro: "); //colata de informação 
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
    	printf("CPF não localizado!.\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\nessas são as informações do usuario: ");
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
		printf("O usuario não existe!.\n");
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
	
	printf("### Cartório do Laboratorio ###\n\n"); //inicio do menu
	printf("Escolha a opção desejada do menu \n\n");
	printf("\t1 - Registrar produto nomes\n");
	printf("\t2 - Consultar produto nomes\n");
	printf("\t3 - Deletar produto nomes \n"); 
	printf("Opção: "); //fim do menu
	
	scanf("%d", &opcao); //armazenamento de scolha do usuario
	
	system("cls"); //responsavel por limpa a tela
	
	
	switch(opcao)
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
		
		
		default:
		printf("opção não disponivel");
		system ("pause");
		break;
		
		
	} //fim da seleção
	
	
	
    }

}
