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
		printf("\t\t\t#       5- Imprimir em pós-ordem    6- Imprimir em pré-ordem             #\n");
		printf("\t\t\t#       7- Imprimir em ordem        8- Alterar elemento                  #\n");
		printf("\t\t\t#       9- Maior prefixo comum     10- Calcular a distância de edição    #\n");
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
					printf("\t\t\tA palavra digitada já se encontra na Trie!!\n\n\n");	
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
				//chama a função para eliminar
				eliminar(trie,palavra);
				printf("\t\t\tPalavra Eliminada!!");
				system("pause");
				break;
			case 3:// palavras quebras
				fflush(stdin);
				printf("\n\t\t\tPalavras Quebradas\n");
				printf("\t\t\tNesta sessão lhe serão mostradas as palavras quebras\n");
				printf("\t\t\tDigite a primeira palavra\n");
				printf("\t\t\t_ ");
				gets(palavra);
				//converte as string para minusculas
				lowercase(palavra);
				//Chama aa funçao para verificar as palavras quebradas
			 	palavra_quebrada(trie,palavra);
				system("pause");
				break;
			case 4://Palavras ligadas
				fflush(stdin);
				printf("\n\t\t\tDigite as palavras que serão calculadas as suas distâncias de edição\n");
				printf("\t\t\tDigite a primeira palavra\n");
				printf("\t\t\t_ ");
				gets(palavra);
				fflush(stdin);
				//converte as string para minusculas
				lowercase(palavra);
				do{
					printf("\t\t\tDigite um número\n");
					printf("\t\t\t_ ");
					scanf("%d",&valor);
				}while(valor<=3&&valor>=0)
				//Chama a função para verificar as palavras com comprimento menor ou igual a 3 da palavra digitada
				imprimir_palavras_ligadas(trie, palavra1,palavra, 0,valor);
				system("pause");
				break;
			case 5://Impressão a pós-ordem
				posordemimprimir(trie, palavra, 0);
				system("pause");
				break;
			case 6://Impressão a pré-ordem
				preordemimprimir(trie, palavra, 0);
				system("pause");
				break;
			case 7://Impressão a em-ordem
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
				//condição para verificar a existencia das palavras
				if(buscar(trie,palavra)){
					if(!buscar(trie,palavra1)){
						Alterar(trie,palavra,palavra1);

					}else
						printf("\t\t\t %s já existe na arvore",palavra1);
				}
				else
					printf("\t\t\t %s não foi encontrada na árvore",palavra);
				system("pause");

				break;
			case 9://maior_prefixo_comum
				fflush(stdin);
				printf("\n\t\t\tDigite as palavras que serão calculadas o maior prefixo comum\n");
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
				//Condição para verificar a existencia das palavras
				if(buscar(trie,palavra)&&buscar(trie,palavra1)&&buscar(trie,palavra2))
					printf("\t\t\tO maior prefixo comum entre a palavra %s, %s e %s é de : %s ",palavra,palavra1,palavra2, maior_prefixo_comum(trie,palavra,letra,palavra1,palavra2,0));
				else
					printf("\t\t\tUma das palavras digitadas não consta na árvore");
					system("pause");
				break;
			case 10:
				printf("\n\t\t\tDigite as palavras que serão calculadas as suas distâncias de edição\n");
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
					printf("\t\t\tA distância de edição entre a palavra %s e %s é de : %d ",palavra,palavra1,distancia);
				else
					printf("\t\t\tUma das palavras digitadas não existe na árvore");
				system("pause");
				break;
			default:
				printf("\t\t\tOpção inválida");
				system("pause");

		}
	}while(opcao!=0);

	return 0;
}
