/*

Eng. da Computa��o - CMN05S1 - POTA

Mateus Henrique Carvalho de Sousa - 03096306
Samuel Feitosa da Costa Rodrigues - 03116714
Ayrton Gabriel Alves da Costa - 03118434
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <locale.h>

#define length 10 

struct cadastro{
   	char nome[50], setor[30], cpf[30]; 
	int idade, matricula;
};

struct cadastro serv[length];

int numServ=0;

void Register_Serv(){ 	
	int j;
	setlocale(LC_ALL, "Portuguese");
	system("cls");
	printf(" CADASTRO DE PESSOAS NO Tribunal Rengional do Trabalho 11� Regi�o�\n ================================================\n");
	if (numServ<length){	
		for (int i=numServ;i<length;i++){
				printf("\n Digite o nome do servidor: ");
				scanf("%s",serv[i].nome);
							
				printf("\n Digite a matr�cula (apenas n�meros): ");
					scanf("%d",&serv[i].matricula);
					for (j=0;(j<numServ)&&(j<length);j++){
						while (serv[i].matricula == serv[j].matricula){ 	//isso impede que a mesma matr�cula seja cadastrada para diferentes servidores
							system("cls");
							printf("\n A matr�cula digitada j� foi cadastrada!\n");
							printf("\n Atribua um n�mero v�lido para a matr�cula: ");
							scanf("%d",&serv[i].matricula);
							}
						}
				printf("\n Digite a idade (apenas n�meros): ");
				scanf("%d",&serv[i].idade);
				
				printf("\n Digite o CPF (o campo aceita pontos e h�fen): ");
				scanf("%s",serv[i].cpf);	
				
				printf("\n Digite o Setor: ");
				scanf("%s",serv[i].setor);
				
				numServ++;
				system("cls");
				printf("\n Cadastro conclu�do!\n\n");
				system("pause");
				break;}
					}
	else{
		printf("\n N�o � poss�vel cadastrar mais servidores!\n\n");
		system("pause");}
};

void List_Serv(){		
	setlocale(LC_ALL, "Portuguese");
	system("cls");
	printf(" Listagem de Servidores - TRT11� REGI�O�\n====================================\n");
		if (numServ>0){
			for (int i=0;(i<numServ)&&(i<length);i++){
				printf("\n Posi��o: %d",i);
				printf("\n Nome: %s",serv[i].nome);
				printf("\n Matr�cula: %d",serv[i].matricula);
				printf("\n Idade: %d",serv[i].idade);
				printf("\n CPF: %s",serv[i].cpf);
				printf("\n Setor: %s\n\n",serv[i].setor);
			}
			system("pause");}	
		else{
			printf("\n Ainda n�o h� servidores cadastrados!\n\n");
			system("pause");
	}
};

void Sequential_Search(){		//fun��o que realiza uma busca linear SEM o uso de recurso
	
};

void Sequential_Search_With_Resource(){		//fun��o que realiza uma busca linear COM o uso de recurso para campo tipo string
	setlocale(LC_ALL, "Portuguese");	
	system("cls");
	
	int i=0;
	int encontrado = 0; //falso
	char chave[128];
	
	printf(" BUSCA DE SERVIDORES - TRT11� REGI�O�\n ======================================\n");
	printf("\n Digite o CPF a ser buscado: ");
    scanf("%s", chave);
    
	while (i < length && !encontrado){
		if(strcmp(chave, serv[i].cpf)==0){		//fun��o strcmp  da biblioteca string.h de C/C++ que compara strings
		encontrado = 1; //Verdadeiro
		}else {
			i++;
		}
	}
	
    if(encontrado){
    	system("cls");
    	printf(" BUSCA DE SERVIDORES - TRT11� REGI�O�\n ======================================\n");
    	printf("\n O CPF de N� %s foi encontrado!\n\n", serv[i].cpf);
    	printf("\n Posi��o: %d",i);
		printf("\n Servidor: %s",serv[i].nome);
		printf("\n Matr�cula: %d\n\n",serv[i].matricula);	
    }else{
		system("cls");
		printf(" BUSCA DE SERVIDORES - TRT11� REGI�O�\n ======================================\n");
		printf("\n O CPF de N� %s n�o foi encontrado!\n\n", chave);
	}
};

int Binary_Search(){		//fun��o que realiza uma busca bin�ria SEM o uso de recurso para um campo do tipo num�rico
	setlocale(LC_ALL, "Portuguese");	
	system("cls");

	int i, j;
	struct cadastro aux;
	
	int final, inicial, meio, chave, encontrado = 0;
	inicial = 0;
	final = length;
	
	for (i=0; i<length; i++){
		for (j = 0; j < length; j++){
		    if (serv[i].matricula < serv[j].matricula){
			    aux = serv[i];
			    serv[i] = serv[j];
			    serv[j] = aux;
		}
	    }	
	}
	
	printf(" BUSCA DE SERVIDORES - TRT11� REGI�O�\n ======================================\n");
	printf("\n Digite a matr�cula a ser buscada: ");
    scanf("%d", &chave);
	
	while (inicial <= final && !encontrado){
		meio = (inicial+final) / 2;
	    if (serv[meio].matricula == chave)
		    encontrado = 1;
	    else if (chave < serv[meio].matricula)
		    final = meio - 1;
	    else if (chave > serv[meio].matricula)
		    inicial = meio + 1;
   	}
   	
	if(encontrado){
    	system("cls");
    	printf(" BUSCA DE SERVIDORES - TRT11� REGI�O�\n ======================================\n");
    	printf("\n A matr�cula de N� %d foi encontrada!\n\n", serv[meio].matricula);
    	printf("\n Posi��o: %d",meio);
		printf("\n Servidor: %s",serv[meio].nome);
		printf("\n CPF: %s\n\n",serv[meio].cpf);	
    }else{
		system("cls");
		printf(" BUSCA DE SERVIDORES - TRT11� REGI�O�\n ======================================\n");
		printf("\n A matr�cula de N� %d n�o foi encontrada!\n\n", chave);
	}
};		

void Binary_Search_With_Resource(){
	
};

void Search_Menu(){		
	setlocale(LC_ALL, "Portuguese");
	
	int op_menu;
	
	do{
		system("cls");
		printf(" BUSCA DE SERVIDORES - TRT11� REGI�O�\n ==================================\n");
		
		if (numServ>0){
			system("cls");
			printf(" BUSCA DE SERVIDORES - TRT11� REGI�O�\n ==================================\n");
			printf("\n SELECIONE O M�TODO DE PESQUISA\n\n");
			printf("  1 - PESQUISA SEQUENCIAL SEM USO DE RECURSO\n");
			printf("  2 - PESQUISA SEQUENCIAL COM USO DE RECURSO\n");
			printf("  3 - PESQUISA BIN�RIA SEM USO DE RECURSO\n");
			printf("  4 - PESQUISA BIN�RIA COM USO DE RECURSO\n");
			printf("  0 - CANCELAR\n\n");
				
			printf(" Digite a op��o desejada: ");
			scanf("%d", &op_menu);
		
			switch(op_menu){
				case 0:
					system("cls");
					printf("\n Cancelando...\n\n");
					break;
					
				case 1: Sequential_Search();break;
				case 2: Sequential_Search_With_Resource();break;
				case 3: Binary_Search();break;
				case 4: Binary_Search_With_Resource();break;
				
				default:
		            system("cls");
					printf("\n Op��o inv�lida, tente novamente!\n\n");
					system("pause");
					break;
				}
			}
		else
			printf("\n N�o � poss�vel buscar funcion�rios porque ainda n�o h� cadastros!\n\n");
			system("pause");
	}while(op_menu!=0);
};

main(){	
	setlocale(LC_ALL, "Portuguese");
	system("TITLE Athabasca Systems�");
	int op;
	
	do{
		system("cls");
		printf(" BEM-VINDO(A) AO SISTEMA DE CADASTRO DO TRIBUBUNAL REGIONAL DO TRABALHO - TRT11� REGI�O�\n =================================================================\n");
		printf("\n ESCOLHA UMA DAS OP��ES ABAIXO\n\n");
		printf("  1 - CADASTRAR\n");
		printf("  2 - LISTAR\n");
		printf("  3 - BUSCAR\n");
		printf("  0 - SAIR\n\n");
		
		printf(" Digite a op��o desejada: ");
		scanf("%d", &op);
		
		switch(op){
			case 0:
				system("cls");
				printf("\n Saindo...\n");
				break;
				
			case 1: Register_Serv();break;
			case 2: List_Serv();break;
			case 3: Search_Menu();break; 
			
			default:
	            system("cls");
				printf("\n Op��o inv�lida, tente novamente!\n\n");
				system("pause");
				break;
		}
	}while(op!=0);
};
