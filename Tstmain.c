#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include "TST.c"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int main(int argc, char *argv[]) {
	setlocale(LC_ALL,"Portuguese");
	tst *t_s_t=NULL;
	int op=1,tam,i,chave;
	char senha[60];
	char ficheiro[50];
	FILE *fiche;
	while(op!=5){
		printf("\nBem-vindo(a) ao menu TST!\n\tPor favor, escolha a opção:\n\t\t1-Inserir senha(s)\n\t\t2-Inserir senhas de um ficheiro\n\t\t3-Eliminar senha(s)\n\t\t4-Verificar se a senha é forte\n\t\t5-Sair\n\t\t\t");
		scanf("%d",&op);
			if(op==1){
				system("cls");
				do{
					printf("Por favor ,informe a quantidade de senhas que pretende adicionar:\t" );
					scanf("%d",&tam);
					system("cls");
				}while(tam<0);
				fflush(stdin);
				for(i=0;i<tam;i++){
					fflush(stdin);
					printf("\nSenha %d: ",i+1 );
					gets(senha);insere(senha, &t_s_t);
				}
				system("pause");
				system("cls");
				
			}
			if(op==2){
				system("cls");
				printf("\nNome do ficheiro (nomedoficheiro.txt): ");
				fflush(stdin);
				gets(ficheiro);
				fiche=fopen(ficheiro,"rt");
				if(fiche==NULL){
					printf("\nInsucesso ao abrir o ficheiro de entrada!");
					return;
				}
				else printf("\nSucesso ao abrir o ficheiro de entrada!");
				while(!feof(fiche)){
					fscanf(fiche,"%s",senha);
					insere(senha, &t_s_t);
				}
				system("cls");
				printf("Sucesso!\n");
				system("pause");
				system("cls");
			}
			if(op==3){
				system("cls");
				if(t_s_t==NULL) printf("A TST está vazia.\n");
				else{
					do{
						printf("\tPor favor ,informe a quantidade de senhas que pretende eliminar:\t" );
						scanf("%d",&tam);
						system("cls");
					}while(tam<0);
					for(i=0;i<tam;i++){
						printf("\nSenha %d: ",i+1 );
						fflush(stdin);
						gets(senha);
						if(procura2(senha,t_s_t)==1){
							elimina(senha,&t_s_t);
							printf("Sucesso!\n");
						} 
						else printf("%s, não se encontra na TST.\n",senha);
						strcpy(senha,"");
					}
				}
				system("pause");
				system("cls");
			}
			if(op==4){
				system("cls");
					fflush(stdin);
					printf("Senha criada: ");
					gets(senha);
					system("cls");
					if((strlen(senha)<8) || (procura(senha,t_s_t)==1 && strlen(senha)>=8)){
						printf("\tA senha ,%s, não é forte.\n\n",senha);
					}
					else printf("\tA senha ,%s, é forte.\n\n",senha);
					system("pause");
					system("cls");
					
			}
		}
		fclose(fiche);	
	return 0;
}
