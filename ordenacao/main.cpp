// compilar
// g++ <filename>.cpp -o <filename_out>

// executar
// ./<filename_out>

// copiar e rodar
// g++ main.cpp -o main && ./main


#include <iostream>

// Valor de referencia
// int tamanho = 5;
// int v = {5, 3, 8, 6, 2};
// int c = {2, 3, 5, 6, 8};



// [BUBBLE SORT]
//      - Compara elementos adjacentes e troca se estiverem fora de ordem
//      - Esquerda > Direita
//      - A cara varredura completa do array, o maior item será o mais a direita
//      - Complexidade:
//          - melhor caso = O(n) -> se todos já estiverem na posicao correta, só vai varrer o vetor
//          - pior caso = O(nˆ2) -> se estiver 

// exemplo:
// [5, 3, 8, 6, 2]
// [3, 5, 8, 6, 2]
// [3, 5, 8, 6, 2]
// [3, 5, 6, 8, 2]
// [3, 5, 6, 2, 8]

void bubble_sort() {
    int tamanho = 5;
    int bubble[5] = {5, 3, 8, 6, 2};
    // ignore sempre o ultimo elemento, pois esse nao tem com quem ser trocado
    for(int j = 0; tamanho > j - 1; j++) { // ref maiores = direita -> esquerda
        for (int i = 0; i < tamanho - j - 1 ; i++) { // ref troca = esquerda -> direita
            if(bubble[i] > bubble[i+1]) { // se i atual for maior que proximo i
                // troca
                int aux = bubble[i];
                bubble[i] = bubble[i+1];
                bubble[i+1] = aux;
            }
        }
    }

    // printa o resultado
    for (int i=0; i<tamanho; i++) {
        std::cout << bubble[i] << std::endl;
    }
    return;
}




// [SELECTION SORT]
//      - Encontra o menor elemento, e move para a 1a posição, de maneira recursiva
//      - A o ínicio da pesquisa vai se deslocando para a direita a cada vez que o array é varrido
//      - complexidade -> O(nˆ2) em todos os casos, porque a cond do if é sempre válida ao menos 1 vez por varredura


// exemplo:
// [5, 3, 8, 6, 2]
// [2, 3, 8, 6, 5]
// [2, 3, 8, 6, 5]
// [2, 3, 5, 6, 8]
// [2, 3, 5, 6, 8]
void selection_sort() {
    int tamanho = 5;
    int selection[5] = {5, 3, 8, 6, 2};

    // deslocamento para a direita do array
    for(int j=0; tamanho > j; j++) { // esquerda -> direita
        int index_menor = j; // sempre o menor elemento
        for(int i = j + 1; i  < tamanho; i++) {
            if(selection[index_menor] > selection[i]){
                index_menor = i;
            }
        }

        // troca
        int aux = selection[index_menor];
        selection[index_menor] = selection[j];
        selection[j] = aux;
    }

    // printa o resultado
    for (int i=0; i<tamanho; i++) {
        std::cout << selection[i] << std::endl;
    }
    return;

}

// INSERTION SORT]
//      - Separa o array em 2 partes: 
//          - 1o elemento a esquerda (parte ordenada)
//          - resto (parte desordenada)
//      - Seleciona o 1o elemento da parte nao ordenada (ordenada+1)
//      - Desloca ele até a sua posição dentro do array ordenado (esquerda)

// exemplo:
// [5, 3, 8, 6, 2]
// [3, 5, 8, 6, 2]
// [3, 5, 8, 6, 2]
// [3, 5, 6, 8, 2]
// [2, 3, 5, 6, 8]
void insertion_sort() {
    int tamanho = 5;
    int insertion[5] = {5, 3, 8, 6, 2};

    // comeca com 1 deslocado a direta
    // a posicao 0 aqui equivale a parte ordenada
    for(int i=1; i < tamanho; i++) {
        int key = insertion[i];

        // estabelece o inicio do range da parte ordenada
        int j = i - 1;
        // percorre a parte ordenada
        // movendo para direita tudo que é maior que key
        while(j>=0 && insertion[j] > key) {
            insertion[j+1] = insertion[j];
            j--;
        }

        insertion[j+1] = key; // adiciona a key na posicao correta
    }

    // printa o resultado
    for (int i=0; i<tamanho; i++) {
        std::cout << insertion[i] << std::endl;
    }
    return;

}




// dubbug main
int main () {

    std::cout << "[BUBBLE_SORT]" << std::endl;
    bubble_sort();
    std::cout << "[SELECTION_SORT]" << std::endl;
    selection_sort();
    std::cout << "[INSERTION_SORT]" << std::endl;
    selection_sort();
    return 0;
}


