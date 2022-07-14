#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include "declaration.h"
#include <ctype.h>
#include <string.h>

//declaracao da estrutura de dados arvore
struct tst{
	char letra;
	int ultimaletra;
	struct tst *esquerda,*meio, *direita;
};

//funcao pra inicializar a arvore
TST *inicializar(){
	return NULL;
}

//função para converter a string em minusculas
void lowercase(char *palavra){
	int j;	
	for (j=0;palavra[j]!='\0';j++){
		palavra[j] = tolower(palavra[j]); 		
	}
}

// função que retorna o tamanho de uma string
int vec_len(char *vec){
    int c = -1;
    while(*(vec++))
        c++;
    return c;
}

//função para inserir na raiz
TST *inserirRaiz(char letra){
	setlocale(LC_ALL,"");
	TST *aux = (TST *) malloc(sizeof(TST));
	if(aux){
		aux->letra = letra;
		aux->ultimaletra=0;
		aux->meio=aux->direita=aux->esquerda=NULL;
		return aux;
	}
	else
		printf("Não foi possível alocar memória");
	return NULL;
}

//função para inserir filhos
void inserirfilhos(TST **arvore, char *letra){
			
	if(!(*arvore))
		*arvore=inserirRaiz(*letra);
	if((*arvore)->letra<(*letra))
		inserirfilhos(&((*arvore)->direita),letra);
	else if((*arvore)->letra>(*letra))
		inserirfilhos(&((*arvore)->esquerda),letra);
	else{
		if(*(letra+1))
			inserirfilhos(&((*arvore)->meio),(letra+1));
		else
			(*arvore)->ultimaletra = 1;
	}
}

//função para imprimir em pos-ordem
void posordemimprimir(TST *arvore, char* palavra, int cont)
{
	if (arvore!=NULL)
    {
    		if(arvore->esquerda!=NULL)
     		posordemimprimir(arvore->esquerda, palavra, cont); 
	    if(arvore->direita!=NULL)
        	posordemimprimir(arvore->direita, palavra, cont);
        palavra[cont] = arvore->letra;
        if (arvore->ultimaletra)
        {
            palavra[cont+1] = '\0';
            if(vec_len(palavra)>=2)
            	printf( "%s\n", palavra);
        } 
        if(arvore->meio!=NULL)
        	posordemimprimir(arvore->meio, palavra, cont+1);
    
    
    }
    else
    	printf("\t\t\t\t\t\t\t\t\tÁrvore vazia!!");
}

//Função para carregar o ficheiro das palavras
void carregarpalavrasdoficheiro(TST **arvore){
	FILE *ficha_f;
	char palavra[10000];
	ficha_f=fopen("letras.txt","rt");
	while(!feof(ficha_f)){
		fscanf(ficha_f,"%s\n",palavra);
		lowercase(palavra);
		inserirfilhos(arvore, palavra);
	}
	fclose(ficha_f);
}

//função para imprimir em pre-ordem
void preordemimprimir(TST *arvore, char* palavra, int cont)
{
	if (arvore!=NULL)
    {
     
        palavra[cont] = arvore->letra;
        if (arvore->ultimaletra)
        {
            palavra[cont+1] = '\0';
            if(vec_len(palavra)>=2)
            	printf( "%s\n", palavra);
        } 
       if(arvore->meio!=NULL)
        	preordemimprimir(arvore->meio, palavra, cont+1);
    	if(arvore->esquerda!=NULL)
     		preordemimprimir(arvore->esquerda, palavra, cont); 
	    if(arvore->direita!=NULL)
        	preordemimprimir(arvore->direita, palavra, cont);
    }
    else
    	printf("\t\t\t\t\t\t\t\t\tÁrvore vazia!!");
}

//função para imprimir em-ordem
void emordemimprimir(TST *arvore, char* palavra, int cont)
{
    if (arvore!=NULL)
    {
    	if(arvore->esquerda!=NULL)
     		emordemimprimir(arvore->esquerda, palavra, cont); 
        palavra[cont] = arvore->letra;
        if (arvore->ultimaletra)
        {
            palavra[cont+1] = '\0';
            if(vec_len(palavra)>=2)
            	printf( "%s\n", palavra);
        } 
        if(arvore->meio!=NULL)
        	emordemimprimir(arvore->meio, palavra, cont+1);
        if(arvore->direita!=NULL)
        	emordemimprimir(arvore->direita, palavra, cont);
    }
    else
    	printf("\t\t\t\t\t\t\t\t\tÁrvore vazia!!");
}

//função para para achar a maior palavra entre duas
int maior_palavra_entre_duas(char *palavra,char *palavra1){
		int  i,j,cont=0,numero=vec_len(palavra), numero1=vec_len(palavra1);
		
	if(numero>numero1){
		for (i=0;palavra[i]!='\0'&&palavra[i]==palavra1[i];i++);
		for (j=i;palavra[j]!='\0';j++)
			cont++;
		if(cont==0)
			return -1;
		return cont;
	}
	 	
	else{
		for (i=0;palavra1[i]!='\0'&&palavra1[i]==palavra[i];i++);
		for (j=i;palavra1[j]!='\0';j++)
			cont++;
		if(cont==0)
			return -1;
		return cont;
	}
	return j;
}

//função para calcular a distancia entre duas palavras
int calculo_distancia_de_edicao(TST *arvore,char* palavra,char *palavra1){
	int cont=-1,i;
	if(buscar(arvore,palavra)&&buscar(arvore,palavra1)){
		cont++;
		if(vec_len(palavra)>vec_len(palavra1)){
			for(i=0;palavra[i]!='\0';i++)
				if(palavra[i]!=palavra1[i])
					cont++;
		}
			else{
					for(i=0;palavra1[i]!='\0';i++)
						if(palavra[i]!=palavra1[i])
							cont++;
			}
		return cont;
	}
	else
		return cont;

}

//funcao para imprimir as palavras ligadas, ou palvras com os mesmos prefixos
void imprimir_palavras_ligadas(TST *arvore, char* palavra,char *palavra1, int cont,int valor)
{
	int c;
    if (arvore!=NULL)
    {
    	if(arvore->esquerda!=NULL)
     		imprimir_palavras_ligadas(arvore->esquerda, palavra,palavra1, cont,valor); 
        palavra[cont] = arvore->letra;
        if (arvore->ultimaletra)
        {
            palavra[cont+1] = '\0';
            c=maior_palavra_entre_duas(palavra,palavra1);
        	if(c>=0&&c<=valor||!strcmp(palavra,palavra1))
            	printf( "%s \n", palavra);
        } 
        if(arvore->meio!=NULL)
        	imprimir_palavras_ligadas(arvore->meio, palavra,palavra1, cont+1,valor);
        if(arvore->direita!=NULL)
        	imprimir_palavras_ligadas(arvore->direita, palavra,palavra1, cont,valor);
    }
}

//função para verificar o maior prefixo entre as palavras
char *maior_prefixo_comum(TST *arvore,char* letra, char* palavra,char* palavra1,char *palavra2,int cont){

	if (arvore!=NULL&&(*letra)==(*palavra1)&&(*palavra1)==(*palavra2))
    {

    	if(arvore->esquerda!=NULL)
        	maior_prefixo_comum(arvore->esquerda,letra,palavra,palavra1,palavra2,cont);
        	if(arvore->letra==*letra&&(*letra)==(*palavra1)&&(*palavra1)==(*palavra2))
        		palavra[cont] = arvore->letra;
        if (arvore->ultimaletra||(*letra)!=(*palavra1)||(*palavra1)!=(*palavra2))
        {
            palavra[cont+1] = '\0';
        } 
        if(arvore->meio!=NULL)
        	maior_prefixo_comum(arvore->meio,letra+1,palavra,palavra1+1,palavra2+1,cont+1);
        if(arvore->direita!=NULL)
        	maior_prefixo_comum(arvore->direita,letra,palavra,palavra1,palavra2,cont);
    }
 
    return palavra;
}

//funcao para procurar um elemento 
void buscarelemento(TST *arvore,char *palavra, char* letra,int cont){
	if (arvore!=NULL){
	    if(arvore->esquerda!=NULL&&arvore->letra>*letra)
	   		buscarelemento(arvore->esquerda, palavra,letra, cont);
	       	palavra[cont] = arvore->letra;
       if (arvore->ultimaletra&&arvore->letra==*letra){
	        palavra[cont+1] = '\0';
	        printf( "%s\n", palavra);
	    } 
	    if(arvore->meio!=NULL&&arvore->letra==*letra)
	       	buscarelemento(arvore->meio, palavra,letra+1, cont+1);
        if(arvore->direita!=NULL&&arvore->letra<*letra)
	    	buscarelemento(arvore->direita, palavra,letra, cont);
	}   
}

//função para verificar palavras quebradas
void palavra_quebrada(TST *arvore,char *palavra){
	char palavra1[10000];
	int i,x=0;
	for(i=0;palavra[i]!='\0'&&x!=1;i++)
		x=buscar(arvore,palavra+i);
	if(x)
		printf("Sim. ");
	else
		printf("Não.\n");
	for(i=0;palavra[i]!='\0';i++)
		buscarelemento(arvore,palavra1,palavra+i,0);
}

//funçao para procurar uma palavra
int buscar(TST *arvore, char* letra)
{ 	
	if(arvore==NULL)
		 return 0;
	if(arvore->letra<*letra)
		buscar(arvore->direita,letra);
	else if(arvore->letra>*letra)
		buscar(arvore->esquerda,letra);
	else{
		if(*(letra+1)){
			buscar(arvore->meio,(letra+1));
		}
		else
			return arvore->ultimaletra;
	}
}

//função para eliminar uma palavra
int eliminar(TST *root, char* str)
{
 
    if (root == NULL)
        return 0;
    if (*(str+1)== '\0')
    {
        if (root->ultimaletra)
        {
            root->ultimaletra=0;
            return estavazia(root);
        }
            return 0;
    }
    else
    {
        if (*str < root->letra)
            eliminar(root->esquerda ,str);
        else if (*str > root->letra)
            eliminar(root->direita ,str);
        else if (*str == root->letra)
        {
            if( eliminar(root->meio ,str+1 ) )
            {
                free(root->meio);
                root->meio=NULL;
                return !root->ultimaletra && estavazia(root);
            }
        }
    }
    return 0;
}

//verifica se arvore está vazia
int estavazia(TST *arvore){
	if(arvore->esquerda||arvore->direita||arvore->meio)
		return 0;
	return 1;
}

// altera um elemento, eliminado o quue já existe
void Alterar(TST *arvore, char *palavra, char *palavra1)
{
    eliminar(arvore ,palavra);
	inserirfilhos(&(arvore), palavra1);

}

