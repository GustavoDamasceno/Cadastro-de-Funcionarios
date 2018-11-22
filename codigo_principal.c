#include <stdio.h>
#include <stdlib.h>
#include "prototipos_struct.h"
#include<string.h>

int count=1, opcao,controle=0;

Pessoa empregados[100];

void paralelo() {
	int sair = 0;
	
	do{
		switch(count){
		case 1:{
			menu(); 
			break;
		}
		case 2:{
			add();
			break;
		}
		case 3:{
			if(strlen(empregados[0].nome) != 0){
				lista();
			}
			else{
				system("cls");
				printf("0 empregados cadastrados\n");
				count = 1;
			}
			break;
		}
		case 4:{
			if(strlen(empregados[0].nome) != 0){
				deletar();
			}
			else{
				system("cls");
				printf("0 empregados cadastrados\n");
				count = 1;
			}
			break;
		}
		case 5:{
			if(strlen(empregados[0].nome) != 0){
				editar();
			}
			else{
				system("cls");
				printf("0 empregados cadastrados\n");
				count = 1;
			}
			break;
		}
		case 6:{
			sair = 1;
			break;
		}
		}
	}while(sair == 0);
	
}

//------------------------------------------------- Menu ---------------------------------------------------

void menu(){

	do{
		printf("Sistema de registro de empregados\n\n");
		printf("1 - Adicionar empregado\n");
		printf("2 - Lista de empregado\n");
		printf("3 - Editar cadastro\n");
		printf("4 - Deletar empregado\n");
		printf("5 - Sair\n");
		printf("\nescolha a opcao desejada: ");
		
		scanf("%d", &opcao); //ESCOLHA DO USUARIO
		setbuf(stdin, NULL); //LIMPEZA DE BUFFER
		
			switch(opcao){
			case 1: 
				system("cls");
				count = 2; //chamar funcao add
				break;
			case 2:
				system("cls");
				count = 3; // chama a funcao lista
				break;
			case 3:
				system("cls");
				count = 5; // chama a funcao editar
				break;
			case 4:
				system("cls");
				count = 4; // chama a funcao deletar
				break;
			case 5:
				count=6;
				break;
			default:
				system("cls");
				printf("Opcao incorreta\n\n");
				
				break;
			}		
	}while((opcao<1)||(opcao>5));

}

//-------------------------------------------- adicionar ---------------------------------------------------

void add() {
	int i = 0, N = 0;
	
	FILE *arq;
	arq = fopen("notas.txt", "at");
	
	if(arq == NULL)
		printf("Erro, nao foi possivel abrir o arquivo\n");
	
	else{
		printf("Quantos empregados o Sr. deseja cadastrar: ");
		scanf("%d",&N);
		setbuf(stdin,NULL);
		
		for(i=0; i<N; i++){
			printf("\nDados pessoais do(a) empregado(a): \n\n");
			printf("Informe o nome: ");
			fgets(empregados[controle].nome, 99, stdin);
			setbuf(stdin,NULL);
			fprintf(arq, "nome: %s\n", empregados[controle].nome);
			printf("Informe a idade: ");
			scanf("%d", &empregados[controle].idade);
			setbuf(stdin,NULL);
			fprintf(arq, "idade: %d\n", empregados[controle].idade);
			printf("Informe o codigo de quatro digitos: ");
			scanf("%d", &empregados[controle].codigo);
			setbuf(stdin,NULL);
			fprintf(arq, "codigo: %d\n", empregados[controle].codigo);
			do{
				printf("Informe o sexo do(a) empregado(a), 'F' para feminino e 'M' para masculino : ");
				scanf("%c", &empregados[controle].sexo);
				setbuf(stdin,NULL);
				if((empregados[controle].sexo!='F')&&(empregados[controle].sexo!='M'))
					printf("\nOpcao invalida\n");
			}while((empregados[controle].sexo!='F')&&(empregados[controle].sexo!='M'));
			
			fprintf(arq, "sexo: %c\n", empregados[controle].sexo);
			
			printf("Informe o endereco: ");
			fgets(empregados[controle].endereco, 199, stdin);
			setbuf(stdin,NULL);
			fprintf(arq, "endereco: %s\n\n\n", empregados[controle].endereco);
			
			controle++;		
		}
		fclose(arq);
		
		printf("\n\n");
		do{
			printf("1 - Voltar ao menu\n");
			printf("2 - Encerrar programa:\n");
			printf("\n\n");
			printf("escolha uma opcao: ");
			scanf("%d", &opcao);
			setbuf(stdin,NULL);
			
			switch(opcao){
			case 1:
				system("cls");
				count = 1;	
				break;
			case 2:
				system("cls");
				count = 6;
				break;
			default : 
				system("cls");
				printf("Opcao incorreta\n\n");
		 }
			
		}while((opcao<1)||(opcao>2));
	}
}

//---------------------------------------- Lista ---------------------------------------------------------

void lista(){
	int i, aux;
	char escolha;
	
	do{
		for(i=0; i<controle; i++){
			printf("%d - %s\n", i+1, empregados[i].nome);
		}
		printf("Deseja ver as informacoes de algum dos empregados:(S) para sim e (N) para nao: ");
		scanf("%c",&escolha);
		system("cls");
		if((escolha!='S')&&(escolha!='N')){
			system("cls");
			printf("Opcao invalida\n");
		}	
	}while((escolha!='S')&&(escolha!='N'));
	
	if(escolha == 'S'){
		do{
			for(i=0; i<controle; i++){
				printf("%d - %s\n", i+1, empregados[i].nome);
			}
			printf("Qual o numero do empregado: ");
			scanf("%d",&opcao);
			aux = opcao-1;
			
			if((opcao<1)||(opcao>controle)){
				system("cls");
				printf("Opcao invalida\n");
			}
			
		}while((opcao<1)||(opcao>controle));
		
		system("cls");
		
		printf("Nome: %s\n", empregados[aux].nome);
		printf("Idade: %d\n", empregados[aux].idade);
		printf("Codigo: %d\n", empregados[aux].codigo);
		printf("Sexo: %c\n", empregados[aux].sexo);
		printf("Endereco: %s\n", empregados[aux].endereco);
		
	}
	
		do{
			printf("1 - Voltar ao menu\n");
			printf("2 - Encerrar programa:\n");
			printf("\n\n");
			printf("escolha uma opcao: ");
			scanf("%d", &opcao);
			setbuf(stdin,NULL);
			
			switch(opcao){
			case 1:
				system("cls");
				count = 1;	
				break;
			case 2:
				system("cls");
				count = 6;
				break;
			default : 
				system("cls");
				printf("Opcao incorreta\n\n");
		 }
			
		}while((opcao<1)||(opcao>2));
	
	
	
}

//-------------------------------------------------- Editar -----------------------------------------------

void editar(){
	int estilo,saida=0, i=0, aux = 0;
	do{
			for(i=0; i<controle; i++){
				printf("%d - %s\n", i+1, empregados[i].nome);
			}
			printf("Qual o numero do empregado: ");
			scanf("%d",&opcao);
			aux = opcao-1;
			
			if((opcao<1)||(opcao>controle)){
				system("cls");
				printf("Opcao invalida\n");
			}
			
		}while((opcao<1)||(opcao>controle));
		
		system("cls");
		
		do{
			printf("Nome: %s\n", empregados[aux].nome);
			printf("Idade: %d\n", empregados[aux].idade);
			printf("Codigo: %d\n", empregados[aux].codigo);
			printf("Sexo: %c\n", empregados[aux].sexo);
			printf("Endereco: %s\n", empregados[aux].endereco);
			printf("\n");
			do{
				printf("\n\n");
				printf("Opcoes a escolher: \n");
				printf("1 - Editar nome\n");
				printf("2 - Editar idade\n");
				printf("3 - Editar codigo\n");
				printf("4 - Editar sexo\n");
				printf("5 - Editar endereco\n");
				printf("6 - Escolher outro empregado\n");
				printf("7 - voltar ao menu\n");
				
				scanf("Escolha o numero da opcao : %d", &opcao);
				setbuf(stdin,NULL);
				switch(opcao){
					case 1:{
						
						estilo = 1;
						break;
					}
					case 2:{
						
						estilo = 2;
						break;
					}
					case 3:{
						
						estilo = 3;
						break;
					}
					case 4: {
						
						estilo = 4;
						break;
					}
					case 5:{
						
						estilo = 5;
						break;
					}
					case 6:{
						estilo = 0;
						saida = 1;
						
						count = 5; 
						break;
					}
					case 7:{
						estilo = 0;
						saida = 1;
						
						count = 1;
						break;
					}
					default:
						
						printf("Opcao invalida\n\n");
				}
			}while((opcao<1)||(opcao>7));
		
			if(estilo == 1){
				printf("Informe o nome: ");
				fgets(empregados[aux].nome, 99, stdin);
				setbuf(stdin,NULL);
			}
			if(estilo == 2){
				printf("Informe a idade: ");
				scanf("%d", &empregados[aux].idade);
				setbuf(stdin,NULL);
				
			}
			
			if(estilo == 3){
				printf("Informe o codigo de quatro digitos: ");
				scanf("%d", &empregados[aux].codigo);
				setbuf(stdin,NULL);	
			}
			if(estilo == 4){
					do{
						printf("Informe o sexo do(a) empregado(a), 'F' para feminino e 'M' para masculino : ");
						scanf("%c", &empregados[aux].sexo);
						setbuf(stdin,NULL);
						if((empregados[aux].sexo!='F')&&(empregados[aux].sexo!='M'))
							printf("\nOpcao invalida\n");
					}while((empregados[aux].sexo!='F')&&(empregados[aux].sexo!='M'));
			}
			if(estilo == 5){
				printf("Informe o endereco: ");
				fgets(empregados[aux].endereco, 199, stdin);
				setbuf(stdin,NULL);
			}
			
		}while(saida == 0);
		
	
		FILE *arq;
		arq = fopen("notas.txt", "r+");
		
		if(arq == NULL)
			printf("Erro, nao foi possivel abrir o arquivo\n");
		
		else{
			for(i=0; i<=controle; i++){
					fprintf(arq, "nome: %s\n", empregados[i].nome);
					fprintf(arq, "idade: %d\n", empregados[i].idade);
					fprintf(arq, "codigo: %d\n", empregados[i].codigo);
					fprintf(arq, "sexo: %c\n", empregados[i].sexo);
					fprintf(arq, "endereco: %s\n\n\n", empregados[i].endereco);
					
			}
			fclose(arq);
		}		
		
}

//----------------------------------------- deletar -------------------------------------------------------

void deletar(){
	int i=0, aux;
	char escolha;
	
	do{
		for(i=0; i<controle; i++){
			printf("%d - %s\n", i+1, empregados[i].nome);
		}
		printf("Deseja realmente deletar algum empregado: (S) para sim, (N) para nao:\n ");
		scanf("%c",&escolha);
		system("cls");
		if((escolha!='S')&&(escolha!='N')){
			system("cls");
			printf("Opcao invalida\n");
		}	
	}while((escolha!='S')&&(escolha!='N'));
	
	system("cls");
	
	if(escolha == 'S'){
	
		do{
			for(i=0; i<controle; i++){
			printf("%d - %s\n", i+1, empregados[i].nome);
			}
		
			printf("Numero do empregado que deseja deletar:  ");
			scanf("%d", &opcao);
			aux = opcao-1;
			if((opcao<1)||(opcao>controle)){
				system("cls");
				printf("Opcao invalida");
			}
			
		}while((opcao<1)||(opcao>controle)); 
		if((aux == controle)&&(aux == 0)){
			strcpy(empregados[aux].nome, "");
		}
		else{
			if(aux == controle){
				controle--;
			}
			else{
				empregados[aux] = empregados[controle];
				controle--;
			}
		}
		system("cls");
		printf("Empregado deletado com sucesso\n");
		
	}
		
		do{
			printf("1 - Voltar ao menu\n");
			printf("2 - Deletar outro funcionario:\n");
			printf("\n\n");
			printf("escolha uma opcao: ");
			scanf("%d", &opcao);
			setbuf(stdin,NULL);
			
			switch(opcao){
			case 1:
				system("cls");
				count = 1;	
				break;
			case 2:
				system("cls");
				count = 5;
				break;
			default : 
				system("cls");
				printf("Opcao incorreta\n\n");
		 }
			
		}while((opcao<1)||(opcao>2));
		
	}
