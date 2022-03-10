#pragma once

#include <memory>
#include "LinkedList.h"

namespace myds {

    template <typename T>
    class Stack {
    public:
        Stack() {
            stack = std::make_unique<LinkedList<T>>();
        }

        void push(T data) {
            stack->addLast(data);
        }

        T pop() {
            if ( stack->getSize() == 0 ) {
                std::cerr << "Nothing to pop." << std::endl;
                return NULL;
            }
            T data = stack->get(stack->getSize() - 1);
            stack->deleteAt(stack->getSize() -1 );
            return data;
        }

        T peek() {
            if ( stack->getSize() == 0 ) {
                std::cerr << "Nothing to peek." << std::endl;
                return NULL;
            }
            return stack->get(stack->getSize() - 1);
        }

        int getSize(){
            return stack->getSize();
        }

        bool isEmpty(){
            return stack->isEmpty();
        }

    private:
        std::unique_ptr<LinkedList<T>> stack;
    };
}

