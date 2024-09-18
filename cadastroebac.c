#include <stdio.h> //biblioteca de comunicacao com usuario 
#include <stdlib.h> // biblioteca de espaco em memoria 
#include <locale.h> // biblioteca de locacao de texto por regiao
#include <string.h> //biblioteca responsavel por cuidar das strings 

int registro() //funcao responsavel por cadastrar os usuarios no sistema 
{
   //inicio criacao da variaveis / strings
   char arquivo[40];
   char cpf[40];
   char nome[40];
   char sobrenome[40];
   char cargo[40];
   //final da criacao de variaveis /strings
   
   printf("Digite o CPF a ser cadastrado: ");
   scanf("%s",cpf);
   
   strcpy(arquivo, cpf); //responsavel por copiar os valores das strings cpf p arquivo 
   
   FILE *file; //crie o arquivo no banco de dados 
   file = fopen(arquivo,"w");
   fprintf(file,cpf);  //salva o valor da variavel
   fclose(file); //fecha o arquivo
   
   file = fopen(arquivo, "a");
   fprintf(file,",");
   fclose(file);
   
   printf("digite o nome a ser cadastrado:");
   scanf("%s",nome);
   
   file = fopen(arquivo,"a");
   fprintf(file,nome);
   fclose(file);
   
    file = fopen(arquivo, "a");
   fprintf(file,",");
   fclose(file);
   
   printf("Digite o sobrenome a ser cadastrado: ");
   scanf("%s",sobrenome );
   
   file = fopen(arquivo,"a");
   fprintf(file,sobrenome);
   fclose(file);
   
    file = fopen(arquivo, "a");
   fprintf(file,",");
   fclose(file);
   
   printf("Digite o cargo a ser cadastrado:");
   scanf("%S",cargo);
   
   file = fopen(arquivo,"a");
   fprintf(file,cargo);
   fclose(file);
   
   
   system("pause");
   
   
}

int consulta()
{

	setlocale(LC_ALL, "portuguese"); //definido a linguagem

	char cpf[40];
	char conteudo [200];
	
	printf("Digite o cpf a ser consultado: ");
	scanf("%s" ,cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("nao foi possivel abrir o arquivo, nao localizado. \n");
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\n Essas sao as informacoes do usuario:");
		printf("%s", conteudo);
		printf ("\n\n");
	}
	
	system("pause");
}

int deletar()
{
	char cpf[40];
	
	printf("Digite o CPF do usuario a ser deletado :");
	scanf("%s",cpf);
	
	remove(cpf);  //comando p deletar, importada das bibliotecas
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("O usuario nao se encontra no sistema ! /n ");
		system("pause");
	}
}

int main()
{

   int opcao=0; //definindo variaveis
   int x=1;
	
	for(x=1;x=1;)
	{
	
	 system("cls"); //comando de sistema p limpar a tela 
	 
	 
	 setlocale(LC_ALL, "portuguese"); //definido a linguagem
	
 	 printf("\t---cadastro,consulta e exclusão de nomes ---\n\n  "); //inicio do menu
	 printf("escolha a opcao desejada do menu \n\n");
	 printf("\t 1 - registrar nome \n ");
	 printf("\t 2 - consultar nomes \n");
	 printf("\t 3 - deletar nomes \n\n\n"); 
	 printf("opcoes :\t");//fim do menu
	
	 scanf("%d",&opcao); //armazenando escolha do usuario
	
	 system("cls"); //comando de sistema p limpar a tela 
	 
	 switch(opcao) //inicio de selecao
	 {
	 	case 1:
	 	registro();//chamada de funcoes 
		break;
	 
	 	case 2:
		consulta();
		break;
	
		case 3:
		deletar();
		break;
		
		default:
		printf("\t essa opocao nao esta disponivel tente 1, 2 ou 3 .\n");
		system("pause");
		break;
			
			
	 		
	 }
	
	
		
		
	}//fim da selecao 
	printf("\t\t\t\t esse Software e livre p uso ...\n");
}


