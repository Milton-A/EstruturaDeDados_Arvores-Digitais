#include "functions.c"

int main(){
	setlocale(LC_ALL,"");
	TST *trie=inicializar();
	char palavra[1000],palavra1[1000],palavra2[1000],letra[1000];
	int opcao,i,distancia,valor;
	//Carrega os dados do ficheiro
	carregarpalavrasdoficheiro(&trie);
	do{
		system("cls");
		printf("\t\t\t\t\t\t\tDigital Trie\n\n");
		printf("\t\t\t#************************************************************************#\n");
		printf("\t\t\t#                                                                        #\n");
		printf("\t\t\t#       1- Inserir                  2- Eliminar                          #\n");
		printf("\t\t\t#       3- Palavra quebrada         4- Palavras ligadas                  #\n");
		printf("\t\t\t#       5- Imprimir em p�s-ordem    6- Imprimir em pr�-ordem             #\n");
		printf("\t\t\t#       7- Imprimir em ordem        8- Alterar elemento                  #\n");
		printf("\t\t\t#       9- Maior prefixo comum     10- Calcular a dist�ncia de edi��o    #\n");
		printf("\t\t\t#       0- Sair                                                          #\n");
		printf("\t\t\t#                                                                        #\n");
		printf("\t\t\t#************************************************************************#\n");
		printf("\t\t\tR:_ ");
		scanf("%d",&opcao);
		switch(opcao){
			case 0:
				printf("\t\t\tTerminando o programa...");
				break;
			case 1:
				fflush(stdin);
				printf("\t\t\tDigite a palavra a ser inserida na TRIE\n");
				printf("\t\t\t_ ");
				gets(palavra);
				fflush(stdin);
				lowercase(palavra);
				if(!buscar(trie,palavra)){
					inserirfilhos(&(trie), palavra);
					printf("\t\t\tPalavra inserida na Trie!!");
				}
				else
					printf("\t\t\tA palavra digitada j� se encontra na Trie!!\n\n\n");	
					system("pause");
				break;
			case 2:
				fflush(stdin);
				printf("\t\t\tDigite a palavra a ser eliminda na TRIE\n");
				printf("\t\t\t_ ");
				gets(palavra);
				fflush(stdin);
				//converte as string para minusculas
				lowercase(palavra);
				//chama a fun��o para eliminar
				eliminar(trie,palavra);
				printf("\t\t\tPalavra Eliminada!!");
				system("pause");
				break;
			case 3:// palavras quebras
				fflush(stdin);
				printf("\n\t\t\tPalavras Quebradas\n");
				printf("\t\t\tNesta sess�o lhe ser�o mostradas as palavras quebras\n");
				printf("\t\t\tDigite a primeira palavra\n");
				printf("\t\t\t_ ");
				gets(palavra);
				//converte as string para minusculas
				lowercase(palavra);
				//Chama aa fun�ao para verificar as palavras quebradas
			 	palavra_quebrada(trie,palavra);
				system("pause");
				break;
			case 4://Palavras ligadas
				fflush(stdin);
				printf("\n\t\t\tDigite as palavras que ser�o calculadas as suas dist�ncias de edi��o\n");
				printf("\t\t\tDigite a primeira palavra\n");
				printf("\t\t\t_ ");
				gets(palavra);
				fflush(stdin);
				//converte as string para minusculas
				lowercase(palavra);
				do{
					printf("\t\t\tDigite um n�mero\n");
					printf("\t\t\t_ ");
					scanf("%d",&valor);
				}while(valor<=3&&valor>=0)
				//Chama a fun��o para verificar as palavras com comprimento menor ou igual a 3 da palavra digitada
				imprimir_palavras_ligadas(trie, palavra1,palavra, 0,valor);
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
			case 7://Impress�o a em-ordem
				emordemimprimir(trie, palavra, 0);
				system("pause");
				break;
			case 8://Alterar uma palavra
				fflush(stdin);
				printf("\t\t\tDigite a palavra a ser inserida na TRIE1\n");
				printf("\t\t\t_ ");
				gets(palavra);
				fflush(stdin);
				//converte as string para minusculas
				lowercase(palavra);
				printf("\t\t\tDigite a palavra a ser inserida na TRIE\n");
				printf("\t\t\t_ ");
				gets(palavra1);
				fflush(stdin);
				//converte as string para minusculas
				lowercase(palavra1);
				//condi��o para verificar a existencia das palavras
				if(buscar(trie,palavra)){
					if(!buscar(trie,palavra1)){
						Alterar(trie,palavra,palavra1);

					}else
						printf("\t\t\t %s j� existe na arvore",palavra1);
				}
				else
					printf("\t\t\t %s n�o foi encontrada na �rvore",palavra);
				system("pause");

				break;
			case 9://maior_prefixo_comum
				fflush(stdin);
				printf("\n\t\t\tDigite as palavras que ser�o calculadas o maior prefixo comum\n");
				printf("\t\t\tDigite a primeira palavra\n");
				printf("\t\t\t_ ");
				gets(palavra);
				//converte as string para minusculas
				lowercase(palavra);
				fflush(stdin);
				printf("\t\t\tDigite a segunda palavra\n");
				printf("\t\t\t_ ");
				gets(palavra1);
				fflush(stdin);
				//converte as string para minusculas
				lowercase(palavra1);
				printf("\t\t\tDigite a terceira palavra\n");
				printf("\t\t\t_ ");
				gets(palavra2);
				fflush(stdin);
				//converte as string para minusculas
				lowercase(palavra2);
				//Condi��o para verificar a existencia das palavras
				if(buscar(trie,palavra)&&buscar(trie,palavra1)&&buscar(trie,palavra2))
					printf("\t\t\tO maior prefixo comum entre a palavra %s, %s e %s � de : %s ",palavra,palavra1,palavra2, maior_prefixo_comum(trie,palavra,letra,palavra1,palavra2,0));
				else
					printf("\t\t\tUma das palavras digitadas n�o consta na �rvore");
					system("pause");
				break;
			case 10:
				printf("\n\t\t\tDigite as palavras que ser�o calculadas as suas dist�ncias de edi��o\n");
				fflush(stdin);
				printf("\t\t\tDigite a primeira palavra\n");
				printf("\t\t\t_ ");
				gets(palavra);
				//converte as string para minusculas
				lowercase(palavra);
				fflush(stdin);
				printf("\t\t\tDigite a segunda palavra\n");
				printf("\t\t\t_ ");
				gets(palavra1);
				fflush(stdin);
				//converte as string para minusculas
				lowercase(palavra1);
				//MEtodo para calucular a distancia entre as palavras
				distancia=calculo_distancia_de_edicao(trie,palavra,palavra1);
				if(distancia!=-1)
					printf("\t\t\tA dist�ncia de edi��o entre a palavra %s e %s � de : %d ",palavra,palavra1,distancia);
				else
					printf("\t\t\tUma das palavras digitadas n�o existe na �rvore");
				system("pause");
				break;
			default:
				printf("\t\t\tOp��o inv�lida");
				system("pause");

		}
	}while(opcao!=0);

	return 0;
}
