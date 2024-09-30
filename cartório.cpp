 #include <stdio.h> //bibloteca de comunica��o com usu�rio
#include <stdlib.h> //biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> //biblioteca de aloca��es de texto por regi�o
#include <string.h> //biblioteca respons�vel por cuidar das string

int registro()
{
    char arquivo[40];
	char cpf[15];
    char nome[20];
    char sobrenome[40];
    char cargo[40];
    
    printf("Digite seu CPF a se cadastrado:");
    scanf("%s", cpf);
    
    strcpy(arquivo, cpf); //Respons�vel por copiar os valores das string
    
    FILE *file; //Cria o arquivo
    file = fopen(arquivo, "w"); //cria o arquivo e o "w" significa escrever.
    fprintf(file,cpf); //Salva o valor da vari�vel, exibe os valores do arquivo
    fclose(file); //Fecha o arquivo
    
    file = fopen(arquivo, "a"); //"a"significa atualizar o arquivo.
    fprintf(file, ",");
    fclose(file);
    
    printf("Digite o nome a ser cadastrado:");
    scanf("%s", nome);
    
    file = fopen(arquivo, "a");
    fprintf(file,nome);
    fclose(file);
    
    file = fopen(arquivo, "a");
    fprintf(file, ",");
    fclose(file);
    
    printf("Digite o sobrenome a ser cadastrado:");
    scanf("%s", sobrenome);
    
    file = fopen(arquivo, "a");
    fprintf(file,sobrenome);
    fclose(file);
    
    file = fopen(arquivo, "a");
    fprintf(file, ",");
    fclose(file);
    
    printf("Digite o cargo a ser cadastrado:");
    scanf("%s", cargo);
    
    file = fopen(arquivo, "a");
    fprintf(file,cargo);
    fclose(file);
    
    file = fopen(arquivo, "a");
    fprintf(file, ",");
    fclose(file);
    
    system("pause");
     
}


int consulta()
{
	setlocale(LC_ALL, "portuguese"); //Definindo a linguagem
	
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF a ser consultado: ");
	scanf ("%s", cpf);
	
	FILE *file;
	file = fopen(cpf, "r");
	
	if(file == NULL)
	{
		printf("N�o foi poss�vel abrir o arquivo, n�o localizado!. \n");
	}
	
	while(fgets(conteudo, 200, file)  != NULL)
	{
		printf("\n Essas s�o as informa��es do usu�rio: \n ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	system("pause");
	
}	

int deletar()
{
	char cpf[15];
	printf("Digite o Cpf a ser deletado:");
	scanf("%s",cpf);
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf, "r");
	
	if(file == NULL)
	{
		printf("O usu�rio n�o se encontra no sistema!\n");
		system("pause");
	}
}

    
int main()
    
    {
    int opcao=0; //Definindo as variaveis
    int laco=1;
	
	for (laco=1;laco=1;)
	{
	system("cls");
	
	setlocale(LC_ALL, "portuguese"); //Denifindo a linguagem
	
	printf("###Cart�rio da Ebac###\n\n"); 
	printf("Escolha a op��o desejada do menu:\n\n"); //In�cio do menu
	printf("\t 1 - Registrar aluno \n");
	printf("\t 2 - consultar aluno \n");
	printf("\t 3 - Deletar aluno?  \n");  
	printf("\t 4 - sair do sistema \n");
	printf("Selecione uma op��o:"); //Fim do programa
    
    scanf("%d", &opcao);  //Armazenando as escolhas do usu�rio
    
	system("cls"); 
	
	switch(opcao)
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
	    printf("Obrigado por ultilizar o sistema de registro EBAC. \n");
	    return 0;
	    break;
	    	
	    
	    default:
	    printf("Essa op��o n�o est� dispon�vel\n");   
		system("pause");
		break;//Fim da sele��o
	}
	    while (opcao != 4);

        return 0;
    }
}
