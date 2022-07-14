typedef struct tst TST;
//Fun��es auxiliares
void lowercase(char *palavra);
int vec_len(char *vec);
void carregarpalavrasdoficheiro(TST **arvore);
int maior_palavra_entre_duas(char *palavra,char *palavra1);
void buscarelemento(TST *arvore,char *palavra, char* letra,int cont);
int buscar(TST *arvore, char* letra);
//Fun��es relacionadas a �rvore
TST *inicializar();
int eliminar(TST *root, char* str);
void inserir(TST **arvore,char *dados);
TST *inserirRaiz(char letra);
void inserirfilhos(TST **arvore, char *letra);
void posordemimprimir(TST *arvore, char* palavra, int cont);
void preordemimprimir(TST *arvore, char* palavra, int cont);
void emordemimprimir(TST *arvore, char* palavra, int cont);
void imprimir_palavras_ligadas(TST *arvore, char* palavra,char *palavra1, int cont,int valor);
char *maior_prefixo_comum(TST *arvore,char* letra, char* palavra,char* palavra1,char *palavra2,int cont);
void palavra_quebrada(TST *arvore,char *palavra);
int estavazia(TST *arvore);
void Alterar(TST *arvore, char *palavra, char *palavra1);
int calculo_distancia_de_edicao(TST *arvore,char* palavra,char *palavra1);


