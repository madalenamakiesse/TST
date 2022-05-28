//Estrutura TST
typedef struct tST tst;
//Criar nó
tst *criarno(char chave);
//Função que insere chave na tst
void insere(char chave[], tst **t);
//Função que elimina senha
void elimina(char *chave, tst **t);
//Função que procura senha na TST
int procura(char *chave, tst *t);
int procura2(char *chave, tst *t);


