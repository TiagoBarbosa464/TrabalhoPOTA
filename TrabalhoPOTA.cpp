/*

Eng. da Computação - CMN05S1 - POTA

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
	printf(" CADASTRO DE PESSOAS NO Tribunal Rengional do Trabalho 11° Região®\n ================================================\n");
	if (numServ<length){	
		for (int i=numServ;i<length;i++){
				printf("\n Digite o nome do servidor: ");
				scanf("%s",serv[i].nome);
							
				printf("\n Digite a matrícula (apenas números): ");
					scanf("%d",&serv[i].matricula);
					for (j=0;(j<numServ)&&(j<length);j++){
						while (serv[i].matricula == serv[j].matricula){ 	//isso impede que a mesma matrícula seja cadastrada para diferentes servidores
							system("cls");
							printf("\n A matrícula digitada já foi cadastrada!\n");
							printf("\n Atribua um número válido para a matrícula: ");
							scanf("%d",&serv[i].matricula);
							}
						}
				printf("\n Digite a idade (apenas números): ");
				scanf("%d",&serv[i].idade);
				
				printf("\n Digite o CPF (o campo aceita pontos e hífen): ");
				scanf("%s",serv[i].cpf);	
				
				printf("\n Digite o Setor: ");
				scanf("%s",serv[i].setor);
				
				numServ++;
				system("cls");
				printf("\n Cadastro concluído!\n\n");
				system("pause");
				break;}
					}
	else{
		printf("\n Não é possível cadastrar mais servidores!\n\n");
		system("pause");}
};

void List_Serv(){		
	setlocale(LC_ALL, "Portuguese");
	system("cls");
	printf(" Listagem de Servidores - TRT11° REGIÃO®\n====================================\n");
		if (numServ>0){
			for (int i=0;(i<numServ)&&(i<length);i++){
				printf("\n Posição: %d",i);
				printf("\n Nome: %s",serv[i].nome);
				printf("\n Matrícula: %d",serv[i].matricula);
				printf("\n Idade: %d",serv[i].idade);
				printf("\n CPF: %s",serv[i].cpf);
				printf("\n Setor: %s\n\n",serv[i].setor);
			}
			system("pause");}	
		else{
			printf("\n Ainda não há servidores cadastrados!\n\n");
			system("pause");
	}
};

void Sequential_Search(){		//função que realiza uma busca linear SEM o uso de recurso
	
};

void Sequential_Search_With_Resource(){		//função que realiza uma busca linear COM o uso de recurso para campo tipo string
	setlocale(LC_ALL, "Portuguese");	
	system("cls");
	
	int i=0;
	int encontrado = 0; //falso
	char chave[128];
	
	printf(" BUSCA DE SERVIDORES - TRT11° REGIÃO®\n ======================================\n");
	printf("\n Digite o CPF a ser buscado: ");
    scanf("%s", chave);
    
	while (i < length && !encontrado){
		if(strcmp(chave, serv[i].cpf)==0){		//função strcmp  da biblioteca string.h de C/C++ que compara strings
		encontrado = 1; //Verdadeiro
		}else {
			i++;
		}
	}
	
    if(encontrado){
    	system("cls");
    	printf(" BUSCA DE SERVIDORES - TRT11° REGIÃO®\n ======================================\n");
    	printf("\n O CPF de Nº %s foi encontrado!\n\n", serv[i].cpf);
    	printf("\n Posição: %d",i);
		printf("\n Servidor: %s",serv[i].nome);
		printf("\n Matrícula: %d\n\n",serv[i].matricula);	
    }else{
		system("cls");
		printf(" BUSCA DE SERVIDORES - TRT11° REGIÃO®\n ======================================\n");
		printf("\n O CPF de Nº %s não foi encontrado!\n\n", chave);
	}
};

int Binary_Search(){		//função que realiza uma busca binária SEM o uso de recurso para um campo do tipo numérico
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
	
	printf(" BUSCA DE SERVIDORES - TRT11° REGIÃO®\n ======================================\n");
	printf("\n Digite a matrícula a ser buscada: ");
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
    	printf(" BUSCA DE SERVIDORES - TRT11° REGIÃO®\n ======================================\n");
    	printf("\n A matrícula de Nº %d foi encontrada!\n\n", serv[meio].matricula);
    	printf("\n Posição: %d",meio);
		printf("\n Servidor: %s",serv[meio].nome);
		printf("\n CPF: %s\n\n",serv[meio].cpf);	
    }else{
		system("cls");
		printf(" BUSCA DE SERVIDORES - TRT11° REGIÃO®\n ======================================\n");
		printf("\n A matrícula de Nº %d não foi encontrada!\n\n", chave);
	}
};		

void Binary_Search_With_Resource(){
	
};

void Search_Menu(){		
	setlocale(LC_ALL, "Portuguese");
	
	int op_menu;
	
	do{
		system("cls");
		printf(" BUSCA DE SERVIDORES - TRT11° REGIÃO®\n ==================================\n");
		
		if (numServ>0){
			system("cls");
			printf(" BUSCA DE SERVIDORES - TRT11° REGIÃO®\n ==================================\n");
			printf("\n SELECIONE O MÉTODO DE PESQUISA\n\n");
			printf("  1 - PESQUISA SEQUENCIAL SEM USO DE RECURSO\n");
			printf("  2 - PESQUISA SEQUENCIAL COM USO DE RECURSO\n");
			printf("  3 - PESQUISA BINÁRIA SEM USO DE RECURSO\n");
			printf("  4 - PESQUISA BINÁRIA COM USO DE RECURSO\n");
			printf("  0 - CANCELAR\n\n");
				
			printf(" Digite a opção desejada: ");
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
					printf("\n Opção inválida, tente novamente!\n\n");
					system("pause");
					break;
				}
			}
		else
			printf("\n Não é possível buscar funcionários porque ainda não há cadastros!\n\n");
			system("pause");
	}while(op_menu!=0);
};

main(){	
	setlocale(LC_ALL, "Portuguese");
	system("TITLE Athabasca Systems®");
	int op;
	
	do{
		system("cls");
		printf(" BEM-VINDO(A) AO SISTEMA DE CADASTRO DO TRIBUBUNAL REGIONAL DO TRABALHO - TRT11° REGIÃO®\n =================================================================\n");
		printf("\n ESCOLHA UMA DAS OPÇÕES ABAIXO\n\n");
		printf("  1 - CADASTRAR\n");
		printf("  2 - LISTAR\n");
		printf("  3 - BUSCAR\n");
		printf("  0 - SAIR\n\n");
		
		printf(" Digite a opção desejada: ");
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
				printf("\n Opção inválida, tente novamente!\n\n");
				system("pause");
				break;
		}
	}while(op!=0);
};
