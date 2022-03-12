#pragma once

#include <memory>
#include <iostream>
#include "LinkedList.h"

namespace myds {

    template <typename T>
    class Stack {
    public:
        Stack() {
            stack = std::make_unique<LinkedList<T>>();
        }

        void push(const T& data) {
            stack->addLast(data);
        }

        T pop() {
            if ( isEmpty() ) {
                std::cerr << "Nothing to pop." << std::endl;
                return NULL;
            }
            T data = stack->get(stack->getSize() - 1);
            stack->deleteAt(stack->getSize() -1 );
            return data;
        }

        T peek() const {
            if ( isEmpty() ) {
                std::cerr << "Nothing to peek." << std::endl;
                return NULL;
            }
            return stack->get(stack->getSize() - 1);
        }

        void clear() {
            while (!isEmpty()) pop();
        }

        [[nodiscard]] int getSize() const {
            return stack->getSize();
        }

        [[nodiscard]] bool isEmpty() const {
            return stack->isEmpty();
        }

    private:
        std::unique_ptr<LinkedList<T>> stack;
    };
}

