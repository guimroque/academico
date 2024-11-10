#ifndef STACK_H
#define STACK_H

#include <stdexcept>

template <typename T>
class Stack {
    private:
        T* stack;       // Array de elementos
        int top;
        int capacity;


    public:
        Stack(int size = 10): top(-1), capacity(size) {
            stack = new T[capacity];
        }
        ~Stack() {
            delete[] stack;
        }


        void push(T value) {
            if(top == capacity - 1){
                throw std::overflow_error("Stack overflow");
            }
            stack[++top] = value;
        }

        T pop() {
            if(top == -1){
                throw std::underflow_error("Stack underflow");
            }

            return stack[top--];
        }

        // add const para garantir que nenhum membro seja alterado
        bool is_empty() const {
            return top == -1;
        }

        T peek() const {
            if(top == -1){
                throw std::underflow_error("Stack is Empty");
            }
            return stack[top];
        }

};

#endif
