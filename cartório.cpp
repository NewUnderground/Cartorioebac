 #include <stdio.h> //bibloteca de comunicação com usuário
#include <stdlib.h> //biblioteca de alocação de espaço em memória
#include <locale.h> //biblioteca de alocações de texto por região
#include <string.h> //biblioteca responsável por cuidar das string

int registro()
{
    char arquivo[40];
	char cpf[15];
    char nome[20];
    char sobrenome[40];
    char cargo[40];
    
    printf("Digite seu CPF a se cadastrado:");
    scanf("%s", cpf);
    
    strcpy(arquivo, cpf); //Responsável por copiar os valores das string
    
    FILE *file; //Cria o arquivo
    file = fopen(arquivo, "w"); //cria o arquivo e o "w" significa escrever.
    fprintf(file,cpf); //Salva o valor da variável, exibe os valores do arquivo
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
		printf("Não foi possível abrir o arquivo, não localizado!. \n");
	}
	
	while(fgets(conteudo, 200, file)  != NULL)
	{
		printf("\n Essas são as informações do usuário: \n ");
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
		printf("O usuário não se encontra no sistema!\n");
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
	
	printf("###Cartório da Ebac###\n\n"); 
	printf("Escolha a opção desejada do menu:\n\n"); //Início do menu
	printf("\t 1 - Registrar aluno \n");
	printf("\t 2 - consultar aluno \n");
	printf("\t 3 - Deletar aluno?  \n");  
	printf("\t 4 - sair do sistema \n");
	printf("Selecione uma opção:"); //Fim do programa
    
    scanf("%d", &opcao);  //Armazenando as escolhas do usuário
    
	system("cls"); 
	
	switch(opcao)
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
	    
	    case 4:
	    printf("Obrigado por ultilizar o sistema de registro EBAC. \n");
	    return 0;
	    break;
	    	
	    
	    default:
	    printf("Essa opção não está disponível\n");   
		system("pause");
		break;//Fim da seleção
	}
	    while (opcao != 4);

        return 0;
    }
}
