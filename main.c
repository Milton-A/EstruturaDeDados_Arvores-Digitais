#include "functions.c"

int main(){
	setlocale(LC_ALL,"");
	TST *trie=inicializar();
	char palavra[1000],palavra1[1000],palavra2[1000],letra[1000];
	int opcao,i;
	carregarpalavrasdoficheiro(&trie);
	do{
		system("cls");
		printf("\t\t\t\t\t\t\tDigital Trie\n\n");
		printf("\t\t\t**************************************************************************\n");
		printf("\t\t\t#                                                                        #\n");
		printf("\t\t\t#           1- Inserir       \t\t2- Eliminar                      #\n");
		printf("\t\t\t#           3-Palavra Quebrada \t\t4- -Palavras Ligadas             #\n");
		printf("\t\t\t#           5- Imprimir em p�s-ordem \t6- Imprimir em pr�-ordem         #\n");
		printf("\t\t\t#           7- Imprimir em ordem \t8- Alterar elemento              #\n");
		printf("\t\t\t#           9-Dist�ncia De Edi��o       0-Sair                           #\n");
		printf("\t\t\t#                                                                        #\n");
		printf("\t\t\t**************************************************************************\n");
		printf("\t\t\tR:_ ");
		scanf("%d",&opcao);
		switch(opcao){
			case 0:
				printf("Terminando o programa...");
				break;
			case 1:
				fflush(stdin);
				printf("Digite a palavra a ser inserida na TRIE\n");
				gets(palavra);
				fflush(stdin);
				lowercase(palavra);
				if(!buscar(trie,palavra)){
					inserirfilhos(&(trie), palavra);
					printf("\t\t\t\t\t\t\tPalavra inserida na Trie!!");
				}
				else
					printf("\t\t\t\t\t\t\t A palavra digitada j� se encontra na Trie!!");	
				break;
			case 2:
				fflush(stdin);
				printf("Digite a palavra a ser eliminda na TRIE\n");
				gets(palavra);
				fflush(stdin);
				lowercase(palavra);
				eliminar(trie,palavra);
				break;
			case 3:// palavras quebras
				fflush(stdin);
				printf("\nPalavras Quebradas\n");
				printf("Nesta sess�o lhe ser�o mostradas as palavras quebras\n");
				printf("Digite a primeira palavra\n");
				gets(palavra);
				lowercase(palavra);
			 	palavra_quebrada(trie,palavra);
				system("pause");
				break;
			case 4://Palavras ligadas
				fflush(stdin);
				printf("\nDigite as palavras que ser�o calculadas as suas dist�ncias de edi��o\n");
				printf("Digite a primeira palavra\n");
				gets(palavra);
				fflush(stdin);
				lowercase(palavra);
				imprimir_palavras_com_distacia_de_edicao(trie, palavra1,palavra, 0);
				system("pause");
				break;
			case 5://Impress�o a p�s-ordem
				posordemimprimir(trie, palavra, 0);
				system("pause");
				break;
			case 6://Impress�o a pr�-ordem
				preordemimprimir(trie, palavra, 0);
				system("pause");
				break;
				break;
			case 7://Impress�o a em-ordem
				emordemimprimir(trie, palavra, 0);
				system("pause");
				break;
			case 8://Alterar uma palavra
				fflush(stdin);
				printf("Digite a palavra a ser inserida na TRIE1\n");
				gets(palavra);
				fflush(stdin);
				lowercase(palavra);
				printf("Digite a palavra a ser inserida na TRIE\n");
				gets(palavra1);
				fflush(stdin);
				lowercase(palavra1);
				if(buscar(trie,palavra)){
					if(!buscar(trie,palavra1)){
						Alterar(trie,palavra,palavra1);

					}else
						printf("%s j� existe na arvore",palavra1);
				}
				else
					printf("%s n�o foi encontrada na �rvore",palavra);
				system("pause");

				break;
			case 9:
				fflush(stdin);
				printf("\nDigite as palavras que ser�o calculadas as suas dist�ncias de edi��o\n");
				printf("Digite a primeira palavra\n");
				gets(palavra);
				lowercase(palavra);
				fflush(stdin);
				printf("Digite a segunda palavra\n");
				gets(palavra1);
				fflush(stdin);
				lowercase(palavra1);
				printf("Digite a terceira palavra\n");
				gets(palavra2);
				fflush(stdin);
				lowercase(palavra2);
				if(buscar(trie,palavra)&&buscar(trie,palavra1)&&buscar(trie,palavra2))
					printf("A dist�ncia de edi��o entre a palavra %s e %s � de : %s ",palavra,palavra1, distancia_de_edicao(trie,palavra,letra,palavra1,palavra2,0));
				else
					printf("Uma das palavras digitadas n�o consta na �rvore");
				system("pause");
				break;		
			default:
				printf("Op��o inv�lida");
				system("pause");

		}
	}while(opcao!=0);

	return 0;
}
