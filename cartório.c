#include <stdlib.h> //biblioteca de comunica��o com o usu�rio
#include <locale.h> //biblioteca de aloca��o de espa�o em mem�ria
#include <stdio.h> //biblioteca de aloca��es de texto por regi�o
#include <string.h> //biblioteca respons�vel por cuidar das string



int registro() //fun��o que cadastra os �suarios no sistema
{  
    //in�cio das parte onde cria as vari�veis/strings (conjunto de vari�veis)
    char arquivo[40];
    char cpf[40];
    char nome[40];
    char sobrenome[40];
    char cargo[40];
    //final das parte onde cria as vari�veis/strings (conjunto de vari�veis)
    
    printf("digite o cpf a ser cadastrado: "); //coleta de dados do usu�rio
    scanf("%s", cpf); // "%s" = string (armazenamento)

   strcpy(arquivo, cpf); //responsavel por copiar os valores das string

   FILE *file; //cria o arquivo
   file = fopen(arquivo, "w"); // cria o arquivo "w" = write(ESCREVER)
   fprintf(file,cpf); // salva o valor da variavel
   fclose(file); // fecha o arquivo

   file = fopen(arquivo, "a");
   fprintf(file,",");
   fclose(file);

   printf("digite o nome que ira ser cadastrado: ");
   scanf("%s", nome);

   file = fopen(arquivo,"a");
   fprintf(file,nome);
   fclose(file);

   file = fopen(arquivo,"a");
   fprintf(file, ",");
   fclose(file);

   printf("digite o sobrenome a ser cadastrado: ");
   scanf("%s", sobrenome);

   file = fopen(arquivo,"a");
   fprintf(file,sobrenome);
   fclose(file);

   file = fopen(arquivo,"a");
   fprintf(file,",");
   fclose(file);

   printf("digite o cargo a ser cadastrado: ");
   scanf("%s",cargo);
   
   file = fopen(arquivo, "a");
   fprintf(file,cargo);
   fclose(file);
  
   system("pause");
}

int consulta ()
{
	setlocale(LC_ALL, "portuguese"); // definindo a linguagem
	
    char cpf[40];
    char conteudo[200];

    printf("digite o cpf que ira ser consultado: ");
    scanf("%s",cpf);

    FILE *file;
    file = fopen(cpf,"r");

    if(file ==NULL)  
	{
	printf("n�o foi possivel abrir o arquivo, n�o localizado!.\n");	
	} 
	
    while(fgets(conteudo, 200, file) != NULL)
    {
    printf("\nEssas s�o as informa��oes do usu�rio: ");
    printf("%s", conteudo);
    printf("\n\n");
	}
	
	system("pause");
}

int deletar()
{
    char cpf[40];
    
    printf("digite o CPF que ir� ser deletado: ");
    scanf("%s", cpf); // "%s" = string (ler o armazenamento)
    
    
    FILE *file;
    file = fopen(cpf, "r"); // "r" = read (ler)
    fclose(file);
    
    if (file == NULL)
    {
      printf("o usu�rio nao foi encontrado no sistema!.\n");
      system("pause");
	}
	else
	{
	
	if(remove(cpf) == 0)
	{
	printf("o arquivo foi deletado com sucesso!\n");
	system("pause");
	}
    
	}

}


int main()
   {
    int opcao=0; //definindo as vari�veis
    int laco=1;

    for(laco=1;laco=1;)
    {
     
      system("cls");

      setlocale(LC_ALL, "portuguese"); //definindo a linguagem

      printf("###cartorio da EBAC ###\n\n"); //inicio do menu
      printf("Escolha a op��o desejada do menu\n\n");
      printf("\t1 - Registrar nomes\n");
      printf("\t2 - Consultar nomes\n");
      printf("\t3 - Deletar nomes\n");
      printf("\t4 - sair do sitema\n\n");
      printf("op��o: "); // final do menu
      
      scanf("%d" , &opcao); //armazenamento a esolha do �suario 

      system("cls"); //responsavel por limpar a tela

      switch (opcao) //in�cio da sele��o das op��es
      {
      case 1:
      registro(); //chamada de fun��es
        system("pause");
        break;
      
      case 2:
      consulta(); //chamada de fun��es
        system("pause");
        break;

      case 3:
      deletar(); //chamada de fun��es
        system("pause");
		break;
		
      case 4:
      printf("obrigado por utilizar nosso sistema!");
        return 0;
		break;
	
		
       default:
        printf("essa op��o n�o est� disponivel!\n");
        system("pause");
        break;
        // fim das sele��es
      }

    }

   }
