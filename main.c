#include "functions.c"
int main(){
	TST *trie=inicializar();
	char palavra[1000],palavra1[1000],palavra2[1000],letra[1000];
	int opcao,i;
	do{
		system("cls");
		printf("\n\t\t\t0-Sair 1-Inserir 2-Imprimir 3-Alterar 4-Remover 5-Dist�ncia De Edi��o 6-Palavra Quebrada 7-Pavras Ligadas");
		printf("\n\t\t\t\tDigite a sua op��o\n\t\t\t\t\t");
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
				inserirfilhos(&(trie), palavra);
				break;
			case 2:
				imprimir(trie, palavra, 0);
				system("pause");
				break;
			case 3:
				fflush(stdin);
				printf("Digite a palavra a ser inserida na TRIE1\n");
				gets(palavra);
				fflush(stdin);
				fflush(stdin);
				printf("Digite a palavra a ser inserida na TRIE\n");
				gets(palavra1);
				fflush(stdin);
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
			case 4:
				fflush(stdin);
				printf("Digite a palavra a ser inserida na TRIE\n");
				gets(palavra);
				fflush(stdin);
				eliminar(trie,palavra);
				break;
			case 5:
					fflush(stdin);
					printf("\nDigite as palavras que ser�o calculadas as suas dist�ncias de edi��o\n");
					printf("Digite a primeira palavra\n");
					gets(palavra);
					fflush(stdin);
					fflush(stdin);
					printf("Digite a segunda palavra\n");
					gets(palavra1);
					fflush(stdin);
					printf("Digite a terceira palavra\n");
					gets(palavra2);
					fflush(stdin);
					if(buscar(trie,palavra)&&buscar(trie,palavra1)&&buscar(trie,palavra2))
						printf("A dist�ncia de edi��o entre a palavra %s e %s � de : %s ",palavra,palavra1, distancia_de_edicao(trie,palavra,letra,palavra1,palavra2,0));
					else
						printf("Uma das palavras digitadas n�o consta na �rvore");
					system("pause");
					break;
				case 6:
					fflush(stdin);
					printf("\nDigite as palavras que ser�o calculadas as suas dist�ncias de edi��o\n");
					printf("Digite a primeira palavra\n");
					gets(palavra);
					 palavra_quebrada(trie,palavra);
					system("pause");
					break;
					
				case 7:
					fflush(stdin);
					printf("\nDigite as palavras que ser�o calculadas as suas dist�ncias de edi��o\n");
					printf("Digite a primeira palavra\n");
					gets(palavra);
					fflush(stdin);
				/*	printf("Digite a segunda palavra\n");
					gets(palavra1);
					fflush(stdin);
					printf("%d",maior_palavra_entre_duas(trie,palavra,palavra1));*/
					imprimir_palavras_com_distacia_de_edicao(trie, palavra1,palavra, 0);
					system("pause");
					break;
			default:
				printf("Op��o inv�lida");
				system("pause");

		}
	}while(opcao!=0);

	return 0;
}
