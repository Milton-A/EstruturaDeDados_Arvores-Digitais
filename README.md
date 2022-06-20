# Árvores Digitais
Árvores Digitais

Visão Geral
Um grupo de traficantes tem passado mensagens secretas entre eles por meio
de um código antigo a que chamaremos código XRP. A razão para isso, é que o
código praticamente já não é utilizado e a maioria das pessoas que o conheciam
já morreram. Entretanto, a polícia de investigação conseguiu interceptar
algumas destas mensagens. Depois de usarem as técnicas mais avançadas de
encriptação sem sucesso, o grupo de investigação percebeu que a mensagem
interceptada é uma variação do código XRP que em tempos foi muito usada.
Conseguiu-se obter um ficheiro com o alfabeto do código XRP, o que é uma
grande ajuda, mas leva muito tempo, porque a tradução é feita letra por letra.
Um dos membros da equipa de investigação, lembrou-se de contactar o
departamento de engenharias do ISPTEC para arranjar uma solução que acelere
este processo e vocês foram chamados a participar nesta empreitada.
Uma vez que o código é representado por pontos (.) e traços (-), o problema
poderá ser resolvido com árvores digitais binárias. As letras numa palavra do
código são separadas por espaço ( ), enquanto que as palavras são separadas
por (/).
A ideia geral do programa é a criação da árvore de símbolos do código e permitir
a conversão das mensagens a pedido do utilizador.

Estrutura do trabalho

Ao iniciar o programa, este deverá ler o ficheiro com a representação do código
e construir a árvore que será usada na pesquisa. A entrada dos dados para a
descodificação será feita a partir da linha de comandos. A primeira linha deve
conter um número, que representa o número de mensagens a serem
descodificadas, seguidas pelas mensagens codificadas em XRP, uma mensagem
por cada linha. Como saída, o programa mostra as mensagens descodificadas,
numeradas uma por linha.
É obrigatório criar o TAD árvore binária que represente a árvore de códigos. As
seguintes operações deverão estar disponíveis, não necessariamente nesta
ordem.
1. Criar dicionário (árvore de símbolos a partir do ficheiro)
2. Inserir novo símbolo (insere o novo símbolo e o caracter correspondente)
3. Alterar símbolo
4. Eliminar símbolo
5. Consultar símbolo (mostra caso exista, o símbolo e o caracter
correspondente)
6. Imprimir nas três ordens (imprime sempre para cada símbolo, o caracter
correspondente)
7. Destruir o dicionário (árvore).
8. Descodificar mensagens
De forma a simplificar o programa, serão desconsideradas a acentuação e
caracteres especiais.
Conteúdo do ficheiro XRP.txt
