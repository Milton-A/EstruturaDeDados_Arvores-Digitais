#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include "declaration.h"
#include <ctype.h>
struct tst{
	char letra;
	int ultimaletra;
	struct tst *esquerda,*meio, *direita;
};
TST *inicializar(){
	return NULL;
}
void lowercase(char *palavra){
	int j;	
	for (j=0;palavra[j]!='\0';j++){
		palavra[j] = tolower(palavra[j]); 		
	}
}

int vec_len(char *vec){
    int c = -1;
    while(*(vec++))
        c++;
    return c;
}
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

int maior_palavra_entre_duas(char *palavra,char *palavra1){
		int  i,j,cont=0,numero=vec_len(palavra), numero1=vec_len(palavra1);
	if(numero>numero1){
		for (i=0;palavra[i]!='\0'&&palavra[i]==palavra1[i];i++);
		for (j=i;palavra[j]!='\0';j++)
			cont++;
		return cont;
	}
	 	
	else{
		for (i=0;palavra1[i]!='\0'&&palavra1[i]==palavra[i];i++);
		for (j=i;palavra1[j]!='\0';j++)
			cont++;
		return cont;
	}
	return j;
}
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
void imprimir_palavras_com_distacia_de_edicao(TST *arvore, char* palavra,char *palavra1, int cont)
{
	int c;
    if (arvore!=NULL)
    {
    	if(arvore->esquerda!=NULL)
     		imprimir_palavras_com_distacia_de_edicao(arvore->esquerda, palavra,palavra1, cont); 
        palavra[cont] = arvore->letra;
        if (arvore->ultimaletra)
        {
            palavra[cont+1] = '\0';
            c=maior_palavra_entre_duas(palavra,palavra1);
        	if(c>=0&&c<=3)
            	printf( "%s \n", palavra);
        } 
        if(arvore->meio!=NULL)
        	imprimir_palavras_com_distacia_de_edicao(arvore->meio, palavra,palavra1, cont+1);
        if(arvore->direita!=NULL)
        	imprimir_palavras_com_distacia_de_edicao(arvore->direita, palavra,palavra1, cont);
    }
}

char *distancia_de_edicao(TST *arvore,char* letra, char* palavra,char* palavra1,char *palavra2,int cont){
	if (arvore!=NULL&&arvore->letra==*letra&&arvore->letra==*palavra1&&arvore->letra==*palavra2)
    {
    	if(arvore->esquerda!=NULL&&arvore->letra>*letra)
        	distancia_de_edicao(arvore->meio,letra+1,palavra,palavra1+1,palavra2+1,cont);
        	palavra[cont] = arvore->letra;
        if (arvore->ultimaletra&&arvore->letra==*letra)
        {
            palavra[cont+1] = '\0';
            return palavra;
        } 
        if(arvore->meio!=NULL&&arvore->letra==*letra)
        	distancia_de_edicao(arvore->meio,letra+1,palavra,palavra1+1,palavra2+1,cont+1);
        if(arvore->direita!=NULL&&arvore->letra<*letra)
        	distancia_de_edicao(arvore->meio,letra+1,palavra,palavra1+1,palavra2+1,cont);
    }
 
    return palavra;
}

char *maior_palavra(TST *arvore,char *palavra,char *palavra1,char *palavra2){
	int  numero=vec_len(palavra), numero1=vec_len(palavra1),numero2=vec_len(palavra2);
	char letra[1000];
	if(numero>numero1 &&numero>numero2)
	 	return distancia_de_edicao(arvore,palavra,letra,palavra1,palavra2,0);
	else if(numero1>numero &&numero1>numero2)
		return distancia_de_edicao(arvore,palavra1,letra,palavra,palavra2,0);
	else if(numero2>numero &&numero2>numero1)
		return distancia_de_edicao(arvore,palavra2, letra,palavra1,palavra2,0);
}

void buscarelemento(TST *arvore,char *palavra, char* letra,int cont)
{
 if (arvore!=NULL)
    {
    	if(arvore->esquerda!=NULL&&arvore->letra>*letra)
     		buscarelemento(arvore->esquerda, palavra,letra, cont);
        	palavra[cont] = arvore->letra;
        if (arvore->ultimaletra&&arvore->letra==*letra)
        {
            palavra[cont+1] = '\0';
            printf( "%s\n", palavra);
        } 
        if(arvore->meio!=NULL&&arvore->letra==*letra)
        	buscarelemento(arvore->meio, palavra,letra+1, cont+1);
        if(arvore->direita!=NULL&&arvore->letra<*letra)
        	buscarelemento(arvore->direita, palavra,letra, cont);
    }
}
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
int estavazia(TST *arvore){
	if(arvore->esquerda||arvore->direita||arvore->meio)
		return 0;
	return 1;
}

void Alterar(TST *arvore, char *palavra, char *palavra1)
{
     	eliminar(arvore ,palavra);
		inserirfilhos(&(arvore), palavra1);

}

