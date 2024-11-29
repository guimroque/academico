// compilar
// g++ <filename>.cpp -o <filename_out>

// executar
// ./<filename_out>

// copiar e rodar
// g++ main.cpp -o main && ./main

#include <iostream>

// [ARVORE BINÁRIA]

// - É uma estrutura em cadeia como pilhas ou filas
// - Composta por duas ligações por nó, esquerda e direita
//                      5 -> nó
//                     / \
//  filho esquerdo <- 3   7 -> filho direito
struct Node {
    int value;
    Node* left;
    Node* right;
};

Node* create_node(int value) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->value = value;
    new_node->right = nullptr;
    new_node->left = nullptr;

    return new_node;
}


// Processo:
//  - verifica se a arvore está vazia e cria o 1o nó se necessário
//  - caso a raiz exista, a partir dos 1os filhos, comeca a comparar
//  - se o valor é maior ou menor que o nó atual
//      - menor -> percorre todos os elementos a esquerda dos nós até encontrar um lugar
//      - maior -> percorre itens a direita dos nós até encontrar seu lugar
Node* insert(Node* root, int value) {
    if(root == nullptr){
        return create_node(value);
    }

    if(value < root->value) {
        root->left = insert(root->left, value);
    } else {
        root -> right = insert(root->right, value);
    }

    return root;
}


// [LEITURA]

// esquerda -> raiz -> direita
// resultado: ordem crescente, é usado para ordenar os valores da arvore
void in_order(Node* root) {
    if(root != nullptr){
        in_order(root->left);
        std::cout << root->value << " ";
        in_order(root->right);
    }
}

//  raiz -> esquerda -> direita
//  resultado: navega de maneira hierarquica entre os elementos
void pre_order(Node* root) {
    if (root != nullptr) {
        std::cout << root->value << " "; 
        pre_order(root->left);           
        pre_order(root->right);          
    }
}


//  Esquerda → Direita → Raiz
//  resultado -> varre todas as informacoes abaixo do nó primeiro, util para processar dependencias
void post_order(Node* root) {
    if (root != nullptr) {
        post_order(root->left);          
        post_order(root->right);         
        std::cout << root->value << " "; 
    }
}



int main() {
    Node* root = nullptr;
    

    root = insert(root, 8);
    root = insert(root, 13);
    root = insert(root, 21);
    root = insert(root, 2);
    root = insert(root, 3);
    root = insert(root, 1);
    root = insert(root, 5);

// [GABARITO]

//           8 
//          / \
//         2   13
//        / \     \
//       1   3     21
//            \
//             5

    std::cout << "\n[IN_ORDER]" << std::endl;
    in_order(root);
    std::cout << "\n[PRE_ORDER]" << std::endl;
    pre_order(root);
    std::cout << "\n[POST_ORDER]" << std::endl;
    post_order(root);

}