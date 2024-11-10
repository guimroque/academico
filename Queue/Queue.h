#ifndef QUEUE_H
#define QUEUE_H

#include <stdexcept>

template <typename T>
class Queue {
    private:
        T* queue;       //Array de elementos
        int front;
        int rear;
        int capacity;
        int count;

    public:
        Queue(int size = 100) : front(0), rear(-1), capacity(size), count(0) {
            queue = new T[capacity];
        }

        ~Queue() {
            delete[] queue;
        }


       void enqueue(T item) {
            if (count == capacity) {
                throw std::overflow_error("Queue overflow");
            }
            rear = (rear + 1) % capacity;
            queue[rear] = item;
            count++;
        }

        T dequeue() {
            if (is_empty()) {
                throw std::underflow_error("Queue underflow");
            }
            T item = queue[front];
            front = (front + 1) % capacity;
            count--;
            return item;
        }

        T peek() const {
            if (is_empty()) {
                throw std::underflow_error("Queue is empty");
            }
            return queue[front];
        }

        bool is_empty() const {
            return (count == 0);
        }

        int size() const {
            return count;
        }
};

#endif

