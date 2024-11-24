// compilar
// g++ <filename>.cpp -o <filename_out>

// executar
// ./<filename_out>

// copiar e rodar
// g++ main.cpp -o main && ./main


#include <iostream>

// [PONTEIRO]
// Ponteiro é uma variável que armazena um endereço de memória
// O operador & retorna o endereço de memória de uma variável
// O operador * retorna o valor de uma variável apontada por um ponteiro
void ponteiro() {
    int x = 1;

    // ptr é um ponteiro para um inteiro
    // ptr recebeu o endereço de memória da variável x
    int* ptr = &x;

    std::cout << "Valor de x: " << *ptr << std::endl;
    std::cout << "Endereço de x: " << &ptr << std::endl;

    return;
}

// [NÓ]
// Nós são estruturas de armazenamento, 
// como se fossem uma struct, ou objeto em linguagem de mais alto nivel
// São normalmente utilizados em estruturas de ordenação como filas, pilhas, arvores, grafos
// Podem armazenar mais de um ponteiro ou elementos
// Os nós podem ser diversos, e implementados de acordo com a necessidade
// [NÓ-PILHA]
struct NodePilha {
    int data;
    NodePilha* next;
};

// [PILHA]
// Uma estrutura de dados dinamica, que segue a regra LIFO (Last In, First Out)
// A pilha possui nós (POSICOES)
// Cada nó possui a info que precisa ser lida e um ponteiro para o próximo nó
// a pilha possui um nó especial - 1o, pois a partir dele é possível ler toda a fila
// typedef `NodeFila`<ponteiro da struct> `*Pilha`<Nome da variável>
typedef NodePilha *Pilha;

// `Pilha&` significa que o parametro é passado por referencia
// caso o parametro passado seja alterado dentro da funcao
// também será alterado no contexto fora da função
// As pilhas são iniciadas com null neste exeplo
bool PilhaVazia(Pilha& p) {
    return p == NULL;
}

// A pilha por deinição é o 1o nó
Pilha Topo(Pilha& p)  {
    return p;
}


// adiciona um novo elemento na pilha
void Empilha(Pilha& p, int v) {
    // cria um novo nó, aqui é necessário allocar uma qtd de memoria suficiente
    // o malloc() é usado para definir o tamanho de memoria para a variavel
    // sizeof() mede o tamanho de um item, neste caso da struct NodeFila
    NodePilha* newNodePilha = (NodePilha*)malloc(sizeof(NodePilha));

    // O operador `->` é usado para acessar um campo dentro da variável para onde o ponteiro aponta
    // Processo:
        // - adicionar o valor da variável que recebemos como parametro
        // - adicionar como proximo item, o ponteiro do 1o item da fila recebida
        // - adiciona a fila recebida, o novo node -> Fila = 1o node, por definicao
    newNodePilha->data = v;
    newNodePilha->next = p;
    p = newNodePilha;
}

// o free() libera uma memoria alocada
// Processo:
    // - verifica se a pilha tá vazia e retorna um valor arbitrário -> 100000 (o correto é parar a execucao)
    // - salva o nó do topo
    // - armazenar o valor do topo
    // - atualiza o nó do topo para o nó que o atual aponta
int Desempilha(Pilha& p) {
    if(PilhaVazia(p)){
        std::cout << "Pilha vazia" << std::endl;
        return 100000;
    }

    NodePilha* auxNodePilha = p;
    int valor = auxNodePilha->data;
    p = auxNodePilha->next;
    free(auxNodePilha);

    return valor;
}

// processo:
    // - declara uma variável auxiliar para o elemento atual da pilha
    // - adiciona um looping para travar a execucao até que a var auxiliar seja null
    // - cada execucao printa o valor atual
void PrintPilha(Pilha p){
    while(p != NULL){
        std::cout << "Valor do item: " << p->data << "    item atual: " << p << "    próximo item: " << p->next << std::endl;
        Desempilha(p);
    }
}

void pilha(){

    // declara uma fila vazia
    Pilha mPilha = NULL;
    // por definicao, uma pilha é o ponteiro do ultimo item adiciona a ela

    Empilha(mPilha, 10);
    Empilha(mPilha, 21);
    Empilha(mPilha, 13);
    Empilha(mPilha, 30);
    Desempilha(mPilha);
    Empilha(mPilha, 21);
    Desempilha(mPilha);
    Empilha(mPilha, 31);

    // os enderecos de memoria são espacados entre eles na qtd de memoria utilizado pelo node
    PrintPilha(mPilha);

    return;
}

// [FILA]
// Uma estrutura de dados dinamica, que segue a regra FIFO (First In, First Out)
// A fila possui nós (POSICOES)
// Cada nó possui uma informação para ser lida e um ponteiro para o próximo nó
// as filas possuem 2 nós especiais, o 1o - front e o ultimo - rear
// [NÓ-FILA]
struct NodeFila {
    int data;
    NodeFila* next;
};

// [FILA]
struct Fila {
    NodeFila* front;
    NodeFila* rear;
    int Nro;
};

bool FilaVazia(Fila f){
    return f.front == NULL;
}

// Processo:
    // - cria um novo nó com o valor recebido
    // - recebe o valor do parametro
    // - next aponta para null pois é o ultimo
    // - altera a estrutura da fila
        // - se a fila estiver vazia, esse novo item é o 1o e ultimo
        // - incremente a quantidade de elementos na fila
        // - se a fila possuir itens, altere o ultimo item antigo para que aponte a este nó
void InsereFila(Fila& f, int v) {
    NodeFila* novo = (NodeFila*)malloc(sizeof(NodeFila));

    novo->data = v;
    novo->next = NULL;

    if(FilaVazia(f)) { // se a fila estiver vazia
        f.front = novo; // esse é o 1o nó
    } else { // se possuir itens
        f.rear->next = novo; // o ultimo deve apontar para esse
    }

    f.rear = novo;
    f.Nro++;
}

// Processo:
    // - verifica se a fila é vazia, se for apenas retorne false informando que nao foi possível remover
    // - Crie um nó auxiliar para receber o valor a ser removido
    // - Atualize o início da fila para o próximo nó
        // - Se a fila ficar vazia, adicione o ultimo como NULL
    // - Decremente 1 em Nro (quantidade de elementos)
bool RemoveFila(Fila& f, int& v) {
    if(FilaVazia(f)) {
        return false;
    }

    NodeFila* aux = f.front;
    v = aux->data;
    f.front = aux->next;

    if(FilaVazia(f)) {
        f.rear = NULL;
    }

    free(aux);
    f.Nro--;
    return true;
}

// processo:
    // - declara uma variável auxiliar para o elemento atual da pilha
    // - adiciona um looping para travar a execucao até que a var auxiliar seja null
    // - cada execucao printa o valor atual
void PrintFila(Fila p) {
    while (p.front != NULL) {
        int value = 0;
        RemoveFila(p, value);

        std::cout << "Valor do item: " << value;
        if (p.front != NULL) { // Garante que não acessa NULL
            std::cout << "\t1o: " << p.front->data
                      << "\tproximo: " << p.front->next;
        } else {
            std::cout << "\t1o: NULL";
            std::cout << "\tproximo: NULL";
        }
        std::cout << std::endl;
    }
}

void fila() {
    Fila mFila;
    mFila.front = NULL;
    mFila.rear = NULL;
    mFila.Nro = 0;

    int aux_i = 0;

    InsereFila(mFila, 12);
    InsereFila(mFila, 29);
    InsereFila(mFila, 14);
    InsereFila(mFila, 27);
    RemoveFila(mFila, aux_i);
    InsereFila(mFila, 13);
    
    PrintFila(mFila);
}

int main() {
    std::cout << "\n\n\n[Ponteiro]:" << std::endl;
    ponteiro();
    std::cout << "\n\n\n[Pilha]:" << std::endl;
    pilha();
    std::cout << "\n\n\n[Fila]:" << std::endl;
    fila();

    return 0;
}
