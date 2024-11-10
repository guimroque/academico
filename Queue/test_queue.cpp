#include "Queue.h"
#include "../Mock/Person.h"
#include <iostream>
#include <cassert>
#include <string>




void test_int_queue(){
    Queue<int> queue(3);
    queue.enqueue(11);
    queue.enqueue(13);

    assert(queue.is_empty() == false);

    assert(queue.peek() == 11);
    assert(queue.dequeue() == 11);
    assert(queue.size() == 1);

    assert(queue.dequeue() == 13);
    assert(queue.is_empty() == true);
}




int main() {
    test_int_queue();



    std::cout << "✅ Queue tests." << std::endl;
    return 0;
}
