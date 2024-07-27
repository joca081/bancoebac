#include <stdlib.h> //biblioteca de comunicação com o usuário
#include <locale.h> //biblioteca de alocação de espaço em memória
#include <stdio.h> //biblioteca de alocações de texto por região
#include <string.h> //biblioteca responsável por cuidar das string



int registro() //função que cadastra os úsuarios no sistema
{  
    //início das parte onde cria as variáveis/strings (conjunto de variáveis)
    char arquivo[40];
    char cpf[40];
    char nome[40];
    char sobrenome[40];
    char cargo[40];
    //final das parte onde cria as variáveis/strings (conjunto de variáveis)
    
    printf("digite o cpf a ser cadastrado: "); //coleta de dados do usuário
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
	printf("não foi possivel abrir o arquivo, não localizado!.\n");	
	} 
	
    while(fgets(conteudo, 200, file) != NULL)
    {
    printf("\nEssas são as informaçãoes do usuário: ");
    printf("%s", conteudo);
    printf("\n\n");
	}
	
	system("pause");
}

int deletar()
{
    char cpf[40];
    
    printf("digite o CPF que irá ser deletado: ");
    scanf("%s", cpf); // "%s" = string (ler o armazenamento)
    
    
    FILE *file;
    file = fopen(cpf, "r"); // "r" = read (ler)
    fclose(file);
    
    if (file == NULL)
    {
      printf("o usuário nao foi encontrado no sistema!.\n");
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
    int opcao=0; //definindo as variáveis
    int laco=1;

    for(laco=1;laco=1;)
    {
     
      system("cls");

      setlocale(LC_ALL, "portuguese"); //definindo a linguagem

      printf("###cartorio da EBAC ###\n\n"); //inicio do menu
      printf("Escolha a opção desejada do menu\n\n");
      printf("\t1 - Registrar nomes\n");
      printf("\t2 - Consultar nomes\n");
      printf("\t3 - Deletar nomes\n");
      printf("\t4 - sair do sitema\n\n");
      printf("opção: "); // final do menu
      
      scanf("%d" , &opcao); //armazenamento a esolha do úsuario 

      system("cls"); //responsavel por limpar a tela

      switch (opcao) //início da seleção das opções
      {
      case 1:
      registro(); //chamada de funções
        system("pause");
        break;
      
      case 2:
      consulta(); //chamada de funções
        system("pause");
        break;

      case 3:
      deletar(); //chamada de funções
        system("pause");
		break;
		
      case 4:
      printf("obrigado por utilizar nosso sistema!");
        return 0;
		break;
	
		
       default:
        printf("essa opção não está disponivel!\n");
        system("pause");
        break;
        // fim das seleções
      }

    }

   }
