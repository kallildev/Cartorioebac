#include <stdio.h> //biblioteca de cominicaçao de usuario
#include <stdlib.h> //biblioteca de alocaçao de espaço de memoria
#include <locale.h> //biblioteca de alocaçao de texto por regiao
#include <string.h> //biblioteca reponsavel por cuidar das string

int registro() //funçao responsavel por cadsastra os usuarios do sistema
{
	//inicio da criaçao de variavel
char arquivo[40];
char cpf[40];
char nome[40];
char sobrenome[40];
char cargo[40];
//final da criaçao
printf("digite o CPF a ser cadastrado:  "); //coletento informaçao dos usuarios
scanf("%s", cpf); //%s refere-se a string 

strcpy(arquivo, cpf); //responsavel por copiar os valores das string

FILE *file; //cria o arquivo 
file = fopen(arquivo, "w"); //cria o arquivo e o W significa escrever
fprintf(file,cpf); // salso o valor da variavel
fclose(file); // fecha o arquivo

file = fopen(arquivo, "a");
fprintf(file,",");
fclose(file);

printf("digite o nome a ser cadastrado:  ");
scanf("%s",nome);

file = fopen(arquivo,"a");
fprintf(file,nome);
fclose(file);

file = fopen(arquivo, "a");
fprintf(file,",");
fclose(file);

printf("Digite o sobrenome a ser cadastrado: ");
scanf("%s",sobrenome);

file = fopen(arquivo, "a");
fprintf(file,sobrenome);
fclose(file);

file = fopen(arquivo, "a");
fprintf(file,",");
fclose(file);

printf("Digite o cargo a ser cadastrado: ");
scanf("%s",cargo);

file = fopen(arquivo,"a");
fprintf(file,cargo);
fclose(file);


system("pause");

}

int consutar()
{
	setlocale(LC_ALL, "portuguese"); // definindo a linguagem
	
char cpf[40];
char conteudo[200];

printf("Digite o CPF a ser consutado: ");
scanf("%s",cpf);

FILE *file;
file = fopen(cpf,"r");

if(file == NULL)
{
	printf("Nao foi possivel abri o arquivo nao lacalizado no banco de dados!.\n");
}

while(fgets(conteudo, 200, file)  != NULL)
{
	printf("\nEssas sao as informaçoes do usuario: ");
	printf("%s", conteudo);
	printf("\n\n");
}

system("pause");
}

int deletar()
{
	char cpf[40];
	
	printf("Digite o CPF do usuario a ser deletado:  ");
	scanf("%s",cpf);
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("O usuario nao se encontra no sistema!.\n");
		system("pause");
	}
	
	
}


int main()
{
  int opcao=0; //definindo variaveis
  int x=1;
  
  for(x=1;x=10;)
  {

system("cls");  
  
   setlocale(LC_ALL, "portuguese"); // definindo a linguagem
  
   printf("### cartório da EBAC ###\n\n"); //inicio do menu
   printf("escolha a opçao desejada do menu:\n\n");
   printf("\t1 - registra nomes\n");
   printf("\t2 - consutar  nomes\n");
   printf("\t3 - deletar nomes\n\n"); 
   printf("\t4 - Sair do sisteme\n\n");
   printf("opçao: ");//fim do menu
   
   scanf("%d", &opcao); //armazenando a escolha do usuario 
   
   system("cls"); //responsavel por limpar a tela
   
   
   switch(opcao) //inicio da seleçao do menu
   { 
   	  case 1:
   	registro(); //chamada de funçoes
   	break;
   	
   	case 2:
   	consutar();
   	break;
   	
   	case 3:
   	deletar();
   	break;
   	
   	case 4:
   		printf("Obrigado por utilizar o sistema!\n");
   		return 0;
   		break;
   	
   	default:
   		printf("esta opçao nao esta disponivel!\n");
   system("pause");
   break;
   // fim da seleçao
   }
}

}
