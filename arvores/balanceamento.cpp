// compilar
// g++ <filename>.cpp -o <filename_out>

// executar
// ./<filename_out>

// copiar e rodar
// g++ balanceamento.cpp -o balanceamento && ./balanceamento

#include <iostream>
#include <algorithm>




// [ARVORE BALANCEADA]
// Faça uma análise a partir dos nós
// [altura(sub_esquerda) - altura(sub_direita)] > 1
// 1 -> equivale a diferenca de altura entre as folhas ou fator de balanceamento [FB]

// para identificar um nó desbalanceado
// FB = altura(sub_esquerda) - altura(sub_direita)
// FB = {-1, 0, 1} -> BALANCEADO
// FB < -1 || FB > 1 -> DESBALANCEADO


// - As árvores podem se tornar desbalanceadas caso valores sequenciais comecem a ser inseridos

//[rotacao simples]
//    5
//   / \
// 2   10



//[rotacao simples]
//        15
//       /  \
//      10   20

//[desbalanceada a esquerda-direita]
//     10
//    /
//   5
//    \
//     8

//[desbalanceada a direita-esquerda]
//   10
//     \
//     20
//     /
//    15

struct Node {
    int value;
    int height;
    Node* left;
    Node* right;
};


Node* create_node(int value) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->value = value;
    node->left = nullptr;
    node->right = nullptr;
    node->height = 1; // Cada nó começa com altura 1, o nó mais baixo tem altura 1
    return node;
}

int get_height(Node* node) {
    return node ? node->height : 0;
}

int get_balance(Node* node) {
    return node ? get_height(node->left) - get_height(node->right) : 0;
}

//[desbalanceada a direita]
//        10        [ x ]
//          \
//           15     [ y ]
//             \
//              20 

// Processo:
//      - y é a nova raiz aqui
//      - atualiza as alturas para cada nó alterado
Node* rotate_left(Node* x) {
    Node* y = x->right;
    Node* T = y->left;

    y->left = x;
    x->right = T;

    x->height = std::max(get_height(x->left), get_height(x->right)) + 1;
    y->height = std::max(get_height(y->left), get_height(y->right)) + 1;

    return y;
}

//[desbalanceada a esquerda]
//        10    [ y ]
//       /
//      5       [ x ]
//     /
//    2         

// Processo:
//      - x é a nova raiz aqui
//      - atualiza as alturas para cada nó alterado
Node* rotate_right(Node* y) {
    Node* x = y->left;
    Node* T = x->right;

    x->right = y;
    y->left = T;

    y->height = std::max(get_height(y->left), get_height(y->right)) + 1;
    x->height = std::max(get_height(x->left), get_height(x->right)) + 1;

    return x;
}

Node* insert(Node* node, int value) {
    
    if (node == nullptr) {
        return create_node(value);
    }

    
    if (value < node->value) {
        node->left = insert(node->left, value);
    } else if (value > node->value) {
        node->right = insert(node->right, value);
    } else {
        
        return node;
    }

    
    node->height = 1 + std::max(get_height(node->left), get_height(node->right));

    
    int balance = get_balance(node);

    
    
    if (balance > 1 && value < node->left->value) {
        return rotate_right(node);
    }

    
    if (balance < -1 && value > node->right->value) {
        return rotate_left(node);
    }

    
    if (balance > 1 && value > node->left->value) {
        node->left = rotate_left(node->left);
        return rotate_right(node);
    }

    
    if (balance < -1 && value < node->right->value) {
        node->right = rotate_right(node->right);
        return rotate_left(node);
    }

    return node; 
}

void pre_order(Node* root) {
    if (root != nullptr) {
        std::cout << root->value << " "; 
        pre_order(root->left);           
        pre_order(root->right);          
    }
}

int main() {
    Node* root = nullptr;

    root = insert(root, 10);
    root = insert(root, 20);
    root = insert(root, 30);
    root = insert(root, 40);
    root = insert(root, 50);
    root = insert(root, 25);

    std::cout << "Árvore em ordem: ";
    pre_order(root);
    std::cout << std::endl;

    return 0;
}
