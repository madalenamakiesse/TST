//Estrutura TST
typedef struct tST tst;
//Criar n�
tst *criarno(char chave);
//Fun��o que insere chave na tst
void insere(char chave[], tst **t);
//Fun��o que elimina senha
void elimina(char *chave, tst **t);
//Fun��o que procura senha na TST
int procura(char *chave, tst *t);
int procura2(char *chave, tst *t);


