#include <stdio.h>
#include <stdlib.h>
#include "TST.h"
//Estrutura ABB
typedef struct tST{
	char chave;
	int fimDaChave;
	struct tST *dir, *esq, *meio;
}tst;
//Criar n�
tst *criarno(char chave){
	tst *T=(tst*)malloc(sizeof(tst));
	T->chave=chave;
	T->dir=NULL;
	T->esq=NULL;
	T->meio=NULL;
	T->fimDaChave=0;
	return T;
}
//Fun��o que insere senha na TST
void insere(char chave[], tst **t){
		//Se o n� for igual a NULL quer dizer que n�o tem filhos(dir ou esq ou meio)
		if((*t)==NULL) *t=criarno(chave[0]);
		//Caso seja um pai , avaliarmos se a chave � maior/menor/igual que ele para correctemente posicionarmos na tst
		//Menor a esquerda e maior a direita
		if((*t)->chave > chave[0]) insere(chave,&((*t)->esq));
		if((*t)->chave < chave[0]) insere(chave,&((*t)->dir));
		if((*t)->chave == chave[0]){
			chave++;
			//se as letras s�o iguais e ainda n�o � o fim da string , continua para o meio
			if(chave[0]!='\0') insere(chave,&((*t)->meio));
			if(chave[0]=='\0') (*t)->fimDaChave=1;
			
		}
}
//Fun��o que elimina senha na TST
void elimina(char *chave, tst **t){
	if((*t)==NULL){
		return ;
	}
	else{
		//Vai para esquerda se a letra for menor a que est� no n� presente
		if((*t)->chave > chave[0]) elimina(chave,&(*t)->esq);
		//Vai para direita se a letra for maior a que est� no n� presente
		else if((*t)->chave < chave[0]) elimina(chave,&(*t)->dir);
		//Se n�o � maior ou menor , isto significa que a letra � igual a que est� no n� presente 
		else{
			//Se � prefixo
			if((*t)->fimDaChave==1 && chave[1]=='\0' && (*t)->meio!=NULL){
				(*t)->fimDaChave=0;
			}
			//Se n�o tem filhos
			if((*t)->meio==NULL && (*t)->dir==NULL && (*t)->esq==NULL) (*t)=NULL;
			//Se n�o chegou ao fim da string , avan�a para o meio
			else if(chave[1]!='\0'){
				chave++;
				elimina(chave,&(*t)->meio);
			} 
		}
	}
}
//Fun��o que procura senha
int procura(char *chave, tst *t){
	//Se o n� for igual a NULL quer dizer que n�o tem filhos(dir ou esq ou meio)
	if(t==NULL){
		return 0;
	}
	else{
		//Vai para esquerda se a letra for menor a que est� no n� presente
		if(t->chave > chave[0]) procura(chave,t->esq);
		//Vai para direita se a letra for maior a que est� no n� presente
		else if(t->chave < chave[0]) procura(chave,t->dir);
		//Se n�o � maior ou menor , isto significa que a letra � igual a que est� no n� presente 
		else{
			//Avalia se a palavra est� na TST
			if(t->fimDaChave==1 && chave[1]=='\0'){
				//Se chegou no fim da string e a senha se encontra na TST , retorna 1
				return 1;
			}
			else if(t->fimDaChave==1 && (chave[1]>='0' && chave[1]<='9') && chave[2]=='\0'){ 
				return 1;
				}
			else if(t->fimDaChave==0 && chave[1]=='\0') return 0;	
			//Se n�o chegou ao fim da string , avan�a para o meio
			else if(chave[1]!='\0'){
				chave++;
				procura(chave,t->meio);
			}
		}
	}		
}
int procura2(char *chave, tst *t){
	//Se o n� for igual a NULL quer dizer que n�o tem filhos(dir ou esq ou meio)
	if(t==NULL){
		return 0;
	}
	if(t->fimDaChave==1 && chave[1]=='\0'){
		//Se chegou no fim da string e a senha se encontra na TST , retorna 1
		return 1;
	}
	else{
		//Vai para esquerda se a letra for menor a que est� no n� presente
		if(t->chave > chave[0]) procura2(chave,t->esq);
		//Vai para direita se a letra for maior a que est� no n� presente
		else if(t->chave < chave[0]) procura2(chave,t->dir);
		//Se n�o � maior ou menor , isto significa que a letra � igual a que est� no n� presente 
		//Se n�o chegou ao fim da string , avan�a para o meio
		else if(chave[1]!='\0'){
			chave++;
			procura2(chave,t->meio);
		}
	}		
}



