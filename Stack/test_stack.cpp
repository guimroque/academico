#include "Stack.h"
#include "../Mock/Person.h"
#include <iostream>
#include <cassert>
#include <string>



void test_int_stack() {
    Stack<int> stack(3);
    stack.push(10);
    stack.push(20);

    assert(stack.is_empty() == false);
    assert(stack.pop() == 20);
    assert(stack.pop() == 10);
    assert(stack.is_empty() == true);
}


void test_person_stack() {
    Stack<Person> stack(4);
    Person guilherme("Guilherme", 2);
    Person miguel("Miguel", 25);


    stack.push(guilherme);
    stack.push(miguel);

    assert(stack.is_empty() == false);
    assert(stack.peek() == miguel);
    assert(stack.pop() == miguel);
    assert(stack.pop() == guilherme);
    assert(stack.is_empty() == true);
}


int main() {    
    test_int_stack();
    test_person_stack();

    std::cout << "✅ Stack tests." << std::endl;

    return 0;
}
